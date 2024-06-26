/* source/widget/sgl_checkbox.h
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

#ifndef __SGL_CHECKBOX_H__
#define __SGL_CHECKBOX_H__

#include "../core/sgl_core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sgl_checkbox {
    sgl_obj_t   obj;
    sgl_font_t *font;
    const char *text;
    bool status;
    sgl_align_type_e align;
}sgl_checkbox_t;


int sgl_checkbox_init(sgl_checkbox_t *checkbox, sgl_obj_t* parent, bool status);
sgl_obj_t* sgl_checkbox_create(sgl_obj_t* parent, bool status);
void sgl_checkbox_set_status(sgl_obj_t *obj, bool status);
bool sgl_checkbox_get_status(sgl_obj_t *obj);
void sgl_checkbox_set_font(sgl_obj_t *obj, sgl_font_t *font);
void sgl_checkbox_set_text(sgl_obj_t *obj, const char* text);


#ifdef __cplusplus
}
#endif


#endif //__SGL_CHECKBOX_H__
