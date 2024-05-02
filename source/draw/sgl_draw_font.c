/* source/draw/sgl_draw_font.c
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

#include "./sgl_draw_font.h"

/**
    font bitmap example is:
    <----------------Width-------------->   font is 4bpp Anti-Aliasing.
    |              |          ^         |
    |              |          |         |         
    |<--offset_x-->|      offset_y      |     
    |              |          |         |
    |              |          v         |       
    |              x..@@@@@@@..x        |
  Height           x@.........@x        |
    |              @@.........@@        |
    |              @@.........@@        |
    |              .@@@.....@@@@        | 
    |              ....@@@@@..@@        |
    |              ...........@@        |
    |              ...........@@        |
    |              .@@.......@@.        |
    v              x..@@@@@@@..x        v
    ------------------------------------
***/

#if(SGL_CONFIG_TEXT_UTF8 == 1)

uint32_t sgl_utf8_to_unicode(const uint8_t *utf8_str, uint32_t *p_unicode_buffer) {
    int bytes = 0;
    if (*utf8_str < 0x80) { // 1-byte/7-bit ASCII
        bytes = 1;
        *p_unicode_buffer = utf8_str[0];
    } else if ((*utf8_str & 0xE0) == 0xC0) { // 2-byte
        bytes = 2;
        *p_unicode_buffer = (utf8_str[0] & 0x1F) << 6;
        *p_unicode_buffer |= (utf8_str[1] & 0x3F);
    } else if ((*utf8_str & 0xF0) == 0xE0) { // 3-byte
        bytes = 3;
        *p_unicode_buffer = (utf8_str[0] & 0x0F) << 12;
        *p_unicode_buffer |= (utf8_str[1] & 0x3F) << 6;
        *p_unicode_buffer |= (utf8_str[2] & 0x3F);        
    } else if ((*utf8_str & 0xF8) == 0xF0) { // 4-byte
        bytes = 4;
        *p_unicode_buffer = (utf8_str[0] & 0x07) << 18;
        *p_unicode_buffer |= (utf8_str[2] & 0x3F) << 6;
        *p_unicode_buffer |= (utf8_str[1] & 0x3F) << 12;
        *p_unicode_buffer |= (utf8_str[3] & 0x3F);        
    }
    return bytes;
}

uint32_t sgl_search_unicode_ch_index(sgl_font_t *font, uint32_t unicode)
{
    for (uint32_t i = 0; i < font->unicode_list_len; i++){
        if (font->unicode_list[i] == unicode) {
            return i;
        }
    }
    return 0;
}

/**
 * only support bpp:4
*/
void sgl_draw_font( sgl_surf_t *surf, int16_t x, int16_t y,
                    uint32_t ch_index,
                    sgl_color_t color, sgl_color_t bg_color,
                    sgl_font_t *font)
{
    int pos_x, pos_y;
    const uint8_t *dot = &font->bitmap[font->table[ch_index].bitmap_index];
    for(int i = 0; i < font->table[ch_index].height; i++) {
        for(int j = 0; j < font->table[ch_index].width; j +=2) {
            pos_x = x + j + font->table[ch_index].ofs_x;
            pos_y = y + i + font->table[ch_index].ofs_y;
            sgl_draw_point(surf, pos_x, pos_y, 
                            sgl_color_mixer(color, bg_color, (((*dot)>>4)&0xF)*16));
            sgl_draw_point(surf, pos_x + 1, pos_y, 
                            sgl_color_mixer(color, bg_color, (((*dot))&0xF)*16));
            dot ++;
        }
    }
}

void sgl_draw_font_string( sgl_surf_t *surf, int16_t x, int16_t y, 
                           const char *string, 
                           sgl_color_t color, sgl_color_t bg_color, 
                           sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    uint32_t unicode = 0;
    uint8_t *ptr = (uint8_t *)string;        
    while(*ptr) {
        ptr += sgl_utf8_to_unicode(ptr, &unicode);
        ch_index = sgl_search_unicode_ch_index(font, unicode);
        sgl_draw_font(surf, ofs_x, y, ch_index, color, bg_color, font);
        ofs_x += font->table[ch_index].width;
    }
}

void sgl_draw_font_string_len( sgl_surf_t *surf, int16_t x, int16_t y, 
                               const char *string, int len, sgl_color_t color, sgl_color_t bg_color, 
                               sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    uint32_t unicode = 0;
    uint8_t *ptr = (uint8_t *)string;    
    while(len -- ){
        ptr += sgl_utf8_to_unicode(ptr, &unicode);
        ch_index = sgl_search_unicode_ch_index(font, unicode);
        sgl_draw_font(surf, ofs_x, y, ch_index, color, bg_color, font);
        ofs_x += font->table[ch_index].width;
    }
}


void sgl_draw_font_on_bg( sgl_surf_t *surf, int16_t x, int16_t y, 
                           uint32_t ch_index, sgl_color_t color, 
                           sgl_font_t *font)
{
    int pos_x, pos_y;
    const uint8_t *dot = &font->bitmap[font->table[ch_index].bitmap_index];
    for(int i = 0; i < font->table[ch_index].height; i++) {
        for(int j = 0; j < font->table[ch_index].width; j +=2) {
            if(*dot) {
                pos_x = x + j + font->table[ch_index].ofs_x;
                pos_y = y + i + font->table[ch_index].ofs_y;
                sgl_draw_point(surf, pos_x, pos_y, 
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16));

                sgl_draw_point(surf, pos_x + 1, pos_y,
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16));
            }
            dot ++;
        }
    }
}


void sgl_draw_font_string_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                 const char *string, 
                                 sgl_color_t color,
                                 sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    uint32_t unicode = 0;
    uint8_t *ptr = (uint8_t *)string;    
    while(*ptr) {
        ptr += sgl_utf8_to_unicode(ptr, &unicode);
        ch_index = sgl_search_unicode_ch_index(font, unicode);
        sgl_draw_font_on_bg(surf, ofs_x, y, ch_index, color, font);
        ofs_x += font->table[ch_index].width;
    }
}


void sgl_draw_font_string_len_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                     const char *string, int len, sgl_color_t color,
                                     sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    uint32_t unicode = 0;
    uint8_t *ptr = (uint8_t *)string;    
    while(len -- ){
        ptr += sgl_utf8_to_unicode(ptr, &unicode);
        ch_index = sgl_search_unicode_ch_index(font, unicode);
        sgl_draw_font_on_bg(surf, ofs_x, y, ch_index, color, font);
        ofs_x += font->table[ch_index].width;
       
    }
}

void sgl_draw_font_transp_on_bg( sgl_surf_t *surf, int16_t x, int16_t y, 
                           uint32_t ch_index, sgl_color_t color, 
                           sgl_font_t *font, uint8_t alpha)
{
    int pos_x, pos_y;
    const uint8_t *dot = &font->bitmap[font->table[ch_index].bitmap_index];
    for(int i = 0; i < font->table[ch_index].height; i++) {
        for(int j = 0; j < font->table[ch_index].width; j +=2) {
            if(*dot) {
                pos_x = x + j + font->table[ch_index].ofs_x;
                pos_y = y + i + font->table[ch_index].ofs_y;
                sgl_draw_point(surf, pos_x, pos_y, 
                               sgl_color_mixer(sgl_get_draw_buffer_color(surf, pos_x, pos_y), 
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16), alpha));

                sgl_draw_point(surf, pos_x + 1, pos_y,
                               sgl_color_mixer(sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), 
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16), alpha));
            }
            dot ++;
        }
    }
}


void sgl_draw_font_string_transp_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                 const char *string, 
                                 sgl_color_t color,
                                 sgl_font_t *font, uint8_t alpha)
{
    int16_t ofs_x = x;
    int ch_index;
    uint32_t unicode = 0;
    uint8_t *ptr = (uint8_t *)string;    
    while(*ptr) {
        ptr += sgl_utf8_to_unicode(ptr, &unicode);
        ch_index = sgl_search_unicode_ch_index(font, unicode);        
        sgl_draw_font_transp_on_bg(surf, ofs_x, y, ch_index, color, font, alpha);
        ofs_x += font->table[ch_index].width;   
    }
}


void sgl_draw_font_string_len_transp_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                     const char *string, int len, sgl_color_t color,
                                     sgl_font_t *font, uint8_t alpha)
{
    int16_t ofs_x = x;
    int ch_index;
    uint32_t unicode = 0;
    uint8_t *ptr = (uint8_t *)string;
    while(len -- ){
        ptr += sgl_utf8_to_unicode(ptr, &unicode);
        ch_index = sgl_search_unicode_ch_index(font, unicode);        
        sgl_draw_font_transp_on_bg(surf, ofs_x, y, ch_index, color, font, alpha);
        ofs_x += font->table[ch_index].width;        
    }
}

#else

/**
 * only support bpp:4
*/
void sgl_draw_font( sgl_surf_t *surf, int16_t x, int16_t y, 
                    uint32_t ch_index,
                    sgl_color_t color, sgl_color_t bg_color, 
                    sgl_font_t *font)
{
    ch_index = ch_index - 32;
    int pos_x, pos_y;
    const uint8_t *dot = &font->bitmap[font->table[ch_index].bitmap_index];
    for(int i = 0; i < font->table[ch_index].height; i++) {
        for(int j = 0; j < font->table[ch_index].width; j +=2) {
            pos_x = x + j + font->table[ch_index].ofs_x;
            pos_y = y + i + font->table[ch_index].ofs_y;
            sgl_draw_point(surf, pos_x, pos_y, 
                            sgl_color_mixer(color, bg_color, (((*dot)>>4)&0xF)*16));
            sgl_draw_point(surf, pos_x + 1, pos_y, 
                            sgl_color_mixer(color, bg_color, (((*dot))&0xF)*16));
            dot ++;
        }
    }
}

void sgl_draw_font_string( sgl_surf_t *surf, int16_t x, int16_t y, 
                           const char *string, 
                           sgl_color_t color, sgl_color_t bg_color, 
                           sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    while(*string) {
        ch_index = (uint8_t)(*string) - 32;
        sgl_draw_font(surf, ofs_x, y, *string, color, bg_color, font);
        ofs_x += font->table[ch_index].width;
        string ++;
    }
}

void sgl_draw_font_string_len( sgl_surf_t *surf, int16_t x, int16_t y, 
                               const char *string, int len, sgl_color_t color, sgl_color_t bg_color, 
                               sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    while(len -- ){
        ch_index = (uint8_t)(*string) - 32;
        sgl_draw_font(surf, ofs_x, y, *string, color, bg_color, font);
        ofs_x += font->table[ch_index].width;
        string ++;
    }
}


void sgl_draw_font_on_bg( sgl_surf_t *surf, int16_t x, int16_t y, 
                           uint32_t ch_index, sgl_color_t color, 
                           sgl_font_t *font)
{
    ch_index = ch_index - 32;
    int pos_x, pos_y;
    const uint8_t *dot = &font->bitmap[font->table[ch_index].bitmap_index];
    for(int i = 0; i < font->table[ch_index].height; i++) {
        for(int j = 0; j < font->table[ch_index].width; j +=2) {
            if(*dot) {
                pos_x = x + j + font->table[ch_index].ofs_x;
                pos_y = y + i + font->table[ch_index].ofs_y;
                sgl_draw_point(surf, pos_x, pos_y, 
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16));

                sgl_draw_point(surf, pos_x + 1, pos_y,
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16));
            }
            dot ++;
        }
    }
}


void sgl_draw_font_string_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                 const char *string, 
                                 sgl_color_t color,
                                 sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    while(*string) {
        ch_index = (uint8_t)(*string) - 32;
        sgl_draw_font_on_bg(surf, ofs_x, y, *string, color, font);
        ofs_x += font->table[ch_index].width;
        string ++;
    }
}


void sgl_draw_font_string_len_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                     const char *string, int len, sgl_color_t color,
                                     sgl_font_t *font)
{
    int16_t ofs_x = x;
    int ch_index;
    while(len -- ){
        ch_index = (uint8_t)(*string) - 32;
        sgl_draw_font_on_bg(surf, ofs_x, y, *string, color, font);
        ofs_x += font->table[ch_index].width;
        string ++;
    }
}

void sgl_draw_font_transp_on_bg( sgl_surf_t *surf, int16_t x, int16_t y, 
                           uint32_t ch_index, sgl_color_t color, 
                           sgl_font_t *font, uint8_t alpha)
{
    ch_index = ch_index - 32;
    int pos_x, pos_y;
    const uint8_t *dot = &font->bitmap[font->table[ch_index].bitmap_index];
    for(int i = 0; i < font->table[ch_index].height; i++) {
        for(int j = 0; j < font->table[ch_index].width; j +=2) {
            if(*dot) {
                pos_x = x + j + font->table[ch_index].ofs_x;
                pos_y = y + i + font->table[ch_index].ofs_y;
                sgl_draw_point(surf, pos_x, pos_y, 
                               sgl_color_mixer(sgl_get_draw_buffer_color(surf, pos_x, pos_y), 
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x, pos_y), (((*dot)>>4)&0xF)*16), alpha));

                sgl_draw_point(surf, pos_x + 1, pos_y,
                               sgl_color_mixer(sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), 
                               sgl_color_mixer(color, sgl_get_draw_buffer_color(surf, pos_x + 1, pos_y), (((*dot))&0xF)*16), alpha));
            }
            dot ++;
        }
    }
}


void sgl_draw_font_string_transp_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                 const char *string, 
                                 sgl_color_t color,
                                 sgl_font_t *font, uint8_t alpha)
{
    int16_t ofs_x = x;
    int ch_index;
    while(*string) {
        ch_index = (uint8_t)(*string) - 32;
        sgl_draw_font_transp_on_bg(surf, ofs_x, y, *string, color, font, alpha);
        ofs_x += font->table[ch_index].width;
        string ++;
    }
}


void sgl_draw_font_string_len_transp_on_bg(sgl_surf_t *surf, int16_t x, int16_t y, 
                                     const char *string, int len, sgl_color_t color,
                                     sgl_font_t *font, uint8_t alpha)
{
    int16_t ofs_x = x;
    int ch_index;
    while(len -- ){
        ch_index = (uint8_t)(*string) - 32;
        sgl_draw_font_transp_on_bg(surf, ofs_x, y, *string, color, font, alpha);
        ofs_x += font->table[ch_index].width;
        string ++;
    }
}

#endif
