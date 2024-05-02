#include "./heap_0.h"
#include "sgl_conf.h"

#if SGL_CONFIG_HEAP_POLICY == 0

static void* mem_pool = NULL;
static size_t all_mem_size = 0;
static size_t used_mem_size = 0;

#define SGL_CONFIG_HEAP_ALIGN  4
#define SGL_HEAP_ALIGN_MASK (SGL_CONFIG_HEAP_ALIGN - 1)


void sgl_heap0_init(void *mem, size_t size)
{
    mem_pool = mem;
    all_mem_size = size;
}


/**
 * @brief  sgl memory alloc, the function is unsafe, you should ensure that 
 *         the requested size is smaller than the free size of memory
 * 
 * @param  size   request size of memory
 * 
 * @return point to request memory address
*/
void* sgl_heap0_malloc(size_t size)
{
    void *ret = NULL;
    if((size & SGL_HEAP_ALIGN_MASK) != 0) {
        size += (SGL_CONFIG_HEAP_ALIGN - (size & SGL_HEAP_ALIGN_MASK));
    }
    if(size <= (all_mem_size - used_mem_size)) {
        ret = (void*)&((char*)mem_pool)[used_mem_size];
        used_mem_size += size;
    }
    return ret;
}


/**
 * @brief  sgl memory free
 * 
 * @param  p  the pointer of request size of memory
 * 
 * @return none
*/
void sgl_heap0_free(void* p)
{
    //nothing to do
}

#endif //SGL_CONFIG_HEAP_POLICY == 0
