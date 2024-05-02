/* source/core/sgl_anim.c
 *
 * MIT License
 *
 * Copyright(c) 2023-present All contributors of SGL  
 *  
 * Email: 1477153217@qq.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "./sgl_core.h"
#include "../libs/sgl_string.h"
#include "../draw/sgl_draw.h"
#include "./sgl_log.h"

/**
 * Counter used to record system time, in milliseconds
*/
static uint64_t sgl_tick_ms_counter = 0;


/**
 * @brief The system clock increases by ms each time, in milliseconds
 * 
 * @param ms:  increases time, ms
 * 
 * @return none
*/
void sgl_tick_inc(uint32_t ms)
{
    sgl_tick_ms_counter += ms;
}


/**
 * @brief get the system clock, in milliseconds
 * 
 * @param: none
 * 
 * @return uint64_t: system clock, in milliseconds
*/
uint64_t sgl_tick_get(void)
{
    return sgl_tick_ms_counter;
}


/**
 * @brief Set the callback function for animation, which is used to fulfill the user's needs
 * 
 * @param anim:  animation object
 * @param anim_cb:  animation callback function
 * @param data:  callback function parameter
 * 
 * @return none
*/
void sgl_anim_set_anim_cb(sgl_anim_t *anim, void (*anim_cb)(struct sgl_anim *, void *), void* data)
{
    anim->anim_cb = anim_cb;
    anim->anim_cb_data = data;
}


/**
 * @brief Set the execution cycle of the animation
 * 
 * @param anim:  animation object
 * @param times: cycle of the animation
 * 
 * @return none
*/
void sgl_anim_set_times(sgl_anim_t *anim, uint32_t  times)
{
    anim->times = times;
}


/**
 * @brief Set the execution interval of the callback function for animation, in milliseconds
 * 
 * @param anim:  animation object
 * @param interval:  The time interval between the execution of the callback function, in milliseconds
 * 
 * @return none
*/
void sgl_anim_set_interval(sgl_anim_t *anim, uint32_t  interval)
{
    anim->interval = interval;
}


/**
 * @brief Set the animation to endless mode, meaning that the callback function will continue to execute
 * 
 * @param anim:  animation object
 * @param status:  Is there no termination of execution?
 * 
 * @return none
*/
void sgl_anim_set_endless(sgl_anim_t *anim, bool status)
{
    anim->endless = status;
    anim->times = 0xFFFFFFFF;
}


/**
 * @brief Bind animation to objects, animation only applies to this object, note that an 
 *        animation can only bind one object
 * 
 * @param anim:  animation object
 * @param obj:   the sgl object, such as arcbar, switch, button, etc.
 * 
 * @return none
*/
void sgl_anim_bind_obj(sgl_anim_t *anim, sgl_obj_t *obj)
{
    anim->obj = obj;
}


/**
 * @brief The animation starts executing, and after executing this function, 
 *        the animation object will be added to the animation queue
 * 
 * @param anim:  animation object
 * 
 * @return none
*/
void sgl_anim_exec(sgl_anim_t *anim)
{
    sgl_page_t *page = container_of(anim->obj->parent, sgl_page_t, obj);
    
    anim->tick = sgl_tick_ms_counter;
    if(page != NULL) {
        sgl_list_add_node_at_tail(&page->anim, &anim->node);
    }
}


/**
 * @brief Set animation active, this function will active the animation
 * 
 * @param anim: animation object
 * 
 * @return none
*/
void sgl_anim_active(sgl_anim_t *anim)
{
    anim->active_flag = true;
}


/**
 * @brief Set animation inactive, this function will stop the animation
 * 
 * @param anim: animation object
 * 
 * @return none
*/
void sgl_anim_inactive(sgl_anim_t *anim)
{
    anim->active_flag = false;
}


/**
 * @brief Animation destroy, this function will delete the animation from the animation linked list
 * 
 * @param anim: animation object
 * 
 * @return none
*/
void sgl_anim_destroy(sgl_anim_t *anim)
{
    sgl_page_t *page = container_of(anim->obj->parent, sgl_page_t, obj);
    anim->tick = 0;
    if(page != NULL) {
        sgl_list_del_node(&anim->node);
    }
}


/**
 * @brief The execution handle of the animation, which will traverse all animations and execute its callback function. 
 *        Note that this function will only traverse the current active page, and inactive pages will not be executed4
 *
 * @param none
 * 
 * @return none
*/
void sgl_animation_handler(void)
{
    sgl_anim_t *current_anim;
    sgl_list_node_t *current_node;

    //get page object and foreach page anim list
    sgl_obj_t *page_obj = sgl_page_get_active();
    sgl_page_t *page = container_of(page_obj, sgl_page_t, obj);

    sgl_list_node_t *node_head = &page->anim;
    sgl_list_for_each(current_node, node_head) {
        current_anim = container_of(current_node, struct sgl_anim, node);
        if(current_anim->active_flag) {

            if((sgl_tick_ms_counter - current_anim->tick) >= current_anim->interval) {
                if(current_anim->times) {
                    current_anim->anim_cb(current_anim, current_anim->anim_cb_data);
                    if(!current_anim->endless) {
                        current_anim->times -- ;
                    }
                }
                sgl_obj_set_event_status(current_anim->obj, SGL_EVENT_FORCE_DRAW);
                current_anim->obj->draw_cb(current_anim->obj);
                current_anim->tick += current_anim->interval;
            }
            if(current_anim->times == 0) {
                sgl_anim_destroy(current_anim);
            }
        }
    }
}

