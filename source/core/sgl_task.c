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

#include "sgl_conf.h"
#include "./sgl_task.h"
#include "./sgl_event.h"
#include "../libs/sgl_string.h"

/**
 * Define task queue storage space to store created tasks, The purpose of using arrays is because data 
 * does not generate memory fragments, while using dynamic memory allocation will generate a lot of 
 * memory fragments, seriously affecting real-time performance
*/
static sgl_task_t sgl_task_queue[SGL_CONFIG_TASKQUEUE_DEPTH];

static int16_t __queue_head = 0;
static int16_t __queue_tail = 0;


/**
 * @brief check if the task queue is empty
 * 
 * @param none
 * 
 * @return bool: true is empty, false is not empty
*/
bool sgl_task_queue_is_empty(void)
{
    if(__queue_head == __queue_tail) {
        return true;
    }
    else {
        return false;
    }
}


/**
 * @brief check  if the task queue is full
 * 
 * @param none
 * 
 * @return bool: true is full, false is not full
*/
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


/**
 * @brief Push a new task into the task queue
 * 
 * @param task: The task to be pushed
 * 
 * @return none
*/
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


/**
 * @brief Pop up a task from the task queue
 * 
 * @param none
 * 
 * @return sgl_task_t: Pop up tasks
*/
sgl_task_t sgl_task_queue_pop(void)
{
    sgl_task_t task = sgl_task_queue[__queue_tail];
    if(sgl_task_queue_is_empty()) {
        task.task_fun = NULL;
        task.data = NULL;
        return task;
    }
    if((__queue_tail - 1) < 0) {
        __queue_tail = (SGL_CONFIG_TASKQUEUE_DEPTH - 1);
    }
    else {
        __queue_tail -- ;
    }
    return task;
}


/**
 * @brief Clear all tasks in the task queue
 * 
 * @param none
 * 
 * @return none
*/
void sgl_task_queue_clear(void)
{
    __queue_head = 0;
    __queue_tail = 0;
}

