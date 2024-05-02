/* source/core/sgl_mem.c
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
#include "../core/sgl_core.h"
#include "./sgl_mem.h"
#include "./sgl_mem.h"
#include "./heap/heap_0.h"
#include "./heap/heap_tlsf.h"


#define SGL_MEM_TOTAL_SIZE   (SGL_CONFIG_HEAP_POOL_SIZE * 1024)

static char sgl_mem_pool[SGL_MEM_TOTAL_SIZE];


//to use a policy for memory alloc
#if SGL_CONFIG_HEAP_POLICY == 0

/**
 * @brief  sgl memory initializatin 
 * 
 * @param  none
 * 
 * @return none
*/
void sgl_mem_init(void)
{
    sgl_heap0_init(sgl_mem_pool, SGL_MEM_TOTAL_SIZE);
}


/**
 * @brief  sgl memory alloc, the function is unsafe, you should ensure that 
 *         the requested size is smaller than the free size of memory
 * 
 * @param  size   request size of memory
 * 
 * @return point to request memory address
*/
void* sgl_malloc(size_t size)
{
    return sgl_heap0_malloc(size);
}


/**
 * @brief  sgl memory free
 * 
 * @param  p  the pointer of request size of memory
 * 
 * @return none
*/
void sgl_free(void* p)
{
    sgl_heap0_free(p);
}


/**
 * @brief  get memory information, include total memory size, free size and used size
 * 
 * @param  none
 * 
 * @return memory information
*/
sgl_mem_monitor_t sgl_mem_get_monitor(void)
{
    sgl_mem_monitor_t info;
    //TODO
    return info;
}

#elif SGL_CONFIG_HEAP_POLICY == 1


#elif SGL_CONFIG_HEAP_POLICY == 2

#elif SGL_CONFIG_HEAP_POLICY == 3

#elif SGL_CONFIG_HEAP_POLICY == 4

#elif SGL_CONFIG_HEAP_POLICY == 5


/**
 * @brief  sgl memory initializatin 
 * 
 * @param  none
 * 
 * @return none
*/
void sgl_mem_init(void)
{
    tlsf_create_with_pool(sgl_mem_pool, SGL_MEM_TOTAL_SIZE);
}

/**
 * @brief  sgl memory alloc, the function is unsafe, you should ensure that 
 *         the requested size is smaller than the free size of memory
 * 
 * @param  size   request size of memory
 * 
 * @return point to request memory address
*/
void* sgl_malloc(size_t size)
{
    return tlsf_malloc(sgl_mem_pool, size);
}


/**
 * @brief  sgl memory free
 * 
 * @param  p  the pointer of request size of memory
 * 
 * @return none
*/
void sgl_free(void *p)
{
    tlsf_free(sgl_mem_pool, p);
}


/**
 * @brief  get memory information, include total memory size, free size and used size
 * 
 * @param  none
 * 
 * @return memory information
*/
sgl_mem_monitor_t sgl_mem_get_monitor(void)
{
    sgl_mem_monitor_t info;
    //TODO
    return info;
}

#elif SGL_CONFIG_HEAP_POLICY == 6

#else

#endif
