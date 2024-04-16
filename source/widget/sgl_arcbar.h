/* source/widget/sgl_arcbar.h
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

#ifndef  __SGL_ARCBAR_H__
#define  __SGL_ARCBAR_H__

#include "../core/sgl_core.h"
#include "../sgl.h"
#include "../draw/sgl_draw_rect.h"
#include "../draw/sgl_draw_arc.h"


typedef struct sgl_arcbar {
    sgl_obj_t   obj;
    uint8_t     value;
    uint8_t     thick;
    sgl_font_t *font;

}sgl_arcbar_t;


int sgl_arcbar_init(sgl_arcbar_t *arcbar, sgl_obj_t* parent, uint8_t value);
sgl_obj_t* sgl_arcbar_create(sgl_obj_t* parent, uint8_t value);
void sgl_arcbar_set_value(sgl_obj_t* obj, uint8_t value);
void sgl_arcbar_set_thick(sgl_obj_t* obj, uint8_t thick);
uint8_t sgl_arcbar_get_value(sgl_obj_t* obj);
void sgl_arcbar_set_font(sgl_obj_t* obj, sgl_font_t *font);
void sgl_arcbar_draw(sgl_obj_t* obj);


#endif
