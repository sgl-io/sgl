/* source/core/sgl_obj.c
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

#include "./sgl_core.h"
#include <string.h>
#include "../sgl.h"
#include "stdio.h"

void sgl_obj_set_pos(sgl_obj_t *obj, int16_t x, int16_t y)
{
    obj->pos.x = obj->parent->pos.x + x;
    obj->pos.y = obj->parent->pos.y + y;
}

sgl_pos_t sgl_obj_get_pos(sgl_obj_t *obj)
{
    return obj->pos;
}

void sgl_obj_set_pos_x(sgl_obj_t *obj, int16_t x)
{
    obj->pos.x = obj->parent->pos.x + x;
}

int16_t sgl_obj_get_pos_x(sgl_obj_t *obj)
{
    return obj->pos.x;
}

void sgl_obj_set_pos_y(sgl_obj_t *obj, int16_t y)
{
    obj->pos.y = obj->parent->pos.y + y;
}

int16_t sgl_obj_get_pos_y(sgl_obj_t *obj)
{
    return obj->pos.y;
}

void sgl_obj_set_size(sgl_obj_t *obj, int16_t width, int16_t height)
{
    obj->size.w = width;
    obj->size.h = height;
}

void sgl_obj_set_size_w(sgl_obj_t *obj, int16_t width)
{
    obj->size.w = width;
}

void sgl_obj_set_size_h(sgl_obj_t *obj, int16_t height)
{
    obj->size.h = height;
}

void sgl_obj_set_style(sgl_obj_t *obj, sgl_style_t style)
{
    obj->style = style;
}

void sgl_obj_set_body_color(sgl_obj_t *obj, sgl_color_t color)
{
    obj->style.body_color = color;
}

void sgl_obj_set_text_color(sgl_obj_t *obj, sgl_color_t color)
{
    obj->style.text_color = color;
}

void sgl_obj_set_radius(sgl_obj_t *obj, int radius)
{
    obj->style.radius = radius;
}

void sgl_obj_set_bgimg(sgl_obj_t *obj, sgl_img_t *bg)
{
    obj->style.bg_img = bg;
}

sgl_img_t* sgl_obj_get_bgimg(sgl_obj_t *obj)
{
    return obj->style.bg_img;
}

void sgl_obj_set_parent(sgl_obj_t *obj, sgl_obj_t *parent)
{
    obj->parent = parent;
}

sgl_pos_t sgl_get_align_pos(sgl_size_t *parent_size, sgl_size_t *size, sgl_align_type_e type)
{
    sgl_pos_t ret = {.x = 0, .y = 0};
    switch(type) {                
        case SGL_ALIGN_TOP_MID:          
            ret.x = (parent_size->w - size->w)/2;
            ret.y = 0;
        break;

        case SGL_ALIGN_TOP_LEFT:
            ret.x = 0;
            ret.y = 0;
        break; 
            
        case SGL_ALIGN_TOP_RIGHT:    
            ret.x = parent_size->w - size->w;
            ret.y = 0;
        break;

        case SGL_ALIGN_CENTER_MID:
            ret.x = (parent_size->w - size->w)/2;
            ret.y = (parent_size->h - size->h)/2;
        break;
        
        case SGL_ALIGN_CENTER_LEFT:
            ret.x = 0;
            ret.y = (parent_size->h - size->h)/2;
        break;

        case SGL_ALIGN_CENTER_RIGHT:
            ret.x = parent_size->w - size->w ;
            ret.y = (parent_size->h - size->h)/2;
        break;

        case SGL_ALIGN_BOT_LEFT:
            ret.x = 0;
            ret.y = parent_size->h - size->h;
        break;

        case SGL_ALIGN_BOT_MID:
            ret.x = (parent_size->w - size->w)/2;
            ret.y = parent_size->h - size->h;
        break;

        case SGL_ALIGN_BOT_RIGHT:
            ret.x = parent_size->w - size->w;
            ret.y = parent_size->h - size->h;
        break;

        case SGL_ALIGN_TOP: 
            ret.y = 0;
        break;
        case SGL_ALIGN_CENTER: 
            ret.y = (parent_size->h - size->h)/2;
        break;
        case SGL_ALIGN_BOT: 
            ret.y = parent_size->h - size->h;
        break;
        case SGL_ALIGN_LEFT: 
            ret.x = 0;
        break;
        case SGL_ALIGN_MID: 
            ret.x = (parent_size->w - size->w)/2;
        break;
        case SGL_ALIGN_RIGHT: 
            ret.x = parent_size->w - size->w; 
        break;
        default: break;
    }
    return ret;
}

void sgl_obj_set_align(sgl_obj_t *obj, sgl_align_type_e type)
{
    sgl_obj_t *parent_obj = obj->parent;
    sgl_pos_t pos = sgl_get_align_pos(&parent_obj->size, &obj->size, type);
    obj->pos.x = pos.x + parent_obj->pos.x;
    obj->pos.y = pos.y + parent_obj->pos.y;
}

void sgl_obj_set_event_cb(sgl_obj_t *obj, void (*event)(sgl_obj_t *, void *), void *data)
{
    obj->event_fn = event;
    obj->event_data = data;
}

void sgl_obj_event_cb(sgl_obj_t *obj)
{
    if(obj->event_fn) {
        obj->event_fn(obj, obj->event_data);
    }
}

void sgl_obj_set_event_status(sgl_obj_t *obj, sgl_event_type_e status)
{
    obj->ev_stat = status;
}

sgl_event_type_e sgl_obj_get_event_status(sgl_obj_t *obj)
{
    return obj->ev_stat;
}

bool sgl_obj_draw_valid(sgl_obj_t *obj)
{
    int __buffer_size = sgl_get_device_panel()->buffer_size / sizeof(sgl_color_t);
    if(obj->size.w * obj->size.h > __buffer_size)
        return false;
    else
        return true;
}

bool sgl_obj_event_active(sgl_obj_t* obj, int x, int y)
{
    if((x > (obj->pos.x + obj->size.w)) || (x < obj->pos.x) 
            || (y > (obj->pos.y + obj->size.h)) || (y < obj->pos.y)
    ) {
        return false;
    }
    else {
        return true;
    }
}

void sgl_obj_set_selected(sgl_obj_t* obj, bool status)
{
    if(status != obj->selected) {
        obj->selected = status;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

void sgl_obj_set_hide(sgl_obj_t* obj, bool status)
{
    if(status != obj->hide) {
        obj->hide = status;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

void sgl_obj_set_alpha(sgl_obj_t* obj, uint8_t alpha)
{
    if(alpha != obj->alpha) {
        obj->alpha = alpha;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

void sgl_obj_event_click(sgl_obj_t *obj)
{
    if(obj->ev_stat != SGL_EVENT_PRESSED){
        obj->ev_stat = SGL_EVENT_PRESSED;
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

void sgl_obj_event_press(sgl_obj_t *obj)
{
    if(obj->ev_stat != SGL_EVENT_PRESSED){
        obj->ev_stat = SGL_EVENT_PRESSED;
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

void sgl_obj_event_release(sgl_obj_t *obj)
{
    if(obj->ev_stat != SGL_EVENT_RELEASED) {
        obj->ev_stat = SGL_EVENT_RELEASED;
        sgl_page_add_dirty_obj(obj->parent, obj);
    }
}

extern void sgl_anim_init_active_list(void);

int sgl_init()
{
    sgl_anim_init_active_list();
    //TODO: other initialize
    return 0;
}
