/* source/widget/sgl_battery.c
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

#include "./sgl_battery.h"

int sgl_battery_init(sgl_battery_t *battery, sgl_obj_t* parent, uint8_t quantity)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    battery->empty = SGL_WHITE;
    battery->quantity = quantity;
    battery->border_w = 3;
    obj = &battery->obj;
    obj->parent = parent;
    obj->selected = 0;
    obj->hide = 0;
    obj->obj_type = SGL_OBJ_BATTERY;
    sgl_page_add_obj(parent, obj);
    sgl_page_add_dirty_obj(parent, obj);
    return 0;
}

sgl_obj_t* sgl_battery_create(sgl_obj_t* parent, uint8_t quantity)
{
    int ret;
    sgl_battery_t *battery;
    if(parent == NULL) {
        return NULL;
    }
    battery = (sgl_battery_t *)sgl_alloc(sizeof(sgl_battery_t));
    if(battery == NULL)
        return NULL;
    ret = sgl_battery_init(battery, parent, quantity);
    if(ret) {
        return NULL;
    }
    return  &battery->obj;
}

void sgl_battery_set_quantity(sgl_obj_t* obj, uint8_t quantity)
{
    sgl_battery_t *battery = container_of(obj, sgl_battery_t, obj);
    if(quantity > 100) {
        quantity = 100;
    }
    battery->quantity = quantity;
}

void sgl_battery_set_empty_color(sgl_obj_t* obj, sgl_color_t color)
{
    sgl_battery_t *battery = container_of(obj, sgl_battery_t, obj);
    battery->empty = color;
}

void sgl_battery_set_border_weight(sgl_obj_t* obj, uint8_t weight)
{
    sgl_battery_t *battery = container_of(obj, sgl_battery_t, obj);
    battery->border_w = weight;
}

void sgl_battery_draw(sgl_obj_t* obj)
{
    sgl_battery_t *battery = container_of(obj, sgl_battery_t, obj);
    int16_t hat = battery->border_w;
    int16_t hat_w = obj->size.w / 4;
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_widget_draw_rect(rect);
    sgl_rect_t hat_rect;
    hat_rect.x1 = sgl_widget_draw_ofs_x(hat_w);
    hat_rect.x2 = sgl_widget_draw_ofs_x(obj->size.w - hat_w);
    hat_rect.y1 = sgl_widget_draw_ofs_y(0);
    hat_rect.y2 = sgl_widget_draw_ofs_y(hat);
    sgl_widget_buffer_valid(obj);
    rect.y1 += hat;
    sgl_draw_buffer_clear(surf, obj->parent->style.body_color);
    int height = (obj->size.h - hat * 2 - battery->border_w * 2) * (100 - battery->quantity) / 100;
    if(obj->style.radius == 0) {
        sgl_draw_rect_solid(surf, rect, obj->style.text_color);
    }
    else {
        sgl_draw_round_rect_solid(surf, rect, obj->style.radius, obj->style.text_color, obj->parent->style.body_color);
    }
    sgl_draw_rect_solid(surf, hat_rect, obj->style.text_color);
    rect.x1 = sgl_widget_draw_ofs_x(battery->border_w);
    rect.x2 = sgl_widget_draw_ofs_x(obj->size.w - battery->border_w);
    rect.y1 = sgl_widget_draw_ofs_y(battery->border_w + hat); 
    rect.y2 = rect.y1 + height;
    sgl_draw_rect_solid(surf, rect, battery->empty);
    rect.y1 = rect.y2;
    rect.y2 = sgl_widget_draw_ofs_y(obj->size.h - battery->border_w);
    sgl_draw_rect_solid(surf, rect, obj->style.body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}

