/* source/widget/sgl_number.h
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

#ifndef __SGL_NUMBER_H__
#define __SGL_NUMBER_H__

#include "../core/sgl_core.h"



typedef struct sgl_number {
    sgl_obj_t   obj;
    sgl_font_t *font;
    double      value;
    sgl_align_type_e align;

}sgl_number_t;


int sgl_number_init(sgl_number_t *number, sgl_obj_t* parent, double value);
sgl_obj_t* sgl_number_create(sgl_obj_t* parent, double value);
void sgl_number_set_font(sgl_obj_t* obj, sgl_font_t *font);
void sgl_number_set_value(sgl_obj_t* obj, double value);
void sgl_number_set_text_align(sgl_obj_t *obj, sgl_align_type_e align);

#endif //__SGL_NUMBER_H__

