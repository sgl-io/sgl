/* source/core/sgl_log.c
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

#include "./sgl_log.h"
#include "../libs/sgl_string.h"
#include "stdarg.h"
#include "./sgl_device.h"

#if SGL_CONFIG_DEBUG

/**
 * @brief SGL log printing function, used to print debugging information. Note that this function 
 *        should only be called in debugging mode, otherwise it may affect system real-time 
 *        performance due to long execution time
 * 
 * @param info:  log information, such as, INFO, USER...
 * @param format:  log content
 * 
 * @return none
*/
void sgl_log(const char *info, const char * format, ...)
{
    sgl_device_stdout_t *out_dev;
    char buffer[256];
    char *p = buffer;
    sgl_strcpy(p, info);
    p += sgl_strlen(info);
    va_list va;
    va_start(va, format);
    __sgl_sprintf(p, format, va);
    va_end(va);
    out_dev = sgl_device_get_stdout();
    if(out_dev != NULL) {
        out_dev->put(buffer);
    }
}

#endif
