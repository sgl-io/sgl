/* source/draw/sgl_draw.h
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

#ifndef __SGL_DRAW_H__
#define __SGL_DRAW_H__

#include "../sgl.h"

#ifdef __cplusplus
extern "C"{
#endif

sgl_color_t sgl_color_mixer(sgl_color_t fg_color, sgl_color_t bg_color, uint8_t factor);
void sgl_draw_point(sgl_surf_t *surf, int16_t x, int16_t y, sgl_color_t color);
void sgl_draw_hline(sgl_surf_t *surf, int16_t x, int16_t y, int16_t len, sgl_color_t color);
void sgl_draw_vline(sgl_surf_t *surf, int16_t x, int16_t y, int16_t len, sgl_color_t color);
void sgl_draw_area_color(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t color);
void sgl_draw_buffer_clear(sgl_surf_t *surf, sgl_color_t color);
void sgl_draw_obj_buffer_clear(sgl_surf_t *surf, sgl_obj_t *obj, sgl_color_t color);
void sgl_draw_obj_buffer_pick_img(sgl_surf_t *surf, sgl_obj_t *obj, sgl_img_t *img);
void sgl_draw_obj_buffer_pick_surf(sgl_surf_t *surf, sgl_obj_t *obj);
void sgl_draw_buffer_flush(sgl_surf_t *surf, int16_t x, int16_t y);
void sgl_draw_area_flush(sgl_rect_t rect, sgl_color_t *src);
void sgl_draw_buffer_flush_hclip(sgl_surf_t *surf, int16_t x, int16_t y, int16_t clip_start, int16_t clip_end);


int sgl_figure_circle_path(int16_t r, int16_t* path);
sgl_pos_t sgl_figure_arc_endpoint(int16_t r, int16_t deg);
int sgl_text_width(sgl_font_t *font, const char* text);
int sgl_text_height(sgl_font_t *font);
sgl_color_t sgl_get_draw_buffer_color(sgl_surf_t *surf, int16_t x, int16_t y);


//render left top
#define SGL_RENDER_ROUND_EDGE_LT(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx-y, cy-x, color); \
sgl_draw_point(surf, cx-x, cy-y, color);

//render left top on background
#define SGL_RENDER_ROUND_EDGE_LT_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx-y, cy-x, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy-x), mix)); \
sgl_draw_point(surf, cx-x, cy-y, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy-y), mix));


//render right top
#define SGL_RENDER_ROUND_EDGE_RT(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx+y-1, cy-x, color); \
sgl_draw_point(surf, cx+x-1, cy-y, color);

//render right top on background
#define SGL_RENDER_ROUND_EDGE_RT_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx+y-1, cy-x, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy-x), mix)); \
sgl_draw_point(surf, cx+x-1, cy-y, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy-y), mix));

//render left bottom
#define SGL_RENDER_ROUND_EDGE_LB(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx-y, cy+x-1, color); \
sgl_draw_point(surf, cx-x, cy+y-1, color);

//render left bottom on background
#define SGL_RENDER_ROUND_EDGE_LB_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx-y, cy+x-1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy+x-1), mix)); \
sgl_draw_point(surf, cx-x, cy+y-1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x, cy+y-1), mix));

//render right bottom
#define SGL_RENDER_ROUND_EDGE_RB(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx+y-1, cy+x-1, color);  \
sgl_draw_point(surf, cx+x-1, cy+y-1, color);


//render right bottom on background
#define SGL_RENDER_ROUND_EDGE_RB_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx+y-1, cy+x-1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy+x-1), mix));  \
sgl_draw_point(surf, cx+x-1, cy+y-1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-1, cy+y-1), mix));


//render left top internal
#define SGL_RENDER_ROUND_EDGE_LTI(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx-y, cy-x+1, color); \
sgl_draw_point(surf, cx-x+1, cy-y, color);

//render left top internal on background
#define SGL_RENDER_ROUND_EDGE_LTI_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx-y, cy-x+1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy-x+1), mix)); \
sgl_draw_point(surf, cx-x+1, cy-y, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x+1, cy-y), mix));


//render right top internal
#define SGL_RENDER_ROUND_EDGE_RTI(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx+y-1, cy-x+1, color);  \
sgl_draw_point(surf, cx+x-2, cy-y, color); 

//render right top internal on background
#define SGL_RENDER_ROUND_EDGE_RTI_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx+y-1, cy-x+1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy-x+1), mix));  \
sgl_draw_point(surf, cx+x-2, cy-y, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-2, cy-y), mix)); 

//render left bottom internal
#define SGL_RENDER_ROUND_EDGE_LBI(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx-y, cy+x-2, color);  \
sgl_draw_point(surf, cx-x+1, cy+y-1, color);

//render left bottom internal on background
#define SGL_RENDER_ROUND_EDGE_LBI_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx-y, cy+x-2, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-y, cy+x-2), mix));  \
sgl_draw_point(surf, cx-x+1, cy+y-1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx-x+1, cy+y-1), mix));

//render right bottom internal
#define SGL_RENDER_ROUND_EDGE_RBI(surf, cx, cy, x, y, color) \
sgl_draw_point(surf, cx+y-1, cy+x-2, color);  \
sgl_draw_point(surf, cx+x-2, cy+y-1, color);

//render right bottom internal on background
#define SGL_RENDER_ROUND_EDGE_RBI_BG(surf, cx, cy, x, y, color, mix) \
sgl_draw_point(surf, cx+y-1, cy+x-2, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+y-1, cy+x-2), mix));  \
sgl_draw_point(surf, cx+x-2, cy+y-1, sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, cx+x-2, cy+y-1), mix));


#if SGL_CONFIG_FRAMEBUFFER_MMAP
#define sgl_draw_obj_selected(obj, surf, rect, color) \
if(obj->selected) { \
    rect.x1 = obj->pos.x; \
    rect.y1 = obj->pos.y; \
    rect.x2 = obj->pos.x + obj->size.w - 1; \
    rect.y2 = obj->pos.y + obj->size.h - 1; \
    sgl_draw_rect_hollow(surf, rect, color); \
}

#define sgl_draw_obj_unselected  sgl_draw_obj_selected

#define sgl_widget_draw_buffer_flush(obj, surf)
#define sgl_widget_draw_ofs_x(pos_x)  ((pos_x) + obj->pos.x)
#define sgl_widget_draw_ofs_y(pos_y)  ((pos_y) + obj->pos.y)


#define sgl_widget_draw_rect(rect)   \
sgl_rect_t rect = {.x1 = obj->pos.x, .y1 = obj->pos.y, .x2 = (int16_t)(obj->pos.x + obj->size.w - 1), .y2 = (int16_t)(obj->pos.y + obj->size.h - 1)};

#define sgl_widget_buffer_valid(obj) {}

#else
#define sgl_draw_obj_selected(obj, surf, rect, color) \
if(obj->selected) { \
    rect.x1 = 0; \
    rect.y1 = 0; \
    rect.x2 = obj->size.w - 1; \
    rect.y2 = obj->size.h - 1; \
    sgl_draw_rect_hollow(surf, rect, color); \
}

#define sgl_draw_obj_unselected

#define sgl_widget_draw_buffer_flush(obj, surf)  sgl_draw_buffer_flush(surf, obj->pos.x, obj->pos.y);
#define sgl_widget_draw_ofs_x(x)  (x)
#define sgl_widget_draw_ofs_y(y)  (y)


#define sgl_widget_draw_rect(rect) \
sgl_rect_t rect = {.x1 = 0, .y1 = 0, .x2 = (int16_t)(obj->size.w - 1), .y2 = (int16_t)(obj->size.h - 1)};

#define sgl_widget_buffer_valid(obj)  {if(!sgl_draw_obj_valid(obj)) return;}

#endif


/**
* @brief Check if object drawing exceeds the size of the drawing cache
*
* @param obj:  The object
*
* @return bool  true: valid, false: invalid
*/
bool sgl_draw_obj_valid(sgl_obj_t *obj);





#ifdef __cplusplus
}
#endif

#endif //__SGL_DRAW_H__
