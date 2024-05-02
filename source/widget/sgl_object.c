/* source/widget/sgl_object.c
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

#include "./sgl_object.h"
#include "./sgl_obj.h"
#include "./sgl_page.h"
#include "./sgl_device.h"
#include "./sgl_event.h"
#include "./sgl_task.h"
#include "../libs/sgl_mem.h"
#include "../libs/sgl_string.h"
#include "../draw/sgl_draw.h"
#include "../draw/sgl_draw_rect.h"
#include "../draw/sgl_draw_font.h"
#include "../draw/sgl_draw_circle.h"
#include "../draw/sgl_draw_icon.h"


/**
 * Draws a single circle object.
 *
 * This function handles drawing a circle on the specified graphical object,
 * considering background images and transparency.
 *
 * @param obj Pointer to the graphical object to draw. The object must be a circle or inherit from a circular object.
 */
static void sgl_circle_draw(sgl_obj_t* obj)
{
    // Retrieve the active drawing surface
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    int cx, cy, radius;
    // Attempt to get the background image
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    // Ensure the widget buffer is valid
    sgl_widget_buffer_valid(obj);

    // Calculate the circle's radius
    radius = obj->size.w / 2;
    // Calculate the circle center's drawing offset positions
    cx = sgl_widget_draw_ofs_x(obj->size.w / 2);
    cy = sgl_widget_draw_ofs_y(obj->size.w / 2);

    if(bg_img == NULL) {
        // If no background image, draw the circle directly on the surface
        sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style->body_color);
        if(obj->ev_stat == SGL_EVENT_FORCE_DRAW_CLEAR) {
            // If the event status requires forced clear drawing, return early
            return;
        }
        // Handle drawing for non-transparent and transparent circles
        if(!obj->alpha) {
            sgl_draw_circle_solid(surf,
                                cx, cy,
                                radius,
                                obj->style->body_color, obj->parent->style->body_color
                                );
        }
        else {
            // TODO: Support alpha value drawing
            sgl_draw_circle_solid(surf,
                                cx, cy,
                                radius,
                                obj->style->body_color, obj->parent->style->body_color
                                );
        }
    }
    else {
        // If a background image exists, pick it into the buffer first
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->bg_img);
        if(obj->ev_stat == SGL_EVENT_FORCE_DRAW_CLEAR) {
            // If the event status requires forced clear drawing, return early
            return;
        }
        // Draw non-transparent and transparent circles on the background image
        if(!obj->alpha) {
            sgl_draw_circle_solid_on_bg(surf,
                                    cx, cy,
                                    radius,
                                    obj->style->body_color
                                    );
        }
        else {
            sgl_draw_circle_solid_transp_on_bg(surf,
                                    cx, cy,
                                    radius,
                                    obj->style->body_color, obj->alpha
                                    );
        }
    }
    // Flush the drawing buffer to the target surface
    sgl_widget_draw_buffer_flush(obj, surf);
}


/**
 * @brief A callback function for handling circle objects in the Small Graphics Library (SGL).
 *
 * @param obj Pointer to the SGL object. This is a structure containing information about the circle, such as its position, size, and current event status.
 *
 * This function is triggered based on the event status of the circle object:
 * - If `obj->ev_stat` is `SGL_EVENT_PRESSED`, it indicates that the circle has been pressed or interacted with. In this case:
 *   - The `sgl_obj_event_cb` function is called to handle the general object event.
 *   - The `sgl_circle_draw` function is called to redraw the circle, reflecting the pressed state.
 * - If `obj->ev_stat` is `SGL_EVENT_FORCE_DRAW`, it means that the circle needs to be forcefully redrawn, regardless of user interaction. The `sgl_circle_draw` function is called to update the display.
 */
static void sgl_circle_cb(sgl_obj_t* obj)
{
    if (obj->ev_stat == SGL_EVENT_PRESSED) {
        sgl_obj_event_cb(obj);
        sgl_circle_draw(obj);
    }
    else if (obj->ev_stat == SGL_EVENT_FORCE_DRAW) {
        sgl_circle_draw(obj);
    }
}


int sgl_circle_init(sgl_obj_t* circle, sgl_obj_t* parent)
{
    if(parent == NULL) {
        return -1;
    }
    circle->parent = parent;
    circle->dirty = 1;
    circle->hide = 0;
    circle->alpha = 0;
    circle->draw_cb = sgl_circle_cb;
    circle->event_data = NULL;
    circle->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, circle);
    return 0;
}

sgl_obj_t* sgl_circle_create(sgl_obj_t* parent)
{
    int ret;
    sgl_obj_t* circle = (sgl_obj_t *)sgl_malloc(sizeof(sgl_obj_t));
    if(circle == NULL)
        return NULL;
    ret = sgl_circle_init(circle, parent);
    if(ret) {
        return NULL;
    }
    return circle;
}


static void sgl_rect_draw(sgl_obj_t* obj)
{
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_widget_draw_rect(rect);
    sgl_widget_buffer_valid(obj);

    if(bg_img == NULL) {
        sgl_draw_obj_buffer_clear(surf, obj, obj->parent->style->body_color);
        if(obj->ev_stat == SGL_EVENT_FORCE_DRAW_CLEAR) {
            return;
        }
        if(!obj->alpha) {
            if(obj->bg_img == NULL) {
                sgl_draw_round_rect_solid(surf,
                                rect,
                                obj->style->radius,
                                obj->style->body_color, obj->parent->style->body_color
                                );
            }
            else {
                sgl_draw_round_rect_img(surf,
                                rect,
                                obj->style->radius,
                                obj->parent->style->body_color, obj->bg_img
                                );
            }

        }
        else {
            if(obj->bg_img == NULL) {
                sgl_draw_round_rect_transp_on_bg(surf,
                                rect,
                                obj->style->radius,
                                obj->style->body_color, obj->alpha
                                );
            }
            else {
                sgl_draw_round_rect_img_transp_on_bg(surf,
                                rect,
                                obj->style->radius,
                                obj->bg_img, obj->alpha
                                );
            }
        }
    }
    else {
        sgl_draw_obj_buffer_pick_img(surf, obj, obj->parent->bg_img);
        if(obj->ev_stat == SGL_EVENT_FORCE_DRAW_CLEAR) {
            return;
        }
        if(!obj->alpha) {
            if(obj->bg_img == NULL) {
                sgl_draw_round_rect_solid_on_bg(surf,
                                rect,
                                obj->style->radius,
                                obj->style->body_color
                                );
            }
            else {
                sgl_draw_round_rect_img_on_bg(surf,
                                rect,
                                obj->style->radius,
                                obj->bg_img
                                );
            }

        }
        else {
            if(obj->bg_img == NULL) {
                sgl_draw_round_rect_transp_on_bg(surf,
                                rect,
                                obj->style->radius,
                                obj->style->body_color, obj->alpha
                                );
            }
            else {
                sgl_draw_round_rect_img_transp_on_bg(surf,
                                rect,
                                obj->style->radius,
                                obj->bg_img, obj->alpha
                                );
            }
        }
    }
    sgl_widget_draw_buffer_flush(obj, surf);
}

static void sgl_rect_cb(sgl_obj_t* obj)
{
    if(obj->ev_stat == SGL_EVENT_PRESSED) {
        sgl_obj_event_cb(obj);
        sgl_rect_draw(obj);
    }
    else if(obj->ev_stat == SGL_EVENT_FORCE_DRAW) {
        sgl_rect_draw(obj);
    }
}

int sgl_rect_init(sgl_obj_t* rect, sgl_obj_t* parent)
{
    if(parent == NULL) {
        return -1;
    }
    rect->parent = parent;
    rect->dirty = 1;
    rect->hide = 0;
    rect->alpha = 0;
    rect->draw_cb = sgl_rect_cb;
    rect->event_data = NULL;
    rect->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, rect);
    return 0;
}


sgl_obj_t* sgl_rect_create(sgl_obj_t* parent)
{
    int ret;
    sgl_obj_t* rect = (sgl_obj_t *)sgl_malloc(sizeof(sgl_obj_t));
    if(rect == NULL)
        return NULL;
    ret = sgl_rect_init(rect, parent);
    if(ret) {
        return NULL;
    }
    return rect;
}


static void sgl_hline_cb(sgl_obj_t* obj)
{
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_widget_buffer_valid(obj);
    sgl_draw_obj_buffer_clear(surf, obj, obj->style->body_color);
    sgl_widget_draw_buffer_flush(obj, surf);
}


int sgl_hline_init(sgl_obj_t* hline, sgl_obj_t* parent)
{
    if(parent == NULL) {
        return -1;
    }
    hline->parent = parent;
    hline->dirty = 1;
    hline->hide = 0;
    hline->alpha = 0;
    hline->draw_cb = sgl_hline_cb;
    hline->event_data = NULL;
    hline->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, hline);
    return 0;
}


sgl_obj_t* sgl_hline_create(sgl_obj_t* parent)
{
    int ret;
    sgl_obj_t* hline = (sgl_obj_t *)sgl_malloc(sizeof(sgl_obj_t));
    if(hline == NULL)
        return NULL;
    ret = sgl_hline_init(hline, parent);
    if(ret) {
        return NULL;
    }
    return hline;
}


static void sgl_string_cb(sgl_obj_t* obj)
{
    sgl_string_t *string = container_of(obj, sgl_string_t, obj);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_img_t *bg_img = sgl_obj_get_bgimg(obj->parent);
    sgl_size_t _size;
    sgl_pos_t pos;
    //sgl_widget_draw_rect(rect);
    if(sgl_draw_obj_valid(obj)) {
        _size.w = sgl_text_width(string->font, string->text);
        _size.h = sgl_text_height(string->font);
        pos = sgl_get_align_pos(&obj->size, &_size, string->align);
        pos.x = sgl_widget_draw_ofs_x(pos.x);
        pos.y = sgl_widget_draw_ofs_y(pos.y);
        if(bg_img) {
            sgl_draw_font_string_on_bg(surf, pos.x, pos.y, string->text, obj->style->body_color, string->font);
        }
        else {
            sgl_draw_font_string(surf, pos.x, pos.y, string->text, obj->style->body_color, obj->parent->style->body_color, string->font);
        }
        sgl_widget_draw_buffer_flush(obj, surf);
    }
    else {
        
    }
}


int sgl_string_init(sgl_obj_t* string, sgl_obj_t* parent)
{
    if(parent == NULL) {
        return -1;
    }
    string->parent = parent;
    string->dirty = 1;
    string->hide = 0;
    string->alpha = 0;
    string->draw_cb = sgl_string_cb;
    string->event_data = NULL;
    string->ev_stat = SGL_EVENT_FORCE_DRAW;
    sgl_page_add_obj(parent, string);
    return 0;
}


sgl_obj_t* sgl_string_create(sgl_obj_t* parent)
{
    int ret;
    sgl_string_t* string = (sgl_string_t *)sgl_malloc(sizeof(sgl_string_t));
    if(string == NULL)
        return NULL;
    ret = sgl_string_init(&string->obj, parent);
    if(ret) {
        return NULL;
    }
    string->text = NULL;
    string->font = NULL;
    return &string->obj;
}


void sgl_string_set_text(sgl_obj_t* obj, const char* text)
{
    sgl_string_t *string = container_of(obj, sgl_string_t, obj);
    string->text = text;
}

void sgl_string_set_font(sgl_obj_t* obj, sgl_font_t *font)
{
    sgl_string_t *string = container_of(obj, sgl_string_t, obj);
    string->font = font;
}
