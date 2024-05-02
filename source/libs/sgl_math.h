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

#ifdef __cplusplus
extern "C" {
#endif

#include "sgl_conf.h"
#include "sgl_types.h"

typedef struct sgl_trigo {
    int16_t cos_h;
    int16_t sin_h;
} sgl_trigo_t;


#define sgl_min(a, b) ((a) < (b) ? (a) : (b))
#define sgl_min3(a, b, c) (sgl_min(sgl_min(a,b), c))
#define sgl_min4(a, b, c, d) (sgl_min(sgl_min(a,b), sgl_min(c,d)))


#define sgl_max(a, b) ((a) > (b) ? (a) : (b))
#define sgl_max3(a, b, c) (sgl_max(sgl_max(a,b), c))
#define sgl_max4(a, b, c, d) (sgl_max(sgl_max(a,b), sgl_max(c,d)))

#define sgl_clamp(min, val, max) (sgl_max(min, (sgl_min(val, max))))

#define sgl_abs(x) ((x) > 0 ? (x) : (-(x)))


/**
 * @brief calculate sin value by round angle
 * 
 * @param angle  angle of round, should be in [0,360]
 * 
 * @return sin value, should be in [-32768, 32768]
*/
int32_t sgl_trigo_sin(int16_t angle);


/**
 * @brief calculate cos value by round angle
 * 
 * @param angle  angle of round, should be in [0,360]
 * 
 * @return cos value, should be in [-32768, 32768]
*/
int32_t sgl_trigo_cos(int16_t angle);


/**
 * @brief calculate square root
 * 
 * @param square source
 * 
 * @return value of square root
*/
uint16_t sgl_sqrt(uint32_t x);


/**
 * @brief Calculate the angle based on the x and y coordinates. This function is a fast algorithm 
 *        implementation, with reference address: www.RomanBlack.com (Fast XY vector to integer degree algorithm)
 * 
 * @param x:  The x coordinate on a circle
 * @param y:  The y coordinate on a circle
 * 
 * @return angle
*/
uint16_t sgl_fast_atan2(int x, int y);


#ifdef __cplusplus
}
#endif

#endif //__SGL_MATH_H__
