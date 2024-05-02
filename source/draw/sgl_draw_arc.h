/* source/draw/sgl_draw_arc.h
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

#ifndef  __SGL_DRAW_ARC_H__
#define  __SGL_DRAW_ARC_H__

#include "../core/sgl_core.h"
#include "./sgl_draw.h"

#ifdef __cplusplus
extern "C" {
#endif

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
void sgl_draw_thick_arc(sgl_surf_t *surf, int16_t cx, int16_t cy, int16_t radius, 
                        int16_t angle_start, int16_t angle_end, 
                        int16_t thick, 
                        sgl_color_t color, sgl_color_t bg_color);


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
                        sgl_color_t color);


#ifdef __cplusplus
}
#endif

#endif //__SGL_DRAW_ARC_H__
