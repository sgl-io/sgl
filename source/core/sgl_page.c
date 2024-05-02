/* source/widget/sgl_page.c
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

#include "sgl_conf.h"
#include "./sgl_obj.h"
#include "./sgl_page.h"
#include "./sgl_device.h"
#include "./sgl_task.h"
#include "../libs/sgl_mem.h"
#include "../libs/sgl_string.h"
#include "../draw/sgl_draw.h"

static sgl_style_t page_default_style;

/**
 * Define a page pointer for an activity that always points to the active page. 
 * When a page switches, this pointer will point to a new page
*/
sgl_obj_t *active_page = NULL;


static void sgl_page_draw(sgl_obj_t *page);


/**
 * @brief Initialize a page, and whenever you create a page, you should call this function to initialize it
 * 
 * @param page: Newly created page structure address
 * 
 * @return none
*/
void sgl_page_init(sgl_obj_t *page)
{
    page->pos.x = 0;
    page->pos.y = 0;
    //set page size as panel x resolution
    //set page size as panel y resolution
    page->size.w = sgl_get_device_panel()->xres;
    page->size.h = sgl_get_device_panel()->yres;
    page->event_fn = NULL;
    page->event_data = NULL;
    page->parent = NULL;
    page->draw_cb = sgl_page_draw;
    page->ev_stat = SGL_EVENT_FORCE_DRAW;
    page->dirty = 1;
    page->selected = 0;
    //set background color, default is SGL_CONFIG_PAGE_COLOR
    // you can change it in sgl_conf.h file 
    sgl_style_set_body_color(&page_default_style, SGL_CONFIG_PAGE_COLOR);
    sgl_style_set_text_color(&page_default_style, SGL_CONFIG_PAGE_COLOR);
    sgl_style_set_radius(&page_default_style, 0);
    page->style = &page_default_style;
    //init object list
    sgl_list_init(&page->node);
    //if active_page pointer is NULL, it means that no active page, so, set the active page as new page
    if(active_page == NULL) {
        active_page = page;
    }
}


/**
 * @brief Creating pages in a dynamic way, you must check if the return value is NULL
 * 
 * @param none
 * 
 * @return sgl_obj_t pointer: Point to the address of the created page structure
*/
sgl_obj_t* sgl_page_create(void)
{
    sgl_page_t *page = (sgl_page_t*)sgl_malloc(sizeof(sgl_page_t));
    if(page != NULL)
        sgl_page_init(&page->obj);
    sgl_list_init(&page->anim);
    return &page->obj;
}


/**
 * @brief Add an object to a page that must have already been initialized
 * 
 * @param page:  The page to which the object is added
 * @param obj:   Object, usually a control, has already been initialized
 * 
 * @return none
*/
void sgl_page_add_obj(sgl_obj_t *page, sgl_obj_t *obj)
{
    sgl_list_add_node_at_tail(&page->node, &obj->node);
}


/**
 * @brief Delete an object from the page, which must already be on the page
 * 
 * @param obj:  Objects to be deleted
 * 
 * @return none
*/
void sgl_page_del_obj(sgl_obj_t *obj)
{
    sgl_list_del_node(&obj->node);
}


/**
 * @brief Get the linked header of the linked list of objects on the page
 * 
 * @param page:  Page containing object linked list
 * 
 * @return sgl_list_node_t pointer: Pointer to the header of an object linked list
*/
sgl_list_node_t* sgl_page_get_obj_head(sgl_obj_t *page)
{
    return &page->node;
}


/**
 * @brief Determine whether an object is on the page
 * 
 * @param obj:  Operation object
 *
 * @return bool: true is in the list, false is not in the list
*/
bool sgl_page_obj_is_in_list(sgl_obj_t* obj)
{
    if(obj->node.prev->next == &obj->node) {
        return true;
    }
    return false;
}


/**
 * @brief Set the page style, this function can only set the background color to monochrome
 * 
 * @param page:  The page object
 * @param style: background color style
 * 
 * @return none
*/
void sgl_page_set_style(sgl_obj_t *page, sgl_style_t *style)
{
    page->style = style;
}


/**
 * @brief Set the background image of the page
 * 
 * @param page:  The page object
 * @param img:   Pointer to background image
 * 
 * @return none
*/
void sgl_page_set_background(sgl_obj_t *page, sgl_img_t *img)
{
    page->bg_img = img;
}


/**
 * @brief Refresh the color of the page to the screen. Users should not call this function as 
 *        it is time-consuming
 * 
 * @param page: The page object
 * 
 * @return none
*/
static void sgl_page_flush_color(sgl_obj_t *page)
{
    sgl_color_t color = page->style->body_color;
    sgl_surf_t *surf = sgl_get_active_surf(page);
    int width = page->size.w;
    int height = page->size.h;
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    int pitch = sgl_get_device_panel()->xres_virtual;
    sgl_color_t *p = surf->fb;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            p[j] = color;
        }
        p += pitch;
    }
#else
    int i;
    int buffer_line = sgl_get_device_panel()->buffer_size / (width * sizeof(sgl_color_t));
    sgl_set_active_surf_size(width, buffer_line);
    sgl_draw_buffer_clear(surf, color);
    for(i = 0; (i + buffer_line) <= height; i += buffer_line) {
        sgl_draw_buffer_flush(surf, 0, i);
    }
    sgl_set_active_surf_size(width, height - i);
    sgl_draw_buffer_flush(surf, 0, i);
#endif
}


/**
 * @brief the background image of the page to the screen. Users should not call this function 
 *        as it is time-consuming
 * 
 * @param page:  The page object
 * 
 * @return none
*/
static void sgl_page_flush_background(sgl_obj_t *page)
{
    sgl_surf_t *surf = sgl_get_active_surf(page);
    sgl_img_t *img = page->bg_img;
    sgl_color_t *cherry = (sgl_color_t*)img->bitmap;
    sgl_color_t *pick = surf->fb;
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    int pitch = sgl_get_device_panel()->xres_virtual;
    for(int i = 0; i < img->height; i++) {
        for(int j = 0; j < img->width; j++) {
            pick[j] = *cherry;
            cherry ++;
        }
        pick += pitch;
    }
#else
    int width = sgl_get_device_panel()->xres;
    int height = sgl_get_device_panel()->yres;
    int h_pos = 0;
    int buffer_line = sgl_get_device_panel()->buffer_size / (width * sizeof(sgl_color_t));
    sgl_set_active_surf_size(width, buffer_line);
    for(h_pos = 0; (h_pos + buffer_line) <= height; h_pos += buffer_line) {
        for(int i = 0; i < buffer_line * width; i++) {
            *pick ++  = *cherry ++ ;
        }
        sgl_draw_buffer_flush(surf, 0, h_pos);
        pick = surf->fb;
    }
    for(int i = 0; i < (height - h_pos) * width; i++) {
        *pick ++  = *cherry ++ ;
    }
    sgl_set_active_surf_size(width, height - h_pos);
    sgl_draw_buffer_flush(surf, 0, h_pos);
#endif
}


/**
 * @brief Draw a page, this function is used to refresh the background or color of a page. 
 *        When a page switches, this function will be called
 * 
 * @param page:  The page object
 * 
 * @return none
*/
static void sgl_page_draw(sgl_obj_t *page)
{
    if(page->bg_img == NULL) {
        sgl_page_flush_color(page);
    }
    else {
        sgl_page_flush_background(page);
    }
}


/**
 * @brief This function is used to switch pages. When switching pages, it will traverse all objects on the page. 
 *        When an object is marked as dirty, it will be redrawn
 * 
 * @param data:  Private pointer
 * 
 * @return int: 0 is ok, 1 is error
*/
static int sgl_page_switch_task(void *data)
{
    sgl_obj_t *current_obj;
    sgl_obj_t *page = (sgl_obj_t*)(data);
    sgl_list_node_t *current_node;
    sgl_list_node_t *root_node = &active_page->node;
    sgl_page_draw(page);
    sgl_list_for_each(current_node, root_node) {
        current_obj = container_of(current_node, struct sgl_obj, node);
        if( current_obj->hide == 0 ) {
            sgl_obj_set_event_status(current_obj, SGL_EVENT_FORCE_DRAW);
            current_obj->dirty = 1;
        }
    }
    return 0;
}


/**
 * @brief Set a page to the active page, and once this function is called, the display screen 
 *        will switch to the set page
 * 
 * @param page:  The page object
 * 
 * @return none
*/
void sgl_page_set_active(sgl_obj_t *page)
{
    sgl_task_t flust_page_task = { .task_fun = sgl_page_switch_task, .data = page, };
    active_page = page;
    sgl_task_queue_push(flust_page_task);
}


/**
 * @brief Get the current activity page, this function will return a pointer to the activity page
 * 
 * @param none
 * 
 * @return sgl_obj_t: pointer to active page
*/
sgl_obj_t *sgl_page_get_active(void)
{
    return active_page;
}
