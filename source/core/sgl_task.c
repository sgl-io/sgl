/* source/core/sgl_task.c
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

static sgl_task_t sgl_task_queue[SGL_CONFIG_TASKQUEUE_DEPTH];


static int16_t __queue_head = 0;
static int16_t __queue_tail = 0;

bool sgl_task_queue_is_empty(void)
{
    if(__queue_head == __queue_tail) {
        return true;
    }
    else {
        return false;
    }
}

bool sgl_task_queue_is_full(void)
{
    if(__queue_head == 0 && __queue_tail == (SGL_CONFIG_TASKQUEUE_DEPTH - 1)) {
        return true;
    }
    else if((__queue_tail + 1) == __queue_head) {
        return true;
    }
    else {
        return false;
    }
}

void sgl_task_queue_push(sgl_task_t task)
{
    if(task.task_fun == NULL)
        return;
    sgl_task_queue[__queue_head] = task;
    if((__queue_head - 1) < 0) {
        __queue_head = (SGL_CONFIG_TASKQUEUE_DEPTH - 1);
    }
    else {
        __queue_head -- ;
    }
}

sgl_task_t sgl_task_queue_pop(void)
{
    sgl_task_t task = sgl_task_queue[__queue_tail];
    if((__queue_tail - 1) < 0) {
        __queue_tail = (SGL_CONFIG_TASKQUEUE_DEPTH - 1);
    }
    else {
        __queue_tail -- ;
    }
    return task;
}

void sgl_task_queue_clear(void)
{
    __queue_head = 0;
    __queue_tail = 0;
}


extern void sgl_event_handler(void);
extern void sgl_active_page_dirty_handler(void);
extern void sgl_animation_handler(void);


void sgl_task_handler(void)
{
    sgl_event_handler();
    sgl_active_page_dirty_handler();
    sgl_animation_handler();
    if(!sgl_task_queue_is_empty()) {
        sgl_task_t task = sgl_task_queue_pop();
        task.task_fun(task.data);
    }
}
