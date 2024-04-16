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

#include <stdint.h>
#include "sgl_conf.h"
#include "./sgl_list.h"
#include "./sgl_math.h"
#include "./sgl_misc.h"


#if _WIN32 || WIN32
#define _const __attribute__((section (".const")))
#else
#define _const  const
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef bool
#define bool int
#endif


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
    SGL_EVENT_ALL = 255,

}sgl_event_type_e;


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

typedef enum sgl_obj_type {
    SGL_OBJ_UNKNOW = 0,
    SGL_OBJ_PAGE = 1,
    SGL_OBJ_BUTTON = 2,
    SGL_OBJ_LABEL = 3,
    SGL_OBJ_SWITCH,
    SGL_OBJ_BATTERY,
    SGL_OBJ_PIXELMAP,
    SGL_OBJ_TABVIEW,
    SGL_OBJ_CHECKBOX,
    SGL_OBJ_RADIOBUTTON,
    SGL_OBJ_COMBOX,
    SGL_OBJ_MSGBOX,
    SGL_OBJ_NUMBER,
    SGL_OBJ_PROGRESSBAR,
    SGL_OBJ_ARCBAR,
    SGL_OBJ_CUSTOM,
    
}sgl_obj_type_e;


typedef struct sgl_pos {
    int16_t x;
    int16_t y;
}sgl_pos_t;

typedef struct sgl_size {
    int16_t w;
    int16_t h;
}sgl_size_t;

typedef struct sgl_rect {
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
}sgl_rect_t;

typedef union {
    struct {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
        uint8_t alpha;
    };
    uint32_t full;
}sgl_color32_t;

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

typedef struct sgl_surf {
    sgl_color_t *fb;
    sgl_size_t  size;

}sgl_surf_t;


typedef struct sgl_img {
    const uint8_t *bitmap;
    uint16_t      width;
    uint16_t      height;
    
}sgl_img_t;

typedef sgl_img_t sgl_icon_t;

typedef struct sgl_style {
    sgl_color_t body_color;
    sgl_color_t text_color;
    uint16_t    radius;
    sgl_img_t   *bg_img;  //background image
    
}sgl_style_t;

typedef struct sgl_obj {
    sgl_pos_t          pos;
    sgl_size_t         size;
    sgl_style_t        style;
    void               (*event_fn)(struct sgl_obj *obj, void *data);
    void               *event_data;
    struct sgl_obj     *parent;
    sgl_list_node_t    node;
    sgl_list_node_t    dirty;
    sgl_obj_type_e     obj_type;
    sgl_event_type_e   ev_stat;
    uint16_t           selected: 1;
    uint16_t           hide: 1;
    uint8_t            alpha;
    uint8_t            reserved; 

}sgl_obj_t;

typedef struct sgl_anim {
    sgl_list_node_t node;
    sgl_obj_t *obj;
    sgl_pos_t pos_start;
    sgl_pos_t pos_end;
    uint64_t  tick;
    uint32_t  interval;//ms
    uint32_t  times;
    uint32_t  endless: 1;
    void (*anim_cb)(struct sgl_anim *anim, void *data);
    void *anim_cb_data;
    
}sgl_anim_t;

typedef struct sgl_event_pos {
    int16_t x;
    int16_t y;
    sgl_event_type_e type;

}sgl_event_pos_t;

typedef struct sgl_font_table {
    int bitmap_index;
    int8_t height;
    int8_t width;
    int8_t ofs_x;
    int8_t ofs_y;

}sgl_font_table_t;


typedef struct sgl_font {
    const uint8_t  *bitmap;
    const sgl_font_table_t  *table;
    uint16_t  font_table_size;
    uint16_t  font_height;
    uint8_t   bpp; //AA depth TODO: add 1,1,8bpp
}sgl_font_t;


typedef struct sgl_task {
    int (*task_fun)(void *data);
    void *data;

}sgl_task_t;

static inline sgl_color_t sgl_int2color(uint32_t color)
{
    return *(sgl_color_t*)(&color);
}

static inline sgl_color_t sgl_rgb2color(uint8_t red, uint8_t green, uint8_t blue)
{
#if SGL_CONFIG_COLOR16_SWAP
    sgl_color_t color = { .green_h = (uint16_t)((green>>3) & 0x7), .red=red, .blue=blue, .green_l = (uint16_t)(green & 0x7)};
#else
    sgl_color_t color = { .blue = blue, .green = green, .red = red,};
#endif
    return color;
}


typedef struct sgl_device_panel {
    sgl_color_t *framebuffer;
    int buffer_size;
    int16_t xres;
    int16_t yres;
    int16_t xres_virtual;
    int16_t yres_virtual;
    void (*flush_area)(int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t *src);

}sgl_device_panel_t;

typedef struct sgl_device_input {
    sgl_event_pos_t (*get)(void *data);

}sgl_device_input_t;

/**
 * sgl obj api
 * 
*/
void sgl_obj_set_pos(sgl_obj_t *obj, int16_t x, int16_t y);
sgl_pos_t sgl_obj_get_pos(sgl_obj_t *obj);
void sgl_obj_set_pos_x(sgl_obj_t *obj, int16_t x);
int16_t sgl_obj_get_pos_x(sgl_obj_t *obj);
void sgl_obj_set_pos_y(sgl_obj_t *obj, int16_t y);
int16_t sgl_obj_get_pos_y(sgl_obj_t *obj);
void sgl_obj_set_size(sgl_obj_t *obj, int16_t width, int16_t height);
void sgl_obj_set_size_w(sgl_obj_t *obj, int16_t width);
void sgl_obj_set_size_h(sgl_obj_t *obj, int16_t height);
void sgl_obj_set_style(sgl_obj_t *obj, sgl_style_t style);
void sgl_obj_set_body_color(sgl_obj_t *obj, sgl_color_t color);
void sgl_obj_set_text_color(sgl_obj_t *obj, sgl_color_t color);
void sgl_obj_set_radius(sgl_obj_t *obj, int radius);
void sgl_obj_set_bgimg(sgl_obj_t *obj, sgl_img_t *bg);
sgl_img_t* sgl_obj_get_bgimg(sgl_obj_t *obj);
void sgl_obj_set_parent(sgl_obj_t *obj, sgl_obj_t *parent);
void sgl_obj_set_align(sgl_obj_t *obj, sgl_align_type_e type);
void sgl_obj_set_event_cb(sgl_obj_t *obj, void (*event)(sgl_obj_t *, void *), void *data);
void sgl_obj_event_cb(sgl_obj_t *obj);
void sgl_obj_set_event_status(sgl_obj_t *obj, sgl_event_type_e status);
sgl_event_type_e sgl_obj_get_event_status(sgl_obj_t *obj);
bool sgl_obj_draw_valid(sgl_obj_t *obj);
bool sgl_obj_event_active(sgl_obj_t* obj, int x, int y);
void sgl_obj_set_selected(sgl_obj_t* obj, bool status);
void sgl_obj_set_hide(sgl_obj_t* obj, bool status);
void sgl_obj_set_alpha(sgl_obj_t* obj, uint8_t alpha);
void sgl_obj_event_click(sgl_obj_t *obj);
void sgl_obj_event_press(sgl_obj_t *obj);
void sgl_obj_event_release(sgl_obj_t *obj);

sgl_pos_t sgl_get_align_pos(sgl_size_t *parent_size, sgl_size_t *size, sgl_align_type_e type);


/**
 *  sgl event queue api
*/
bool sgl_event_queue_is_empty(void);
bool sgl_event_queue_is_full(void);
void sgl_event_queue_push(sgl_event_pos_t event);
sgl_event_pos_t sgl_event_queue_pop(void);
void sgl_task_handler(void);

/**
 *  sgl task queue api
*/
bool sgl_task_queue_is_empty(void);
bool sgl_task_queue_is_full(void);
void sgl_task_queue_push(sgl_task_t task);
sgl_task_t sgl_task_queue_pop(void);
void sgl_task_queue_clear(void);


void sgl_event_set_device_pos(sgl_event_pos_t event);
sgl_event_pos_t sgl_event_get_device_pos(void);


int sgl_device_register(sgl_device_panel_t *panel, sgl_device_input_t *input);
void sgl_device_input_handle(void *data);
sgl_device_panel_t* sgl_get_device_panel(void);
sgl_surf_t* sgl_get_active_surf(sgl_obj_t *obj);
void sgl_set_active_surf(sgl_color_t *fb, int16_t width, int16_t height);
void sgl_set_active_surf_size(int16_t width, int16_t height);


/**
 * sgl anim api
*/
void sgl_tick_inc(uint32_t ms);
void sgl_anim_set_anim_cb(sgl_anim_t *anim, void (*anim_cb)(struct sgl_anim *, void *), void* data);
void sgl_anim_set_times(sgl_anim_t *anim, uint32_t  times);
void sgl_anim_set_interval(sgl_anim_t *anim, uint32_t  interval);
void sgl_anim_set_endless(sgl_anim_t *anim, bool status);
void sgl_anim_bind_obj(sgl_anim_t *anim, sgl_obj_t *obj);
void sgl_anim_exec(sgl_anim_t *anim);


/**
 * sgl page api
*/

void sgl_page_init(sgl_obj_t *page);
sgl_obj_t* sgl_page_create(void);
void sgl_page_add_obj(sgl_obj_t *page, sgl_obj_t *obj);
void sgl_page_del_obj(sgl_obj_t *obj);
sgl_list_node_t* sgl_page_get_obj_head(sgl_obj_t *page);
bool sgl_page_obj_is_in_list(sgl_obj_t* obj, sgl_list_node_t* list_head);
void sgl_page_add_dirty_obj(sgl_obj_t *page, sgl_obj_t *obj);
void sgl_page_del_dirty_obj(sgl_obj_t *obj);
sgl_list_node_t* sgl_page_get_dirty_obj_head(sgl_obj_t *page);
bool sgl_page_obj_is_in_dirty_list(sgl_obj_t* obj, sgl_list_node_t* list_head);
void sgl_page_set_active(sgl_obj_t *page);
sgl_obj_t *sgl_page_get_active(void);
void sgl_page_set_color(sgl_obj_t *page, sgl_color_t color);
void sgl_page_set_background(sgl_obj_t *page, sgl_img_t *img);


void* sgl_alloc(int size);

int sgl_init();

#endif //__SGL_CORE_H__
