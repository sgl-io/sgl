/* source/draw/sgl_draw.c
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

#include "./sgl_draw.h"
#include "stdio.h"


#if (SGL_CONFIG_MIXER_TYPE == 1)

sgl_color_t sgl_color_mixer(sgl_color_t fg_color, sgl_color_t bg_color, uint8_t factor)
{
    sgl_color_t ret;
    int f_r, f_g, f_b, b_r, b_g, b_b, r, g, b;
#if (SGL_CONFIG_PANEL_PIXEL_DEPTH == 32 || SGL_CONFIG_PANEL_PIXEL_DEPTH == 24) 
    f_r = (fg_color.full >> 0) & ((1<<8) - 1);
    f_g = (fg_color.full >> 8) & ((1<<8) - 1);
    f_b = (fg_color.full >> 16) & ((1<<8) - 1);
    b_r = (bg_color.full >> 0) & ((1<<8) - 1);
    b_g = (bg_color.full >> 8) & ((1<<8) - 1);
    b_b = (bg_color.full >> 16) & ((1<<8) - 1);
    r = (f_r * factor + b_r*(255 - factor)) >> 8;
    g = (f_g * factor + b_g*(255 - factor)) >> 8;
    b = (f_b * factor + b_b*(255 - factor)) >> 8;
    ret.full = (r<<0) + (g <<8) + (b<<16);
#elif(SGL_CONFIG_PANEL_PIXEL_DEPTH == 16) 
#if SGL_CONFIG_COLOR16_SWAP
    f_r = (fg_color.full >> 3) & 0x1F;
    f_g = ((fg_color.full & 0x7) << 3) | ((fg_color.full >> 13) & 0x7);
    f_b = (fg_color.full >> 8) & 0x1F;
    b_r = (bg_color.full >> 3) & 0x1F;
    b_g = ((bg_color.full & 0x7) << 3) | ((bg_color.full >> 13) & 0x7);
    b_b = (bg_color.full >> 8) & 0x1F;
    r = (f_r * factor + b_r*(255 - factor)) >> 8;
    g = (f_g * factor + b_g*(255 - factor)) >> 8;
    b = (f_b * factor + b_b*(255 - factor)) >> 8;
    ret.full = ((g >> 3) & 0x7) + (r << 3) + (b << 8) + ((g & 0x7) << 13);
#else
    f_r = (fg_color.full >> 0) & ((1<<5) - 1);
    f_g = (fg_color.full >> 5) & ((1<<6) - 1);
    f_b = (fg_color.full >> 11) & ((1<<5) - 1);
    b_r = (bg_color.full >> 0) & ((1<<5) - 1);
    b_g = (bg_color.full >> 5) & ((1<<6) - 1);
    b_b = (bg_color.full >> 11) & ((1<<5) - 1);
    r = (f_r * factor + b_r*(255 - factor)) >> 8;
    g = (f_g * factor + b_g*(255 - factor)) >> 8;
    b = (f_b * factor + b_b*(255 - factor)) >> 8;
    ret.full = (r<<0) + (g <<5) + (b<<11);
#endif
#else
    //add your pixel bit type
#endif
    return ret;
}

#else

sgl_color_t sgl_color_mixer(sgl_color_t fg_color, sgl_color_t bg_color, uint8_t factor)
{
    sgl_color_t ret;
#if (SGL_CONFIG_PANEL_PIXEL_DEPTH == 16)
#if SGL_CONFIG_COLOR16_SWAP
    uint16_t fgc = (fg_color.full >> 8) | (fg_color.full & 0xFF) << 8;
    uint16_t bgc = (bg_color.full >> 8) | (bg_color.full & 0xFF) << 8;
    uint32_t rxb = bgc & 0xF81F;
    rxb += ((fgc & 0xF81F) - rxb) * (factor >> 2) >> 6;
    uint32_t xgx = bgc & 0x07E0;
    xgx += ((fgc & 0x07E0) - xgx) * factor >> 8;
    ret.full = (rxb & 0xF81F) | (xgx & 0x07E0);
    ret.full = (ret.full >> 8) | (ret.full & 0xFF) << 8;
#else
    uint32_t rxb = bg_color.full & 0xF81F;
    rxb += ((fg_color.full & 0xF81F) - rxb) * (factor >> 2) >> 6;
    uint32_t xgx = bg_color.full & 0x07E0;
    xgx += ((fg_color.full & 0x07E0) - xgx) * factor >> 8;
    ret.full = (rxb & 0xF81F) | (xgx & 0x07E0);
#endif
#elif (SGL_CONFIG_PANEL_PIXEL_DEPTH == 24)
    uint32_t rxx = bg_color.full & 0xFF0000;
    rxx += ((fg_color.full & 0xFF0000) - rxx) * factor >> 8;
    uint32_t xgx = bg_color.full & 0x00FF00;
    xgx += ((fg_color.full & 0x00FF00) - xgx) * factor >> 8;
    uint32_t xxb = bg_color.full & 0x0000FF;
    xxb += ((fg_color.full & 0x0000FF) - xxb) * factor >> 8;
    ret.full = (rxx & 0xFF0000) | (xgx & 0x00FF00) | (xxb & 0x0000FF);
#elif (SGL_CONFIG_PANEL_PIXEL_DEPTH == 32)
    uint32_t xxxa = bg_color.full & 0xFF000000;
    xxxa += ((fg_color.full & 0xFF000000) - xxxa) * factor >> 8;
    uint32_t rxx = bg_color.full & 0xFF0000;
    rxx += ((fg_color.full & 0xFF0000) - rxx) * factor >> 8;
    uint32_t xgx = bg_color.full & 0x00FF00;
    xgx += ((fg_color.full & 0x00FF00) - xgx) * factor >> 8;
    uint32_t xxb = bg_color.full & 0x0000FF;
    xxb += ((fg_color.full & 0x0000FF) - xxb) * factor >> 8;
    ret.full = (rxx & 0xFF0000) | (xgx & 0x00FF00) | (xxb & 0x0000FF) | (xxxa & 0xFF000000);
#endif
    return ret;
}

#endif


void sgl_draw_point(sgl_surf_t *surf, int16_t x, int16_t y, sgl_color_t color)
{
    sgl_color_t *pos = surf->fb;
    *(pos + y * surf->size.w + x) = color;
}

void sgl_draw_hline(sgl_surf_t *surf, int16_t x, int16_t y, int16_t len, sgl_color_t color)
{
    sgl_color_t *pos = surf->fb;
    pos += (y * surf->size.w + x);
    for(int i = 0; i < len; i++) {
        *(pos + i) = color;
    }
}

void sgl_draw_vline(sgl_surf_t *surf, int16_t x, int16_t y, int16_t len, sgl_color_t color)
{
    sgl_color_t *pos = surf->fb;
    pos += (y * surf->size.w + x);
    for(int i = 0; i < len; i++) {
        *(pos + i * surf->size.w) = color;
    }
}

void sgl_draw_area_color(sgl_surf_t *surf, int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t color)
{
    sgl_color_t *pos = surf->fb;
    pos += (y1 * surf->size.w + x1);
    for(int i = 0; i < (y2 - y1); i ++) {
        for(int j = 0; j < (x2 - x1); j ++) {
            *(pos + i * surf->size.w + j) = color;
        }
    }
}

void sgl_draw_buffer_clear(sgl_surf_t *surf, sgl_color_t color)
{
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    return;
#else
    sgl_color_t *pos = surf->fb;
    for(int i = 0 ;i < surf->size.w * surf->size.h; i++) {
        *pos = color;
        pos ++ ;
    }
#endif
}

void sgl_draw_buffer_pick_img(sgl_surf_t *surf, sgl_img_t *img)
{
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    return;
#else
    //TODO:
#endif  
}

void sgl_draw_obj_buffer_clear(sgl_surf_t *surf, sgl_obj_t *obj, sgl_color_t color)
{
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    sgl_color_t *pos = surf->fb + obj->pos.y*surf->size.w + obj->pos.x;
    for(int i = 0 ;i < obj->size.h; i++) {
        for(int j = 0; j < obj->size.w; j++) {
            *(pos + j) = color;
        }
        pos += surf->size.w;
    }
#else
    sgl_color_t *pos = surf->fb;
    for(int i = 0 ;i < surf->size.w * surf->size.h; i++) {
        *pos = color;
        pos ++ ;
    }
#endif
}

void sgl_draw_obj_buffer_pick_img(sgl_surf_t *surf, sgl_obj_t *obj, sgl_img_t *img)
{
    sgl_color_t *cherry = (sgl_color_t*)img->bitmap;
    cherry += obj->pos.y * img->width + obj->pos.x;
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    sgl_color_t *pos = surf->fb + obj->pos.y*surf->size.w + obj->pos.x;
    for(int i = 0; i < obj->size.h; i++) {
        for(int j = 0; j < obj->size.w; j++) {
            pos[j] = cherry[j];
        }
        pos += surf->size.w;
        cherry += img->width;
    }
#else
    sgl_color_t *pos = surf->fb;
    for(int i = 0; i < obj->size.h; i++) {
        for(int j = 0; j < obj->size.w; j++) {
            *pos = cherry[j];
            pos ++;
        }
        cherry += img->width;
    }
#endif
}


void sgl_draw_obj_buffer_pick_surf(sgl_surf_t *surf, sgl_obj_t *obj)
{
    sgl_color_t *cherry = surf->fb;
    cherry += obj->pos.y * surf->size.w + obj->pos.x;
#if SGL_CONFIG_FRAMEBUFFER_MMAP
    sgl_color_t *pos = surf->fb + obj->pos.y*surf->size.w + obj->pos.x;
    for(int i = 0; i < obj->size.h; i++) {
        for(int j = 0; j < obj->size.w; j++) {
            pos[j] = cherry[j];
        }
        pos += surf->size.w;
        cherry += surf->size.w;
    }
#else
    sgl_color_t *pos = surf->fb;
    for(int i = 0; i < obj->size.h; i++) {
        for(int j = 0; j < obj->size.w; j++) {
            *pos = cherry[j];
            pos ++;
        }
        cherry += surf->size.w;
    }
#endif
}

extern sgl_device_panel_t *sgl_active_panel;

void sgl_draw_buffer_flush(sgl_surf_t *surf, int16_t x, int16_t y)
{
    sgl_active_panel->flush_area(x, y, x + surf->size.w - 1, y + surf->size.h - 1, surf->fb);
}

void sgl_draw_buffer_flush_hclip(sgl_surf_t *surf, int16_t x, int16_t y, int16_t clip_start, int16_t clip_end)
{
    sgl_active_panel->flush_area(x, y, x + surf->size.w, y + (clip_end - clip_start), surf->fb + clip_start * surf->size.w);
}

void sgl_draw_buffer_flush_vclip(sgl_surf_t *surf, int16_t x, int16_t y, int16_t clip_start, int16_t clip_end)
{
    //TODO:
}

//TODO: 是实现draw buffer的裁剪
void sgl_draw_area_flush(sgl_rect_t rect, sgl_color_t *src)
{
    sgl_active_panel->flush_area(rect.x1, rect.y1, rect.x2, rect.y2, src);;
}


/*  
 * This function is used to calculate circle path
 *  
 * @param cx: center x position of the circle 
 * @param cy: center y position of the circle 
 * @param r:  radius size of the circle 
 * @param path: path position of the circle
 * @return int: x and y middle
 * 
 * The algorithm adopts the DDA algorithm
 */
int sgl_figure_circle_path(int16_t r, int16_t* path)
{
    int32_t   deci;    /* Decision Variable */
    uint32_t  dx;      /* Current X Value   */
    uint32_t  dy;      /* Current Y Value   */
    deci = 3 - (r << 1);
    dx = 0;
    dy = r;
    while (dx <= dy)
    {
        path[dx] = dy;
        if (deci < 0) {
            deci += (dx << 2) + 6;
        }
        else {
            deci += ((dx - dy) << 2) + 10;
            dy--;
        }
        dx++;
    }
    return dx-1;
}

int sgl_text_width(sgl_font_t *font, const char* text)
{
    int text_w = 0;
    while(*text) {
        text_w += font->table[(uint8_t)(*text) - 32].width;
        text ++;
    }
    return text_w;
}

int sgl_text_height(sgl_font_t *font)
{
    return font->font_height;
}

void sgl_draw_handler(sgl_obj_t *obj)
{
    switch(obj->obj_type) {
        case SGL_OBJ_BUTTON: {
            sgl_button_event_cb(obj);
            break;
        }
        case SGL_OBJ_SWITCH: {
            sgl_switch_event_cb(obj);
            break;
        }
        case SGL_OBJ_LABEL: {
            sgl_label_event_cb(obj);
            break;
        }
        case SGL_OBJ_BATTERY: {
            sgl_battery_draw(obj);
            break;
        }
        case SGL_OBJ_CHECKBOX: {
            sgl_checkbox_event_cb(obj);
            break;
        }
        case SGL_OBJ_RADIOBUTTON: {
            sgl_radiobtn_event_cb(obj);
            break;
        }
        case SGL_OBJ_NUMBER: {
            sgl_number_event_cb(obj);
            break;
        }
        case SGL_OBJ_PROGRESSBAR: {
            sgl_pgsbar_event_cb(obj);
            break;
        }
        case SGL_OBJ_ARCBAR: {
            sgl_arcbar_draw(obj);
            break;
        }
        case SGL_OBJ_PIXELMAP: {
            sgl_pixmap_draw(obj);
            break;
        }
        
        default: break;
    }
}

sgl_color_t sgl_get_draw_buffer_color(sgl_surf_t *surf, int16_t x, int16_t y)
{
    sgl_color_t *color = surf->fb;
    return color[y * surf->size.w + x];
}
