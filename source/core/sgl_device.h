/* source/core/sgl_device.h
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

#ifndef __SGL_DEVICE_H__
#define __SGL_DEVICE_H__

#include "./sgl_core.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief The callback function of the input device, in the interrupt function of the 
 *        output device, you should call this function to send input event messages to the system
 * 
 * @param data:  Incoming parameters
 * 
 * @return none
*/
void sgl_device_input_handle(void *data);


/**
 * @brief To register the display screen and input device, you should call it after system initialization 
 *        and check the return value to see if the registration was successful
 * 
 * @param panel:  Display device structure
 * @param input:  Input device structure
 * 
 * @return 0 is OK, otherwise is failed
*/
int sgl_device_register(sgl_device_panel_t *panel, sgl_device_input_t *input);


/**
 * @brief Get the active display device, this function will return a pointer to the structure of the active device
 * 
 * @param none
 * 
 * @return sgl_device_panel_t: pointer to the structure of the active device
*/
sgl_device_panel_t* sgl_get_device_panel(void);


/**
 * @brief Get the surface of the activity, which is a special function. For a complete frame buffer device, 
 *        return the size of the surface's rows and columns as the size of the entire frame buffer. 
 *        For a non complete frame buffer device, return the size of the surface's rows and columns as the size of an object
 * 
 * @param obj: an object
 * 
 * @return sgl_surf_t: pointer to active surface
*/
sgl_surf_t* sgl_get_active_surf(sgl_obj_t *obj);


/**
 * @brief Set the size of the surface
 * 
 * @param width: width of the surface
 * @param height: height of the surface
 * 
 * @return none
*/
void sgl_set_active_surf_size(int16_t width, int16_t height);


/**
 * @brief Register an output device for debugging
 * 
 * @param device: Available output device
 * 
 * @return none
*/
void sgl_device_stdout_register(sgl_device_stdout_t *device);


/**
 * @brief Get the pointer to device for debugging output
 * 
 * @param none
 * 
 * @return pointer to available output device
*/
sgl_device_stdout_t* sgl_device_get_stdout(void);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_DEVICE_H__