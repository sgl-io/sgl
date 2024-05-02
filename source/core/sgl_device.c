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

#include "./sgl_device.h"
#include "./sgl_event.h"
#include "./sgl_page.h"

/**
 * This variable points to the surface of an activity and is only assigned 
 * a value when registering a new display screen
*/
static sgl_surf_t sgl_active_surf;

/**
 * pointer to devices used for debugging output
*/
static sgl_device_stdout_t *stdout = NULL;

/**
 * This pointer points to the active panel, and this value will only be assigned 
 * when a new display screen is registered
*/
sgl_device_panel_t *sgl_active_panel = NULL;

/**
 * This pointer points to an input device, which can be a mouse, keyboard, touch screen, etc
*/
sgl_device_input_t *sgl_active_input = NULL;


/**
 * @brief The callback function of the input device, in the interrupt function of the 
 *        output device, you should call this function to send input event messages to the system
 * 
 * @param data:  Incoming parameters
 * 
 * @return none
*/
void sgl_device_input_handle(void *data)
{
    sgl_event_queue_push(sgl_active_input->get(data));
}


/**
 * @brief To register the display screen and input device, you should call it after system initialization 
 *        and check the return value to see if the registration was successful
 * 
 * @param panel:  Display device structure
 * @param input:  Input device structure
 * 
 * @return 0 is OK, otherwise is failed
*/
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


/**
 * @brief Get the active display device, this function will return a pointer to the structure of the active device
 * 
 * @param none
 * 
 * @return sgl_device_panel_t: pointer to the structure of the active device
*/
sgl_device_panel_t* sgl_get_device_panel(void)
{
    return sgl_active_panel;
}


/**
 * @brief Get the surface of the activity, which is a special function. For a complete frame buffer device, 
 *        return the size of the surface's rows and columns as the size of the entire frame buffer. 
 *        For a non complete frame buffer device, return the size of the surface's rows and columns as the size of an object
 * 
 * @param obj: an object
 * 
 * @return sgl_surf_t: pointer to active surface
*/
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


/**
 * @brief Set the size of the surface
 * 
 * @param width: width of the surface
 * @param height: height of the surface
 * 
 * @return none
*/
void sgl_set_active_surf_size(int16_t width, int16_t height)
{
    sgl_active_surf.size.w = width;
    sgl_active_surf.size.h = height;
}


/**
 * @brief Register an output device for debugging
 * 
 * @param device: Available output device
 * 
 * @return none
*/
void sgl_device_stdout_register(sgl_device_stdout_t *device)
{
    stdout = device;
}


/**
 * @brief Get the pointer to device for debugging output
 * 
 * @param none
 * 
 * @return pointer to available output device
*/
sgl_device_stdout_t* sgl_device_get_stdout(void)
{
    return stdout;
}
