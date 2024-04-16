/* source/draw/sgl_draw_circle.c
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

#include "./sgl_draw_circle.h"
#include "stdio.h"


void sgl_draw_circle_solid_noaa(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color)
{
    int x = -radius, y = 0, err = 2-2*radius;
    do {
        sgl_draw_point(surf, cx-x, cy+y, color);
        sgl_draw_point(surf, cx-y, cy-x, color);
        sgl_draw_point(surf, cx+x, cy-y, color);
        sgl_draw_point(surf, cx+y, cy+x, color);
        radius = err;
        if (radius <= y) 
            err += ++y*2+1;
        if (radius > x || err > y)
            err += ++x*2+1;
    } while (x < 0);
}

void sgl_draw_circle_solid(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int x = radius, y = 0, err = 0, i, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx+x, cy+y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx-y, cy+x, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx-x, cy-y, sgl_color_mixer(bg_color, fg_color, mix)); 
            sgl_draw_point(surf, cx+y, cy-x, sgl_color_mixer(bg_color, fg_color, mix)); 
        }
        for (i = x; i > 0; i--) {
            sgl_draw_point(surf, cx+i, cy+y, fg_color);
            sgl_draw_point(surf, cx-y, cy+i, fg_color);
            sgl_draw_point(surf, cx-i, cy-y, fg_color); 
            sgl_draw_point(surf, cx+y, cy-i, fg_color);
        }
    }
    sgl_draw_point(surf, cx, cy, fg_color);
}


void sgl_draw_circle_hollow(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx+x, cy-y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx+y, cy+x, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx-x, cy+y, sgl_color_mixer(bg_color, fg_color, mix));
        sgl_draw_point(surf, cx-y, cy-x, sgl_color_mixer(bg_color, fg_color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx+x, cy-y+1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx+y-1, cy+x, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx-x, cy+y-1, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx-y+1, cy-x, sgl_color_mixer(bg_color, fg_color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx+x2, cy-y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx+y, cy+x2, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx-x2, cy+y, sgl_color_mixer(bg_color, fg_color, mix));
                sgl_draw_point(surf, cx-y, cy-x2, sgl_color_mixer(bg_color, fg_color, mix));
            } 
            err -= --y*2-1; 
        }
    }
}


void sgl_draw_circle_img(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t bg_color, sgl_img_t *img)
{
    int x = radius, y = 0, err = 0, i, mix;
    sgl_color_t *pick = (sgl_color_t*)img->bitmap;
    int pick_cx = img->width/2;
    int pick_cy = img->height/2;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx+x, cy+y, sgl_color_mixer(bg_color, pick[(pick_cy+y)*img->width + pick_cx+x], mix)); 
            sgl_draw_point(surf, cx-y, cy+x, sgl_color_mixer(bg_color, pick[(pick_cy+x)*img->width + pick_cx-y], mix)); 
            sgl_draw_point(surf, cx-x, cy-y, sgl_color_mixer(bg_color, pick[(pick_cy-y)*img->width + pick_cx-x], mix)); 
            sgl_draw_point(surf, cx+y, cy-x, sgl_color_mixer(bg_color, pick[(pick_cy-x)*img->width + pick_cx+y], mix));
        }
        for (i = x; i > 0; i--) {
            sgl_draw_point(surf, cx+i, cy+y, pick[(pick_cy+y)*img->width + pick_cx+i]);
            sgl_draw_point(surf, cx-y, cy+i, pick[(pick_cy+i)*img->width + pick_cx-y]);
            sgl_draw_point(surf, cx-i, cy-y, pick[(pick_cy-y)*img->width + pick_cx-i]); 
            sgl_draw_point(surf, cx+y, cy-i, pick[(pick_cy-i)*img->width + pick_cx+y]);
        }
    }
    sgl_draw_point(surf, cx, cy, pick[(pick_cy)*img->width + pick_cx]);
}


void sgl_draw_circle_img_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_img_t *img)
{
    int x = radius, y = 0, err = 0, i, mix;
    sgl_color_t *pick = (sgl_color_t*)img->bitmap;
    int pick_cx = img->width/2;
    int pick_cy = img->height/2;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx+x, cy+y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+x, cy+y), pick[(pick_cy+y)*img->width + pick_cx+x], mix)); 
            sgl_draw_point(surf, cx-y, cy+x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-y, cy+x), pick[(pick_cy+x)*img->width + pick_cx-y], mix)); 
            sgl_draw_point(surf, cx-x, cy-y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-x, cy-y), pick[(pick_cy-y)*img->width + pick_cx-x], mix)); 
            sgl_draw_point(surf, cx+y, cy-x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+y, cy-x), pick[(pick_cy-x)*img->width + pick_cx+y], mix));
        }
        for (i = x; i > 0; i--) {
            sgl_draw_point(surf, cx+i, cy+y, pick[(pick_cy+y)*img->width + pick_cx+i]);
            sgl_draw_point(surf, cx-y, cy+i, pick[(pick_cy+i)*img->width + pick_cx-y]);
            sgl_draw_point(surf, cx-i, cy-y, pick[(pick_cy-y)*img->width + pick_cx-i]); 
            sgl_draw_point(surf, cx+y, cy-i, pick[(pick_cy-i)*img->width + pick_cx+y]);
        }
    }
    sgl_draw_point(surf, cx, cy, pick[(pick_cy)*img->width + pick_cx]);
}


void sgl_draw_circle_img_transp_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_img_t *img, uint8_t alpha)
{
    int x = radius, y = 0, err = 0, i, mix;
    sgl_color_t *pick = (sgl_color_t*)img->bitmap;
    int pick_cx = img->width/2;
    int pick_cy = img->height/2;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx+x, cy+y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+x, cy+y),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+x, cy+y), pick[(pick_cy+y)*img->width + pick_cx+x], mix),alpha)); 
            sgl_draw_point(surf, cx-y, cy+x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-y, cy+x),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-y, cy+x), pick[(pick_cy+x)*img->width + pick_cx-y], mix),alpha)); 
            sgl_draw_point(surf, cx-x, cy-y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-x, cy-y),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-x, cy-y), pick[(pick_cy-y)*img->width + pick_cx-x], mix),alpha)); 
            sgl_draw_point(surf, cx+y, cy-x, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+y, cy-x),
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+y, cy-x), pick[(pick_cy-x)*img->width + pick_cx+y], mix),alpha));
        }
        for (i = x; i > 0; i--) {
            sgl_draw_point(surf, cx+i, cy+y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+i, cy+y), pick[(pick_cy+y)*img->width + pick_cx+i], alpha));
            sgl_draw_point(surf, cx-y, cy+i, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-y, cy+i), pick[(pick_cy+i)*img->width + pick_cx-y], alpha));
            sgl_draw_point(surf, cx-i, cy-y, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx-i, cy-y), pick[(pick_cy-y)*img->width + pick_cx-i], alpha)); 
            sgl_draw_point(surf, cx+y, cy-i, 
                            sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx+y, cy-i), pick[(pick_cy-i)*img->width + pick_cx+y], alpha));
        }
    }
    sgl_draw_point(surf, cx, cy, 
                    sgl_color_mixer(sgl_get_draw_buffer_color(surf,cx, cy), pick[(pick_cy)*img->width + pick_cx], alpha));
}



void sgl_draw_circle_solid_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color)
{
    int x = radius, y = 0, err = 0, i, mix;
    for (radius = 2*radius+1; x > 0; err += ++y*2-1) {
        if (err+2*x+1 < radius) err += ++x*2-1;
        for ( ; err > 0; err -= --x*2+1) {
            mix = 255*err/radius;
            sgl_draw_point(surf, cx+x, cy+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+x, cy+y), color, mix)); 
            sgl_draw_point(surf, cx-y, cy+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-y, cy+x), color, mix)); 
            sgl_draw_point(surf, cx-x, cy-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-x, cy-y), color, mix)); 
            sgl_draw_point(surf, cx+y, cy-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+y, cy-x), color, mix)); 
        }
        for (i = x; i > 0; i--) {
            sgl_draw_point(surf, cx+i, cy+y, color);
            sgl_draw_point(surf, cx-y, cy+i, color);
            sgl_draw_point(surf, cx-i, cy-y, color); 
            sgl_draw_point(surf, cx+y, cy-i, color);
        }
    }
    sgl_draw_point(surf, cx, cy, color);
}


void sgl_draw_circle_hollow_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int radius, sgl_color_t color)
{
    int x = radius, y = 0;
    int mix, x2, e2, err = 2-2*radius;
    radius = 1-err;
    while(1) {
        mix = 255*sgl_abs(err+2*(x+y)-2)/radius;
        sgl_draw_point(surf, cx+x, cy-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+x, cy-y), color, mix));
        sgl_draw_point(surf, cx+y, cy+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+y, cy+x), color, mix));
        sgl_draw_point(surf, cx-x, cy+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-x, cy+y), color, mix));
        sgl_draw_point(surf, cx-y, cy-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-y, cy-x), color, mix));
        if (x == 0)
            break;
        e2 = err; x2 = x;
        if (err > y) {
            mix = 255*(err+2*x-1)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx+x, cy-y+1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+x, cy-y+1), color, mix));
                sgl_draw_point(surf, cx+y-1, cy+x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+y-1, cy+x), color, mix));
                sgl_draw_point(surf, cx-x, cy+y-1, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-x, cy+y-1), color, mix));
                sgl_draw_point(surf, cx-y+1, cy-x, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-y+1, cy-x), color, mix));
            }
            err -= --x*2-1; 
        }
        if (e2 <= x2--) {
            mix = 255*(1-2*y-e2)/radius;
            if (mix < 255) {
                sgl_draw_point(surf, cx+x2, cy-y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+x2, cy-y), color, mix));
                sgl_draw_point(surf, cx+y, cy+x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx+y, cy+x2), color, mix));
                sgl_draw_point(surf, cx-x2, cy+y, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-x2, cy+y), color, mix));
                sgl_draw_point(surf, cx-y, cy-x2, sgl_color_mixer(sgl_get_draw_buffer_color(surf, cx-y, cy-x2), color, mix));
            } 
            err -= --y*2-1; 
        }
    }
}


static void sgl_draw_circle_blend_outedge(sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
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
            sgl_draw_point(surf, cx-y, cy-x, aa_color);
            sgl_draw_point(surf, cx-x, cy-y, aa_color);
            sgl_draw_point(surf, cx+y-1, cy-x, aa_color);
            sgl_draw_point(surf, cx+x-1, cy-y, aa_color);
            sgl_draw_point(surf, cx-y, cy+x-1, aa_color);
            sgl_draw_point(surf, cx-x, cy+y-1, aa_color);
            sgl_draw_point(surf, cx+y-1, cy+x-1, aa_color);
            sgl_draw_point(surf, cx+x-1, cy+y-1, aa_color);
        f += ddF_x + 1;
    }
}

static void sgl_draw_circle_blend_inedge(sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r, sgl_color_t fg_color, sgl_color_t bg_color)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    sgl_color_t aa_color;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        aa_color = sgl_color_mixer(fg_color, bg_color, 255 + f * 128 / r);
        sgl_draw_point(surf, cx-y, cy-x, aa_color);
        sgl_draw_point(surf, cx-x, cy-y, aa_color);
        sgl_draw_point(surf, cx+y-1, cy-x, aa_color);
        sgl_draw_point(surf, cx+x-1, cy-y, aa_color); 
        sgl_draw_point(surf, cx-y, cy+x-1, aa_color);
        sgl_draw_point(surf, cx-x, cy+y-1, aa_color);
        sgl_draw_point(surf, cx+y-1, cy+x-1, aa_color);
        sgl_draw_point(surf, cx+x-1, cy+y-1, aa_color);
        f += ddF_x + 1;
    }
}

void sgl_draw_circle_thick(sgl_surf_t *surf, uint16_t cx, uint16_t cy, uint16_t radius, uint16_t thick, sgl_color_t color, sgl_color_t bg_color)
{
    uint16_t r2 = radius - thick;
    uint32_t rr = radius * radius;
    uint32_t r2r2 = r2 * r2;
    for(int16_t y = -radius; y < 0; y++) {
        for(int16_t x = -radius; x < 0; x++) {
            uint32_t r2 = x * x + y * y;
            if ((r2 <= rr) && (r2 >= r2r2)) {
                sgl_draw_point(surf, cx+x, cy+y, color);
                sgl_draw_point(surf, cx+x, cy-y - 1, color);
                sgl_draw_point(surf, cx-x-1, cy+y, color);
                sgl_draw_point(surf, cx-x - 1, cy-y - 1, color);
            }
        }
    }
    //to render edge
    sgl_draw_circle_blend_outedge(surf, cx, cy, radius, color, bg_color);
    sgl_draw_circle_blend_inedge(surf, cx, cy, r2, color, bg_color);
}


static void sgl_draw_circle_blend_outedge_on_bg( sgl_surf_t *surf, 
                                                 int16_t cx, int16_t cy, 
                                                 int16_t r,
                                                 sgl_color_t color)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    int mix = 0;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        mix = - f * 128 / r;
        sgl_draw_point( surf, cx-y, cy-x,
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy-x), mix));
        sgl_draw_point( surf, cx-y, cy-x+1, color);

        sgl_draw_point( surf, cx-x, cy-y, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy-y), mix));
        sgl_draw_point( surf, cx-x+1, cy-y, color);

        sgl_draw_point( surf, cx+y-1, cy-x, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy-x), mix));
        sgl_draw_point( surf, cx+y-1, cy-x+1, color);

        sgl_draw_point( surf, cx+x-1, cy-y, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy-y), mix));
        sgl_draw_point( surf, cx+x-2, cy-y, color);

        sgl_draw_point( surf, cx-y, cy+x-1, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy+x-1), mix));
        sgl_draw_point( surf, cx-y, cy+x-2, color);

        sgl_draw_point( surf, cx-x, cy+y-1, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy+y-1), mix));
        sgl_draw_point( surf, cx-x + 1, cy+y-1, color);

        sgl_draw_point( surf, cx+y-1, cy+x-1, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy+x-1), mix));
        sgl_draw_point( surf, cx+y-1, cy+x-2, color);

        sgl_draw_point( surf, cx+x-1, cy+y-1, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy+y-1), mix));
        sgl_draw_point( surf, cx+x-2, cy+y-1, color);

        f += ddF_x + 1;
    }
}

static void sgl_draw_circle_blend_inedge_on_bg( sgl_surf_t *surf, 
                                                int16_t cx, int16_t cy, 
                                                int16_t r, 
                                                sgl_color_t color)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    int mix = 0;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        mix = 255 + f * 128 / r;

        sgl_draw_point( surf, cx-y, cy-x,
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy-x), mix));
        sgl_draw_point( surf, cx-y, cy-x -1, color);


        sgl_draw_point( surf, cx-x, cy-y, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy-y), mix));
        sgl_draw_point( surf, cx-x-1, cy-y, color);


        sgl_draw_point( surf, cx+y-1, cy-x, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy-x), mix));
        sgl_draw_point( surf, cx+y-1, cy-x-1, color);


        sgl_draw_point( surf, cx+x-1, cy-y,
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy-y), mix)); 
        sgl_draw_point( surf, cx+x, cy-y, color);


        sgl_draw_point( surf, cx-y, cy+x-1,
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy+x-1), mix));
        sgl_draw_point( surf, cx-y, cy+x, color);


        sgl_draw_point( surf, cx-x, cy+y-1,
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy+y-1), mix)); 
        sgl_draw_point( surf, cx-x-1, cy+y-1, color);


        sgl_draw_point( surf, cx+y-1, cy+x-1, 
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy+x-1), mix));
        sgl_draw_point( surf, cx+y-1, cy+x, color);


        sgl_draw_point( surf, cx+x-1, cy+y-1,
                        sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy+y-1), mix));
        sgl_draw_point( surf, cx+x, cy+y-1, color);

        f += ddF_x + 1;
    }
}


void sgl_draw_circle_thick_on_bg( sgl_surf_t *surf, 
                                int16_t cx, int16_t cy, 
                                int16_t radius, 
                                int16_t thick,
                                sgl_color_t color)
{
    //to render edge
    uint16_t r2 = radius - thick;
    sgl_draw_circle_blend_outedge_on_bg(surf, cx, cy, radius, color);
    sgl_draw_circle_blend_inedge_on_bg(surf, cx, cy, r2, color);
    uint16_t arc_r = radius - 1;
    r2 += 1;
    uint32_t rr = arc_r * arc_r;
    uint32_t r2r2 = r2 * r2;
    for(int16_t y = - radius; y < 0; y++) {
        for(int16_t x = -radius; x < 0; x++) {
            uint32_t r2 = x * x + y * y;
            if ((r2 < rr) && (r2 > r2r2)) {

                sgl_draw_point(surf, cx+x, cy+y, color);

                sgl_draw_point(surf, cx+x, cy-y-1, color);

                sgl_draw_point(surf, cx-x-1, cy+y, color);

                sgl_draw_point(surf, cx-x-1, cy-y-1, color);
            }
        }
    }
}


sgl_pos_t sgl_circle_pos_by_angle(int16_t r, int16_t angle)
{
    sgl_pos_t ret;
    sgl_trig_t trig;
    trig = sgl_trig(angle * 0x4000 / 90);
    ret.x = trig.sin_h  * r / 32766;
    ret.y = trig.cos_h * r / 32766;
    return ret;
}
