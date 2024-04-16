/* source/draw/sgl_draw_line.c
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

#include "./sgl_draw_line.h"
#include "stdio.h"


void sgl_draw_line(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int dx = sgl_abs(x2-x1), sx = x1 < x2 ? 1 : -1;
    int dy = sgl_abs(y2-y1), sy = y1 < y2 ? 1 : -1; 
    int err = dx-dy, e2, x3;                                   /* error value e_xy */
    int ed = dx+dy == 0 ? 1 : sgl_sqrt((float)dx*dx+(float)dy*dy);

    while(1){                                                 /* pixel loop */
        sgl_draw_point(surf,x1,y1, sgl_color_mixer(bg_color, fg_color, 255*sgl_abs(err-dx+dy)/ed));
        e2 = err; x3 = x1;
        if (2*e2 >= -dx) {                                    /* x step */
            if (x1 == x2) break;
            if (e2+dy < ed) sgl_draw_point(surf, x1, y1 + sy, sgl_color_mixer(bg_color, fg_color, 255*(e2+dy)/ed));
            err -= dy; x1 += sx; 
        } 
        if (2*e2 <= dy) {                                     /* y step */
            if (y1 == y2) break;
            if (dx-e2 < ed) sgl_draw_point(surf, x3 + sx, y1, sgl_color_mixer(bg_color, fg_color, 255*(dx-e2)/ed));
            err += dx; y1 += sy; 
        }
    }
}


void sgl_draw_line_on_bg(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, sgl_color_t color)
{
    int dx = sgl_abs(x2-x1), sx = x1 < x2 ? 1 : -1;
    int dy = sgl_abs(y2-y1), sy = y1 < y2 ? 1 : -1; 
    int err = dx-dy, e2, x3;                                   /* error value e_xy */
    int ed = dx+dy == 0 ? 1 : sgl_sqrt((float)dx*dx+(float)dy*dy);

    while(1){                                                 /* pixel loop */
        sgl_draw_point(surf, x1, y1, 
                        sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1), color, 255*sgl_abs(err-dx+dy)/ed));
        e2 = err; x3 = x1;
        if (2*e2 >= -dx) {                                    /* x step */
            if (x1 == x2) break;
            if (e2+dy < ed) sgl_draw_point(surf, x1, y1 + sy, 
                                            sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1 + sy), color, 255*(e2+dy)/ed));
            err -= dy; x1 += sx; 
        }
        if (2*e2 <= dy) {                                     /* y step */
            if (y1 == y2) break;
            if (dx-e2 < ed) sgl_draw_point(surf, x3 + sx, y1, 
                                            sgl_color_mixer(sgl_get_draw_buffer_color(surf, x3 + sx, y1), color, 255*(dx-e2)/ed));
            err += dx; y1 += sy; 
        }
    }
}


void sgl_draw_line_thick(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t thick, sgl_color_t fg_color, sgl_color_t bg_color)
{ /* plot an anti-aliased line of thickness thick */
    int dx = sgl_abs(x2-x1), sx = x1 < x2 ? 1 : -1; 
    int dy = sgl_abs(y2-y1), sy = y1 < y2 ? 1 : -1; 
    int err = dx-dy, e2, x3, y3; /* error value e_xy */
    float ed = dx+dy == 0 ? 1 : sgl_sqrt((float)dx*dx+(float)dy*dy);

    for (thick = (thick+1)/2; ; ) { /* pixel loop */
        sgl_draw_point(surf, x1, y1, sgl_color_mixer(bg_color, fg_color, sgl_max(0, 255*(sgl_abs(err-dx+dy)/ed-thick+1))));
        e2 = err; x3 = x1;
        if (2*e2 >= -dx) { /* x step */
            for (e2 += dy, y3 = y1; e2 < ed*thick && (y2 != y3 || dx > dy); e2 += dx)
                sgl_draw_point(surf, x1, y3 += sy, sgl_color_mixer(bg_color, fg_color, sgl_max(0, 255*(sgl_abs(e2)/ed-thick+1))));
            if (x1 == x2) 
                break;
            e2 = err; 
            err -= dy; 
            x1 += sx; 
        } 
        if (2*e2 <= dy) { /* y step */
            for (e2 = dx-e2; e2 < ed*thick && (x2 != x3 || dx < dy); e2 += dy)
                sgl_draw_point(surf, x3 += sx, y1, sgl_color_mixer(bg_color, fg_color, sgl_max(0, 255*(sgl_abs(e2)/ed-thick+1))));
            if (y1 == y2) 
                break;
            err += dx; 
            y1 += sy; 
        }
    }
}


void sgl_draw_line_thick_on_bg(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t thick, sgl_color_t color)
{
    /* plot an anti-aliased line of thickness thick */
    int dx = sgl_abs(x2-x1), sx = x1 < x2 ? 1 : -1; 
    int dy = sgl_abs(y2-y1), sy = y1 < y2 ? 1 : -1; 
    int err = dx-dy, e2, x3, y3; /* error value e_xy */
    float ed = dx+dy == 0 ? 1 : sgl_sqrt((float)dx*dx+(float)dy*dy);

    for (thick = (thick+1)/2; ; ) { /* pixel loop */
        sgl_draw_point(surf, x1, y1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1), 
                                                     color, sgl_max(0, 255*(sgl_abs(err-dx+dy)/ed-thick+1))));
        e2 = err; x3 = x1;
        if (2*e2 >= -dx) { /* x step */
            for (e2 += dy, y3 = y1; e2 < ed*thick && (y2 != y3 || dx > dy); e2 += dx) {
                sgl_draw_point(surf, x1, y3, sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y3), 
                                                                   color, sgl_max(0, 255*(sgl_abs(e2)/ed-thick+1))));
                y3+= sy;
            }
            if (x1 == x2) 
                break;
            e2 = err; 
            err -= dy; 
            x1 += sx; 
        } 
        if (2*e2 <= dy) { /* y step */
            for (e2 = dx-e2; e2 < ed*thick && (x2 != x3 || dx < dy); e2 += dy) {
                sgl_draw_point(surf, x3, y1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, x3, y1), 
                                                                   color, sgl_max(0, 255*(sgl_abs(e2)/ed-thick+1))));
                x3 += sx;
            }
            if (y1 == y2) 
                break;
            err += dx; 
            y1 += sy; 
        }
    }
}


void sgl_draw_line_transp_on_bg(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, sgl_color_t color, uint8_t alpha)
{
    int dx = sgl_abs(x2-x1), sx = x1 < x2 ? 1 : -1;
    int dy = sgl_abs(y2-y1), sy = y1 < y2 ? 1 : -1; 
    int err = dx-dy, e2, x3;                                   /* error value e_xy */
    int ed = dx+dy == 0 ? 1 : sgl_sqrt((float)dx*dx+(float)dy*dy);

    while(1){                                                 /* pixel loop */
        sgl_draw_point(surf, x1, y1, 
                        sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1), color, 255*sgl_abs(err-dx+dy)/ed), alpha));
        e2 = err; x3 = x1;
        if (2*e2 >= -dx) {                                    /* x step */
            if (x1 == x2) break;
            if (e2+dy < ed) 
                sgl_draw_point(surf, x1, y1 + sy, 
                        sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1 + sy),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf, x1, y1 + sy), color, 255*(e2+dy)/ed), alpha));
            err -= dy; x1 += sx; 
        }
        if (2*e2 <= dy) {                                     /* y step */
            if (y1 == y2) break;
            if (dx-e2 < ed) 
                sgl_draw_point(surf, x3 + sx, y1, 
                        sgl_color_mixer(sgl_get_draw_buffer_color(surf, x3 + sx, y1),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf, x3 + sx, y1), color, 255*(dx-e2)/ed), alpha));
            err += dx; y1 += sy; 
        }
    }
}
