/* source/core/sgl_obj.h
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

#ifndef __SGL_OBJ_H__
#define __SGL_OBJ_H__

#include "./sgl_core.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
* @brief Set the position of an object, x and y
*
* @param obj:      The object
* @param x:        position x
* @param y:        position y
*
* @return none
*/
static inline void sgl_obj_set_pos(sgl_obj_t *obj, int16_t x, int16_t y)
{
    obj->pos.x = obj->parent->pos.x + x;
    obj->pos.y = obj->parent->pos.y + y;
}


/**
* @brief Get the position of an object
*
* @param obj:   The object
*
* @return sgl_pos_t
*/
static inline sgl_pos_t sgl_obj_get_pos(sgl_obj_t *obj)
{
    return obj->pos;
}


/**
* @brief Set the x position of an object
*
* @param obj:     The object
* @param x:       position x
*
* @return none
*/
static inline void sgl_obj_set_pos_x(sgl_obj_t *obj, int16_t x)
{
    obj->pos.x = obj->parent->pos.x + x;
}


/**
* @brief Get the x position of an object
*
* @param obj:     The object
*
* @return int16_t: position x
*/
static inline int16_t sgl_obj_get_pos_x(sgl_obj_t *obj)
{
    return obj->pos.x;
}


/**
* @brief Set the y position of an object
*
* @param obj:  The object
* @param y:    position y
*
* @return none
*/
static inline void sgl_obj_set_pos_y(sgl_obj_t *obj, int16_t y)
{
    obj->pos.y = obj->parent->pos.y + y;
}


/**
* @brief Get the y position of an object
*
* @param obj:     The object
*
* @return int16_t: position y
*/
static inline int16_t sgl_obj_get_pos_y(sgl_obj_t *obj)
{
    return obj->pos.y;
}


/**
* @brief Set the size of an object
*
* @param obj:       The object
* @param width:     The width of the object
* @param height:    The height of the object
*
* @return none
*/
static inline void sgl_obj_set_size(sgl_obj_t *obj, int16_t width, int16_t height)
{
    obj->size.w = width;
    obj->size.h = height;
}


/**
* @brief Set the width size of an object
*
* @param obj:       The object
* @param width:     The width of the object
*
* @return none
*/
static inline void sgl_obj_set_size_w(sgl_obj_t *obj, int16_t width)
{
    obj->size.w = width;
}


/**
* @brief Set the height size of an object
*
* @param obj:        The object
* @param height:     The height of the object
*
* @return none
*/
static inline void sgl_obj_set_size_h(sgl_obj_t *obj, int16_t height)
{
    obj->size.h = height;
}


/**
* @brief Set the style of the object, including color, width, background, etc
*
* @param obj:      The object
* @param style:    Style of the object
*
* @return none
*/
static inline void sgl_obj_set_style(sgl_obj_t *obj, sgl_style_t *style)
{
    obj->style = style;
}


/**
* @brief Set the color style of the object
*
* @param style:    Style of the object
* @param color:    color style of the object
*
* @return none
*/
static inline void sgl_style_set_body_color(sgl_style_t *style, sgl_color_t color)
{
    style->body_color = color;
}


/**
* @brief Set the text color style of the object
*
* @param style:    Style of the object
* @param color:    text color style of the object
*
* @return none
*/
static inline void sgl_style_set_text_color(sgl_style_t *style, sgl_color_t color)
{
    style->text_color = color;
}


/**
* @brief Set the radius of the rounded rectangle for object styles
*
* @param style:     Style of the object
* @param radius:    The radius size of a rounded rectangle, in pixels
*
* @return none
*/
static inline void sgl_style_set_radius(sgl_style_t *style, int radius)
{
    style->radius = radius;
}


/**
* @brief Set the background image of the object
*
* @param obj:  The object
* @param bg:   point to the image of background
*
* @return none
*/
static inline void sgl_obj_set_bgimg(sgl_obj_t *obj, sgl_img_t *bg)
{
    obj->bg_img = bg;
}


/**
* @brief Get the background image of the object
*
* @param obj:  The object
*
* @return sgl_img_t  The Pointer to image of background
*/
static inline sgl_img_t* sgl_obj_get_bgimg(sgl_obj_t *obj)
{
    return obj->bg_img;
}


/**
* @brief Set the parent of an object
*
* @param obj:       The object
* @param parent:    The parent of the object
*
* @return sgl_img_t  The Pointer to image of background
*/
static inline void sgl_obj_set_parent(sgl_obj_t *obj, sgl_obj_t *parent)
{
    obj->parent = parent;
}


/**
* @brief Obtain the alignment position of the object, note that the position 
*        here is calculated based on the relative position
*
* @param parent_size:       size of parent object
* @param size:              size of object
* @param size:              The parent of the object
*
* @return sgl_pos_t  The calculated position
*/
sgl_pos_t sgl_get_align_pos(sgl_size_t *parent_size, sgl_size_t *size, sgl_align_type_e type);


/**
* @brief Set the alignment of the object, this function sets the position of the object in alignment,
*
* @param obj:       The object
* @param type:      Alignment type
*
* @return none
*/
static inline void sgl_obj_set_align(sgl_obj_t *obj, sgl_align_type_e type)
{
    sgl_obj_t *parent_obj = obj->parent;
    sgl_pos_t pos = sgl_get_align_pos(&parent_obj->size, &obj->size, type);
    obj->pos.x = pos.x + parent_obj->pos.x;
    obj->pos.y = pos.y + parent_obj->pos.y;
}


/**
* @brief Set the alignment of the object, this function sets the position of the object in alignment,
*
* @param obj:       The object
* @param type:      Alignment type
*
* @return none
*/
static inline void sgl_obj_set_event_cb(sgl_obj_t *obj, void (*event)(sgl_obj_t *, void *), void *data)
{
    obj->event_fn = event;
    obj->event_data = data;
}


/**
* @brief Event callback function for executing objects
*
* @param obj:       The object
*
* @return none
*/
static inline void sgl_obj_event_cb(sgl_obj_t *obj)
{
    if(obj->event_fn) {
        obj->event_fn(obj, obj->event_data);
    }
}


/**
* @brief Set the event status of an object, for example, when an object is clicked, 
*        it should be set to SGL_EVENT_PRESSED
*
* @param obj:       The object
*
* @return none
*/
static inline void sgl_obj_set_event_status(sgl_obj_t *obj, sgl_event_type_e status)
{
    obj->ev_stat = status;
}


/**
* @brief Get the event status of an object
*
* @param obj:       The object
*
* @return sgl_event_type_e  event status, such as SGL_EVENT_PRESSED
*/
static inline sgl_event_type_e sgl_obj_get_event_status(sgl_obj_t *obj)
{
    return obj->ev_stat;
}


/**
* @brief Check if the object is within the range of the event click, for example, 
*        when clicking the mouse, this function needs to be used to detect whether 
*        the control is clicked
*
* @param obj:  The object
* @param x:    x position of event/click
* @param y:    y position of event/click
*
* @return bool  true: be clicked, false: not be clicked 
*/
static inline bool sgl_obj_event_active(sgl_obj_t* obj, int x, int y)
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


/**
* @brief Dirty object flag, used to set whether an object needs to be redrawn, 
*        if the value is set to 1, the object will be redrawn in the next cycle
*
* @param obj:     The object
* @param flag:    Whether to be redrawn
*
* @return none
*/
static inline void sgl_obj_set_dirty(sgl_obj_t* obj, bool flag)
{
    if(flag != obj->dirty) {
        obj->dirty = flag;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    }
}


/**
* @brief Set the selected state of the control. For ordinary independent buttons, 
*        developers can use this function to box the control in order to show the 
*        interface which control is selected
*
* @param obj:       The object
* @param status:    Whether to be selected
*
* @return none
*/
static inline void sgl_obj_set_selected(sgl_obj_t* obj, bool status)
{
    if(status != obj->selected) {
        obj->selected = status;
        obj->dirty = 1;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    }
}


/**
* @brief Hide the control so that when the function is applied to an object, 
*        it will not be displayed or processed and will be hidden
*
* @param obj:       The object
* @param status:    Whether to be hide
*
* @return none
*/
static inline void sgl_obj_set_hide(sgl_obj_t* obj, bool status)
{
    if(status != obj->hide) {
        obj->hide = status;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
        obj->dirty = 1;
    }
}


/**
* @brief Set the transparency value of an object, this function allows the 
*        user to set the transparency alpha of an object to appear transparent
*
* @param obj:       The object
* @param alpha:     The value of transparency, where 0 represents complete opacity and 
*                  255 represents complete transparency
*
* @return none
*/
static inline void sgl_obj_set_alpha(sgl_obj_t* obj, uint8_t alpha)
{
    if(alpha != obj->alpha) {
        obj->alpha = alpha;
        obj->ev_stat = SGL_EVENT_FORCE_DRAW;
        obj->dirty = 1;
    }
}


/**
* @brief Forcefully trigger the click event callback function of an object
*
* @param obj:       The object
*
* @return none
*/
static inline void sgl_obj_event_click(sgl_obj_t *obj)
{
    if(obj->ev_stat != SGL_EVENT_PRESSED){
        obj->ev_stat = SGL_EVENT_PRESSED;
        obj->dirty = 1;
    }
}


/**
* @brief Forcefully trigger the callback function for the object's press event
*
* @param obj:       The object
*
* @return none
*/
static inline void sgl_obj_event_press(sgl_obj_t *obj)
{
    if(obj->ev_stat != SGL_EVENT_PRESSED){
        obj->ev_stat = SGL_EVENT_PRESSED;
        obj->dirty = 1;
    }
}


/**
* @brief Forcefully trigger the callback function for the object's release event
*
* @param obj:       The object
*
* @return none
*/
static inline void sgl_obj_event_release(sgl_obj_t *obj)
{
    if(obj->ev_stat != SGL_EVENT_RELEASED) {
        obj->ev_stat = SGL_EVENT_RELEASED;
        obj->dirty = 1;
    }
}


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_OBJ_H__