/* source/core/heap_0.h
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

#ifndef __HEAP_0_H__
#define __HEAP_0_H__

#include <stddef.h>
#include "../sgl_types.h"

#if defined(__cplusplus)
extern "C" {
#endif

void sgl_heap0_init(void *mem, size_t size);


/**
 * @brief  sgl memory alloc, the function is unsafe, you should ensure that 
 *         the requested size is smaller than the free size of memory
 * 
 * @param  size   request size of memory
 * 
 * @return point to request memory address
*/
void* sgl_heap0_malloc(size_t size);


/**
 * @brief  sgl memory free
 * 
 * @param  p  the pointer of request size of memory
 * 
 * @return none
*/
void sgl_heap0_free(void* p);



#if defined(__cplusplus)
};
#endif

#endif
