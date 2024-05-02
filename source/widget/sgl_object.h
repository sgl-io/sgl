/* source/widget/sgl_object.h
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

#ifndef __SGL_OBJECT_H__
#define __SGL_OBJECT_H__

#include "../core/sgl_core.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Defined an SGL internal string that can be used to draw large fonts
 * 
 * @obj: the object
 * @text: pointer to string
 * @font: pointer to font 
*/
typedef struct sgl_string {
    sgl_obj_t obj;
    const char *text;
    sgl_font_t *font;
    sgl_align_type_e align;

}sgl_string_t;

sgl_obj_t* sgl_circle_create(sgl_obj_t* parent);

sgl_obj_t* sgl_rect_create(sgl_obj_t* parent);

sgl_obj_t* sgl_hline_create(sgl_obj_t* parent);

#define sgl_vline_create sgl_hline_create


sgl_obj_t* sgl_string_create(sgl_obj_t* parent);

void sgl_string_set_text(sgl_obj_t* obj, const char* text);
void sgl_string_set_font(sgl_obj_t* obj, sgl_font_t *font);

#ifdef __cplusplus
}
#endif

#endif //__SGL_OBJECT_H__
