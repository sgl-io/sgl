/* source/fonts/sgl_font.h
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

#ifndef __SGL_FONT_H__
#define __SGL_FONT_H__

#include "../core/sgl_core.h"
#include "../draw/sgl_draw.h"
#include "../draw/sgl_draw_font.h"

#ifdef __cplusplus
extern "C"{
#endif

#if(SGL_CONFIG_FONT_CONSOLAS12 == 1)
extern sgl_font_t consolas12;
#endif

#if(SGL_CONFIG_FONT_CONSOLAS15 == 1)
extern sgl_font_t consolas15;
#endif

#if(SGL_CONFIG_FONT_SONG10 == 1)
extern sgl_font_t song10;
#endif

#if(SGL_CONFIG_FONT_SONG23 == 1)
extern sgl_font_t song23;
#endif

#if(SGL_CONFIG_FONT_CASCADIA_MONO17 == 1)
extern sgl_font_t cascadia_mono17;
#endif

#if(SGL_CONFIG_FONT_SONG12 == 1)
extern sgl_font_t song12;
#endif


#ifdef __cplusplus
}
#endif

#endif //__SGL_FONT_H__

