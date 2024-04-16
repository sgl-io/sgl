/* source/draw/sgl_draw_pie.c
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


#include "./sgl_draw_pie.h"
#include "./sgl_draw_circle.h"
#include "./sgl_draw_line.h"
#include "stdio.h"

static void sgl_draw_pie_blend_outedge( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r, 
                                        int16_t angle_start, int16_t angle_end, 
                                        sgl_color_t fg_color, sgl_color_t bg_color
                                      )
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    int16_t deg;
    sgl_color_t aa_color;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        aa_color = sgl_color_mixer(fg_color, bg_color, - f * 128 / r);
        deg = sgl_fast_atan2(-y, -x);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx-y, cy-x, aa_color);
        deg = sgl_fast_atan2(-x, -y);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx-x, cy-y, aa_color);
        deg = sgl_fast_atan2(y, -x);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx+y-1, cy-x, aa_color);
        deg = sgl_fast_atan2(x, -y);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx+x-1, cy-y, aa_color);

        deg = sgl_fast_atan2(-y, x);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx-y, cy+x-1, aa_color);
        deg = sgl_fast_atan2(-x, y);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx-x, cy+y-1, aa_color);

        deg = sgl_fast_atan2(y, x);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx+y-1, cy+x-1, aa_color);

        deg = sgl_fast_atan2(x, y);
        if ((deg >= angle_start) && (deg <= angle_end))
            sgl_draw_point(surf, cx+x-1, cy+y-1, aa_color);

        f += ddF_x + 1;
    }
}


void sgl_draw_pie( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t radius, 
                         int16_t angle_start, int16_t angle_end, 
                         sgl_color_t color, sgl_color_t bg_color)
{
    int16_t deg;
    uint32_t rr = radius * radius;
    for(int16_t y = -radius; y < 0; y++) {
        for(int16_t x = -radius; x < 0; x++) {
            uint32_t r2 = x * x + y * y;
            if (r2 < rr) {
                deg = sgl_fast_atan2(x, y);
                if ((deg >= angle_start) && (deg <= angle_end))
                    sgl_draw_point(surf, cx+x, cy+y, color);
                deg = sgl_fast_atan2(x, -y);
                if ((deg >= angle_start) && (deg <= angle_end))
                    sgl_draw_point(surf, cx+x, cy-y - 1, color);
                deg = sgl_fast_atan2(-x, y);
                if ((deg >= angle_start) && (deg <= angle_end))
                    sgl_draw_point(surf, cx-x-1, cy+y, color);
                deg = sgl_fast_atan2(-x, -y);
                if ((deg >= angle_start) && (deg <= angle_end))
                    sgl_draw_point(surf, cx-x - 1, cy-y - 1, color);
            }
        }
    }
    //to render edge
    sgl_draw_pie_blend_outedge( surf, cx, cy, radius, 
                                angle_start, angle_end, 
                                color, bg_color);
}
