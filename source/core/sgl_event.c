/* source/core/sgl_event.c
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

#include "./sgl_obj.h"
#include "./sgl_event.h"
#include "./sgl_page.h"
#include "../libs/sgl_string.h"

/**
 * A queue has been defined, and arrays are used here for speed. If a sampling linked list is implemented, 
 * real-time performance may not meet the requirements
*/
sgl_event_pos_t sgl_event_queue[SGL_CONFIG_EVQUEUE_DEPTH];

/**
 * A global variable is defined here to store information about the event that is currently occurring
*/
sgl_event_pos_t sgl_event_device;


static int16_t __queue_head = 0;
static int16_t __queue_tail = 0;


/**
 * @brief Determine if the event queue is empty
 * 
 * @param none
 * 
 * @return bool: true is empty, false is not empty
*/
bool sgl_event_queue_is_empty(void)
{
    if(__queue_head == __queue_tail) {
        return true;
    }
    else {
        return false;
    }
}


/**
 * @brief Determine if the event queue is full
 * 
 * @param none
 * 
 * @return bool: true is full, false is not full
*/
bool sgl_event_queue_is_full(void)
{
    if(__queue_head == 0 && __queue_tail == (SGL_CONFIG_EVQUEUE_DEPTH - 1)) {
        return true;
    }
    else if((__queue_tail + 1) == __queue_head) {
        return true;
    }
    else {
        return false;
    }
}


/**
 * @brief Push an element to the event queue
 * 
 * @param event: Events to be pushed in
 * 
 * @return none
*/
void sgl_event_queue_push(sgl_event_pos_t event)
{
    if(event.type == SGL_EVENT_NULL)
        return;
    sgl_event_queue[__queue_head] = event;
    if((__queue_head - 1) < 0) {
        __queue_head = (SGL_CONFIG_EVQUEUE_DEPTH - 1);
    }
    else {
        __queue_head -- ;
    }
    sgl_event_set_device_pos(event);
}


/**
 * @brief Pop up an element from the event queue
 * 
 * @param none
 * 
 * @return sgl_event_pos_t: Pop up event, including the coordinates and type of the event
*/
sgl_event_pos_t sgl_event_queue_pop(void)
{
    sgl_event_pos_t event = sgl_event_queue[__queue_tail];
    if((__queue_tail - 1) < 0) {
        __queue_tail = (SGL_CONFIG_EVQUEUE_DEPTH - 1);
    }
    else {
        __queue_tail -- ;
    }
    return event;
}


/**
 * @brief Clear all elements in the event queue
 * 
 * @param none
 * 
 * @return none
*/
void sgl_event_queue_clear(void)
{
    for(int i = 0; i < SGL_CONFIG_EVQUEUE_DEPTH; i++) {
        sgl_event_queue[i].type = SGL_EVENT_NULL;
    }
    __queue_head = 0;
    __queue_tail = 0;
}


/**
 * @brief Set the currently occurring event, which will be called every time it is pushed into the event queue
 * 
 * @param Ongoing events
 * 
 * @return none
*/
void sgl_event_set_device_pos(sgl_event_pos_t event)
{
    sgl_event_device = event;
}


/**
 * @brief Get ongoing events
 * 
 * @param none
 * 
 * @return Ongoing events
*/
sgl_event_pos_t sgl_event_get_device_pos(void)
{
    return sgl_event_device;
}

extern sgl_obj_t *active_page;


/**
 * @brief All event handling in SGL, this function will traverse all elements in the event queue, 
 *        respond to each element with an event, so that all events will trigger and point to the 
 *        corresponding callback function
 * 
 * @param none
 * 
 * @return none
*/
void sgl_event_handler(void)
{
    sgl_obj_t *current_obj;
    sgl_list_node_t *current_node;
    sgl_list_node_t *root_node = sgl_page_get_obj_head(active_page);
    sgl_event_pos_t evt_pos;

    if(!sgl_event_queue_is_empty()) {

        //pop an event from event queue
        evt_pos = sgl_event_queue_pop();

        //foreach all event, and it will handinig callback function 
        sgl_list_for_each(current_node, root_node) {
            current_obj = container_of(current_node, struct sgl_obj, node);
            if( current_obj->event_fn 
                && sgl_obj_event_active(current_obj, evt_pos.x, evt_pos.y) 
                && current_obj->hide == 0) {
                    
                //set the event status, it will be used in draw callback
                sgl_obj_set_event_status(current_obj, evt_pos.type);
                current_obj->dirty = 1;
            }
        }
    }
}


/**
 * @brief Redraw all objects on the current active page. If the object is in a dirty state, redraw it. 
 *        Otherwise, nothing will be done
 * 
 * @param none
 * 
 * @return none
*/
void sgl_active_page_dirty_handler(void)
{
    sgl_obj_t *current_obj;
    sgl_list_node_t *current_node;
    sgl_list_node_t *node_head = sgl_page_get_obj_head(active_page);

    sgl_list_for_each(current_node, node_head) {
        current_obj = container_of(current_node, struct sgl_obj, node);
        //if the object is dirty and it will be redraw
        if(current_obj->dirty == 1) {

            current_obj->draw_cb(current_obj);

            //clear the status for object, set it as SGL_EVENT_NORMAL
            sgl_obj_set_event_status(current_obj, SGL_EVENT_NORMAL);
            
            current_obj->dirty = 0;
        }
    }
}

