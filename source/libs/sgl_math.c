/* source/core/sgl_math.c
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

#include <stdint.h>
#include "./sgl_math.h"
#include "string.h"

/**
 * sin table, refrence LVGL implement
*/
static const uint16_t sin0_90_table[] = {
    0,     572,   1144,  1715,  2286,  2856,  3425,  3993,  4560,  5126,  5690,  6252,  6813,  7371,  7927,  8481,
    9032,  9580,  10126, 10668, 11207, 11743, 12275, 12803, 13328, 13848, 14365, 14876, 15384, 15886, 16384, 16877,
    17364, 17847, 18324, 18795, 19261, 19720, 20174, 20622, 21063, 21498, 21926, 22348, 22763, 23170, 23571, 23965,
    24351, 24730, 25102, 25466, 25822, 26170, 26510, 26842, 27166, 27482, 27789, 28088, 28378, 28660, 28932, 29197,
    29452, 29698, 29935, 30163, 30382, 30592, 30792, 30983, 31164, 31336, 31499, 31651, 31795, 31928, 32052, 32166,
    32270, 32365, 32449, 32524, 32588, 32643, 32688, 32723, 32748, 32763, 32768
};


/**
 * @brief calculate sin value by round angle
 * 
 * @param angle  angle of round, should be in [0,360]
 * 
 * @return sin value, should be in [-32768, 32768]
*/
int32_t sgl_trigo_sin(int16_t angle)
{
    int32_t ret = 0;
    while(angle < 0) angle += 360;
    while(angle >= 360) angle -= 360;

    if(angle < 90) {
        ret = sin0_90_table[angle];
    }
    else if(angle >= 90 && angle < 180) {
        angle = 180 - angle;
        ret   = sin0_90_table[angle];
    }
    else if(angle >= 180 && angle < 270) {
        angle = angle - 180;
        ret   = -sin0_90_table[angle];
    }
    else {   /*angle >=270*/
        angle = 360 - angle;
        ret   = -sin0_90_table[angle];
    }

    if(ret == 32767) return 32768;
    else if(ret == -32767) return -32768;
    else return ret;
}


/**
 * @brief calculate cos value by round angle
 * 
 * @param angle  angle of round, should be in [0,360]
 * 
 * @return cos value, should be in [-32768, 32768]
*/
int32_t sgl_trigo_cos(int16_t angle)
{
    int32_t ret = 0;
    while(angle < 0) angle += 360;
    while(angle >= 360) angle -= 360;

    if(angle < 90) {
        ret = sin0_90_table[90 - angle];
    }
    else if(angle >= 90 && angle < 180) {
        angle = 180 - angle;
        ret   = sin0_90_table[90 - angle];
    }
    else if(angle >= 180 && angle < 270) {
        angle = angle - 180;
        ret   = -sin0_90_table[90 - angle];
    }
    else {   /*angle >=270*/
        angle = 360 - angle;
        ret   = -sin0_90_table[90 - angle];
    }

    if(ret == 32767) return 32768;
    else if(ret == -32767) return -32768;
    else return ret;
}


/**
 * @brief calculate square root
 * 
 * @param square source
 * 
 * @return value of square root
*/
uint16_t sgl_sqrt(uint32_t x)
{
    uint32_t rem = 0;
    uint32_t root = 0;
    uint32_t divisor = 0;

    for(int i=0; i<16; i++) {
        root <<= 1;
        rem = ((rem << 2) + (x >> 30));
        x <<= 2;
        divisor = (root<<1) + 1;
        
        if(divisor <= rem) {
            rem -= divisor;
            root++;
        }
    }
    return (uint16_t)(root);
}


/**
 * @brief Calculate the angle based on the x and y coordinates. This function is a fast algorithm 
 *        implementation, with reference address: www.RomanBlack.com (Fast XY vector to integer degree algorithm)
 * 
 * @param x:  The x coordinate on a circle
 * @param y:  The y coordinate on a circle
 * 
 * @return angle
*/
uint16_t sgl_fast_atan2(int x, int y)
{
    unsigned char negflag;
    unsigned char tempdegree;
    unsigned char comp;
    unsigned int degree;
    unsigned int ux;
    unsigned int uy;
    negflag = 0;
    if(x < 0)
    {
        negflag += 0x01;
        x = (0 - x);
    }
    ux = x;
    if(y < 0)
    {
        negflag += 0x02;
        y = (0 - y);
    }
    uy = y;

    if(ux > uy)
    {
        degree = (uy * 45) / ux;
        negflag += 0x10;
    }
    else
    {
        degree = (ux * 45) / uy;
    }

    comp = 0;
    tempdegree = degree;
    if(tempdegree > 22)
    {
        if(tempdegree <= 44) comp++;
        if(tempdegree <= 41) comp++;
        if(tempdegree <= 37) comp++;
        if(tempdegree <= 32) comp++;
    }
    else
    {
        if(tempdegree >= 2) comp++;
        if(tempdegree >= 6) comp++;
        if(tempdegree >= 10) comp++;
        if(tempdegree >= 15) comp++;
    }
    degree += comp;

    if(negflag & 0x10) degree = (90 - degree);

    if(negflag & 0x02)
    {
    if(negflag & 0x01)
        degree = (180 + degree);
    else
        degree = (180 - degree);
    }
    else
    {
    if(negflag & 0x01)
        degree = (360 - degree);
    }
    return degree;
}
