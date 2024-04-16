/* source/draw/sgl_draw_rect.h
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

#ifndef __SGL_DRAW_RECT_H__
#define __SGL_DRAW_RECT_H__

#include "../core/sgl_core.h"
#include "./sgl_draw.h"


void sgl_draw_rect_solid(sgl_surf_t *surf, sgl_rect_t rect, sgl_color_t color);
void sgl_draw_rect_hollow(sgl_surf_t *surf, sgl_rect_t rect, sgl_color_t color);

void sgl_draw_round_rect_solid(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_hollow(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_solid_thalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_solid_bhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_solid_lhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_solid_rhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_hollow_thalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_hollow_bhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_hollow_lhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);
void sgl_draw_round_rect_hollow_rhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color);

void sgl_draw_round_rect_solid_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_hollow_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_solid_thalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_solid_bhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_solid_lhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_solid_rhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_hollow_thalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_hollow_bhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_hollow_lhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);
void sgl_draw_round_rect_hollow_rhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color);

void sgl_draw_round_rect_img(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t bg_color, sgl_img_t *img);
void sgl_draw_round_rect_img_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_img_t *img);
void sgl_draw_round_rect_img_transp_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_img_t *img, uint8_t alpha);

#endif //__SGL_DRAW_RECT_H__
