/* source/draw/sgl_draw_icon.c
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

#include "./sgl_draw_icon.h"


void sgl_draw_icon(sgl_surf_t *surf, int x, int y, sgl_color_t color, sgl_color_t bg_color, sgl_icon_t *icon)
{
    const uint8_t *dot = icon->bitmap;
    for(int i = 0; i < icon->height; i++) {
        for(int j = 0; j < icon->width; j +=2) {
            sgl_draw_point(surf, x + j, y + i, sgl_color_mixer(color, bg_color, (((*dot)>>4)&0xF)*16));
            sgl_draw_point(surf, x + j + 1, y + i, sgl_color_mixer(color, bg_color, (((*dot))&0xF)*16));
            dot ++;
        }
    }
}

void sgl_draw_icon_transp(sgl_surf_t *surf, int x, int y, sgl_color_t color, sgl_color_t bg_color, sgl_icon_t *icon, uint8_t alpha)
{
    const uint8_t *dot = icon->bitmap;
    for(int i = 0; i < icon->height; i++) {
        for(int j = 0; j < icon->width; j +=2) {
            sgl_draw_point(surf, x + j, y + i, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,x + j, y + i), 
                                            sgl_color_mixer(color, bg_color, (((*dot)>>4)&0xF)*16), alpha));
            sgl_draw_point(surf, x + j + 1, y + i, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,x + j + 1, y + i), 
                                            sgl_color_mixer(color, bg_color, (((*dot))&0xF)*16), alpha));
            dot ++;
        }
    }
}

void sgl_draw_icon_on_bg(sgl_surf_t *surf, int x, int y, sgl_color_t color, sgl_icon_t *icon)
{
    int pos_x, pos_y;
    const uint8_t *dot = icon->bitmap;
    for(int i = 0; i < icon->height; i++) {
        for(int j = 0; j < icon->width; j +=2) {
            if(*dot) {
                pos_x = x + j;
                pos_y = y + i;
                sgl_draw_point(surf, x + j, y + i, 
                                sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16));
                sgl_draw_point(surf, x + j + 1, y + i, 
                                sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16));
            }
            dot ++;
        }
    }
}

void sgl_draw_icon_transp_on_bg(sgl_surf_t *surf, int x, int y, sgl_color_t color, sgl_icon_t *icon, uint8_t alpha)
{
    int pos_x, pos_y;
    const uint8_t *dot = icon->bitmap;
    for(int i = 0; i < icon->height; i++) {
        for(int j = 0; j < icon->width; j +=2) {
            if(*dot) {
                pos_x = x + j;
                pos_y = y + i;
                sgl_draw_point(surf, x + j, y + i, 
                                sgl_color_mixer(sgl_get_draw_buffer_color(surf,x + j, y + i), 
                                                sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16), alpha));
                sgl_draw_point(surf, x + j + 1, y + i, 
                                sgl_color_mixer(sgl_get_draw_buffer_color(surf,x + j, y + i), 
                                                sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16), alpha));
            }
            dot ++;
        }
    }
}


void sgl_draw_icon_lines_on_bg(sgl_surf_t *surf, int x, int y, int lines_start, int lines, sgl_color_t color, sgl_icon_t *icon)
{
    int pos_x, pos_y;
    const uint8_t *dot = icon->bitmap + lines_start*icon->width / 2;
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < icon->width; j +=2) {
            if(*dot) {
                pos_x = x + j;
                pos_y = y + i;
                sgl_draw_point(surf, x + j, y + i, 
                                sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16));
                sgl_draw_point(surf, x + j + 1, y + i, 
                                sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16));
            }
            dot ++;
        }
    }
}
