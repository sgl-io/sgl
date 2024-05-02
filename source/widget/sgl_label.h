/* source/widget/sgl_label.h
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

#ifndef __SGL_LABEL_H__
#define __SGL_LABEL_H__

#include "../core/sgl_core.h"


typedef struct sgl_label {
    sgl_obj_t obj;
    sgl_font_t *font;
    const char *text;
    sgl_icon_t *icon;
    sgl_align_type_e align;
    bool spin;
}sgl_label_t;


int sgl_label_init(sgl_label_t *label, sgl_obj_t* parent);
sgl_obj_t* sgl_label_create(sgl_obj_t* parent);
void sgl_label_set_bgcolor(sgl_obj_t *obj, sgl_color_t color);
void sgl_label_set_font(sgl_obj_t *obj, sgl_font_t *font);
void sgl_label_set_text(sgl_obj_t *obj, const char *text);
void sgl_label_set_text_align(sgl_obj_t *obj, sgl_align_type_e align);
void sgl_label_set_icon(sgl_obj_t *obj, sgl_icon_t *icon);


#endif
