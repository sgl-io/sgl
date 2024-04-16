/* source/widget/sgl_switch.c
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

#include "stdio.h"
#include "./sgl_switch.h"
#include "../draw/sgl_draw_icon.h"
#include "../draw/sgl_draw_font.h"


int sgl_switch_init(sgl_switch_t *sw_btn, sgl_obj_t* parent, bool status)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    sw_btn->status = status;
    obj = &sw_btn->obj;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    obj->parent = parent;
    obj->selected = 0;
    obj->hide = 0;
    obj->obj_type = SGL_OBJ_SWITCH;
    sgl_page_add_obj(parent, obj);
    sgl_page_add_dirty_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_switch_create(sgl_obj_t* parent, bool status)
{
    int ret;
    sgl_switch_t *sw_btn;
    if(parent == NULL) {
        return NULL;
    }
    sw_btn = (sgl_switch_t *)sgl_alloc(sizeof(sgl_switch_t));
    if(sw_btn == NULL)
        return NULL;
    
    ret = sgl_switch_init(sw_btn, parent, status);
    if(ret) {
        return NULL;
    }
    return  &sw_btn->obj;
}


void sgl_switch_set_toggle_color(sgl_obj_t *obj, sgl_color_t color)
{
    sgl_switch_t *sw = container_of(obj, sgl_switch_t, obj);
    sw->toggle_color = color;
}


void sgl_switch_draw(sgl_obj_t* obj)
{
    sgl_widget_draw_rect(rect);
    sgl_widget_buffer_valid(obj);
    sgl_switch_t *sw_btn = container_of(obj, sgl_switch_t, obj);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_color_t dot_color;
    int toggle_w = obj->size.h - 2;
    sgl_widget_buffer_valid(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    if(bg_img == NULL)
        sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style.body_color);
    else
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->style.bg_img);
    if(obj->hide) return;
    if(obj->style.radius != 0) {
        if(sw_btn->status) {
            dot_color = sgl_color_mixer(obj->style.body_color, obj->parent->style.body_color, 128);
            if(bg_img == NULL)
                sgl_draw_round_rect_solid(surf, rect, obj->style.radius, obj->style.body_color, obj->parent->style.body_color);
            else
                sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style.radius, obj->style.body_color);
            rect.x1 = rect.x2 - toggle_w; 
            rect.x2 = rect.x2 - 2; 
            rect.y1 += 2;
            rect.y2 -= 2;
            sgl_draw_round_rect_solid(surf, rect, obj->style.radius - 2, dot_color, obj->style.body_color);
        }
        else {
            dot_color = sgl_color_mixer(sw_btn->toggle_color, obj->parent->style.body_color, 128);
            if(bg_img == NULL)
                sgl_draw_round_rect_solid(surf, rect, obj->style.radius, sw_btn->toggle_color, obj->parent->style.body_color);
            else
                sgl_draw_round_rect_solid_on_bg(surf, rect, obj->style.radius, sw_btn->toggle_color);
            rect.x1 +=2; 
            rect.x2 = rect.x1 + toggle_w - 2; 
            rect.y1 += 2;
            rect.y2 -= 2;
            sgl_draw_round_rect_solid(surf, rect, obj->style.radius - 2, dot_color, sw_btn->toggle_color);
        }
    }
    else {
        if(sw_btn->status) {
            dot_color = sgl_color_mixer(obj->style.body_color, obj->parent->style.body_color, 128);
            sgl_draw_rect_solid(surf, rect, obj->style.body_color);
            rect.x1 = rect.x2 - toggle_w; 
            rect.x2 = rect.x2 - 2; 
            rect.y1 += 2; 
            rect.y2 -= 2;
            sgl_draw_rect_solid(surf, rect, dot_color);
        }
        else {
            dot_color = sgl_color_mixer(sw_btn->toggle_color, obj->parent->style.body_color, 128);
            sgl_draw_rect_solid(surf, rect, sw_btn->toggle_color);
            rect.x1 +=2; 
            rect.x2 = rect.x1 + toggle_w; 
            rect.y1 += 2; 
            rect.y2 -= 2;
            sgl_draw_rect_solid(surf, rect, dot_color);
        }
    }
    sgl_draw_obj_selected(obj, surf, rect, obj->style.body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}

void sgl_switch_set_status(sgl_obj_t *obj, bool status)
{
    sgl_switch_t *sw_btn = container_of(obj, sgl_switch_t, obj);
    sw_btn->status = status;
}


bool sgl_switch_get_status(sgl_obj_t* obj)
{
    sgl_switch_t *sw_btn = container_of(obj, sgl_switch_t, obj);
    return sw_btn->status;
}

void sgl_switch_event_cb(sgl_obj_t *obj)
{
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        sgl_switch_t *sw_btn = container_of(obj, sgl_switch_t, obj);
        sw_btn->status = !sw_btn->status;
        sgl_obj_event_cb(obj);
        sgl_switch_draw(obj);
    }
    else if(obj->ev_stat == SGL_EVENT_FORCE_DRAW) {
        sgl_switch_draw(obj);
    }
}
