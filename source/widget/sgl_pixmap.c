/* source/widget/sgl_img.c
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

#include "./sgl_pixmap.h"


int sgl_pixmap_init(sgl_pixmap_t *pixmap, sgl_obj_t *parent, sgl_img_t bitmap)
{
    sgl_obj_t* obj;
    if(parent == NULL) {
        return -1;
    }
    pixmap->bitmap = bitmap;
    obj = &pixmap->obj;
    obj->parent = parent;
    obj->selected = 0;
    obj->event_data = NULL;
    obj->ev_stat = SGL_EVENT_FORCE_DRAW;
    obj->obj_type = SGL_OBJ_PIXELMAP;
    // sgl_obj_add_src_act_list(obj);
    // sgl_obj_add_dirty_list(obj);
    return 0;
}

sgl_obj_t* sgl_pixmap_create(sgl_obj_t *parent, sgl_img_t bitmap)
{
    int ret;
    sgl_pixmap_t *pixmap;
    if(parent == NULL) {
        return NULL;
    }
    pixmap = (sgl_pixmap_t *)sgl_alloc(sizeof(sgl_pixmap_t));
    if(pixmap == NULL)
        return NULL;
    ret = sgl_pixmap_init(pixmap, parent, bitmap);
    if(ret) {
        return NULL;
    }
    return &pixmap->obj;
}

void sgl_pixmap_set_bitmap(sgl_obj_t* obj, sgl_img_t bitmap)
{
    sgl_pixmap_t *pixmap = container_of(obj, sgl_pixmap_t, obj);
    pixmap->bitmap = bitmap;
}

void sgl_pixmap_set_width(sgl_obj_t* obj, int16_t width)
{
    sgl_pixmap_t *pixmap = container_of(obj, sgl_pixmap_t, obj);
    pixmap->bitmap.width = width;
}

void sgl_pixmap_set_height(sgl_obj_t* obj, int16_t height)
{
    sgl_pixmap_t *pixmap = container_of(obj, sgl_pixmap_t, obj);
    pixmap->bitmap.height = height;
}

void sgl_pixmap_draw(sgl_obj_t* obj)
{
    sgl_pixmap_t *pixmap = container_of(obj, sgl_pixmap_t, obj);
    sgl_widget_draw_rect(rect);
    sgl_surf_t *surf = sgl_get_active_surf(obj);
    sgl_color_t *color_p = surf->fb;
    sgl_color_t *bitmap = (sgl_color_t*)pixmap->bitmap.bitmap;
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    color_p += obj->pos.y * surf->size.w + obj->pos.x;
    for(int i = 0; i < pixmap->bitmap.height; i ++) {
        for(int j = 0; j < pixmap->bitmap.width; j ++) {
            color_p[j] = *bitmap;
            bitmap ++;
        }
        color_p += surf->size.w;
    }
#else

#endif
}

