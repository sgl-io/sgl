/* source/core/sgl_string.h
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

#ifndef  __SGL_STRING_H__
#define  __SGL_STRING_H__

#include "./sgl_types.h"
#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif


int __sgl_sprintf(char * buffer, const char * format, va_list va);


/**
 * @brief Format string, this function may affect system real-time performance. 
 *        Please use this function with caution when calling
 * 
 * @param buffer:  Formatted output buffer
 * @param Content that needs to be formatted
 * 
 * @return Formatted length
*/
int sgl_sprintf(char * buffer, const char * format, ...);


/**
 * @brief Memory Copy Function
 * 
 * @param dst: Destination memory address
 * @param src: Source memory address
 * @param len: Size of copied memory in bytes
 * 
 * @return none
*/
void * sgl_memcpy(void * dst, const void * src, size_t len);


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
void sgl_memset(void * dst, uint8_t v, size_t len);


/**
 * @brief Move data from one segment of memory to another segment of memory
 * 
 * @param dst:  Destination memory address
 * @param src:  Source memory address
 * @param len:  Size of copied memory in bytes
 * 
 * @return none
*/
void * sgl_memmove(void * dst, const void * src, size_t len);


/**
 * @brief Compare whether the data in two memory segments is the same
 * 
 * @param p1:  Pointer to one of the memory addresses
 * @param p2:  Pointer to one of the memory addresses
 * @param len: Size of copied memory in bytes
 * 
 * @return none
*/
int32_t sgl_memcmp(const void * p1, const void * p2, size_t len);


/**
 * @brief Get the length of a string
 * 
 * @param str: Pointing to a string
 * 
 * @return The length of the string
*/
size_t sgl_strlen(const char * str);


/**
 * @brief String copying, copying one string to another memory
 * 
 * @param dst:  Destination memory address
 * @param src:  Pointer to string
 * @param dst_size: Memory size to be copied
 * 
 * @return the address of the target memory
*/
char * sgl_strncpy(char * dst, const char * src, size_t dst_size);


/**
 * @brief String copying, copying one string to another memory
 * 
 * @param dst:  Destination memory address
 * @param src:  Pointer to string
 * 
 * @return the address of the target memory
*/
char * sgl_strcpy(char * dst, const char * src);


/**
 * @brief Compare two strings to see if they are the same
 * 
 * @param s1:  Pointer to string1
 * @param s2:  Pointer to string2
 * 
 * @return If str1 is less than str2, return less than 0; If str1 is greater than str2 
 *         and greater than 0; If both are equal, return 0
*/
int32_t sgl_strcmp(const char * s1, const char * s2);


/**
 * @brief Copy the string to the newly created location
 * 
 * @param src:  Pointer to string
 * 
 * @return Returns a pointer to the space allocated for copying a string; 
 *         If space allocation fails, return a NULL value.
*/
char * sgl_strdup(const char * src);


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
char * sgl_strcat(char * dst, const char * src);


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
char * sgl_strncat(char * dst, const char * src, size_t src_len);


/**
 * @brief Calculate the digits of a decimal number
 * 
 * @param number  decimal number
 * 
 * @return digits of a decimal number
*/
uint32_t sgl_digits10(uint64_t number);


/**
 * @brief Convert int64 type to a string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_int64_to_str(int64_t number, char* str_out);


/**
 * @brief Convert uint64 type to a string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_uint64_to_str(uint64_t number, char* str_out);


/**
 * @brief Convert int64 type to a hex string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_int64_to_hexstr(int64_t number, char* str_out);


/**
 * @brief Convert uint64 type to a hex string type
 * 
 * @param number:  Number to be converted
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_uint64_to_hexstr(uint64_t number, char* str_out);


/**
 * @brief Convert float to string, refrence: TFT_eSPI::drawFloat
 * 
 * @param number:  Number to be converted
 * @param dp:      Decimal places
 * @param str_out: Converted string output
 * 
 * @return none
*/
void sgl_float_to_str(float number, int dp, char* str_out);



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_STRING_H__
