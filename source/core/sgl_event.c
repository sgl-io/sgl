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

#include "./sgl_core.h"
#include <string.h>
#include "stdio.h"
#include "../draw/sgl_draw.h"


sgl_event_pos_t sgl_event_queue[SGL_CONFIG_EVQUEUE_DEPTH];
sgl_event_pos_t sgl_event_device;

static int16_t __queue_head = 0;
static int16_t __queue_tail = 0;

bool sgl_event_queue_is_empty(void)
{
    if(__queue_head == __queue_tail) {
        return true;
    }
    else {
        return false;
    }
}

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

void sgl_event_queue_clear(void)
{
    for(int i = 0; i < SGL_CONFIG_EVQUEUE_DEPTH; i++) {
        sgl_event_queue[i].type = SGL_EVENT_NULL;
    }
    __queue_head = 0;
    __queue_tail = 0;
}

void sgl_event_set_device_pos(sgl_event_pos_t event)
{
    sgl_event_device = event;
}

sgl_event_pos_t sgl_event_get_device_pos(void)
{
    return sgl_event_device;
}

extern sgl_obj_t *active_page;

void sgl_event_handler(void)
{
    sgl_obj_t *current_obj;
    sgl_list_node_t *current_node;
    sgl_list_node_t *root_node = sgl_page_get_obj_head(active_page);
    sgl_event_pos_t evt_pos;
    if(!sgl_event_queue_is_empty()) {
        evt_pos = sgl_event_queue_pop();
        sgl_list_for_each(current_node, root_node) {
            current_obj = container_of(current_node, struct sgl_obj, node);
            if( current_obj->event_fn && sgl_obj_event_active(current_obj, evt_pos.x, evt_pos.y) && current_obj->hide == 0) {
                sgl_obj_set_event_status(current_obj, evt_pos.type);
                sgl_page_add_dirty_obj(active_page, current_obj);
            }
        }
    }
}


void sgl_active_page_dirty_handler(void)
{
    sgl_obj_t *current_obj;
    sgl_list_node_t *current_node;
    sgl_list_node_t *node_head = sgl_page_get_dirty_obj_head(active_page);
    sgl_list_for_each(current_node, node_head) {
        current_obj = container_of(current_node, struct sgl_obj, dirty);
        sgl_draw_handler(current_obj);
        sgl_obj_set_event_status(current_obj, SGL_EVENT_NORMAL);
        sgl_page_del_dirty_obj(current_obj);
    }
}

