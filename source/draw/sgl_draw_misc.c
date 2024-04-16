/* source/draw/sgl_draw_misc.c
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


// #include "sgl_draw_misc.h"

// void sgl_draw_line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int fg_color, int bg_color) {
// /*
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int x = x0;
//     int y = y0;
//     int n = 1 + dx + dy;
//     int x_inc = (x1 > x0) ? 1 : -1;
//     int y_inc = (y1 > y0) ? 1 : -1;
//     int error = dx - dy;
//     dx >>= 1;
//     dy >>= 1;
//     for (int i = 0; i < n; i++) {
//         unsigned int intensity = fabs(error) * 8 / fmax(dx, dy);        
//         if (error > 0) {
//             draw_point(x, y, color_bright_2(color,8-intensity));
//             draw_point(x+1, y-1, color_bright_2(color,intensity));
//             x += x_inc;
//             error -= dy;
//         } else {
//             draw_point(x, y, color_bright_2(color,8-intensity));
//             y += y_inc;
//             error += dx;
//         }
//     }
//     */
// }

// void sgl_draw_fork(int16_t cx, int16_t cy, int16_t size, int fg_color, int bg_color)
// {
//     int n = size >> 1;
//     int16_t x = cx - n;
//     int16_t y = cy - n;
//     int edge_color = sgl_color_mixer(fg_color, bg_color, 128);
//     for (int i = 0; i < size; i++) {
//         sgl_disp_pixel(x, y, fg_color);
//         sgl_disp_pixel(x+1, y, edge_color);
//         sgl_disp_pixel(x, y+1, edge_color);

//         sgl_disp_pixel(cy + n - i, y, fg_color);
//         sgl_disp_pixel(cy + n - i - 1, y, edge_color);
//         sgl_disp_pixel(cy + n - i, y + 1, edge_color);
//         x++;
//         y++;
//     }
//     sgl_disp_pixel(x, y, fg_color);
//     sgl_disp_pixel(x - size, y, fg_color);
// }

