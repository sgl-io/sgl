/* source/core/sgl_page.h
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

#ifndef __SGL_PAGE_H__
#define __SGL_PAGE_H__

#include "./sgl_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize a page, and whenever you create a page, you should call this function to initialize it
 * 
 * @param page: Newly created page structure address
 * 
 * @return none
*/
void sgl_page_init(sgl_obj_t *page);


/**
 * @brief Creating pages in a dynamic way, you must check if the return value is NULL
 * 
 * @param none
 * 
 * @return sgl_obj_t pointer: Point to the address of the created page structure
*/
sgl_obj_t* sgl_page_create(void);


/**
 * @brief Add an object to a page that must have already been initialized
 * 
 * @param page:  The page to which the object is added
 * @param obj:   Object, usually a control, has already been initialized
 * 
 * @return none
*/
void sgl_page_add_obj(sgl_obj_t *page, sgl_obj_t *obj);


/**
 * @brief Delete an object from the page, which must already be on the page
 * 
 * @param obj:  Objects to be deleted
 * 
 * @return none
*/
void sgl_page_del_obj(sgl_obj_t *obj);


/**
 * @brief Get the linked header of the linked list of objects on the page
 * 
 * @param page:  Page containing object linked list
 * 
 * @return sgl_list_node_t pointer: Pointer to the header of an object linked list
*/
sgl_list_node_t* sgl_page_get_obj_head(sgl_obj_t *page);


/**
 * @brief Determine whether an object is on the page
 * 
 * @param obj:  Operation object
 *
 * @return bool: true is in the list, false is not in the list
*/
bool sgl_page_obj_is_in_list(sgl_obj_t* obj);


/**
 * @brief Set the page style, this function can only set the background color to monochrome
 * 
 * @param page:  The page object
 * @param style: background color style
 * 
 * @return none
*/
void sgl_page_set_style(sgl_obj_t *page, sgl_style_t *style);


/**
 * @brief Set the background image of the page
 * 
 * @param page:  The page object
 * @param img:   Pointer to background image
 * 
 * @return none
*/
void sgl_page_set_background(sgl_obj_t *page, sgl_img_t *img);


/**
 * @brief Set a page to the active page, and once this function is called, the display screen 
 *        will switch to the set page
 * 
 * @param page:  The page object
 * 
 * @return none
*/
void sgl_page_set_active(sgl_obj_t *page);


/**
 * @brief Get the current activity page, this function will return a pointer to the activity page
 * 
 * @param none
 * 
 * @return sgl_obj_t: pointer to active page
*/
sgl_obj_t *sgl_page_get_active(void);



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_PAGE_H__
