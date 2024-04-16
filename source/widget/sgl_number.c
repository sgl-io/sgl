/* source/widget/sgl_number.c
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

#include "./sgl_number.h"
#include "stdio.h"

int sgl_number_init(sgl_number_t *number, sgl_obj_t* parent, double value)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    number->value = value;
    number->font = NULL;
    obj = &number->obj;
    obj->parent = parent;
    obj->selected = 0;
    obj->hide = 0;
    obj->obj_type = SGL_OBJ_NUMBER;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, obj);
    sgl_page_add_dirty_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_number_create(sgl_obj_t* parent, double value)
{
    int ret;
    sgl_number_t *number;
    if(parent == NULL) {
        return NULL;
    }
    number = (sgl_number_t *)sgl_alloc(sizeof(sgl_number_t));
    if(number == NULL)
        return NULL;
    ret = sgl_number_init(number, parent, value);
    if(ret) {
        return NULL;
    }
    return  &number->obj;
}

void sgl_number_set_font(sgl_obj_t* obj, sgl_font_t *font)
{
    sgl_number_t *number = container_of(obj, sgl_number_t, obj);
    number->font = font;
}

void sgl_number_set_value(sgl_obj_t* obj, double value)
{
    sgl_number_t *number = container_of(obj, sgl_number_t, obj);
    if(value != number->value) {
        number->value = value;
        sgl_obj_set_event_status(obj, SGL_EVENT_FORCE_DRAW);
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

void sgl_number_set_text_align(sgl_obj_t *obj, sgl_align_type_e align)
{
    sgl_number_t *number = container_of(obj, sgl_number_t, obj);
    number->align = align;
}

void sgl_number_draw(sgl_obj_t* obj)
{
    sgl_number_t *number = container_of(obj, sgl_number_t, obj);
    char text[65] = { '0', '\0' };
    sgl_size_t _size;
    sgl_pos_t pos;
    sgl_int64_to_str(number->value, text);
    sgl_widget_draw_rect(rect);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_widget_buffer_valid(obj);
    if(obj->style.radius) {
        if(bg_img == NULL) {
            sgl_draw_buffer_clear(surf, obj->parent->style.body_color);
            sgl_draw_round_rect_solid(surf, rect, obj->style.radius, obj->style.body_color, obj->parent->style.body_color);
        }
        else {
            sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->style.bg_img);
            sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style.radius, obj->style.body_color);
        }
    }
    else {
        sgl_draw_buffer_clear(surf, obj->style.body_color);
    }
    if(obj->hide) return;
    if(number->font) {
        _size.w = sgl_text_width(number->font, text);
        _size.h = sgl_text_height(number->font);
        pos = sgl_get_align_pos(&obj->size, &_size, number->align);
        pos.x = sgl_widget_draw_ofs_x(pos.x);
        pos.y = sgl_widget_draw_ofs_y(pos.y);
        if(bg_img == NULL)
            sgl_draw_font_string(surf, pos.x, pos.y, text, obj->style.text_color, obj->style.body_color, number->font);
        else
            sgl_draw_font_string_on_bg(surf, pos.x, pos.y, text, obj->style.text_color, number->font);
    }
    sgl_widget_draw_buffer_flush(obj, surf);
}

void sgl_number_event_cb(sgl_obj_t *obj)
{
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        sgl_obj_event_cb(obj);
        sgl_number_draw(obj);
    }
    else if(obj->ev_stat == SGL_EVENT_FORCE_DRAW) {
        sgl_number_draw(obj);
    }
}
