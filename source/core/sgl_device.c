/* source/core/sgl_device.c
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

static sgl_surf_t sgl_active_surf;
sgl_device_panel_t *sgl_active_panel = NULL;
sgl_device_input_t *sgl_active_input = NULL;

void sgl_device_input_handle(void *data)
{
    sgl_event_queue_push(sgl_active_input->get(data));
}

int sgl_device_register(sgl_device_panel_t *panel, sgl_device_input_t *input)
{
    if(panel->xres == 0 || panel->yres == 0) {
        return -1;
    }
    sgl_active_panel = panel;
    if(sgl_active_panel->framebuffer != NULL) {
        sgl_active_surf.fb = sgl_active_panel->framebuffer;
    }
    else {
        return -1;
    }
    if(panel->xres != 0 && panel->yres != 0) {
        sgl_active_surf.size.w = panel->xres;
        sgl_active_surf.size.h = panel->yres;
    }
    if(panel->xres_virtual != 0 && panel->yres_virtual != 0) {
        sgl_active_surf.size.w = panel->xres_virtual;
        sgl_active_surf.size.h = panel->yres_virtual;
    }
#if SGL_CONFIG_FRAMEBUFFER_MMAP == 0
    if(!sgl_active_panel->flush_area) {
        return -1;
    }
#endif
    if(input != NULL) {
        sgl_active_input = input;
    }
    return 0;
}

sgl_device_panel_t* sgl_get_device_panel(void)
{
    return sgl_active_panel;
}

sgl_surf_t* sgl_get_active_surf(sgl_obj_t *obj)
{
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    return &sgl_active_surf;
#else
    sgl_active_surf.size.w = obj->size.w;
    sgl_active_surf.size.h = obj->size.h;
    return &sgl_active_surf;
#endif
}

void sgl_set_active_surf_size(int16_t width, int16_t height)
{
    sgl_active_surf.size.w = width;
    sgl_active_surf.size.h = height;
}
