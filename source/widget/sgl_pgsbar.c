/* source/widget/sgl_pgsbar.c
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

#include "./sgl_pgsbar.h"
#include "stdio.h"

int sgl_pgsbar_init(sgl_pgsbar_t *bar, sgl_obj_t* parent, uint8_t value)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    bar->value = value;
    bar->font = NULL;
    bar->anim = false;
    obj = &bar->obj;
    obj->parent = parent;
    obj->selected = 0;
    obj->hide = 0;
    obj->obj_type = SGL_OBJ_PROGRESSBAR;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, obj);
    sgl_page_add_dirty_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_pgsbar_create(sgl_obj_t* parent, uint8_t value)
{
    int ret;
    sgl_pgsbar_t *bar;
    if(parent == NULL) {
        return NULL;
    }
    bar = (sgl_pgsbar_t *)sgl_alloc(sizeof(sgl_pgsbar_t));
    if(bar == NULL)
        return NULL;
    ret = sgl_pgsbar_init(bar, parent, value);
    if(ret) {
        return NULL;
    }
    return &bar->obj;
}

void sgl_pgsbar_set_value(sgl_obj_t* obj, uint8_t value)
{
    sgl_pgsbar_t *bar = container_of(obj, sgl_pgsbar_t, obj);
    if(value != bar->value) {
        bar->value = value;
        sgl_obj_set_event_status(obj, SGL_EVENT_PRESSED);
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

uint8_t sgl_pgsbar_get_value(sgl_obj_t* obj)
{
    sgl_pgsbar_t *bar = container_of(obj, sgl_pgsbar_t, obj);
    return bar->value;
}

void sgl_pgsbar_set_font(sgl_obj_t* obj, sgl_font_t *font)
{
    sgl_pgsbar_t *bar = container_of(obj, sgl_pgsbar_t, obj);
    bar->font = font;
}

void sgl_pgsbar_draw(sgl_obj_t* obj)
{
    sgl_pgsbar_t *bar = container_of(obj, sgl_pgsbar_t, obj);
    char value[5] = {' ', ' ', ' ', '%', 0};
    int width = obj->size.w;
    sgl_widget_draw_rect(rect);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    int pos_x;
    sgl_widget_buffer_valid(obj);
    if(bar->font) {
        // draw text for value
        int value_len;
        if(bar->value > 9 && bar->value != 100) {
            sgl_int64_to_str(bar->value, &value[1]);
        }
        else if(bar->value >= 0 && bar->value < 10) {
            sgl_int64_to_str(bar->value, &value[2]);
        }
        else if(bar->value == 100) {
            sgl_int64_to_str(bar->value, value);
        }
        value[3] = '%';
        value_len = sgl_text_width(bar->font, value);
        width = obj->size.w - value_len - 2;
        pos_x = width  * bar->value / 100;
    }
    else {
        pos_x = obj->size.w * bar->value / 100;
    }
    if(bar->anim) {
        //TODO: add animation support
    }
    else {
        /**
         * not set progress bar font, so it will not draw text for value
         * 
         * draw background bar
        */
        if(obj->style.radius) {
            if(bg_img == NULL)
                sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style.body_color);
            else
                sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->style.bg_img);
            if(obj->hide) return;
            if(bar->font) {
                rect.x2 = sgl_widget_draw_ofs_x(width);
                int pos_y = sgl_widget_draw_ofs_y((obj->size.h - sgl_text_height(bar->font)) / 2);
                if(bg_img == NULL)
                    sgl_draw_font_string(surf, rect.x2 + 2, pos_y, value, obj->style.text_color, obj->parent->style.body_color, bar->font);
                else
                    sgl_draw_font_string_on_bg(surf, rect.x2 + 2, pos_y, value, obj->style.text_color, bar->font);
            }
            if(pos_x >= (width - obj->style.radius)) {
                rect.x2 = sgl_widget_draw_ofs_x(width);
                if(bg_img == NULL)
                    sgl_draw_round_rect_solid(surf, rect, obj->style.radius, obj->style.text_color, obj->parent->style.body_color);
                else
                    sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style.radius, obj->style.text_color);
            }
            else if(pos_x == 0) {
                if(bg_img == NULL)
                    sgl_draw_round_rect_solid(surf, rect, obj->style.radius, obj->style.body_color, obj->parent->style.body_color);
                else
                    sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style.radius, obj->style.body_color);
            }
            else if(pos_x <= obj->style.radius) {
                rect.x2 = sgl_widget_draw_ofs_x(obj->style.radius);
                if(bg_img == NULL)
                    sgl_draw_round_rect_solid_lhalf(surf, rect, obj->style.radius, obj->style.text_color, obj->parent->style.body_color);
                else
                    sgl_draw_round_rect_solid_lhalf_on_bg(surf, rect, obj->style.radius, obj->style.text_color);
                rect.x1 = rect.x2;
                rect.x2 = sgl_widget_draw_ofs_x(width);
                if(bg_img == NULL)
                    sgl_draw_round_rect_solid_rhalf(surf, rect, obj->style.radius, obj->style.body_color, obj->parent->style.body_color);
                else
                    sgl_draw_round_rect_solid_rhalf_on_bg(surf, rect, obj->style.radius, obj->style.body_color);
            }
            else {
                rect.x1 = sgl_widget_draw_ofs_x(0);
                rect.x2 = sgl_widget_draw_ofs_x(pos_x);
                if(bg_img == NULL)
                    sgl_draw_round_rect_solid_lhalf(surf, rect, obj->style.radius, obj->style.text_color, obj->parent->style.body_color);
                else
                    sgl_draw_round_rect_solid_lhalf_on_bg(surf, rect, obj->style.radius, obj->style.text_color);
                rect.x1 = sgl_widget_draw_ofs_x(pos_x);
                rect.x2 = sgl_widget_draw_ofs_x(width);
                if(bg_img == NULL)
                    sgl_draw_round_rect_solid_rhalf(surf, rect, obj->style.radius, obj->style.body_color, obj->parent->style.body_color);
                else
                    sgl_draw_round_rect_solid_rhalf_on_bg(surf, rect, obj->style.radius, obj->style.body_color);
            }
        }
        else {
            sgl_draw_buffer_clear(surf, obj->style.body_color);
            if(bar->font) {
                
            }
            sgl_draw_rect_solid(surf, rect, obj->style.text_color);
        }
    }
    sgl_draw_obj_selected(obj, surf, rect, obj->style.text_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}


void sgl_pgsbar_event_cb(sgl_obj_t *obj)
{
    sgl_pgsbar_t *bar = container_of(obj, sgl_pgsbar_t, obj);
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        if(obj->event_fn) {
            sgl_event_pos_t ev_pos = sgl_event_get_device_pos();
            if(bar->font) {
                char value[5] = {' ',' ',' ', '%', 0};
                int value_len;
                value_len = sgl_text_width(bar->font, value);
                if((ev_pos.x - obj->pos.x) >= (obj->size.w - value_len - 2)) {
                    bar->value = 100;
                }
                else {
                    bar->value = (ev_pos.x - obj->pos.x) *100 / (obj->size.w - value_len - 2);
                }
            }
            else {
                bar->value = (ev_pos.x - obj->pos.x) *100 / obj->size.w;
            }
        }
        sgl_obj_event_cb(obj);
        sgl_pgsbar_draw(obj);
    }
    else if(obj->ev_stat == SGL_EVENT_FORCE_DRAW) {
        sgl_pgsbar_draw(obj);
    }
}
