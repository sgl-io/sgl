/* source/widget/sgl_arcbar.c
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

#include "./sgl_arcbar.h"
#include "./sgl_obj.h"
#include "./sgl_page.h"
#include "./sgl_device.h"
#include "./sgl_task.h"
#include "../libs/sgl_mem.h"
#include "../libs/sgl_string.h"
#include "../draw/sgl_draw.h"
#include "../draw/sgl_draw_rect.h"
#include "../draw/sgl_draw_font.h"
#include "../draw/sgl_draw_circle.h"
#include "../draw/sgl_draw_icon.h"
#include "../draw/sgl_draw_arc.h"


static void sgl_arcbar_draw(sgl_obj_t* obj);


int sgl_arcbar_init(sgl_arcbar_t *arcbar, sgl_obj_t* parent, uint8_t value)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    arcbar->font = NULL;
    arcbar->value = value;
    arcbar->thick = 5;
    obj = &arcbar->obj;
    obj->parent = parent;
    obj->dirty = 1;
    obj->selected = 0;
    obj->hide = 0;
    obj->draw_cb = sgl_arcbar_draw;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_arcbar_create(sgl_obj_t* parent, uint8_t value)
{
    sgl_arcbar_t *arcbar;
    if(parent == NULL) {
        return NULL;
    }
    arcbar = (sgl_arcbar_t *)sgl_malloc(sizeof(sgl_arcbar_t));
    if(arcbar == NULL)
        return NULL;
    sgl_arcbar_init(arcbar, parent, value);
    return &arcbar->obj;
}

void sgl_arcbar_set_value(sgl_obj_t* obj, uint8_t value)
{
    sgl_arcbar_t *arcbar = container_of(obj, sgl_arcbar_t, obj);
    if(arcbar->value != value) {
        sgl_obj_set_event_status(obj, SGL_EVENT_FORCE_DRAW);
        arcbar->value = value;
        obj->dirty = 1;
    }
}

uint8_t sgl_arcbar_get_value(sgl_obj_t* obj)
{
    sgl_arcbar_t *arcbar = container_of(obj, sgl_arcbar_t, obj);
    return arcbar->value;
}

void sgl_arcbar_set_font(sgl_obj_t* obj, sgl_font_t *font)
{
    sgl_arcbar_t *arcbar = container_of(obj, sgl_arcbar_t, obj);
    arcbar->font = font;
}

void sgl_arcbar_set_thick(sgl_obj_t* obj, uint8_t thick)
{
    sgl_arcbar_t *arcbar = container_of(obj, sgl_arcbar_t, obj);
    arcbar->thick = thick;
}

static void sgl_arcbar_draw(sgl_obj_t* obj)
{
    sgl_arcbar_t *arcbar = container_of(obj, sgl_arcbar_t, obj);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    int cx, cy, radius;
    char value[5] = {' ', ' ', ' ', '%', 0};
    int deg_end = 360 - 360 * arcbar->value / 100;
    int value_len;
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_widget_buffer_valid(obj);
    radius = obj->size.w / 2;
    cx = sgl_widget_draw_ofs_x(obj->size.w / 2);
    cy = sgl_widget_draw_ofs_y(obj->size.w / 2);
    if(bg_img == NULL) {
        sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style->body_color);
        if(obj->ev_stat == SGL_EVENT_FORCE_DRAW_CLEAR) {
            return;
        }
        if(!obj->alpha) {
            sgl_draw_thick_arc(surf,
                            cx, cy,
                            radius,
                            0, deg_end,
                            arcbar->thick,
                            obj->style->body_color, obj->parent->style->body_color
                            );
            sgl_draw_thick_arc(surf,
                            cx, cy,
                            radius, 
                            deg_end , 360,
                            arcbar->thick,
                            obj->style->text_color, obj->parent->style->body_color
                            );
        }
        else {
            // TODO: suport alpha value
            sgl_draw_thick_arc(surf,
                            cx, cy,
                            radius,
                            0, deg_end,
                            arcbar->thick,
                            obj->style->body_color, obj->parent->style->body_color
                            );
            sgl_draw_thick_arc(surf,
                            cx, cy,
                            radius, 
                            deg_end , 360,
                            arcbar->thick,
                            obj->style->text_color, obj->parent->style->body_color
                            );
        }
    }
    else {
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->bg_img);
        if(obj->ev_stat == SGL_EVENT_FORCE_DRAW_CLEAR) {
            return;
        }
        sgl_draw_thick_arc_on_bg(surf,
                        cx, cy,
                        radius,
                        0, deg_end,
                        arcbar->thick,
                        obj->style->body_color
                        );
        sgl_draw_thick_arc_on_bg(surf,
                        cx, cy,
                        radius, 
                        deg_end , 360,
                        arcbar->thick,
                        obj->style->text_color
                        );
    }
    if(obj->hide) return;
    if(arcbar->font) {
#if SGL_CONFIG_FRAMEBUFFER_MMAP
        sgl_widget_draw_rect(rect);
        value_len = sgl_text_width(arcbar->font, value);
        rect.x1 = sgl_widget_draw_ofs_x((obj->size.w - value_len) / 2);
        rect.y1 = sgl_widget_draw_ofs_y((obj->size.w - sgl_text_height(arcbar->font)) / 2);
        rect.x2 = rect.x1 + value_len;
        rect.y2 = rect.y1 + sgl_text_height(arcbar->font);
#endif
        // draw text for value
        if(arcbar->value > 9 && arcbar->value != 100) {
            sgl_int64_to_str(arcbar->value, value);
            value[2] = '%';
            value[3] = '\0';
        }
        else if(arcbar->value >= 0 && arcbar->value < 10) {
            sgl_int64_to_str(arcbar->value, value);
            value[1] = '%';
            value[2] = '\0';
        }
        else if(arcbar->value == 100) {
            sgl_int64_to_str(arcbar->value, value);
            value[3] = '%';
            value[4] = '\0';
        }

        value_len = sgl_text_width(arcbar->font, value);
        cx = sgl_widget_draw_ofs_x((obj->size.w - value_len) / 2);
        cy = sgl_widget_draw_ofs_y((obj->size.w - sgl_text_height(arcbar->font)) / 2);
        if(bg_img == NULL) {
            sgl_draw_font_string(surf, cx, cy, value, obj->style->text_color, obj->parent->style->body_color, arcbar->font);
        }else {
            sgl_draw_font_string_on_bg(surf, cx, cy, value, obj->style->text_color, arcbar->font);
        }
    }
    sgl_widget_draw_buffer_flush(obj, surf);
}
