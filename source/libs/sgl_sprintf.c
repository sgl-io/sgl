/* source/core/sgl_sprintf.c
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


int __sgl_sprintf(char * buffer, const char * format, va_list va)
{
    char tmp[256];
    int number;
    char *str;
    while(*format) {
        if(*format == '%') {
            switch(*(format + 1)) {
            case 0:
                *buffer++ = *format;
                *buffer = 0;
                return 0;
            case 'd':
                number = va_arg(va, int);
                sgl_int64_to_str(number, tmp);
                sgl_strcpy(buffer, tmp);
                buffer += sgl_strlen(tmp);
                format += 2;
                break;

            case 'x':
                number = va_arg(va, int);
                sgl_uint64_to_hexstr(number, tmp);
                sgl_strcpy(buffer, tmp);
                buffer += sgl_strlen(tmp);
                format += 2;
                break;

            case  's':
                str = va_arg(va, char*);
                sgl_strcpy(buffer, str);
                buffer += sgl_strlen(str);
                format += 2;
                break;

            case 'p':
                number = va_arg(va, int);
                sgl_uint64_to_hexstr(number, tmp);
                *buffer ++ = '0';
                *buffer ++ = 'x';
                sgl_strcpy(buffer, tmp);
                buffer += sgl_strlen(tmp);
                format += 2;
                break;

            default: 
                *buffer = *format;
                buffer ++;
                format ++;
                break;
            }
        }
        if(*format == 0) {
            *buffer = *format;
            return 0;
        }
        else 
        {
            *buffer = *format;
            format ++;
            buffer ++;
        }
    }
    va_end(va);
    *buffer = 0;
    return sgl_strlen(buffer);
}


/**
 * @brief Format string, this function may affect system real-time performance. 
 *        Please use this function with caution when calling
 * 
 * @param buffer:  Formatted output buffer
 * @param Content that needs to be formatted
 * 
 * @return Formatted length
*/
int sgl_sprintf(char * buffer, const char * format, ...)
{
    int ret = -1;
    va_list va;
    va_start(va, format);
    ret = __sgl_sprintf(buffer, format, va);
    va_end(va);
    return ret;
}
