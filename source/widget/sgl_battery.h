/* source/widget/sgl_battery.h
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

#ifndef __SGL_BATTERY_H__
#define __SGL_BATTERY_H__

#include "../core/sgl_core.h"
#include "../sgl.h"
#include "../draw/sgl_draw_rect.h"
#include "../draw/sgl_draw_circle.h"


typedef struct sgl_battery {
    sgl_obj_t   obj;
    sgl_color_t empty;
    uint8_t     quantity;
    uint8_t     border_w;

}sgl_battery_t;


int sgl_battery_init(sgl_battery_t *battery, sgl_obj_t* parent, uint8_t quantity);
sgl_obj_t* sgl_battery_create(sgl_obj_t* parent, uint8_t quantity);
void sgl_battery_set_quantity(sgl_obj_t* obj, uint8_t quantity);
void sgl_battery_set_empty_color(sgl_obj_t* obj, sgl_color_t color);
void sgl_battery_set_border_weight(sgl_obj_t* obj, uint8_t weight);
void sgl_battery_draw(sgl_obj_t* obj);

#endif //__SGL_BATTERY_H__
