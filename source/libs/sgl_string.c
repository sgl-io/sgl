/* source/core/sgl_string.c
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

#include "./sgl_string.h"
#include "./sgl_mem.h"

#define ALIGN_MASK  0x3
#define _COPY(d, s) *d = *s; d++; s++;
#define _SET(d, v) *d = v; d++;
#define _REPEAT8(expr) expr expr expr expr expr expr expr expr


/**
 * @brief Memory Copy Function
 * 
 * @param dst: Destination memory address
 * @param src: Source memory address
 * @param len: Size of copied memory in bytes
 * 
 * @return none
*/
void * sgl_memcpy(void * dst, const void * src, size_t len)
{
    uint8_t * d8 = (uint8_t *)dst;
    const uint8_t * s8 = (uint8_t *)src;

    /*Simplify for small memories*/
    if(len < 16) {
        while(len) {
            *d8 = *s8;
            d8++;
            s8++;
            len--;
        }
        return dst;
    }

    uintptr_t d_align = (uintptr_t)d8 & ALIGN_MASK;
    uintptr_t s_align = (uintptr_t)s8 & ALIGN_MASK;

    /*Byte copy for unaligned memories*/
    if(s_align != d_align) {
        while(len > 32) {
            _REPEAT8(_COPY(d8, s8));
            _REPEAT8(_COPY(d8, s8));
            _REPEAT8(_COPY(d8, s8));
            _REPEAT8(_COPY(d8, s8));
            len -= 32;
        }
        while(len) {
            _COPY(d8, s8)
            len--;
        }
        return dst;
    }

    /*Make the memories aligned*/
    if(d_align) {
        d_align = ALIGN_MASK + 1 - d_align;
        while(d_align && len) {
            _COPY(d8, s8);
            d_align--;
            len--;
        }
    }

    uint32_t * d32 = (uint32_t *)d8;
    const uint32_t * s32 = (uint32_t *)s8;
    while(len > 32) {
        _REPEAT8(_COPY(d32, s32))
        len -= 32;
    }

    d8 = (uint8_t *)d32;
    s8 = (const uint8_t *)s32;
    while(len) {
        _COPY(d8, s8)
        len--;
    }
    return dst;
}


/**
 * @brief Memory initialization function, used to quickly initialize a segment of memory 
 *        and initialize it all to specific values
 * 
 * @param dst: Destination memory address
 * @param v:   Initialized value
 * @param len: Size of copied memory in bytes
 * 
 * @return none
*/
void sgl_memset(void * dst, uint8_t v, size_t len)
{
    uint8_t * d8 = (uint8_t *)dst;
    uintptr_t d_align = (uintptr_t) d8 & ALIGN_MASK;

    /*Make the address aligned*/
    if(d_align) {
        d_align = ALIGN_MASK + 1 - d_align;
        while(d_align && len) {
            _SET(d8, v);
            len--;
            d_align--;
        }
    }

    uint32_t v32 = (uint32_t)v + ((uint32_t)v << 8) + ((uint32_t)v << 16) + ((uint32_t)v << 24);
    uint32_t * d32 = (uint32_t *)d8;

    while(len > 32) {
        _REPEAT8(_SET(d32, v32));
        len -= 32;
    }

    d8 = (uint8_t *)d32;
    while(len) {
        _SET(d8, v);
        len--;
    }
}


/**
 * @brief Move data from one segment of memory to another segment of memory
 * 
 * @param dst:  Destination memory address
 * @param src:  Source memory address
 * @param len:  Size of copied memory in bytes
 * 
 * @return none
*/
void * sgl_memmove(void * dst, const void * src, size_t len)
{
    if(dst < src || (char *)dst > ((char *)src + len)) {
        return sgl_memcpy(dst, src, len);
    }

    if(dst > src) {
        char * tmp = (char *)dst + len - 1;
        char * s   = (char *)src + len - 1;

        while(len--) {
            *tmp-- = *s--;
        }
    }
    else {
        char * tmp = (char *)dst;
        char * s   = (char *)src;

        while(len--) {
            *tmp++ = *s++;
        }
    }

    return dst;
}


/**
 * @brief Compare whether the data in two memory segments is the same
 * 
 * @param p1:  Pointer to one of the memory addresses
 * @param p2:  Pointer to one of the memory addresses
 * @param len: Size of copied memory in bytes
 * 
 * @return none
*/
int32_t sgl_memcmp(const void * p1, const void * p2, size_t len)
{
    const char * s1 = (const char *) p1;
    const char * s2 = (const char *) p2;
    while(--len > 0 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}


/**
 * @brief Get the length of a string
 * 
 * @param str: Pointing to a string
 * 
 * @return The length of the string
*/
size_t sgl_strlen(const char * str)
{
    size_t i = 0;
    while(str[i]) i++;

    return i;
}


/**
 * @brief String copying, copying one string to another memory
 * 
 * @param dst:  Destination memory address
 * @param src:  Pointer to string
 * @param dst_size: Memory size to be copied
 * 
 * @return the address of the target memory
*/
char * sgl_strncpy(char * dst, const char * src, size_t dst_size)
{
    size_t i;
    for(i = 0; i < dst_size - 1 && src[i]; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}


/**
 * @brief String copying, copying one string to another memory
 * 
 * @param dst:  Destination memory address
 * @param src:  Pointer to string
 * 
 * @return the address of the target memory
*/
char * sgl_strcpy(char * dst, const char * src)
{
    char * tmp = dst;
    while((*dst++ = *src++) != '\0');
    return tmp;
}


/**
 * @brief Compare two strings to see if they are the same
 * 
 * @param s1:  Pointer to string1
 * @param s2:  Pointer to string2
 * 
 * @return If str1 is less than str2, return less than 0; If str1 is greater than str2 
 *         and greater than 0; If both are equal, return 0
*/
int32_t sgl_strcmp(const char * s1, const char * s2)
{
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}


/**
 * @brief Copy the string to the newly created location
 * 
 * @param src:  Pointer to string
 * 
 * @return Returns a pointer to the space allocated for copying a string; 
 *         If space allocation fails, return a NULL value.
*/
char * sgl_strdup(const char * src)
{
    size_t len = sgl_strlen(src) + 1;
    char * dst = (char *)sgl_malloc(len);
    if(dst == NULL) return NULL;

    sgl_memcpy(dst, src, len);
    return dst;
}


/**
 * @brief Copy the string pointed to by src (including "\ 0") after the string pointed to by 
 *        dest (remove "\ 0" from the original end of * dest). Ensure that * dest is long enough 
 *        to accommodate the copied * src* The original characters in src remain unchanged. 
 *        Returns a pointer to dest.
 * 
 * @param dst:  Destination memory address
 * @param src:  Pointer to string
 * 
 * @return Pointer to dest
*/
char * sgl_strcat(char * dst, const char * src)
{
    sgl_strcpy(dst + sgl_strlen(dst), src);
    return dst;
}


/**
 * @brief Add the first n characters of the string referred to by src to the end of the 
 *        string referred to by dest, and overwrite the '\ 0' at the end of the string 
 *        referred to by dest to achieve string concatenation.
 * 
 * @param dst:  Destination memory address
 * @param src:  Pointer to string
 * @param src_len: The length of the string to be added
 * 
 * @return Pointer to dest
*/
char * sgl_strncat(char * dst, const char * src, size_t src_len)
{
    char * tmp = dst;
    while(*dst != '\0') {
        dst++;
    }
    while(src_len != 0 && *src != '\0') {
        src_len--;
        *dst++ = *src++;
    }
    *dst = '\0';
    return tmp;
}


/**
 * @brief Calculate the digits of a decimal number
 * 
 * @param number  decimal number
 * 
 * @return digits of a decimal number
*/
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


/**
 * @brief Convert int64 type to a string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
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


/**
 * @brief Convert uint64 type to a string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_uint64_to_str(uint64_t number, char* str_out)
{
    int text_len = 0;
    if(number > 0) {
        text_len = sgl_digits10(number);
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


/**
 * @brief Convert int64 type to a hex string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_int64_to_hexstr(int64_t number, char* str_out)
{
    int i = 0;
    while (number) {
        if (number < 0) {
            str_out[i++] = '-';
            number = -number;
        }
        str_out[i] = number % 16;
        if (str_out[i] > 9) {
            str_out[i] += 87;
            i++;
        }
        else {
            str_out[i] += 48;
            i++;
        }
        number /= 16;
    }
    str_out[i] = '\0';
    int left = (str_out[0] == '-') ? 1 : 0, right = i - 1;
    while (left < right) {
        char temp = str_out[left];
        str_out[left] = str_out[right];
        str_out[right] = temp;
        left++;
        right--;
    }
}


/**
 * @brief Convert uint64 type to a hex string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_uint64_to_hexstr(uint64_t number, char* str_out)
{
    int i = 0;
    while (number) {
        str_out[i] = number % 16;
        if (str_out[i] > 9) {
            str_out[i] += 87;
            i++;
        }
        else {
            str_out[i] += 48;
            i++;
        }
        number /= 16;
    }
    str_out[i] = '\0';
    int left = (str_out[0] == '-') ? 1 : 0, right = i - 1;
    while (left < right) {
        char temp = str_out[left];
        str_out[left] = str_out[right];
        str_out[right] = temp;
        left++;
        right--;
    }
}


/**
 * @brief Convert float to string, refrence: TFT_eSPI::drawFloat
 * 
 * @param number:  Number to be converted
 * @param dp:      Decimal places
 * @param str_out: Converted string output
 * 
 * @return none
*/
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
        sgl_strcpy(str_out, "...");
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

