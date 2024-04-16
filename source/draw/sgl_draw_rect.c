/* source/draw/sgl_draw_rect.c
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

#include "./sgl_draw_rect.h"
#include "stdio.h"


void sgl_draw_rect_solid(sgl_surf_t *surf, sgl_rect_t rect, sgl_color_t color)
{
    sgl_draw_area_color(surf, rect.x1, rect.y1, rect.x2, rect.y2, color);
}

void sgl_draw_rect_hollow(sgl_surf_t *surf, sgl_rect_t rect, sgl_color_t color)
{
    sgl_draw_hline(surf, rect.x1, rect.y1, rect.x2 - rect.x1, color);
    sgl_draw_hline(surf, rect.x1, rect.y2, rect.x2 - rect.x1, color);
    sgl_draw_vline(surf, rect.x1, rect.y1, rect.y2 - rect.y1, color);
    sgl_draw_vline(surf, rect.x2, rect.y1, rect.y2 - rect.y1 + 1, color);
}


void sgl_draw_round_rect_solid(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(bg_color, fg_color, mix)); 
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, 2*x + cx2 - cx1 + 1, fg_color);
        sgl_draw_hline(surf, cx1-x, cy2+y, 2*x + cx2 - cx1 + 1, fg_color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, fg_color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_hollow(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx2+x, cy2-y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx1+y, cy2+x, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx1-x, cy1+y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx2-y, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x, cy2-y+1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1+y-1, cy2+x, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1-x, cy1+y-1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx2-y+1, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x2, cy2-y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1+y, cy2+x2, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1-x2, cy1+y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx2-y, cy1-x2, sgl_color_mixer(bg_color, fg_color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y1, cx2 - cx1, fg_color);
        sgl_draw_hline(surf, cx1, rect.y2, cx2 - cx1, fg_color);
    }
    if(cy2 - cy1) {
        sgl_draw_vline(surf, rect.x1, cy1, cy2 - cy1, fg_color);
        sgl_draw_vline(surf, rect.x2, cy1, cy2 - cy1, fg_color);
    }
}


void sgl_draw_round_rect_solid_thalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, 2*x + cx2 - cx1 + 1, fg_color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, rect.y2 - m_heigit, m_width, fg_color); 
        m_heigit --;
    }
}


void sgl_draw_round_rect_solid_bhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - rect.y1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(bg_color, fg_color, mix)); 
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, 2*x + cx2 - cx1 + 1, fg_color);
        sgl_draw_hline(surf, cx1-x, cy2+y, 2*x + cx2 - cx1 + 1, fg_color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, fg_color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_solid_lhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(bg_color, fg_color, mix)); 
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, x + cx2 + 1, fg_color);
        sgl_draw_hline(surf, cx1-x, cy2+y, x + cx2 + 1, fg_color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, fg_color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_solid_rhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(bg_color, fg_color, mix)); 
        }
        sgl_draw_hline(surf, rect.x1, cy1-y, x + cx2 + 1, fg_color);
        sgl_draw_hline(surf, rect.x1, cy2+y, x + cx2 + 1, fg_color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, fg_color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_hollow_thalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx1-x, cy1+y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx2-y, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1-x, cy1+y-1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx2-y+1, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1-x2, cy1+y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx2-y, cy1-x2, sgl_color_mixer(bg_color, fg_color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y1, cx2 - cx1, fg_color);
        sgl_draw_hline(surf, rect.x1, rect.y2, rect.x2 - rect.x1 + 1, fg_color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, cy1, cy2 - rect.y1, fg_color);
        sgl_draw_vline(surf, rect.x2, cy1, cy2 - rect.y1, fg_color);
    }
}


void sgl_draw_round_rect_hollow_bhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx2+x, cy2-y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx1+y, cy2+x, sgl_color_mixer(bg_color, fg_color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x, cy2-y+1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1+y-1, cy2+x, sgl_color_mixer(bg_color, fg_color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x2, cy2-y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1+y, cy2+x2, sgl_color_mixer(bg_color, fg_color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y2, cx2 - cx1, fg_color);
        sgl_draw_hline(surf, rect.x1, rect.y1, rect.x2 - rect.x1 + 1, fg_color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, rect.y1, cy2 - rect.y1, fg_color);
        sgl_draw_vline(surf, rect.x2, rect.y1, cy2 - rect.y1, fg_color);
    }
}


void sgl_draw_round_rect_hollow_lhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx1+y, cy2+x, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx1-x, cy1+y, sgl_color_mixer(bg_color, fg_color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1+y-1, cy2+x, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1-x, cy1+y-1, sgl_color_mixer(bg_color, fg_color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1+y, cy2+x2, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx1-x2, cy1+y, sgl_color_mixer(bg_color, fg_color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y2, rect.x2 - cx1 + 1, fg_color);
        sgl_draw_hline(surf, cx1, rect.y1, rect.x2 - cx1 + 1, fg_color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, cy1, cy2 - cy1, fg_color);
        sgl_draw_vline(surf, rect.x2, rect.y1, rect.y2 - rect.y1, fg_color);
    }
}


void sgl_draw_round_rect_hollow_rhalf(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx2+x, cy2-y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx2-y, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x, cy2-y+1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx2-y+1, cy1-x, sgl_color_mixer(bg_color, fg_color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x2, cy2-y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx2-y, cy1-x2, sgl_color_mixer(bg_color, fg_color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, rect.x1, rect.y1, rect.x2 - cx1 + 1, fg_color);
        sgl_draw_hline(surf, rect.x1, rect.y2, rect.x2 - cx1 + 1, fg_color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, rect.y1, rect.y2 - rect.y1, fg_color);
        sgl_draw_vline(surf, rect.x2, cy1, cy2 - cy1, fg_color);
    }
}


/**** on background ***/
void sgl_draw_round_rect_solid_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2+y), color, mix)); 
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-y, cy2+x), color, mix)); 
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1-y), color, mix)); 
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+y, cy1-x), color, mix)); 
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, 2*x + cx2 - cx1 + 1, color);
        sgl_draw_hline(surf, cx1-x, cy2+y, 2*x + cx2 - cx1 + 1, color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_hollow_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx2+x, cy2-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2-y), color, mix));
        sgl_draw_point(surf, cx1+y, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y, cy2+x), color, mix));
        sgl_draw_point(surf, cx1-x, cy1+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1+y), color, mix));
        sgl_draw_point(surf, cx2-y, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y, cy1-x), color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x, cy2-y+1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2-y+1), color, mix));
                sgl_draw_point(surf, cx1+y-1, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y-1, cy2+x), color, mix));
                sgl_draw_point(surf, cx1-x, cy1+y-1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1+y-1), color, mix));
                sgl_draw_point(surf, cx2-y+1, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y+1, cy1-x), color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x2, cy2-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x2, cy2-y), color, mix));
                sgl_draw_point(surf, cx1+y, cy2+x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y, cy2+x2), color, mix));
                sgl_draw_point(surf, cx1-x2, cy1+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x2, cy1+y), color, mix));
                sgl_draw_point(surf, cx2-y, cy1-x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y, cy1-x2), color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y1, cx2 - cx1, color);
        sgl_draw_hline(surf, cx1, rect.y2, cx2 - cx1, color);
    }
    if(cy2 - cy1) {
        sgl_draw_vline(surf, rect.x1, cy1, cy2 - cy1, color);
        sgl_draw_vline(surf, rect.x2, cy1, cy2 - cy1, color);
    }
}


void sgl_draw_round_rect_solid_thalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1-y), color, mix)); 
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+y, cy1-x), color, mix));
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, 2*x + cx2 - cx1 + 1, color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, rect.y2 - m_heigit, m_width, color); 
        m_heigit --;
    }
}


void sgl_draw_round_rect_solid_bhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - rect.y1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2+y), color, mix)); 
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-y, cy2+x), color, mix)); 
        }
        sgl_draw_hline(surf, cx1-x, cy2+y, 2*x + cx2 - cx1 + 1, color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_solid_lhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-y, cy2+x), color, mix)); 
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1-y), color, mix)); 
        }
        sgl_draw_hline(surf, cx1-x, cy1-y, x + cx2 - rect.x1 + 1, color);
        sgl_draw_hline(surf, cx1-x, cy2+y, x + cx2 - rect.x1 + 1, color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_solid_rhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2+y), color, mix)); 
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+y, cy1-x), color, mix)); 
        }
        sgl_draw_hline(surf, rect.x1, cy1-y, x + rect.x2 - cx1 + 1, color);
        sgl_draw_hline(surf, rect.x1, cy2+y, x + rect.x2 - cx1 + 1, color);
    }
    while(m_heigit > 0) {
        sgl_draw_hline(surf, rect.x1, cy2 - m_heigit, m_width, color);
        m_heigit --;
    }
}


void sgl_draw_round_rect_hollow_thalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx1-x, cy1+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1+y), color, mix));
        sgl_draw_point(surf, cx2-y, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y, cy1-x), color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1-x, cy1+y-1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1+y-1), color, mix));
                sgl_draw_point(surf, cx2-y+1, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y+1, cy1-x), color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1-x2, cy1+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x2, cy1+y), color, mix));
                sgl_draw_point(surf, cx2-y, cy1-x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y, cy1-x2), color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y1, cx2 - cx1, color);
        sgl_draw_hline(surf, rect.x1, rect.y2, rect.x2 - rect.x1 + 1, color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, cy1, cy2 - rect.y1, color);
        sgl_draw_vline(surf, rect.x2, cy1, cy2 - rect.y1, color);
    }
}


void sgl_draw_round_rect_hollow_bhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx2+x, cy2-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2-y), color, mix));
        sgl_draw_point(surf, cx1+y, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y, cy2+x), color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x, cy2-y+1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2-y+1), color, mix));
                sgl_draw_point(surf, cx1+y-1, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y-1, cy2+x), color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x2, cy2-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x2, cy2-y), color, mix));
                sgl_draw_point(surf, cx1+y, cy2+x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y, cy2+x2), color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y2, cx2 - cx1, color);
        sgl_draw_hline(surf, rect.x1, rect.y1, rect.x2 - rect.x1 + 1, color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, rect.y1, cy2 - rect.y1, color);
        sgl_draw_vline(surf, rect.x2, rect.y1, cy2 - rect.y1, color);
    }
}


void sgl_draw_round_rect_hollow_lhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx1+y, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y, cy2+x), color, mix));
        sgl_draw_point(surf, cx1-x, cy1+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1+y), color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1+y-1, cy2+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y-1, cy2+x), color, mix));
                sgl_draw_point(surf, cx1-x, cy1+y-1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x, cy1+y-1), color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx1+y, cy2+x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1+y, cy2+x2), color, mix));
                sgl_draw_point(surf, cx1-x2, cy1+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx1-x2, cy1+y), color, mix));
            } 
            err -= --y*2-1; 
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, cx1, rect.y2, rect.x2 - cx1 + 1, color);
        sgl_draw_hline(surf, cx1, rect.y1, rect.x2 - cx1 + 1, color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, cy1, cy2 - cy1, color);
        sgl_draw_vline(surf, rect.x2, rect.y1, rect.y2 - rect.y1, color);
    }
}


void sgl_draw_round_rect_hollow_rhalf_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t color)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx2+x, cy2-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2-y), color, mix));
        sgl_draw_point(surf, cx2-y, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y, cy1-x), color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x, cy2-y+1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x, cy2-y+1), color, mix));
                sgl_draw_point(surf, cx2-y+1, cy1-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y+1, cy1-x), color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx2+x2, cy2-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2+x2, cy2-y), color, mix));
                sgl_draw_point(surf, cx2-y, cy1-x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx2-y, cy1-x2), color, mix));
            } 
            err -= --y*2-1;
        }
    }
    if(cx2 - cx1) {
        sgl_draw_hline(surf, rect.x1, rect.y1, rect.x2 - cx1 + 1, color);
        sgl_draw_hline(surf, rect.x1, rect.y2, rect.x2 - cx1 + 1, color);
    }
    if(cy2 - rect.x1) {
        sgl_draw_vline(surf, rect.x1, rect.y1, rect.y2 - rect.y1, color);
        sgl_draw_vline(surf, rect.x2, cy1, cy2 - cy1, color);
    }
}


void sgl_draw_round_rect_img(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_color_t bg_color, sgl_img_t *img)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    sgl_color_t *pick = (sgl_color_t*)img->bitmap;
    int pick_x = (img->width - (rect.x2 - rect.x1 + 1)) / 2;
    int pick_y = (img->height - (rect.y2 - rect.y1 + 1)) / 2;
    int pick_cx1 = pick_x + radius;
    int pick_cy1 = pick_y + radius;
    int pick_cx2 = img->width - pick_x - radius;
    int pick_cy2 = img->height - pick_y - radius;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, sgl_color_mixer(bg_color, pick[(pick_cy2+y)*img->width + pick_cx2+x], mix));
            sgl_draw_point(surf, cx1-y, cy2+x, sgl_color_mixer(bg_color, pick[(pick_cy2+x)*img->width + pick_cx1-y], mix));
            sgl_draw_point(surf, cx1-x, cy1-y, sgl_color_mixer(bg_color, pick[(pick_cy1-y)*img->width + pick_cx1-x], mix));
            sgl_draw_point(surf, cx2+y, cy1-x, sgl_color_mixer(bg_color, pick[(pick_cy1-x)*img->width + pick_cx2+y], mix));
        }
        for (int i = 0; i < 2*x + cx2 - cx1 + 1; i++) {
            sgl_draw_point(surf, cx1-x+i, cy1-y, pick[(pick_cy1-y)*img->width + pick_cx1-x+i]); 
            sgl_draw_point(surf, cx1-x+i, cy2+y, pick[(pick_cy2+y)*img->width + pick_cx1-x+i]);
        }
    }
    while(m_heigit > 0) {
        for(int i = 0; i < m_width; i++)
        sgl_draw_point(surf, rect.x1 + i, cy2 - m_heigit, pick[(pick_cy2 - m_heigit)*img->width + pick_x + i]);
        m_heigit --;
    }
}


void sgl_draw_round_rect_img_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_img_t *img)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    sgl_color_t *pick = (sgl_color_t*)img->bitmap;
    int pick_x = (img->width - (rect.x2 - rect.x1 + 1)) / 2;
    int pick_y = (img->height - (rect.y2 - rect.y1 + 1)) / 2;
    int pick_cx1 = pick_x + radius;
    int pick_cy1 = pick_y + radius;
    int pick_cx2 = img->width - pick_x - radius;
    int pick_cy2 = img->height - pick_y - radius;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx2+x, cy2+y), pick[(pick_cy2+y)*img->width + pick_cx2+x], mix));
            sgl_draw_point(surf, cx1-y, cy2+x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-y, cy2+x), pick[(pick_cy2+x)*img->width + pick_cx1-y], mix));
            sgl_draw_point(surf, cx1-x, cy1-y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-x, cy1-y), pick[(pick_cy1-y)*img->width + pick_cx1-x], mix));
            sgl_draw_point(surf, cx2+y, cy1-x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx2+y, cy1-x), pick[(pick_cy1-x)*img->width + pick_cx2+y], mix));
        }
        for (int i = 0; i < 2*x + cx2 - cx1 + 1; i++) {
            sgl_draw_point(surf, cx1-x+i, cy1-y, pick[(pick_cy1-y)*img->width + pick_cx1-x+i]); 
            sgl_draw_point(surf, cx1-x+i, cy2+y, pick[(pick_cy2+y)*img->width + pick_cx1-x+i]);
        }
    }
    while(m_heigit > 0) {
        for(int i = 0; i < m_width; i++)
        sgl_draw_point(surf, rect.x1 + i, cy2 - m_heigit, pick[(pick_cy2 - m_heigit)*img->width + pick_x + i]);
        m_heigit --;
    }
}


void sgl_draw_round_rect_img_transp_on_bg(sgl_surf_t *surf, sgl_rect_t rect, int radius, sgl_img_t *img, uint8_t alpha)
{
    int cx1 = rect.x1+radius;
    int cx2 = rect.x2-radius;
    int cy1 = rect.y1+radius;
    int cy2 = rect.y2-radius;
    int m_heigit = cy2 - cy1 - 1;
    int m_width = rect.x2 - rect.x1 + 1;
    sgl_color_t *pick = (sgl_color_t*)img->bitmap;
    int pick_x = (img->width - (rect.x2 - rect.x1 + 1)) / 2;
    int pick_y = (img->height - (rect.y2 - rect.y1 + 1)) / 2;
    int pick_cx1 = pick_x + radius;
    int pick_cy1 = pick_y + radius;
    int pick_cx2 = img->width - pick_x - radius;
    int pick_cy2 = img->height - pick_y - radius;
    int x = radius, y = 0, err = 0, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx2+x, cy2+y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx2+x, cy2+y),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx2+x, cy2+y), pick[(pick_cy2+y)*img->width + pick_cx2+x], mix), alpha));
            sgl_draw_point(surf, cx1-y, cy2+x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-y, cy2+x), 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-y, cy2+x), pick[(pick_cy2+x)*img->width + pick_cx1-y], mix), alpha));
            sgl_draw_point(surf, cx1-x, cy1-y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-x, cy1-y), 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-x, cy1-y), pick[(pick_cy1-y)*img->width + pick_cx1-x], mix), alpha));
            sgl_draw_point(surf, cx2+y, cy1-x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx2+y, cy1-x), 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx2+y, cy1-x), pick[(pick_cy1-x)*img->width + pick_cx2+y], mix), alpha));
        }
        for (int i = 0; i < 2*x + cx2 - cx1 + 1; i++) {
            sgl_draw_point(surf, cx1-x+i, cy1-y,
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-x+i, cy1-y), pick[(pick_cy1-y)*img->width + pick_cx1-x+i], alpha)); 
            sgl_draw_point(surf, cx1-x+i, cy2+y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx1-x+i, cy2+y), pick[(pick_cy2+y)*img->width + pick_cx1-x+i], alpha));
        }
    }
    while(m_heigit > 0) {
        for(int i = 0; i < m_width; i++)
        sgl_draw_point(surf, rect.x1 + i, cy2 - m_heigit, 
                        sgl_color_mixer(sgl_get_draw_buffer_color(surf,rect.x1 + i, cy2 - m_heigit), pick[(pick_cy2 - m_heigit)*img->width + pick_x + i], alpha));
        m_heigit --;
    }
}
