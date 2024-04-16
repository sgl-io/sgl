/* source/widget/sgl_img.h
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

#ifndef __SGL_PIXMAP_H__
#define __SGL_PIXMAP_H__

#include "../core/sgl_core.h"
#include "../sgl.h"


typedef struct sgl_pixmap {
    sgl_obj_t   obj;
    sgl_img_t   bitmap;

}sgl_pixmap_t;



int sgl_pixmap_init(sgl_pixmap_t *pixmap, sgl_obj_t *parent, sgl_img_t bitmap);
sgl_obj_t* sgl_pixmap_create(sgl_obj_t *parent, sgl_img_t bitmap);
void sgl_pixmap_draw(sgl_obj_t* obj);

#endif //__SGL_PIXMAP_H__
