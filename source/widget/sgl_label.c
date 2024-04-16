/* source/widget/sgl_label.c
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

#include "./sgl_label.h"
#include "../draw/sgl_draw_font.h"
#include "../draw/sgl_draw_icon.h"
#include "stdio.h"

static void sgl_spin_anim_cb()
{
    //TODO
}

int sgl_label_init(sgl_label_t *label, sgl_obj_t* parent)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    label->font = NULL;
    label->text = NULL;
    label->icon = NULL;
    label->align = SGL_ALIGN_CENTER_MID;
    obj = &label->obj;
    obj->parent = parent;
    obj->selected = 0;
    obj->hide = 0;
    obj->obj_type = SGL_OBJ_LABEL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, obj);
    sgl_page_add_dirty_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_label_create(sgl_obj_t* parent)
{
    sgl_label_t *label;
    if(parent == NULL) {
        return NULL;
    }
    label = (sgl_label_t *)sgl_alloc(sizeof(sgl_label_t));
    if(label == NULL)
        return NULL;
    sgl_label_init(label, parent);
    return &label->obj;
}

void sgl_label_set_font(sgl_obj_t *obj, sgl_font_t *font)
{
    sgl_label_t *label = container_of(obj, sgl_label_t, obj);
    label->font = font;
}

void sgl_label_set_text(sgl_obj_t *obj, const char *text)
{
    sgl_label_t *label = container_of(obj, sgl_label_t, obj);
    label->text = text;
}

void sgl_label_set_icon(sgl_obj_t *obj, sgl_icon_t *icon)
{
    sgl_label_t *label = container_of(obj, sgl_label_t, obj);
    label->icon = icon;
}

void sgl_label_set_text_align(sgl_obj_t *obj, sgl_align_type_e align)
{
    sgl_label_t *label = container_of(obj, sgl_label_t, obj);
    label->align = align;
}


void sgl_label_draw(sgl_obj_t* obj)
{
    sgl_label_t *label = container_of(obj, sgl_label_t, obj);
    sgl_size_t _size;
    sgl_pos_t pos;
    sgl_widget_draw_rect(rect);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_widget_buffer_valid(obj);
    if (bg_img == NULL){        
        if(obj->style.radius) {
            sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style.body_color);
            sgl_draw_round_rect_solid(surf, rect, obj->style.radius, obj->style.body_color, obj->parent->style.body_color);
        }
        else {
            sgl_draw_obj_buffer_clear(surf, obj, obj->style.body_color);
        }
    }
    else{
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->style.bg_img);
    }
    if(obj->hide) return;
    if(label->icon) {
        if(label->text == NULL || label->font == NULL) {
            _size.w = label->icon->width;
            _size.h = label->icon->height;
            pos = sgl_get_align_pos(&obj->size, &_size, label->align);
            pos.x = sgl_widget_draw_ofs_x(pos.x);
            pos.y = sgl_widget_draw_ofs_y(pos.y);
            if (bg_img == NULL){
                sgl_draw_icon(surf, pos.x, pos.y, obj->style.text_color, obj->style.body_color, label->icon);
            }
            else{
                sgl_draw_icon_on_bg(surf, pos.x, pos.y, obj->style.text_color, label->icon);
            }
        }
        else {
            _size.w = (sgl_text_width(label->font, label->text) + label->icon->width + 4);
            _size.h = label->icon->height;
            pos = sgl_get_align_pos(&obj->size, &_size, label->align);
            pos.x = sgl_widget_draw_ofs_x(pos.x);
            pos.y = sgl_widget_draw_ofs_y(pos.y);
            if (bg_img == NULL){
                sgl_draw_icon(surf, pos.x, pos.y, obj->style.text_color, obj->style.body_color, label->icon);
            }
            else{
                sgl_draw_icon_on_bg(surf, pos.x, pos.y, obj->style.text_color, label->icon);
            }           
            _size.h = sgl_text_height(label->font);
            pos = sgl_get_align_pos(&obj->size, &_size, label->align);
            pos.x = sgl_widget_draw_ofs_x(pos.x);
            pos.y = sgl_widget_draw_ofs_y(pos.y);
            if(bg_img == NULL) {
                sgl_draw_font_string(surf, pos.x + label->icon->width + 4, pos.y, label->text, obj->style.text_color, obj->style.body_color, label->font);
            }else {
                sgl_draw_font_string_on_bg(surf, pos.x + label->icon->width + 4, pos.y, label->text, obj->style.text_color, label->font);
            }            
        }
    }
    else {
        if(label->text && label->font) {
            _size.w = sgl_text_width(label->font, label->text);
            _size.h = sgl_text_height(label->font);
            pos = sgl_get_align_pos(&obj->size, &_size, label->align);
            pos.x = sgl_widget_draw_ofs_x(pos.x);
            pos.y = sgl_widget_draw_ofs_y(pos.y);
            if(bg_img == NULL) {
                sgl_draw_font_string(surf, pos.x, pos.y, label->text, obj->style.text_color, obj->style.body_color, label->font); 
            }else {
                sgl_draw_font_string_on_bg(surf, pos.x, pos.y, label->text, obj->style.text_color, label->font);                
            }            
        }
    }
    sgl_draw_obj_selected(obj, surf, rect, obj->style.body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}

void sgl_label_event_cb(sgl_obj_t* obj)
{
    sgl_obj_event_cb(obj);
    sgl_label_draw(obj);
}
