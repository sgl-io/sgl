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


// newton algorithm
#if (SGL_CONFIG_SQRT_ALGO == 1)

uint16_t sgl_sqrt(uint32_t x)
{
    if( x==0 )
        return 0;
    double xk = 1, xk1 = 0; 
    double err = 1e-6; // err为误差，1e-6就是1乘10的-6次幂
    
    while( sgl_abs(xk-xk1) > err )
    {
        xk1 = xk;
        xk = ( xk + x/xk )/2; //迭代公式
    }
    return xk;
}

#elif (SGL_CONFIG_SQRT_ALGO == 2)

uint16_t sgl_sqrt(uint32_t x)
{
     uint32_t N, i;
     uint32_t tmp, ttp;  // 结果、循环计数
 
     if (x == 0)  // 被开方数，开方结果也为0
         return 0;
 
     N = 0;
     tmp = (x >> 30);  // 获取最高位：B[m-1]
     x <<= 2;
 
     if (tmp > 1)   // 最高位为1
     {
         N ++;      // 结果当前位为1，否则为默认的0
         tmp -= N;
     }
 
     for (i=15; i>0; i--)   // 求剩余的15位
     {
         N <<= 1;     // 左移一位
         tmp <<= 2;
         tmp += (x >> 30);  // 假设
         ttp = N;
         ttp = (ttp<<1)+1;
 
         x <<= 2;
         if (tmp >= ttp)   // 假设成立
         {
             tmp -= ttp;
             N ++;
         }
     }
     return N;
}

#else
    #error "SGL sqrt function is not support other"
#endif


const int16_t sgl_sin_cos_h[256] = {
    0x0000,0x00C9,0x0192,0x025B,0x0324,0x03ED,0x04B6,0x057F,
    0x0648,0x0711,0x07D9,0x08A2,0x096A,0x0A33,0x0AFB,0x0BC4,
    0x0C8C,0x0D54,0x0E1C,0x0EE3,0x0FAB,0x1072,0x113A,0x1201,
    0x12C8,0x138F,0x1455,0x151C,0x15E2,0x16A8,0x176E,0x1833,
    0x18F9,0x19BE,0x1A82,0x1B47,0x1C0B,0x1CCF,0x1D93,0x1E57,
    0x1F1A,0x1FDD,0x209F,0x2161,0x2223,0x22E5,0x23A6,0x2467,
    0x2528,0x25E8,0x26A8,0x2767,0x2826,0x28E5,0x29A3,0x2A61,
    0x2B1F,0x2BDC,0x2C99,0x2D55,0x2E11,0x2ECC,0x2F87,0x3041,
    0x30FB,0x31B5,0x326E,0x3326,0x33DF,0x3496,0x354D,0x3604,
    0x36BA,0x376F,0x3824,0x38D9,0x398C,0x3A40,0x3AF2,0x3BA5,
    0x3C56,0x3D07,0x3DB8,0x3E68,0x3F17,0x3FC5,0x4073,0x4121,
    0x41CE,0x427A,0x4325,0x43D0,0x447A,0x4524,0x45CD,0x4675,
    0x471C,0x47C3,0x4869,0x490F,0x49B4,0x4A58,0x4AFB,0x4B9D,
    0x4C3F,0x4CE0,0x4D81,0x4E20,0x4EBF,0x4F5D,0x4FFB,0x5097,
    0x5133,0x51CE,0x5268,0x5302,0x539B,0x5432,0x54C9,0x5560,
    0x55F5,0x568A,0x571D,0x57B0,0x5842,0x58D3,0x5964,0x59F3,
    0x5A82,0x5B0F,0x5B9C,0x5C28,0x5CB3,0x5D3E,0x5DC7,0x5E4F,
    0x5ED7,0x5F5D,0x5FE3,0x6068,0x60EB,0x616E,0x61F0,0x6271,
    0x62F1,0x6370,0x63EE,0x646C,0x64E8,0x6563,0x65DD,0x6656,
    0x66CF,0x6746,0x67BC,0x6832,0x68A6,0x6919,0x698B,0x69FD,
    0x6A6D,0x6ADC,0x6B4A,0x6BB7,0x6C23,0x6C8E,0x6CF8,0x6D61,
    0x6DC9,0x6E30,0x6E96,0x6EFB,0x6F5E,0x6FC1,0x7022,0x7083,
    0x70E2,0x7140,0x719D,0x71F9,0x7254,0x72AE,0x7307,0x735E,
    0x73B5,0x740A,0x745F,0x74B2,0x7504,0x7555,0x75A5,0x75F3,
    0x7641,0x768D,0x76D8,0x7722,0x776B,0x77B3,0x77FA,0x783F,
    0x7884,0x78C7,0x7909,0x794A,0x7989,0x79C8,0x7A05,0x7A41,
    0x7A7C,0x7AB6,0x7AEE,0x7B26,0x7B5C,0x7B91,0x7BC5,0x7BF8,
    0x7C29,0x7C59,0x7C88,0x7CB6,0x7CE3,0x7D0E,0x7D39,0x7D62,
    0x7D89,0x7DB0,0x7DD5,0x7DFA,0x7E1D,0x7E3E,0x7E5F,0x7E7E,
    0x7E9C,0x7EB9,0x7ED5,0x7EEF,0x7F09,0x7F21,0x7F37,0x7F4D,
    0x7F61,0x7F74,0x7F86,0x7F97,0x7FA6,0x7FB4,0x7FC1,0x7FCD,
    0x7FD8,0x7FE1,0x7FE9,0x7FF0,0x7FF5,0x7FF9,0x7FFD,0x7FFE
};


sgl_trig_t sgl_trig(int16_t angle)
{
    int32_t shindex;
    uint16_t uhindex;

    sgl_trig_t trig;

    /* 10 bit index computation  */
    shindex = ( ( int32_t )32768 + ( int32_t )angle );
    uhindex = ( uint16_t )shindex;
    //uhindex /= ( uint16_t )64;
    uhindex = uhindex >> 6;
    /**
     | hAngle    | angle  | std   |
    | (0,16384]   | U0_90  | (0,0.5] |
    | (16384,32767]  | U90_180  | (0.5,0.99]|
    | (-16384,-1]   | U270_360  | (0,-0.5]  |
    | (-16384,-32768] | U180_270  | (-0.5,-1) |
    */
    //SIN_MASK        0x0300u
    switch ( ( uint16_t )( uhindex ) & 0x0300u)
    {          
        //0~90
        case 0x0200u:
            trig.sin_h = sgl_sin_cos_h[( uint8_t )( uhindex )];
            trig.cos_h = sgl_sin_cos_h[( uint8_t )( 0xFFu - ( uint8_t )( uhindex ) )];
        break;
        //90~180
        case 0x0300u:
            trig.sin_h = sgl_sin_cos_h[( uint8_t )( 0xFFu - ( uint8_t )( uhindex ) )];
            trig.cos_h = - sgl_sin_cos_h[( uint8_t )( uhindex )];
        break;
        //180~270
        case 0x0000u:
            trig.sin_h = - sgl_sin_cos_h[( uint8_t )( uhindex )];
            trig.cos_h = - sgl_sin_cos_h[( uint8_t )( 0xFFu - ( uint8_t )( uhindex ) )];
        break;
        //270~360
        case 0x0100u:
            trig.sin_h =  - sgl_sin_cos_h[( uint8_t )( 0xFFu - ( uint8_t )( uhindex ) )];
            trig.cos_h =  sgl_sin_cos_h[( uint8_t )( uhindex )];
        break;
        default: break;
    }
    return trig;
}

uint32_t sgl_digits10(uint64_t number) 
{
    if (number < 10) return 1;
    if (number < 100) return 2;
    if (number < 1000) return 3;
    if (number < 1000000000000) {    // 10^12
        if (number < 100000000) {    // 10^8
            if (number < 1000000) {  // 10^6
                if (number < 10000) return 4;
                return 5 + (number >= 100000); // 10^5
            }
            return 7 + (number >= 10000000); // 10^7
        }
        if (number < 10000000000) {  // 10^10
            return 9 + (number >= 1000000000); // 10^9
        }
        return 11 + (number >= 100000000000); // 10^11
    }
    return 12 + sgl_digits10(number / 1000000000000); // 10^12
}

void sgl_int64_to_str(int64_t number, char* str_out)
{
    int text_len = 0;
    if(number > 0) {
        text_len = sgl_digits10(number);
    }
    else if(number < 0) {
        str_out[0] = '-';
        number = - number;
        text_len = sgl_digits10(number) + 1;
    }
    else {
        str_out[0] = '0';
        str_out[1] = 0;
        return ;
    }
    str_out[text_len] = 0;
    while(number) {
        text_len -- ;
        str_out[text_len] = (number%10) + 48;
        number /= 10;
    }
}

//refrence: TFT_eSPI::drawFloat
void sgl_float_to_str(float number, int dp, char* str_out)
{
    uint8_t ptr = 0;            // Initialise pointer for array
    int8_t  digits = 1;         // Count the digits to avoid array overflow
    float rounding = 0.5;       // Round up down delta
    bool negative = false;

    if (dp > 7) dp = 7; // Limit the size of decimal portion

    // Adjust the rounding value
    for (uint8_t i = 0; i < dp; ++i) rounding /= 10.0;

    if (number < -rounding) {   // add sign, avoid adding - sign to 0.0!
        str_out[ptr++] = '-'; // Negative number
        str_out[ptr] = 0; // Put a null in the array as a precaution
        digits = 0;   // Set digits to 0 to compensate so pointer value can be used later
        number = -number; // Make positive
        negative = true;
    }

    number += rounding; // Round up or down

    if (dp == 0) {
        if (negative) number = -number;
        sgl_int64_to_str(number, str_out);
        return;
    }

    // For error put ... in string and return (all TFT_eSPI library fonts contain . character)
    if (number >= 2147483647) {
        strcpy(str_out, "...");
        return;
    }
    // No chance of overflow from here on

    // Get integer part
    uint32_t temp = (uint32_t)number;

    // Put integer part into array
    sgl_int64_to_str(temp, str_out + ptr);

    // Find out where the null is to get the digit count loaded
    while ((uint8_t)str_out[ptr] != 0) ptr++; // Move the pointer along
    digits += ptr;                  // Count the digits

    str_out[ptr++] = '.'; // Add decimal point
    str_out[ptr] = '0';   // Add a dummy zero
    str_out[ptr + 1] = 0; // Add a null but don't increment pointer so it can be overwritten

    // Get the decimal portion
    number = number - temp;

    // Get decimal digits one by one and put in array
    // Limit digit count so we don't get a false sense of resolution
    uint8_t i = 0;
    while ((i < dp) && (digits < 9)) { // while (i < dp) for no limit but array size must be increased
        i++;
        number *= 10;       // for the next decimal
        temp = number;      // get the decimal
        sgl_int64_to_str(temp, str_out + ptr);
        ptr++; digits++;         // Increment pointer and digits count
        number -= temp;     // Remove that digit
    }
}


uint16_t sgl_fast_atan2(int x, int y)
{
    // Fast XY vector to integer degree algorithm - Jan 2011 www.RomanBlack.com
    // Converts any XY values including 0 to a degree value that should be
    // within +/- 1 degree of the accurate value without needing
    // large slow trig functions like ArcTan() or ArcCos().
    // NOTE! at least one of the X or Y values must be non-zero!
    // This is the full version, for all 4 quadrants and will generate
    // the angle in integer degrees from 0-360.
    // Any values of X and Y are usable including negative values provided
    // they are between -1456 and 1456 so the 16bit multiply does not overflow.
    unsigned char negflag;
    unsigned char tempdegree;
    unsigned char comp;
    unsigned int degree;     // this will hold the result
    //signed int x;            // these hold the XY vector at the start
    //signed int y;            // (and they will be destroyed)
    unsigned int ux;
    unsigned int uy;

    // Save the sign flags then remove signs and get XY as unsigned ints
    negflag = 0;
    if(x < 0)
    {
        negflag += 0x01;    // x flag bit
        x = (0 - x);        // is now +
    }
    ux = x;                // copy to unsigned var before multiply
    if(y < 0)
    {
        negflag += 0x02;    // y flag bit
        y = (0 - y);        // is now +
    }
    uy = y;                // copy to unsigned var before multiply

    // 1. Calc the scaled "degrees"
    if(ux > uy)
    {
        degree = (uy * 45) / ux;   // degree result will be 0-45 range
        negflag += 0x10;    // octant flag bit
    }
    else
    {
        degree = (ux * 45) / uy;   // degree result will be 0-45 range
    }

    // 2. Compensate for the 4 degree error curve
    comp = 0;
    tempdegree = degree;    // use an unsigned char for speed!
    if(tempdegree > 22)      // if top half of range
    {
        if(tempdegree <= 44) comp++;
        if(tempdegree <= 41) comp++;
        if(tempdegree <= 37) comp++;
        if(tempdegree <= 32) comp++;  // max is 4 degrees compensated
    }
    else    // else is lower half of range
    {
        if(tempdegree >= 2) comp++;
        if(tempdegree >= 6) comp++;
        if(tempdegree >= 10) comp++;
        if(tempdegree >= 15) comp++;  // max is 4 degrees compensated
    }
    degree += comp;   // degree is now accurate to +/- 1 degree!

    // Invert degree if it was X>Y octant, makes 0-45 into 90-45
    if(negflag & 0x10) degree = (90 - degree);

    // 3. Degree is now 0-90 range for this quadrant,
    // need to invert it for whichever quadrant it was in
    if(negflag & 0x02)   // if -Y
    {
    if(negflag & 0x01)   // if -Y -X
        degree = (180 + degree);
    else        // else is -Y +X
        degree = (180 - degree);
    }
    else    // else is +Y
    {
    if(negflag & 0x01)   // if +Y -X
        degree = (360 - degree);
    }
    return degree;
}
