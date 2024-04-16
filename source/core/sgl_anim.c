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
#include <string.h>
#include "stdio.h"
#include "../draw/sgl_draw.h"

static uint64_t sgl_tick_ms_counter = 0;

void sgl_tick_inc(uint32_t ms)
{
    sgl_tick_ms_counter += ms;
}

uint64_t sgl_tick_get()
{
    return sgl_tick_ms_counter;
}


static sgl_anim_t sgl_anim_active_list_head;

void sgl_anim_add_active_obj(sgl_anim_t *anim)
{
    sgl_list_add_node_at_tail(&sgl_anim_active_list_head.node, &anim->node);
}

void sgl_anim_del_active_obj(sgl_anim_t *anim)
{
    sgl_list_del_node(&anim->node);
}

sgl_list_node_t* sgl_anim_get_active_list_head(void)
{
    return &sgl_anim_active_list_head.node;
}

void sgl_anim_init_active_list(void)
{
    sgl_list_init(&sgl_anim_active_list_head.node);
}

void sgl_anim_set_anim_cb(sgl_anim_t *anim, void (*anim_cb)(struct sgl_anim *, void *), void* data)
{
    anim->anim_cb = anim_cb;
    anim->anim_cb_data = data;
}

void sgl_anim_set_times(sgl_anim_t *anim, uint32_t  times)
{
    anim->times = times;
}

void sgl_anim_set_interval(sgl_anim_t *anim, uint32_t  interval)
{
    anim->interval = interval;
}

void sgl_anim_set_endless(sgl_anim_t *anim, bool status)
{
    anim->endless = status;
}

void sgl_anim_bind_obj(sgl_anim_t *anim, sgl_obj_t *obj)
{
    anim->obj = obj;
}

void sgl_anim_exec(sgl_anim_t *anim)
{
    anim->tick = sgl_tick_ms_counter;
    sgl_anim_add_active_obj(anim);
}


void sgl_animation_handler(void)
{
    sgl_anim_t *current_anim;
    sgl_list_node_t *current_node;
    sgl_list_node_t *node_head = sgl_anim_get_active_list_head();
    sgl_list_for_each(current_node, node_head) {
        current_anim = container_of(current_node, struct sgl_anim, node);
        if((sgl_tick_ms_counter - current_anim->tick) >= current_anim->interval) {
            if(current_anim->times) {
                current_anim->anim_cb(current_anim, current_anim->anim_cb_data);
                if(!current_anim->endless) {
                    current_anim->times -- ;
                }
            }
            sgl_obj_set_event_status(current_anim->obj, SGL_EVENT_FORCE_DRAW);
            sgl_draw_handler(current_anim->obj);
            current_anim->tick += current_anim->interval;
        }
        if(current_anim->times == 0) {
            sgl_anim_del_active_obj(current_anim);
        }
    }
}
