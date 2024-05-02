/* source/draw/sgl_draw_font.h
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

#ifndef __SGL_DRAW_FONT_H__
#define __SGL_DRAW_FONT_H__

#include "../core/sgl_core.h"
#include "./sgl_draw.h"


#if(SGL_CONFIG_TEXT_UTF8 == 1)
uint32_t sgl_utf8_to_unicode(const uint8_t *utf8_str, uint32_t *p_unicode_buffer);
uint32_t sgl_search_unicode_ch_index(sgl_font_t *font, uint32_t unicode);
#endif

void sgl_draw_font( sgl_surf_t *surf, int16_t x, int16_t y, 
                    uint32_t ch_index,
                    sgl_color_t color, sgl_color_t bg_color, 
                    sgl_font_t *font);

void sgl_draw_font_string( sgl_surf_t *surf, int16_t x, int16_t y, 
                           const char *string, 
                           sgl_color_t color, sgl_color_t bg_color, 
                           sgl_font_t *font);

void sgl_draw_font_string_len( sgl_surf_t *surf, int16_t x, int16_t y, 
                               const char *string, int len, sgl_color_t color, sgl_color_t bg_color, 
                               sgl_font_t *font);

void sgl_draw_font_on_bg( sgl_surf_t *surf, int16_t x, int16_t y, 
                           uint32_t ch_index, 
                           sgl_color_t color, 
                           sgl_font_t *font);

void sgl_draw_font_string_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                 const char *string, 
                                 sgl_color_t color,
                                 sgl_font_t *font);

void sgl_draw_font_string_len_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                     const char *string,  int len, sgl_color_t color,
                                     sgl_font_t *font);

void sgl_draw_font_transp_on_bg( sgl_surf_t *surf, int16_t x, int16_t y, 
                           uint32_t ch_index, sgl_color_t color,
                           sgl_font_t *font, uint8_t alpha);

void sgl_draw_font_string_transp_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                 const char *string, 
                                 sgl_color_t color,
                                 sgl_font_t *font, uint8_t alpha);

void sgl_draw_font_string_len_transp_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                     const char *string,  int len, sgl_color_t color,
                                     sgl_font_t *font, uint8_t alpha);


void sgl_draw_font_line(sgl_surf_t *surf, 
                        int16_t x, int16_t y,
                        int16_t line, 
                        uint32_t ch_index,
                        sgl_color_t color, sgl_color_t bg_color,
                        sgl_font_t *font);

                        

#endif //__SGL_DRAW_FONT_H__
