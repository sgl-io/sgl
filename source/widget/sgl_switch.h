/* source/widget/sgl_switch.h
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

#ifndef __SGL_SWITCH_H__
#define __SGL_SWITCH_H__

#include "../core/sgl_core.h"


typedef struct sgl_switch {
    sgl_obj_t   obj;
    sgl_color_t toggle_color;
    sgl_img_t   *toggle_img;
    bool status;

}sgl_switch_t;


int sgl_switch_init(sgl_switch_t *sw_btn, sgl_obj_t* parent, bool status);
sgl_obj_t* sgl_switch_create(sgl_obj_t* parent, bool status);
void sgl_switch_set_toggle_color(sgl_obj_t *obj, sgl_color_t color);
void sgl_switch_set_toggle_img(sgl_obj_t *obj, sgl_img_t *img);
void sgl_switch_set_status(sgl_obj_t *obj, bool status);
bool sgl_switch_get_status(sgl_obj_t* obj);
void sgl_switch_set_anim_flag(sgl_obj_t *obj, bool flag);

#endif //__SGL_SWITCH_H__
