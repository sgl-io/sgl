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

#include "./sgl_core.h"
#include "../sgl.h"

sgl_obj_t *active_page = NULL;


void sgl_page_init(sgl_obj_t *page)
{
    page->pos.x = 0;
    page->pos.y = 0;
    page->size.w = sgl_get_device_panel()->xres;
    page->size.h = sgl_get_device_panel()->yres;
    page->event_fn = NULL;
    page->event_data = NULL;
    page->parent = NULL;
    page->obj_type = SGL_OBJ_PAGE;
    page->ev_stat = SGL_EVENT_FORCE_DRAW;
    page->selected = 0;
    page->style.text_color = SGL_CONFIG_PAGE_COLOR;
    page->style.body_color = SGL_CONFIG_PAGE_COLOR;
    sgl_list_init(&page->node);
    sgl_list_init(&page->dirty);
    if(active_page == NULL) {
        active_page = page;
    }
}


sgl_obj_t* sgl_page_create(void)
{
    sgl_obj_t *page = (sgl_obj_t*)sgl_alloc(sizeof(sgl_obj_t));
    sgl_page_init(page);
    return page;
}

void sgl_page_add_obj(sgl_obj_t *page, sgl_obj_t *obj)
{
    sgl_list_add_node_at_tail(&page->node, &obj->node);
}

void sgl_page_del_obj(sgl_obj_t *obj)
{
    sgl_list_del_node(&obj->node);
}

sgl_list_node_t* sgl_page_get_obj_head(sgl_obj_t *page)
{
    return &page->node;
}

bool sgl_page_obj_is_in_list(sgl_obj_t* obj, sgl_list_node_t* list_head)
{
    sgl_obj_t *current_obj;
    sgl_list_node_t* current_node;
    sgl_list_for_each(current_node, list_head) {
        current_obj = container_of(current_node, struct sgl_obj, node);
        if( current_obj ==  obj) {
            return true;
        }
    }
    return false;
}

void sgl_page_add_dirty_obj(sgl_obj_t *page, sgl_obj_t *obj)
{
    if(!obj->hide) {
        if(!sgl_page_obj_is_in_dirty_list(obj, &page->dirty))
            sgl_list_add_node_at_tail(&page->dirty, &obj->dirty);
    }
}

void sgl_page_del_dirty_obj(sgl_obj_t *obj)
{
    sgl_list_del_node(&obj->dirty);
}

sgl_list_node_t* sgl_page_get_dirty_obj_head(sgl_obj_t *page)
{
    return &page->dirty;
}

bool sgl_page_obj_is_in_dirty_list(sgl_obj_t* obj, sgl_list_node_t* list_head)
{
    sgl_obj_t *current_obj;
    sgl_list_node_t* current_node;
    sgl_list_for_each(current_node, list_head) {
        current_obj = container_of(current_node, struct sgl_obj, dirty);
        if( current_obj ==  obj) {
            return true;
        }
    }
    return false;
}

void sgl_page_set_color(sgl_obj_t *page, sgl_color_t color)
{
    page->style.text_color = color;
    page->style.body_color = color;
}

void sgl_page_flush_color(sgl_obj_t *page)
{
    sgl_color_t color = page->style.body_color;
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

void sgl_page_set_background(sgl_obj_t *page, sgl_img_t *img)
{
    page->style.bg_img = img;
}

void sgl_page_flush_background(sgl_obj_t *page)
{
    sgl_surf_t *surf = sgl_get_active_surf(page);
    sgl_img_t *img = page->style.bg_img;
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

static int sgl_page_switch_task(void *data)
{
    sgl_obj_t *current_obj;
    sgl_obj_t *page = (sgl_obj_t*)(data);
    sgl_list_node_t *current_node;
    sgl_list_node_t *root_node = &active_page->node;
    if(page->style.bg_img == NULL) {
        sgl_page_flush_color(page);
    }
    else {
        sgl_page_flush_background(page);
    }
    sgl_list_for_each(current_node, root_node) {
        current_obj = container_of(current_node, struct sgl_obj, node);
        if( current_obj->hide == 0 ) {
            sgl_obj_set_event_status(current_obj, SGL_EVENT_FORCE_DRAW);
            sgl_page_add_dirty_obj(active_page, current_obj);
        }
    }
    return 0;
}

void sgl_page_set_active(sgl_obj_t *page)
{
    sgl_task_t flust_page_task = { .task_fun = sgl_page_switch_task, .data = page, };
    active_page = page;
    sgl_task_queue_push(flust_page_task);
}

sgl_obj_t *sgl_page_get_active(void)
{
    return active_page;
}
