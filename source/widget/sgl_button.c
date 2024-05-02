/* source/widget/sgl_button.c
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

#include "./sgl_button.h"
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

static void sgl_button_event_cb(sgl_obj_t *obj);

int sgl_button_init(sgl_button_t *button, sgl_obj_t* parent)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    button->text = NULL;
    button->icon = NULL;
    button->font = NULL;
    obj = &button->obj;
    obj->parent = parent;
    obj->dirty = 1;
    obj->selected = 0;
    obj->hide = 0;
    obj->draw_cb = sgl_button_event_cb;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_button_create(sgl_obj_t* parent)
{
    int ret;
    sgl_button_t *button;
    if(parent == NULL) {
        return NULL;
    }
    button = (sgl_button_t *)sgl_malloc(sizeof(sgl_button_t));
    if(button == NULL)
        return NULL;
    ret = sgl_button_init(button, parent);
    if(ret) {
        return NULL;
    }
    return  &button->obj;
}

//TODO
void sgl_button_delete(sgl_obj_t* obj)
{

}

void sgl_button_set_toggle_color(sgl_obj_t *obj, sgl_color_t color)
{
    sgl_button_t *button = container_of(obj, sgl_button_t, obj);
    button->toggle_color = color;
}

void sgl_button_set_toggle_img(sgl_obj_t *obj, sgl_img_t *img)
{
    sgl_button_t *button = container_of(obj, sgl_button_t, obj);
    button->toggle_img = img;
}

void sgl_button_set_font(sgl_obj_t *obj, sgl_font_t *font)
{
    sgl_button_t *button = container_of(obj, sgl_button_t, obj);
    button->font = font;
}

void sgl_button_set_text(sgl_obj_t *obj, const char *text)
{
    sgl_button_t *button = container_of(obj, sgl_button_t, obj);
    button->text = text;  
}

void sgl_button_set_icon(sgl_obj_t *obj, sgl_icon_t *icon)
{
    sgl_button_t *button = container_of(obj, sgl_button_t, obj);
    button->icon = icon;
}

static void sgl_button_draw(sgl_obj_t* obj)
{
    sgl_widget_draw_rect(rect);
    int _start_x = 0, _start_y = 0;
    sgl_color_t _color;
    sgl_button_t *button = container_of(obj, sgl_button_t, obj);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_img_t *obj_img = obj->bg_img;
    sgl_widget_buffer_valid(obj);
    if(bg_img == NULL) {
        sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style->body_color);
    }
    else {
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->bg_img);
    }
    if(obj->hide) return;
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        if(bg_img == NULL) {
            if(button->toggle_img) {
                sgl_draw_round_rect_img(surf, rect, obj->style->radius, obj->parent->style->body_color, button->toggle_img);
            }
            else {
                sgl_draw_round_rect_solid(surf, rect, obj->style->radius, button->toggle_color, obj->parent->style->body_color);
            }
        }
        else{
            if(button->toggle_img) {
                sgl_draw_round_rect_img_on_bg(surf, rect, obj->style->radius, button->toggle_img);
            }
            else {
                sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style->radius, button->toggle_color);
            }
        }
        _color = button->toggle_color;
    }
    else if(obj->ev_stat == SGL_EVENT_RELEASED || obj->ev_stat == SGL_EVENT_NORMAL || obj->ev_stat == SGL_EVENT_FORCE_DRAW) {
        if(bg_img == NULL) {
            if(obj_img) {
                sgl_draw_round_rect_img(surf, rect, obj->style->radius, obj->parent->style->body_color, obj_img);
            }
            else {
                sgl_draw_round_rect_solid(surf, rect, obj->style->radius, obj->style->body_color, obj->parent->style->body_color);
            }
        }
        else{
            if(obj_img) {
                sgl_draw_round_rect_img_on_bg(surf, rect, obj->style->radius, obj_img);
            }
            else {
                sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style->radius, obj->style->body_color);
            }
        }
        _color = obj->style->body_color;
    }
    else {
        //TODO: add other event type
    }
    if(button->icon) {
        if(button->text == NULL || button->font == NULL) {
            _start_x = sgl_widget_draw_ofs_x((obj->size.w - button->icon->width)/2);
            _start_y = sgl_widget_draw_ofs_y((obj->size.h - button->icon->height)/2);
            if(bg_img == NULL)
                sgl_draw_icon(surf, _start_x, _start_y, obj->style->text_color, _color, button->icon);
            else
                sgl_draw_icon_on_bg(surf, _start_x, _start_y, obj->style->text_color, button->icon);
        }
        else {
            int text_width = sgl_text_width(button->font, button->text) + 4;
            _start_x = sgl_widget_draw_ofs_x((obj->size.w - button->icon->width - text_width)/2);
            _start_y = sgl_widget_draw_ofs_y((obj->size.h - button->icon->height)/2);
            sgl_draw_icon(surf, _start_x, _start_y, obj->style->text_color, _color, button->icon);
            _start_y = sgl_widget_draw_ofs_y((obj->size.h - sgl_text_height(button->font))/2);
            if(bg_img == NULL)
                sgl_draw_font_string(surf, _start_x + button->icon->width + 4, _start_y, button->text, obj->style->text_color, _color, button->font);
            else
                sgl_draw_font_string_on_bg(surf, _start_x + button->icon->width + 4, _start_y, button->text, obj->style->text_color, button->font);
        }
    }
    else {
        if(button->text && button->font) {
            int text_width = sgl_text_width(button->font, button->text);
            _start_x = sgl_widget_draw_ofs_x((obj->size.w - text_width)/2);
            _start_y = sgl_widget_draw_ofs_y((obj->size.h - sgl_text_height(button->font))/2);
            if(bg_img == NULL)
                sgl_draw_font_string(surf, _start_x, _start_y, button->text, obj->style->text_color, _color, button->font);
            else
                sgl_draw_font_string_on_bg(surf, _start_x, _start_y, button->text, obj->style->text_color, button->font);
        }
    }
    sgl_draw_obj_selected(obj, surf, rect, obj->style->body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}


static void sgl_button_event_cb(sgl_obj_t *obj)
{
    sgl_obj_event_cb(obj);
    sgl_button_draw(obj);
}
