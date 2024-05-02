/* source/draw/sgl_draw_arc.c
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


#include "./sgl_draw_arc.h"
#include "./sgl_draw_circle.h"
#include "../libs/sgl_math.h"
#include "stdio.h"


/**
 * @brief Draws an arc and blends colors to emphasize the edge of the arc.
 *
 * @param surf: Pointer to the drawing surface, i.e., the canvas.
 * @param cx: X-coordinate of the center of the arc.
 * @param cy: Y-coordinate of the center of the arc.
 * @param r: Radius of the arc.
 * @param angle_start: Starting angle of the arc.
 * @param angle_end: Ending angle of the arc.
 * @param fg_color: Foreground color, representing the edge color of the arc.
 * @param bg_color: Background color, used in color blending with the foreground.
 *
 * @return none
 * 
 * This function employs the Bresenham algorithm to draw a circular arc and applies color blending techniques
 * to accentuate the arc's edge. It initializes parameters required for arc plotting and then, based on the angular
 * conditions and distance from the center, it mixes the foreground and background colors to highlight the edge.
 */
static void sgl_draw_arc_blend_outedge( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r, 
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


/**
 * @brief Draws an arc on a specified surface with edge blending of colors.
 *
 * @param surf: Pointer to the drawing surface.
 * @param cx: X-coordinate of the center of the arc.
 * @param cy: Y-coordinate of the center of the arc.
 * @param r: Radius of the arc.
 * @param angle_start: Starting angle from which the drawing begins.
 * @param angle_end: Ending angle at which the drawing concludes.
 * @param fg_color: Foreground color, primarily used for drawing.
 * @param bg_color: Background color, blended with the foreground color.
 * 
 * @return none
 */
static void sgl_draw_arc_blend_inedge(  sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r,
                                        int16_t angle_start, int16_t angle_end, 
                                        sgl_color_t fg_color, sgl_color_t bg_color)
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
        aa_color = sgl_color_mixer(fg_color, bg_color, 255 + f * 128 / r);
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


/**
 * @brief Draws a thick arc on the specified surface.
 *
 * This function draws a thick arc on the given surface (*surf). The center of the arc is at (cx, cy),
 * with a radius specified by 'radius'. The arc starts at 'angle_start' and ends at 'angle_end'
 * in degrees. The thickness of the arc is determined by 'thick'.
 *
 * @param surf:      Pointer to the surface where the arc will be drawn.
 * @param cx:        X-coordinate of the center point of the arc.
 * @param cy:        Y-coordinate of the center point of the arc.
 * @param radius:    Radius of the arc.
 * @param angle_start: Starting angle of the arc in degrees.
 * @param angle_end:  Ending angle of the arc in degrees.
 * @param thick:     Thickness of the arc.
 * @param color:     Color of the arc.
 * @param bg_color:  Background color for blending edge rendering.
 *
 * @return none
 * 
 * The function first checks each pixel within the inner and outer circles to determine if it's part
 * of the arc. Then it renders the edges using blend functions to create a smooth appearance.
 */
void sgl_draw_thick_arc( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t radius, 
                         int16_t angle_start, int16_t angle_end, 
                         int16_t thick, 
                         sgl_color_t color, sgl_color_t bg_color)
{
    uint16_t r2 = radius - thick;
    int16_t deg;
    uint32_t rr = radius * radius;
    uint32_t r2r2 = r2 * r2;
    for(int16_t y = -radius; y < 0; y++) {
        for(int16_t x = -radius; x < 0; x++) {
            uint32_t r2 = x * x + y * y;
            if ((r2 < rr) && (r2 > r2r2)) {
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
    sgl_draw_arc_blend_outedge( surf, cx, cy, radius, 
                                angle_start, angle_end, 
                                color, bg_color);
    sgl_draw_arc_blend_inedge(  surf, cx, cy, r2, 
                                angle_start, angle_end, 
                                color, bg_color);
}


/**
 * @brief Draws an arc on the given surface and blends color only on the edge of the arc.
 * The arc is defined by its center coordinates (cx, cy), radius (r), and start-end angles.
 * The blending effect decreases linearly from the arc's edge towards its center.
 *
 * @param surf: Pointer to the surface on which the arc will be drawn.
 * @param cx: X-coordinate of the arc's center.
 * @param cy: Y-coordinate of the arc's center.
 * @param r: Radius of the arc.
 * @param angle_start: Starting angle of the arc in degrees.
 * @param angle_end: Ending angle of the arc in degrees.
 * @param color: The color to draw the arc with, used for blending at the edge.
 * 
 * @return none
 * 
 */
static void sgl_draw_arc_blend_outedge_on_bg( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r, 
                                               int16_t angle_start, int16_t angle_end, 
                                               sgl_color_t color)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    int16_t deg;
    int mix = 0;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        deg = sgl_fast_atan2(-y, -x);
        mix = - f * 128 / r;
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-y, cy-x,
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy-x), mix));
            sgl_draw_point( surf, cx-y, cy-x+1, color);
        }

        deg = sgl_fast_atan2(-x, -y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-x, cy-y, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy-y), mix));
            sgl_draw_point( surf, cx-x+1, cy-y, color);
        }

        deg = sgl_fast_atan2(y, -x);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+y-1, cy-x, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy-x), mix));
            sgl_draw_point( surf, cx+y-1, cy-x+1, color);
        }

        deg = sgl_fast_atan2(x, -y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+x-1, cy-y, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy-y), mix));
            sgl_draw_point( surf, cx+x-2, cy-y, color);
        }

        deg = sgl_fast_atan2(-y, x);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-y, cy+x-1, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy+x-1), mix));
            sgl_draw_point( surf, cx-y, cy+x-2, color);
        }

        deg = sgl_fast_atan2(-x, y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-x, cy+y-1, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy+y-1), mix));
            sgl_draw_point( surf, cx-x + 1, cy+y-1, color);
        }


        deg = sgl_fast_atan2(y, x);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+y-1, cy+x-1, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy+x-1), mix));
            sgl_draw_point( surf, cx+y-1, cy+x-2, color);
        }

        deg = sgl_fast_atan2(x, y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+x-1, cy+y-1, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy+y-1), mix));
            sgl_draw_point( surf, cx+x-2, cy+y-1, color);
        }

        f += ddF_x + 1;
    }
}


/**
 * @brief Draws an arc on the given surface and blends its edges with the background.
 *
 * @param surf: Pointer to the surface to draw on.
 * @param cx: The x-coordinate of the center point of the arc.
 * @param cy: The y-coordinate of the center point of the arc.
 * @param r: The radius of the arc.
 * @param angle_start: The starting angle of the arc in degrees.
 * @param angle_end: The ending angle of the arc in degrees.
 * @param color: The color of the arc.
 * 
 * @return none
 */
static void sgl_draw_arc_blend_inedge_on_bg( sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t r, 
                                              int16_t angle_start, int16_t angle_end, 
                                              sgl_color_t color)
{
    int f = 1 - r;
    int diameter = 2*r;
    int ddF_x = 0;
    int ddF_y = - diameter;
    int y = 0;
    int x = r;
    int16_t deg;
    int mix = 0;
    while(y < x) {
        if(f >= 0) {
            x--;
            ddF_y += 2;
            f += ddF_y;
        }
        y++;
        ddF_x += 2;
        deg = sgl_fast_atan2(-y, -x);
        mix = 255 + f * 128 / r;
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-y, cy-x,
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy-x), mix));
            sgl_draw_point( surf, cx-y, cy-x -1, color);
        }

        deg = sgl_fast_atan2(-x, -y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-x, cy-y, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy-y), mix));
            sgl_draw_point( surf, cx-x-1, cy-y, color);
        }


        deg = sgl_fast_atan2(y, -x);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+y-1, cy-x, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy-x), mix));
            sgl_draw_point( surf, cx+y-1, cy-x-1, color);
        }
    
        deg = sgl_fast_atan2(x, -y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+x-1, cy-y,
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy-y), mix)); 
            sgl_draw_point( surf, cx+x, cy-y, color);
        }

        deg = sgl_fast_atan2(-y, x);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-y, cy+x-1,
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy+x-1), mix));
            sgl_draw_point( surf, cx-y, cy+x, color);
        }

        deg = sgl_fast_atan2(-x, y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx-x, cy+y-1,
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy+y-1), mix)); 
            sgl_draw_point( surf, cx-x-1, cy+y-1, color);
        }

        deg = sgl_fast_atan2(y, x);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+y-1, cy+x-1, 
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy+x-1), mix));
            sgl_draw_point( surf, cx+y-1, cy+x, color);
        }


        deg = sgl_fast_atan2(x, y);
        if ((deg >= angle_start) && (deg <= angle_end)) {
            sgl_draw_point( surf, cx+x-1, cy+y-1,
                            sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy+y-1), mix));
            sgl_draw_point( surf, cx+x, cy+y-1, color);
        }

        f += ddF_x + 1;
    }
}


/**
 * @brief Draws a thick arc segment on the specified background surface.
 *
 * This function renders a thick arc from 'angle_start' to 'angle_end' with a given 'thick' on
 * the background of the provided surface, centered at coordinates (cx, cy).
 *
 * @param surf: Pointer to the surface on which the arc will be drawn.
 * @param cx: X-coordinate of the center of the arc.
 * @param cy: Y-coordinate of the center of the arc.
 * @param radius: Outer radius of the arc.
 * @param angle_start: Starting angle of the arc in degrees.
 * @param angle_end: Ending angle of the arc in degrees.
 * @param thick: Thickness of the arc.
 * @param color: Color of the arc to be rendered.
 * 
 * @return none
 */
void sgl_draw_thick_arc_on_bg(sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t radius, 
                        int16_t angle_start, int16_t angle_end, 
                        int16_t thick, 
                        sgl_color_t color)
{
    //to render edge
    uint16_t r2 = radius - thick;
    sgl_draw_arc_blend_outedge_on_bg(surf, cx, cy, radius, angle_start, angle_end, color);
    sgl_draw_arc_blend_inedge_on_bg(surf, cx, cy, r2, angle_start, angle_end, color);
    uint16_t arc_r = radius - 1;
    r2 += 1;
    int16_t deg;
    uint32_t rr = arc_r * arc_r;
    uint32_t r2r2 = r2 * r2;
    for(int16_t y = - radius; y < 0; y++) {
        for(int16_t x = -radius; x < 0; x++) {
            uint32_t r2 = x * x + y * y;
            if ((r2 < rr) && (r2 > r2r2)) {
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
}
