/* source/sgl.h
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

#ifndef __SGL_H__
#define __SGL_H__

#include "./core/sgl_core.h"
#include "./core/sgl_device.h"
#include "./core/sgl_event.h"
#include "./core/sgl_log.h"
#include "./core/sgl_obj.h"
#include "./core/sgl_page.h"
#include "./core/sgl_task.h"
#include "./core/sgl_anim.h"
#include "./libs/sgl_mem.h"
#include "./libs/sgl_math.h"
#include "./libs/sgl_string.h"
#include "./fonts/sgl_font.h"
#include "./widget/sgl_button.h"
#include "./widget/sgl_label.h"
#include "./widget/sgl_switch.h"
#include "./widget/sgl_arcbar.h"
#include "./widget/sgl_pgsbar.h"
#include "./widget/sgl_checkbox.h"
#include "./widget/sgl_radiobtn.h"
#include "./widget/sgl_object.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief The initialization function of sgl, which users must call when writing 
*        their own projects, is used to initialize the data structure of sgl
*
* @param none
*
* @return int  0: OK,  Non 0: Error
*/
static inline int sgl_init(void)
{
    sgl_mem_init();
    //TODO: other initialize
    return 0;
}


/**
 * @brief The core task of SGL is to handle rectangles, which handle event response, 
 *        all dirty page redraws, and page switching
 * 
 * @param none
 * 
 * @return none
*/
static inline void sgl_task_handler(void)
{
    sgl_event_handler();
    sgl_active_page_dirty_handler();
    sgl_animation_handler();
    if(!sgl_task_queue_is_empty()) {
        sgl_task_t task = sgl_task_queue_pop();
        task.task_fun(task.data);
    }
}


#define  sgl_ev_stat(obj)  sgl_obj_get_event_status(obj)


#ifdef __cplusplus
}
#endif

#endif //__SGL_H__
