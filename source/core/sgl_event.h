/* source/core/sgl_event.h
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

#ifndef __SGL_EVENT_H__
#define __SGL_EVENT_H__

#include "./sgl_core.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Determine if the event queue is empty
 * 
 * @param none
 * 
 * @return bool: true is empty, false is not empty
*/
bool sgl_event_queue_is_empty(void);


/**
 * @brief Determine if the event queue is full
 * 
 * @param none
 * 
 * @return bool: true is full, false is not full
*/
bool sgl_event_queue_is_full(void);


/**
 * @brief Push an element to the event queue
 * 
 * @param event: Events to be pushed in
 * 
 * @return none
*/
void sgl_event_queue_push(sgl_event_pos_t event);


/**
 * @brief Pop up an element from the event queue
 * 
 * @param none
 * 
 * @return sgl_event_pos_t: Pop up event, including the coordinates and type of the event
*/
sgl_event_pos_t sgl_event_queue_pop(void);


/**
 * @brief Clear all elements in the event queue
 * 
 * @param none
 * 
 * @return none
*/
void sgl_event_queue_clear(void);


/**
 * @brief Set the currently occurring event, which will be called every time it is pushed into the event queue
 * 
 * @param Ongoing events
 * 
 * @return none
*/
void sgl_event_set_device_pos(sgl_event_pos_t event);


/**
 * @brief Get ongoing events
 * 
 * @param none
 * 
 * @return Ongoing events
*/
sgl_event_pos_t sgl_event_get_device_pos(void);


/**
 * @brief All event handling in SGL, this function will traverse all elements in the event queue, 
 *        respond to each element with an event, so that all events will trigger and point to the 
 *        corresponding callback function
 * 
 * @param none
 * 
 * @return none
*/
void sgl_event_handler(void);


/**
 * @brief Redraw all objects on the current active page. If the object is in a dirty state, redraw it. 
 *        Otherwise, nothing will be done
 * 
 * @param none
 * 
 * @return none
*/
void sgl_active_page_dirty_handler(void);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_EVENT_H__
