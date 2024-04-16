/* source/draw/sgl_draw_line.h
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

#ifndef __SGL_DRAW_LINE_H__
#define __SGL_DRAW_LINE_H__

#include "../core/sgl_core.h"
#include "./sgl_draw.h"

void sgl_draw_line( sgl_surf_t *surf, 
                    int16_t x1, int16_t y1, 
                    int16_t x2, int16_t y2, 
                    sgl_color_t fb_color, sgl_color_t bg_color);

void sgl_draw_line_on_bg( sgl_surf_t *surf, 
                          int16_t x1, int16_t y1, 
                          int16_t x2, int16_t y2, 
                          sgl_color_t color);

void sgl_draw_line_thick( sgl_surf_t *surf, 
                          int16_t x1, int16_t y1, 
                          int16_t x2, int16_t y2, 
                          int16_t thick,
                          sgl_color_t fg_color, sgl_color_t bg_color);

void sgl_draw_line_thick_on_bg( sgl_surf_t *surf, 
                                int16_t x1, int16_t y1, 
                                int16_t x2, int16_t y2, 
                                int16_t thick, 
                                sgl_color_t color);

void sgl_draw_line_transp_on_bg(sgl_surf_t *surf, 
                                int16_t x1, int16_t y1, 
                                int16_t x2, int16_t y2, 
                                sgl_color_t color, uint8_t alpha);

#endif //__SGL_DRAW_LINE_H__

