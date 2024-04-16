/* source/core/sgl_math.h
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

#ifndef __SGL_MATH_H__
#define __SGL_MATH_H__

#include "sgl_conf.h"

typedef struct sgl_trig {
    int16_t cos_h;
    int16_t sin_h;
} sgl_trig_t;


static inline int sgl_abs(int a)
{
    return a < 0 ? -a : a;
}

static inline int sgl_max(int a, int b)
{
    return a > b ? a : b;
}

sgl_trig_t sgl_trig(int16_t angle);
uint16_t sgl_sqrt(uint32_t x);
uint32_t sgl_digits10(uint64_t number);
void sgl_int64_to_str(int64_t number, char* str_out);
void sgl_float_to_str(float number, int dp, char* str_out);
uint16_t sgl_fast_atan2(int x, int y);


#endif //__SGL_MATH_H__
