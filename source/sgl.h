/* source/sgl.h
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

#ifndef __SGL_H__
#define __SGL_H__


#include "string.h"
#include "./core/sgl_core.h"
#include "./fonts/sgl_font.h"
#include "./widget/sgl_button.h"
#include "./widget/sgl_label.h"
#include "./widget/sgl_switch.h"
#include "./widget/sgl_battery.h"
#include "./widget/sgl_checkbox.h"
#include "./widget/sgl_radiobtn.h"
#include "./widget/sgl_number.h"
#include "./widget/sgl_pgsbar.h"
#include "./widget/sgl_arcbar.h"
#include "./widget/sgl_pixmap.h"


// prototype: sgl_rgb(uint8_t r, uint8_t g, uint8_t b)
#if (SGL_CONFIG_PANEL_PIXEL_DEPTH == 32 || SGL_CONFIG_PANEL_PIXEL_DEPTH == 24)
#define sgl_rgb(r,g,b)          (sgl_color_t){.blue=(b), .green=(g), .red=(r),}
#elif (SGL_CONFIG_PANEL_PIXEL_DEPTH == 16)
#if SGL_CONFIG_COLOR16_SWAP                   
#define sgl_rgb(r,g,b)          (sgl_color_t){.green_h = (g >>2) >> 3, .red = (r) >> 3, .blue = (b) >> 3, .green_l = (g >>2) & 0x7,}
#else
#define sgl_rgb(r,g,b)          (sgl_color_t){.blue=(b) >> 3, .green=(g) >> 2, .red=(r) >> 3,}
#endif
#else
//define sgl_rgb macro for other color type
#endif

#define SGL_RED              sgl_rgb(0xFF, 0, 0)
#define SGL_GREEN            sgl_rgb(0, 0xFF, 0)
#define SGL_BLUE             sgl_rgb(0, 0, 0xFF)
#define SGL_WHITE            sgl_rgb(0xFF, 0xFF, 0xFF)
#define SGL_BLACK            sgl_rgb(0, 0, 0)

#ifndef SGL_SRCACT_BACKGROUND_COLOR
#define SGL_SRCACT_BACKGROUND_COLOR    (SGL_WHITE)
#endif

#endif //__SGL_H__
