/* source/widget/sgl_checkbox.c
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

#include "./sgl_checkbox.h"
#include "./sgl_obj.h"
#include "./sgl_page.h"
#include "./sgl_device.h"
#include "./sgl_task.h"
#include "../libs/sgl_mem.h"
#include "../libs/sgl_string.h"
#include "../draw/sgl_draw.h"
#include "../draw/sgl_draw_rect.h"
#include "../draw/sgl_draw_font.h"

static void sgl_checkbox_event_cb(sgl_obj_t *obj);

int sgl_checkbox_init(sgl_checkbox_t *checkbox, sgl_obj_t* parent, bool status)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    checkbox->text = NULL;
    checkbox->font = NULL;
    obj = &checkbox->obj;
    obj->parent = parent;
    obj->dirty = 1;
    obj->selected = 0;
    obj->hide = 0;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    obj->draw_cb = sgl_checkbox_event_cb;
    sgl_page_add_obj(parent, obj);
    return 0;    
}

sgl_obj_t* sgl_checkbox_create(sgl_obj_t* parent, bool status)
{
    int ret;
    sgl_checkbox_t *checkbox;
    if(parent == NULL) {
        return NULL;
    }
    checkbox = (sgl_checkbox_t *)sgl_malloc(sizeof(sgl_checkbox_t));
    if(checkbox == NULL)
        return NULL;
    ret = sgl_checkbox_init(checkbox, parent, status);
    if(ret) {
        return NULL;
    }
    return  &checkbox->obj;
}

void sgl_checkbox_set_status(sgl_obj_t *obj, bool status)
{
    sgl_checkbox_t *checkbox = container_of(obj, sgl_checkbox_t, obj);
    if(status != checkbox->status) {
        checkbox->status = status;
        obj->dirty = 1;
    }
}

bool sgl_checkbox_get_status(sgl_obj_t *obj)
{
    sgl_checkbox_t *checkbox = container_of(obj, sgl_checkbox_t, obj);
    return checkbox->status;
}


void sgl_checkbox_set_font(sgl_obj_t *obj, sgl_font_t *font)
{
    sgl_checkbox_t *checkbox = container_of(obj, sgl_checkbox_t, obj);
    checkbox->font = font;
}

void sgl_checkbox_set_text(sgl_obj_t *obj, const char* text)
{
    sgl_checkbox_t *checkbox = container_of(obj, sgl_checkbox_t, obj);
    checkbox->text = text;
}

static void sgl_checkbox_draw(sgl_obj_t *obj)
{
    int _start_y = 0;
    int weight = obj->size.h / 6;
    sgl_checkbox_t *checkbox = container_of(obj, sgl_checkbox_t, obj);
    sgl_widget_draw_rect(rect);
    sgl_widget_buffer_valid(obj);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style->body_color);
    rect.x2 = rect.x1 + obj->size.h;
    if(bg_img == NULL)
        sgl_draw_rect_solid(surf, rect, obj->style->body_color);
    else
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->bg_img);
    if(obj->hide) return;
    rect.x1 = sgl_widget_draw_ofs_x(weight);
    rect.x2 = sgl_widget_draw_ofs_x(obj->size.h - weight);
    rect.y1 = sgl_widget_draw_ofs_y(weight);
    rect.y2 = sgl_widget_draw_ofs_y(obj->size.h - weight);
    sgl_draw_rect_solid(surf, rect, obj->parent->style->body_color);
    if(checkbox->status) {
        rect.x1 = sgl_widget_draw_ofs_x(weight * 2);
        rect.x2 = sgl_widget_draw_ofs_x(obj->size.h - weight * 2);
        rect.y1 = sgl_widget_draw_ofs_y(weight * 2);
        rect.y2 = sgl_widget_draw_ofs_y(obj->size.h - weight * 2);
        sgl_draw_rect_solid(surf, rect, obj->style->body_color);
    }
    if(checkbox->text && checkbox->font) {
        _start_y = sgl_widget_draw_ofs_y((obj->size.h - sgl_text_height(checkbox->font))/2) - 1;
        if(bg_img == NULL)
            sgl_draw_font_string(surf, 
                                sgl_widget_draw_ofs_x(obj->size.h + 2), 
                                _start_y, 
                                checkbox->text, 
                                obj->style->text_color, 
                                obj->parent->style->body_color, 
                                checkbox->font
                                );
        else
            sgl_draw_font_string_on_bg(surf, 
                                sgl_widget_draw_ofs_x(obj->size.h + 2), 
                                _start_y, 
                                checkbox->text, 
                                obj->style->text_color, 
                                checkbox->font
                                );
    }
    sgl_draw_obj_selected(obj, surf, rect, obj->style->body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}


static void sgl_checkbox_event_cb(sgl_obj_t *obj)
{
    sgl_checkbox_t *checkbox = container_of(obj, sgl_checkbox_t, obj);
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        checkbox->status = !checkbox->status;
        sgl_obj_event_cb(obj);
    }
    sgl_checkbox_draw(obj);
}
