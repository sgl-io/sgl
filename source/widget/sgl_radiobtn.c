/* source/widget/sgl_radiobtn.c
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

#include "./sgl_radiobtn.h"
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


static void sgl_radiobtn_event_cb(sgl_obj_t *obj);

int sgl_radiobtn_init(sgl_radiobtn_t *radiobtn, sgl_obj_t* parent, bool status)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    radiobtn->text = NULL;
    radiobtn->font = NULL;
    obj = &radiobtn->obj;
    obj->parent = parent;
    obj->dirty = 1;
    obj->selected = 0;
    obj->hide = 0;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    obj->draw_cb = sgl_radiobtn_event_cb;
    sgl_page_add_obj(parent, obj);
    return 0;    
}

sgl_obj_t* sgl_radiobtn_create(sgl_obj_t* parent, bool status)
{
    int ret;
    sgl_radiobtn_t *radiobtn;
    if(parent == NULL) {
        return NULL;
    }
    radiobtn = (sgl_radiobtn_t *)sgl_malloc(sizeof(sgl_radiobtn_t));
    if(radiobtn == NULL)
        return NULL;
    ret = sgl_radiobtn_init(radiobtn, parent, status);
    if(ret) {
        return NULL;
    }
    return  &radiobtn->obj;
}

void sgl_radiobtn_set_status(sgl_obj_t *obj, bool status)
{
    sgl_radiobtn_t *radiobtn = container_of(obj, sgl_radiobtn_t, obj);
    if(status != radiobtn->status) {
        radiobtn->status = status;
        obj->dirty = 1;
    }
}

bool sgl_radiobtn_get_status(sgl_obj_t *obj)
{
    sgl_radiobtn_t *radiobtn = container_of(obj, sgl_radiobtn_t, obj);
    return radiobtn->status;
}

void sgl_radiobtn_click(sgl_obj_t *obj)
{
    sgl_obj_set_event_status(obj, SGL_EVENT_PRESSED);
    obj->dirty = 1;
}

void sgl_radiobtn_set_font(sgl_obj_t *obj, sgl_font_t *font)
{
    sgl_radiobtn_t *radiobtn = container_of(obj, sgl_radiobtn_t, obj);
    radiobtn->font = font;
}

void sgl_radiobtn_set_text(sgl_obj_t *obj, const char* text)
{
    sgl_radiobtn_t *radiobtn = container_of(obj, sgl_radiobtn_t, obj);
    radiobtn->text = text;
}

static void sgl_radiobtn_draw(sgl_obj_t *obj)
{
    int r = obj->size.h / 2;
    int weight = obj->size.h / 6;
    int pos_x, pos_y;
    sgl_radiobtn_t *radiobtn = container_of(obj, sgl_radiobtn_t, obj);
    sgl_widget_draw_rect(rect);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_widget_buffer_valid(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    if(bg_img == NULL)
        sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style->body_color);
    else
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->bg_img);
    if(obj->hide) return;
    pos_x = sgl_widget_draw_ofs_x(r);
    pos_y = sgl_widget_draw_ofs_y(r);
    if(bg_img == NULL)
        sgl_draw_circle_solid(surf, pos_x, pos_y, r-1, obj->style->body_color, obj->parent->style->body_color);
    else
        sgl_draw_circle_solid_on_bg(surf, pos_x, pos_y, r - 1, obj->style->body_color);
    sgl_draw_circle_solid(surf, pos_x, pos_y, r - weight, obj->parent->style->body_color, obj->style->body_color);
    if(radiobtn->status) {
        sgl_draw_circle_solid(surf, pos_x, pos_y, r - weight * 2-1, obj->style->body_color, obj->parent->style->body_color);
    }
    if(radiobtn->text && radiobtn->font) {
        pos_x = sgl_widget_draw_ofs_x(obj->size.h + 2);
        pos_y = sgl_widget_draw_ofs_y((obj->size.h - sgl_text_height(radiobtn->font))/2) - 1;
        if(bg_img == NULL)
            sgl_draw_font_string(surf, pos_x, pos_y, radiobtn->text, obj->style->text_color, obj->parent->style->body_color, radiobtn->font); 
        else
            sgl_draw_font_string_on_bg(surf, pos_x, pos_y, radiobtn->text, obj->style->text_color, radiobtn->font); 
    }
    sgl_draw_obj_selected(obj, surf, rect, obj->style->body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}


static void sgl_radiobtn_event_cb(sgl_obj_t *obj)
{
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        sgl_radiobtn_t *radiobtn = container_of(obj, sgl_radiobtn_t, obj);
        radiobtn->status = !radiobtn->status;
        sgl_obj_event_cb(obj);
        sgl_radiobtn_draw(obj);
    }
    else if(obj->ev_stat == SGL_EVENT_FORCE_DRAW){
        sgl_radiobtn_draw(obj);
    }
}
