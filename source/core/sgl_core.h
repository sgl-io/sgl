/* source/core/sgl_core.h
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

#ifndef __SGL_CORE_H__
#define __SGL_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "sgl_conf.h"
#include "./sgl_list.h"
#include "../libs/sgl_types.h"
#include <stddef.h>


// prototype: sgl_rgb(uint8_t r, uint8_t g, uint8_t b)
#if (SGL_CONFIG_PANEL_PIXEL_DEPTH == 32 || SGL_CONFIG_PANEL_PIXEL_DEPTH == 24)
#define sgl_rgb(r,g,b)          (sgl_color_t){.blue=(b), .green=(g), .red=(r),}
#elif (SGL_CONFIG_PANEL_PIXEL_DEPTH == 16)
#if SGL_CONFIG_COLOR16_SWAP                   
#define sgl_rgb(r,g,b)          (sgl_color_t){.green_h = (g >>2) >> 3,     \
                                              .red = (r) >> 3,             \
                                              .blue = (b) >> 3,            \
                                              .green_l = (g >>2) & 0x7,}
#else
#define sgl_rgb(r,g,b)          (sgl_color_t){.blue=(b) >> 3,              \
                                              .green=(g) >> 2,             \
                                              .red=(r) >> 3,}
#endif
#else
//define sgl_rgb macro for other color type
#endif

#define SGL_RED              sgl_rgb(0xFF, 0, 0)
#define SGL_GREEN            sgl_rgb(0, 0xFF, 0)
#define SGL_BLUE             sgl_rgb(0, 0, 0xFF)
#define SGL_WHITE            sgl_rgb(0xFF, 0xFF, 0xFF)
#define SGL_BLACK            sgl_rgb(0, 0, 0)

#ifndef SGL_SRCACT_BACKGROUND_COLOR
#define SGL_SRCACT_BACKGROUND_COLOR    (SGL_WHITE)
#endif


/**
* @brief This enumeration type lists all the event types of sgl
*/
typedef enum sgl_event_type {
    SGL_EVENT_NULL = 0,
    SGL_EVENT_NORMAL = 1,
    SGL_EVENT_PRESSED = 2,
    SGL_EVENT_RELEASED = 3,
    SGL_EVENT_LONG_PRESSED = 4,
    SGL_EVENT_TURN_ON,
    SGL_EVENT_TURN_OFF,
    SGL_EVENT_UNKNOW,
    SGL_EVENT_FORCE_DRAW, //TODO: add force draw event callback
    SGL_EVENT_FORCE_DRAW_CLEAR, //TODO: clear object tile
    SGL_EVENT_ALL = 255,

}sgl_event_type_e;


/**
* @brief This enumeration type defines the alignment of controls in sgl, 
*        i.e. coordinate positions
*/
typedef enum sgl_align_type {
    SGL_ALIGN_TOP_MID,
    SGL_ALIGN_TOP_LEFT,
    SGL_ALIGN_TOP_RIGHT,
    SGL_ALIGN_CENTER_MID,
    SGL_ALIGN_CENTER_LEFT,
    SGL_ALIGN_CENTER_RIGHT,
    SGL_ALIGN_BOT_MID,
    SGL_ALIGN_BOT_LEFT,
    SGL_ALIGN_BOT_RIGHT,
    SGL_ALIGN_TOP,
    SGL_ALIGN_CENTER,
    SGL_ALIGN_BOT,
    SGL_ALIGN_LEFT,
    SGL_ALIGN_MID,
    SGL_ALIGN_RIGHT,

}sgl_align_type_e;


/**
* @brief This structure is a structure that describes the position of the control, 
*        where x represents the position of the x coordinate, which is the row coordinate position, 
*        and y represents the position of the y coordinate, which is the column coordinate position
*
* @x: x coordinate
* @y: y coordinate
*/
typedef struct sgl_pos {
    int16_t x;
    int16_t y;
}sgl_pos_t;


/**
* @brief This structure describes the size of the object, including width and height, in pixels
* 
* @w: width
* @h: height
*/
typedef struct sgl_size {
    int16_t w;
    int16_t h;
}sgl_size_t;


/**
* @brief This structure describes a rectangular region, where x1 and y1 represent the coordinates 
*        of the upper left corner of the rectangle, and x2 and y2 represent the coordinates of the 
*        lower right corner of the rectangle
*  
* @x1: x position left corner of the rectangle
* @y1: y position left corner of the rectangle
* @x2: x position right corner of the rectangle
* @y2: y position right corner of the rectangle
*/
typedef struct sgl_rect {
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
}sgl_rect_t;


/**
* @brief This structure defines a 32 bit color bit field
*
* @blue: Blue color component
* @green: Green color component
* @red: Red color component
* @alpha: Color transparency
*/
typedef union {
    struct {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
        uint8_t alpha;
    };
    uint32_t full;
}sgl_color32_t;


/**
* @brief This structure defines a 16 bit color bit field
* 
* @blue: Blue color component
* @green: Green color component
* @red: Red color component
* @alpha: Color transparency
*/
typedef union {
#if SGL_CONFIG_COLOR16_SWAP
    struct {
        uint16_t green_h : 3;
        uint16_t red : 5;
        uint16_t blue : 5;
        uint16_t green_l : 3;
    };
#else
    struct {
        uint16_t blue : 5;
        uint16_t green : 6;
        uint16_t red : 5;
    };
#endif
    uint16_t full;
}sgl_color16_t;


/**
* @brief This structure defines a 8 bit color bit field
*
* @blue: Blue color component
* @green: Green color component
* @red: Red color component
* @alpha: Color transparency
*/
typedef union {
    struct {
        uint8_t blue : 2;
        uint8_t green : 3;
        uint8_t red : 3;
    };
    uint8_t full;
}sgl_color8_t;

#if (SGL_CONFIG_PANEL_PIXEL_DEPTH == 32)
#define sgl_color_t sgl_color32_t
#elif (SGL_CONFIG_PANEL_PIXEL_DEPTH == 16)
#define sgl_color_t sgl_color16_t
#elif (SGL_CONFIG_PANEL_PIXEL_DEPTH == 8)
#define sgl_color_t sgl_color8_t
#endif


/**
* @brief This structure defines a surface that is used to draw a shape, 
*        and the size of the surface depends on the actual situation. 
*        For a complete frame buffer device, the size of the surface is 
*        the size of the entire screen. For a non complete frame buffer device, 
*        the size generally depends on the actual drawing needs
*
* @fb: point to framebuffer
* @size: size of framebuffer
*/
typedef struct sgl_surf {
    sgl_color_t *fb;
    sgl_size_t  size;

}sgl_surf_t;

/**
* @brief This structure defines an image, with a bitmap pointing to the 
*        bitmap of the image, while specifying the width and height of the image
*
* @bitmap: point to image bitmap
* @width: image width
* @height: image height
*/
typedef struct sgl_img {
    const uint8_t *bitmap;
    uint16_t      width;
    uint16_t      height;
    
}sgl_img_t;

/**
* @brief This structure defines an icon, with a bitmap pointing to the 
*        bitmap of the icon, while specifying the width and height of the icon
*/
typedef sgl_img_t sgl_icon_t;


/**
* @brief This structure defines a style, the body_color describes the body color of an object,
*        the text_color describes the text color of an object, the radius describes the radius
*        of rounded rectangular object, bg_img point background image.
*
* @body_color: body color of object
* @text_color: text color of object
* @radius: the radius size of the rounded rectangle control
*/
typedef struct sgl_style {
    sgl_color_t body_color;
    sgl_color_t text_color;
    uint16_t    radius;

}sgl_style_t;


/**
* @brief This structure defines the object structure of sgl. This object is the core object of sgl, 
*        and all controls must include this object.
* @pos:  object position
* @size: object size
* @style: style of object, to set object color, include body color, text color, radius
* @bg_img: Pointer to the background image, if there is no background, this value should be set to NULL
* @event_fn: point to event callback function
* @event_data: parameter of event callback function
* @parent: parent of object
* @node: link brother object
* @draw_cb: point to draw object callback function
* @ev_stat: event status, such as clicked, pressed released, etc
* @dirty: dirty flag for object
* @selected: set an object to look like be selected
* @hide: hide an object, once the value is true, the object will be not display
* @alpha: set object alpha
*/
typedef struct sgl_obj {
    sgl_pos_t          pos;
    sgl_size_t         size;
    sgl_style_t        *style;
    sgl_img_t          *bg_img;
    void               (*event_fn)(struct sgl_obj *obj, void *data);
    void               *event_data;
    struct sgl_obj     *parent;
    sgl_list_node_t    node;
    void               (*draw_cb)(struct sgl_obj* obj);
    sgl_event_type_e   ev_stat;
    uint8_t            dirty: 1;
    uint8_t            selected: 1;
    uint8_t            hide: 1;
    uint8_t            alpha;

}sgl_obj_t;


/**
* @brief This structure is used to define an animation object, and all animations should have 
*        this structure defined to store the relevant properties of the animation
*
* @node: link all object which will be redraw
* @obj: Animation bound objects
* @tick: Internally used to record animation time
* @interval: Set the time interval for animation callback functions, ms
* @times: Set the execution time of the animation
* @endless: Set whether the animation is continuously executed
* @anim_cb: Set callback function for animation
* @anim_cb_data: parameter of callback function for animation
*/
typedef struct sgl_anim {
    sgl_list_node_t node;
    sgl_obj_t *obj;
    uint64_t  tick;
    uint32_t  interval;//ms
    uint32_t  times;
    uint32_t  endless: 1;
    void (*anim_cb)(struct sgl_anim *anim, void *data);
    void *anim_cb_data;
    bool active_flag;

}sgl_anim_t;


/**
 * @brief Before using controls on SGL pages, it is necessary to create a page and then 
 *        add the controls to this page
 * @obj:  object
 * @anim: list head for animation, the node of anim_list will link all object 
*/
typedef struct sgl_page {
    sgl_obj_t         obj;
    sgl_list_node_t   anim;

}sgl_page_t;


/**
* @brief Event location structure, Used to represent the coordinates of an event, 
*        such as the click position of the mouse, the click position of the touch screen, 
*        and so on
*
* @x: x coordinate
* @y: y coordinate
* @sgl_event_type_e: event type
*/
typedef struct sgl_event_pos {
    int16_t x;
    int16_t y;
    sgl_event_type_e type;

}sgl_event_pos_t;


/**
* @brief Font index table structure, used to describe the bitmap index positions of 
*        all characters in a font, accelerating the search process
*
* @bitmap_index: point to bitmap index of font
* @height: height of font
* @width: width of font
* @ofs_x: offset of character x position
* @ofs_y: offset of character y position
*/
typedef struct sgl_font_table {
    int bitmap_index;
    int8_t height;
    int8_t width;
    int8_t ofs_x;
    int8_t ofs_y;

}sgl_font_table_t;


/**
* @brief A structure used to describe information about a font, Defining a font set requires 
*        the use of this structure to describe relevant information
*
* @bitmap: point to bitmap of font
* @table: point to struct sgl_font_table
* @font_table_size: size of struct sgl_font_table
* @font_height: height of font
* @bpp: The anti aliasing level of the font
*/
typedef struct sgl_font {
    const uint8_t  *bitmap;
    const sgl_font_table_t  *table;
    uint16_t  font_table_size;
    uint16_t  font_height;
    uint8_t   bpp; //AA depth TODO: add 1,2,8bpp
#ifdef SGL_CONFIG_TEXT_UTF8
    const uint16_t *unicode_list;
    uint32_t unicode_list_len;
#endif
}sgl_font_t;


/**
* @brief Used to define an asynchronous execution task
*
* @task_fun: point to task callback function
* @data: parameter of task callback function
*/
typedef struct sgl_task {
    int (*task_fun)(void *data);
    void *data;

}sgl_task_t;


/**
* @brief Inline function that converts the color value of an integer into a color structure
*
* @param: color value 
*
* @return: sgl_color_t
*/
static inline sgl_color_t sgl_int2color(uint32_t color)
{
    return *(sgl_color_t*)(&color);
}


/**
* @brief Inline function that converts the color value of an (r,g,b) into a color structure
*
* @param: red    Red color component  
* @param: green  Green color component
* @param: blue   Blue color component
*
* @return: sgl_color_t
*/
static inline sgl_color_t sgl_rgb2color(uint8_t red, uint8_t green, uint8_t blue)
{
#if SGL_CONFIG_COLOR16_SWAP
    sgl_color_t color;
    color.green_h = (uint16_t)((green>>3) & 0x7);
    color.red = red;
    color.blue = blue;
    color.green_l = (uint16_t)(green & 0x7);
#else
    sgl_color_t color;
    color.blue = blue;
    color.green = green;
    color.red = red;
#endif
    return color;
}


/**
* @brief Used to describe the structure of display panel devices, all display screens 
*        should be abstracted as this structure
*
* @framebuffer: point to framebuffer or draw buffer
* @buffer_size: framebuffer or draw buffer size
* @xres: x resolution
* @yres: y resolution
* @xres_virtual: x virtual resolution
* @yres_virtual: y virtual resolution
* @flush_area: point to the drawing window function used to refresh the drawing buffer 
*              onto the screen, if mmap is used, the value should be set to NULL
*/
typedef struct sgl_device_panel {
    sgl_color_t *framebuffer;
    int buffer_size;
    int16_t xres;
    int16_t yres;
    int16_t xres_virtual;
    int16_t yres_virtual;
    void (*flush_area)(int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t *src);

}sgl_device_panel_t;


/**
* @brief Describe an input device, such as a mouse, touch screen, etc
*
* @get: point to that get the event position callback function
*/
typedef struct sgl_device_input {
    sgl_event_pos_t (*get)(void *data);

}sgl_device_input_t;


typedef struct sgl_devic_stdout {
    int (*put)(char *str);

}sgl_device_stdout_t;


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_CORE_H__
