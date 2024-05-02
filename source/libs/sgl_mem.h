/* source/core/sgl_mem.h
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


#ifndef __SGL_MEM_H__
#define __SGL_MEM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "./sgl_types.h"


/**
 * @brief Used to store information on heap memory
 * 
 * @total_size: Total heap size
 * @free_size: Free heap size
 * @used_size: Used heap size
*/
typedef struct sgl_mem_monitor {
    size_t total_size;
    size_t free_size;
    size_t used_size;
    
} sgl_mem_monitor_t;



/**
 * @brief  sgl memory initializatin, you should call it during system initialization
 * 
 * @param  none
 * 
 * @return none
*/
void sgl_mem_init(void);


/**
 * @brief  sgl memory alloc, the function is unsafe, you should ensure that 
 *         the requested size is smaller than the free size of memory
 * 
 * @param  size   request size of memory
 * 
 * @return point to request memory address
*/
void* sgl_malloc(size_t size);


/**
 * @brief  sgl memory free
 * 
 * @param  p  the pointer of request size of memory
 * 
 * @return none
*/
void sgl_free(void* p);


/**
 * @brief  get memory information, include total memory size, free size and used size
 * 
 * @param  none
 * 
 * @return memory information
*/
sgl_mem_monitor_t sgl_mem_get_monitor(void);


#ifdef __cplusplus
}
#endif


#endif //__SGL_MEM_H__
