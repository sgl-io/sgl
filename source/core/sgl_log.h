/* source/core/sgl_log.h
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

#ifndef __SGL_LOG_H__
#define __SGL_LOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "./sgl_core.h"


#define SGL_LOG_LEVEL_TRACE 0 /**< A lot of logs to give detailed information*/
#define SGL_LOG_LEVEL_INFO  1 /**< Log important events*/
#define SGL_LOG_LEVEL_WARN  2 /**< Log if something unwanted happened but didn't caused problem*/
#define SGL_LOG_LEVEL_ERROR 3 /**< Only critical issue, when the system may fail*/
#define SGL_LOG_LEVEL_USER  4 /**< Custom logs from the user*/
#define SGL_LOG_LEVEL_NONE  5 /**< Do not log anything*/
#define _SGL_LOG_LEVEL_NUM  6 /**< Number of log levels*/


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
void sgl_log(const char *info, const char * format, ...);


#ifndef SGL_LOG_TRACE
#    if SGL_CONFIG_LOG_LEVEL <= SGL_LOG_LEVEL_TRACE
#        define SGL_LOG_TRACE(...) sgl_log("[TRACE] ", __VA_ARGS__)
#    else
#        define SGL_LOG_TRACE(...) do {}while(0)
#    endif
#endif

#ifndef SGL_LOG_INFO
#    if SGL_CONFIG_LOG_LEVEL <= SGL_LOG_LEVEL_INFO
#        define SGL_LOG_INFO(...) sgl_log("[INFO] ",  __VA_ARGS__)
#    else
#        define SGL_LOG_INFO(...) do {}while(0)
#    endif
#endif

#ifndef SGL_LOG_WARN
#    if SGL_CONFIG_LOG_LEVEL <= SGL_LOG_LEVEL_WARN
#        define SGL_LOG_WARN(...) sgl_log("[WARN]", __VA_ARGS__)
#    else
#        define SGL_LOG_WARN(...) do {}while(0)
#    endif
#endif

#ifndef SGL_LOG_ERROR
#    if SGL_CONFIG_LOG_LEVEL <= SGL_LOG_LEVEL_ERROR
#        define SGL_LOG_ERROR(...) sgl_log("[ERROR] ", __VA_ARGS__)
#    else
#        define SGL_LOG_ERROR(...) do {}while(0)
#    endif
#endif

#ifndef SGL_LOG_USER
#    if SGL_CONFIG_LOG_LEVEL <= SGL_LOG_LEVEL_USER
#        define SGL_LOG_USER(...) sgl_log("[USER] ",  __VA_ARGS__)
#    else
#        define SGL_LOG_USER(...) do {}while(0)
#    endif
#endif

#if SGL_CONFIG_LOG_LEVEL < SGL_LOG_LEVEL_NONE
#    define SGL_LOG(...) sgl_log(__VA_ARGS__)
#else
#    define SGL_LOG(...) do {} while(0)
#endif

#else

#define SGL_LOG_TRACE(...) do {}while(0)
#define SGL_LOG_INFO(...) do {}while(0)
#define SGL_LOG_WARN(...) do {}while(0)
#define SGL_LOG_ERROR(...) do {}while(0)
#define SGL_LOG_USER(...) do {}while(0)
#define SGL_LOG(...) do {}while(0)

#endif


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //__SGL_LOG_H__
