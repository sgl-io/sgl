/* source/draw/sgl_draw_circle.h
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

#ifndef __SGL_DRAW_CIRCLE_H__
#define __SGL_DRAW_CIRCLE_H__

#include "../core/sgl_core.h"
#include "./sgl_draw.h"


void sgl_draw_circle_solid_noaa(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color);
void sgl_draw_circle_solid(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_circle_hollow(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_circle_hollow_noaa(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color);
void sgl_draw_circle_thick(sgl_surf_t *surf, uint16_t cx, uint16_t cy, uint16_t radius, uint16_t thick, sgl_color_t color, sgl_color_t bg_color);

void sgl_draw_circle_solid_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color);
void sgl_draw_circle_hollow_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color);
void sgl_draw_circle_thick_on_bg( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t radius, int16_t thick, sgl_color_t color);


void sgl_draw_circle_img(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t bg_color, sgl_img_t *img);
void sgl_draw_circle_img_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_img_t *img);
void sgl_draw_circle_img_transp_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_img_t *img, uint8_t alpha);

sgl_pos_t sgl_circle_pos_by_angle(int16_t r, int16_t angle);

#endif
