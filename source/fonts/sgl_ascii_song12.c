/* source/fonts/sgl_song12.c
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

#include "../core/sgl_core.h"
#include "../draw/sgl_draw.h"
#include "../draw/sgl_draw_font.h"
#include "sgl_conf.h"
#if(SGL_CONFIG_FONT_SONG12 == 1)
/*
* height: 12 pixel
*/
static const uint8_t sgl_ascii_song12_bitmap[] = {
/*   */



/* ! */
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0xf0,0x00,  //..@...


/* " */
0x00,0xf0,0xf0,  //..@.@.
0x00,0xf0,0xf0,  //..@.@.
0x0f,0x0f,0x00,  //.@.@..


/* # */
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0xff,0xff,0xf0,  //@@@@@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0xff,0xff,0xf0,  //@@@@@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..


/* $ */
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0x00,  //.@@@..
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0x00,  //@.@...
0x0f,0xf0,0x00,  //.@@...
0x00,0xff,0x00,  //..@@..
0x00,0xf0,0xf0,  //..@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0x0f,0xff,0x00,  //.@@@..
0x00,0xf0,0x00,  //..@...


/* % */
0x0f,0x00,0xf0,  //.@..@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xff,0x00,  //@.@@..
0xf0,0xf0,0xf0,  //@.@.@.
0x0f,0xff,0x0f,  //.@@@.@
0x00,0xff,0x0f,  //..@@.@
0x0f,0x0f,0x0f,  //.@.@.@
0x0f,0x00,0xf0,  //.@..@.


/* & */
0x00,0xf0,0x00,  //..@...
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0xf0,0xff,  //.@@.@@
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0x0f,0x0f,  //@..@.@
0x0f,0xf0,0xf0,  //.@@.@.


/* ' */
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0xf0,0x00,0x00,  //@.....


/* ( */
0x00,0x00,0xf0,  //....@.
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x00,0xf0,  //....@.


/* ) */
0x0f,0x00,0x00,  //.@....
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0x00,0x00,  //.@....


/* * */
0x00,0xf0,0x00,  //..@...
0xf0,0xf0,0xf0,  //@.@.@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0xff,0x00,  //.@@@..
0xf0,0xf0,0xf0,  //@.@.@.
0x00,0xf0,0x00,  //..@...


/* + */
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x0f,0xff,0xff,  //.@@@@@
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..


/* , */
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0xf0,0x00,0x00,  //@.....


/* - */
0xff,0xff,0xff,  //@@@@@@


/* . */
0x0f,0x00,0x00,  //.@....


/* / */
0x00,0x00,0x0f,  //.....@
0x00,0x00,0xf0,  //....@.
0x00,0x00,0xf0,  //....@.
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0xf0,0x00,0x00,  //@.....


/* 0 */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* 1 */
0x00,0xf0,0x00,  //..@...
0x0f,0xf0,0x00,  //.@@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0x00,  //.@@@..


/* 2 */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x0f,0x00,0x00,  //.@....
0xf0,0x00,0x00,  //@.....
0xff,0xff,0xf0,  //@@@@@.


/* 3 */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0x00,0x00,0xf0,  //....@.
0x00,0xff,0x00,  //..@@..
0x00,0x00,0xf0,  //....@.
0x00,0x00,0xf0,  //....@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* 4 */
0x00,0x0f,0x00,  //...@..
0x00,0xff,0x00,  //..@@..
0x00,0xff,0x00,  //..@@..
0x0f,0x0f,0x00,  //.@.@..
0xf0,0x0f,0x00,  //@..@..
0xff,0xff,0xf0,  //@@@@@.
0x00,0x0f,0x00,  //...@..
0x00,0xff,0xf0,  //..@@@.


/* 5 */
0xff,0xff,0xf0,  //@@@@@.
0xf0,0x00,0x00,  //@.....
0xf0,0x00,0x00,  //@.....
0xff,0xff,0x00,  //@@@@..
0xf0,0x00,0xf0,  //@...@.
0x00,0x00,0xf0,  //....@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* 6 */
0x00,0xff,0x00,  //..@@..
0x0f,0x00,0xf0,  //.@..@.
0xf0,0x00,0x00,  //@.....
0xf0,0xff,0x00,  //@.@@..
0xff,0x00,0xf0,  //@@..@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* 7 */
0x0f,0xff,0xf0,  //.@@@@.
0x00,0x00,0xf0,  //....@.
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...


/* 8 */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* 9 */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x0f,0xf0,  //@..@@.
0x0f,0xf0,0xf0,  //.@@.@.
0x00,0x00,0xf0,  //....@.
0xf0,0x0f,0x00,  //@..@..
0x0f,0xf0,0x00,  //.@@...


/* : */
0x00,0xf0,0x00,  //..@...
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0xf0,0x00,  //..@...


/* ; */
0x00,0xf0,0x00,  //..@...
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...


/* < */
0x00,0x00,0xf0,  //....@.
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x00,0xf0,0x00,  //..@...
0x00,0x0f,0x00,  //...@..
0x00,0x00,0xf0,  //....@.


/* = */
0xff,0xff,0xff,  //@@@@@@
0x00,0x00,0x00,  //......
0xff,0xff,0xff,  //@@@@@@


/* > */
0x0f,0x00,0x00,  //.@....
0x00,0xf0,0x00,  //..@...
0x00,0x0f,0x00,  //...@..
0x00,0x00,0xf0,  //....@.
0x00,0x00,0xf0,  //....@.
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x0f,0x00,0x00,  //.@....


/* ? */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x00,0x00,  //......
0x00,0xf0,0x00,  //..@...


/* @ */
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0x0f,  //.@...@
0xf0,0x0f,0x0f,  //@..@.@
0xf0,0xff,0x0f,  //@.@@.@
0xf0,0xff,0x0f,  //@.@@.@
0xf0,0xff,0xf0,  //@.@@@.
0x0f,0x00,0x0f,  //.@...@
0x00,0xff,0xf0,  //..@@@.


/* A */
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xff,0x00,  //..@@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0xff,0xf0,  //.@@@@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0x00,0xff,  //@@..@@


/* B */
0xff,0xff,0x00,  //@@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xff,0x00,  //@@@@..


/* C */
0x0f,0xff,0xf0,  //.@@@@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0x00,  //@.....
0xf0,0x00,0x00,  //@.....
0xf0,0x00,0x00,  //@.....
0xf0,0x00,0x00,  //@.....
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* D */
0xff,0xff,0x00,  //@@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xff,0x00,  //@@@@..


/* E */
0xff,0xff,0xf0,  //@@@@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0xff,0x00,  //.@@@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0xf0,  //.@..@.
0xff,0xff,0xf0,  //@@@@@.


/* F */
0xff,0xff,0xf0,  //@@@@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0xff,0x00,  //.@@@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0xff,0xf0,0x00,  //@@@...


/* G */
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0xf0,  //.@..@.
0xf0,0x00,0x00,  //@.....
0xf0,0x00,0x00,  //@.....
0xf0,0x0f,0xff,  //@..@@@
0xf0,0x00,0xf0,  //@...@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0x00,  //..@@..


/* H */
0xff,0x00,0xff,  //@@..@@
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0xf0,  //.@@@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0x00,0xff,  //@@..@@


/* I */
0xff,0xff,0xf0,  //@@@@@.
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0xff,0xff,0xf0,  //@@@@@.


/* J */
0x0f,0xff,0xff,  //.@@@@@
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0xf0,0x0f,0x00,  //@..@..
0xff,0xf0,0x00,  //@@@...


/* K */
0xff,0xf0,0xff,  //@@@.@@
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0xf0,0x00,  //.@@...
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xf0,0xff,  //@@@.@@


/* L */
0xff,0xf0,0x00,  //@@@...
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x0f,  //.@...@
0xff,0xff,0xff,  //@@@@@@


/* M */
0xff,0x0f,0xff,  //@@.@@@
0xff,0x0f,0xf0,  //@@.@@.
0xff,0x0f,0xf0,  //@@.@@.
0xff,0x0f,0xf0,  //@@.@@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xff,  //@.@.@@


/* N */
0xff,0x0f,0xff,  //@@.@@@
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xf0,0xf0,  //.@@.@.
0x0f,0xf0,0xf0,  //.@@.@.
0x0f,0x0f,0xf0,  //.@.@@.
0x0f,0x0f,0xf0,  //.@.@@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xf0,0xf0,  //@@@.@.


/* O */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0x0f,0xff,0x00,  //.@@@..


/* P */
0xff,0xff,0x00,  //@@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0xff,0xf0,0x00,  //@@@...


/* Q */
0x0f,0xff,0x00,  //.@@@..
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0xf0,  //@...@.
0xff,0xf0,0xf0,  //@@@.@.
0xf0,0x0f,0xf0,  //@..@@.
0x0f,0xff,0x00,  //.@@@..
0x00,0x0f,0xf0,  //...@@.


/* R */
0xff,0xff,0x00,  //@@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xf0,0xff,  //@@@.@@


/* S */
0x0f,0xff,0xf0,  //.@@@@.
0xf0,0x00,0xf0,  //@...@.
0xf0,0x00,0x00,  //@.....
0x0f,0xf0,0x00,  //.@@...
0x00,0x0f,0x00,  //...@..
0x00,0x00,0xf0,  //....@.
0xf0,0x00,0xf0,  //@...@.
0xff,0xff,0x00,  //@@@@..


/* T */
0xff,0xff,0xf0,  //@@@@@.
0xf0,0xf0,0xf0,  //@.@.@.
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0x00,  //.@@@..


/* U */
0xff,0x00,0xff,  //@@..@@
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0x00,  //..@@..


/* V */
0xff,0x00,0xff,  //@@..@@
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x00,0xff,0x00,  //..@@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...


/* W */
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..


/* X */
0xff,0x0f,0xf0,  //@@.@@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0xff,0x0f,0xf0,  //@@.@@.


/* Y */
0xff,0x0f,0xf0,  //@@.@@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0x00,  //.@@@..


/* Z */
0xff,0xff,0xf0,  //@@@@@.
0xf0,0x0f,0x00,  //@..@..
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0xf0,  //.@..@.
0xff,0xff,0xf0,  //@@@@@.


/* [ */
0x00,0xff,0xf0,  //..@@@.
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xff,0xf0,  //..@@@.


/* \ */
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x00,0xf0,  //....@.
0x00,0x00,0xf0,  //....@.


/* ] */
0x0f,0xff,0x00,  //.@@@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x0f,0xff,0x00,  //.@@@..


/* ^ */
0x00,0xf0,0x00,  //..@...
0x0f,0x0f,0x00,  //.@.@..


/* _ */
0xff,0xff,0xff,  //@@@@@@


/* ` */
0x0f,0x00,0x00,  //.@....
0x00,0xf0,0x00,  //..@...


/* a */
0x00,0xff,0x00,  //..@@..
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0xff,  //..@@@@


/* b */
0xff,0x00,0x00,  //@@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0xff,0x00,  //.@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0x00,  //.@@@..


/* c */
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0x00,  //..@@..


/* d */
0x00,0x0f,0xf0,  //...@@.
0x00,0x00,0xf0,  //....@.
0x00,0x00,0xf0,  //....@.
0x00,0x00,0xf0,  //....@.
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0xff,  //..@@@@


/* e */
0x00,0xff,0x00,  //..@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0xf0,  //.@@@@.
0x0f,0x00,0x00,  //.@....
0x00,0xff,0xf0,  //..@@@.


/* f */
0x00,0x0f,0xf0,  //...@@.
0x00,0xf0,0x0f,  //..@..@
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0xf0,  //.@@@@.
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0xf0,  //.@@@@.


/* g */
0x00,0xff,0xff,  //..@@@@
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0x00,  //..@@..
0x0f,0x00,0x00,  //.@....
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0x0f,  //.@...@
0x00,0xff,0xf0,  //..@@@.


/* h */
0xff,0x00,0x00,  //@@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0xff,0x00,  //.@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xf0,0xff,  //@@@.@@


/* i */
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x0f,0xf0,0x00,  //.@@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0x00,  //.@@@..


/* j */
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x00,0x00,  //......
0x00,0x00,0x00,  //......
0x00,0xff,0x00,  //..@@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0xff,0xf0,0x00,  //@@@...


/* k */
0xff,0x00,0x00,  //@@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0x0f,0x0f,0xf0,  //.@.@@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0xf0,0x00,  //.@@...
0x0f,0x0f,0x00,  //.@.@..
0xff,0x00,0xf0,  //@@..@.


/* l */
0xff,0xf0,0x00,  //@@@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0xff,0xff,0xf0,  //@@@@@.


/* m */
0xff,0xff,0x00,  //@@@@..
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.


/* n */
0xff,0xff,0x00,  //@@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0xff,0xf0,0xff,  //@@@.@@


/* o */
0x00,0xff,0x00,  //..@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0x00,  //..@@..


/* p */
0xff,0xff,0x00,  //@@@@..
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0x00,0x00,  //.@....
0xff,0xf0,0x00,  //@@@...


/* q */
0x00,0xff,0xf0,  //..@@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0xf0,  //..@@@.
0x00,0x00,0xf0,  //....@.
0x00,0x0f,0xff,  //...@@@


/* r */
0xff,0x0f,0xf0,  //@@.@@.
0x0f,0xf0,0x00,  //.@@...
0x0f,0x00,0x00,  //.@....
0x0f,0x00,0x00,  //.@....
0xff,0xf0,0x00,  //@@@...


/* s */
0x0f,0xff,0xf0,  //.@@@@.
0x0f,0x00,0x00,  //.@....
0x00,0xff,0x00,  //..@@..
0x00,0x00,0xf0,  //....@.
0x0f,0xff,0xf0,  //.@@@@.


/* t */
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0xf0,  //.@@@@.
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xff,0xf0,  //..@@@.


/* u */
0xff,0x0f,0xf0,  //@@.@@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0xff,  //..@@@@


/* v */
0xff,0x0f,0xf0,  //@@.@@.
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...


/* w */
0xf0,0xf0,0xf0,  //@.@.@.
0xf0,0xf0,0xf0,  //@.@.@.
0x0f,0xff,0x00,  //.@@@..
0x0f,0x0f,0x00,  //.@.@..
0x0f,0x0f,0x00,  //.@.@..


/* x */
0xff,0x0f,0xf0,  //@@.@@.
0x0f,0x0f,0x00,  //.@.@..
0x00,0xf0,0x00,  //..@...
0x0f,0x0f,0x00,  //.@.@..
0xff,0x0f,0xf0,  //@@.@@.


/* y */
0xff,0x00,0xff,  //@@..@@
0x0f,0x00,0xf0,  //.@..@.
0x0f,0x00,0xf0,  //.@..@.
0x00,0xff,0x00,  //..@@..
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0xff,0x00,0x00,  //@@....


/* z */
0x0f,0xff,0xf0,  //.@@@@.
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xff,0xf0,  //.@@@@.


/* { */
0x00,0x0f,0xf0,  //...@@.
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0xff,0x00,  //..@@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0xf0,  //...@@.


/* | */
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..
0x00,0x0f,0x00,  //...@..


/* } */
0x0f,0xf0,0x00,  //.@@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0x0f,0x00,  //...@..
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x00,0xf0,0x00,  //..@...
0x0f,0xf0,0x00,  //.@@...


/* ~ */
0x0f,0xf0,0xf0,  //.@@.@.
0xf0,0x0f,0x00,  //@..@..


/*  */



/* ℃ */
0x0f,0x00,0x00,0x00,0x00,0x00,  //.@..........
0xf0,0xf0,0x0f,0xff,0x0f,0x00,  //@.@..@@@.@..
0x0f,0x00,0xf0,0x00,0xff,0x00,  //.@..@...@@..
0x00,0x0f,0x00,0x00,0x0f,0x00,  //...@.....@..
0x00,0x0f,0x00,0x00,0x00,0x00,  //...@........
0x00,0x0f,0x00,0x00,0x00,0x00,  //...@........
0x00,0x0f,0x00,0x00,0x00,0x00,  //...@........
0x00,0x0f,0x00,0x00,0x00,0xf0,  //...@......@.
0x00,0x00,0xf0,0x00,0x0f,0x00,  //....@....@..
0x00,0x00,0x0f,0xff,0xf0,0x00,  //.....@@@@...


/* ℉ */
0x0f,0xf0,0xff,0xff,0xff,0x00,  //.@@.@@@@@@..
0xf0,0x0f,0x0f,0x00,0xff,0x00,  //@..@.@..@@..
0xf0,0x0f,0x0f,0x00,0x0f,0x00,  //@..@.@...@..
0x0f,0xf0,0x0f,0x00,0x00,0x00,  //.@@..@......
0x00,0x00,0x0f,0x00,0xf0,0x00,  //.....@..@...
0x00,0x00,0x0f,0xff,0xf0,0x00,  //.....@@@@...
0x00,0x00,0x0f,0x00,0xf0,0x00,  //.....@..@...
0x00,0x00,0x0f,0x00,0x00,0x00,  //.....@......
0x00,0x00,0x0f,0x00,0x00,0x00,  //.....@......
0x00,0x00,0x0f,0x00,0x00,0x00,  //.....@......
0x00,0x00,0xff,0xf0,0x00,0x00,  //....@@@.....

};


static const sgl_font_table_t sgl_ascii_song12_tab[] = {

    {.bitmap_index = 0,	    .height = 0,   .width = 6,   .ofs_x = 0, .ofs_y = 12},/*( )*/
    {.bitmap_index = 0,	    .height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(!)*/
    {.bitmap_index = 24,	.height = 3,   .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(")*/
    {.bitmap_index = 33,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(#)*/
    {.bitmap_index = 57,	.height = 10,  .width = 6,   .ofs_x = 0, .ofs_y = 1},/*($)*/
    {.bitmap_index = 87,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(%)*/
    {.bitmap_index = 111,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(&)*/
    {.bitmap_index = 135,	.height = 3,   .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(')*/
    {.bitmap_index = 144,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(()*/
    {.bitmap_index = 177,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*())*/
    {.bitmap_index = 210,	.height = 6,   .width = 6,   .ofs_x = 0, .ofs_y = 3},/*(*)*/
    {.bitmap_index = 228,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 3},/*(+)*/
    {.bitmap_index = 243,	.height = 3,   .width = 6,   .ofs_x = 0, .ofs_y = 8},/*(,)*/
    {.bitmap_index = 252,	.height = 1,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(-)*/
    {.bitmap_index = 255,	.height = 1,   .width = 6,   .ofs_x = 0, .ofs_y = 9},/*(.)*/
    {.bitmap_index = 258,	.height = 10,  .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(/)*/
    {.bitmap_index = 288,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(0)*/
    {.bitmap_index = 312,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(1)*/
    {.bitmap_index = 336,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(2)*/
    {.bitmap_index = 360,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(3)*/
    {.bitmap_index = 384,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(4)*/
    {.bitmap_index = 408,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(5)*/
    {.bitmap_index = 432,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(6)*/
    {.bitmap_index = 456,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(7)*/
    {.bitmap_index = 480,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(8)*/
    {.bitmap_index = 504,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(9)*/
    {.bitmap_index = 528,	.height = 6,   .width = 6,   .ofs_x = 0, .ofs_y = 4},/*(:)*/
    {.bitmap_index = 546,	.height = 6,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(;)*/
    {.bitmap_index = 564,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(<)*/
    {.bitmap_index = 588,	.height = 3,   .width = 6,   .ofs_x = 0, .ofs_y = 4},/*(=)*/
    {.bitmap_index = 597,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(>)*/
    {.bitmap_index = 621,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(?)*/
    {.bitmap_index = 645,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(@)*/
    {.bitmap_index = 669,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(A)*/
    {.bitmap_index = 693,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(B)*/
    {.bitmap_index = 717,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(C)*/
    {.bitmap_index = 741,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(D)*/
    {.bitmap_index = 765,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(E)*/
    {.bitmap_index = 789,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(F)*/
    {.bitmap_index = 813,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(G)*/
    {.bitmap_index = 837,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(H)*/
    {.bitmap_index = 861,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(I)*/
    {.bitmap_index = 885,	.height = 10,  .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(J)*/
    {.bitmap_index = 915,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(K)*/
    {.bitmap_index = 939,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(L)*/
    {.bitmap_index = 963,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(M)*/
    {.bitmap_index = 987,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(N)*/
    {.bitmap_index = 1011,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(O)*/
    {.bitmap_index = 1035,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(P)*/
    {.bitmap_index = 1059,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(Q)*/
    {.bitmap_index = 1086,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(R)*/
    {.bitmap_index = 1110,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(S)*/
    {.bitmap_index = 1134,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(T)*/
    {.bitmap_index = 1158,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(U)*/
    {.bitmap_index = 1182,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(V)*/
    {.bitmap_index = 1206,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(W)*/
    {.bitmap_index = 1230,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(X)*/
    {.bitmap_index = 1254,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(Y)*/
    {.bitmap_index = 1278,	.height = 8,   .width = 6,   .ofs_x = 0, .ofs_y = 2},/*(Z)*/
    {.bitmap_index = 1302,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*([)*/
    {.bitmap_index = 1335,	.height = 10,  .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(\)*/
    {.bitmap_index = 1365,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(])*/
    {.bitmap_index = 1398,	.height = 2,   .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(^)*/
    {.bitmap_index = 1404,	.height = 1,   .width = 6,   .ofs_x = 0, .ofs_y = 11},/*(_)*/
    {.bitmap_index = 1407,	.height = 2,   .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(`)*/
    {.bitmap_index = 1413,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(a)*/
    {.bitmap_index = 1428,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(b)*/
    {.bitmap_index = 1455,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(c)*/
    {.bitmap_index = 1470,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(d)*/
    {.bitmap_index = 1497,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(e)*/
    {.bitmap_index = 1512,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(f)*/
    {.bitmap_index = 1539,	.height = 7,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(g)*/
    {.bitmap_index = 1560,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(h)*/
    {.bitmap_index = 1587,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(i)*/
    {.bitmap_index = 1614,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(j)*/
    {.bitmap_index = 1647,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(k)*/
    {.bitmap_index = 1674,	.height = 9,   .width = 6,   .ofs_x = 0, .ofs_y = 1},/*(l)*/
    {.bitmap_index = 1701,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(m)*/
    {.bitmap_index = 1716,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(n)*/
    {.bitmap_index = 1731,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(o)*/
    {.bitmap_index = 1746,	.height = 7,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(p)*/
    {.bitmap_index = 1767,	.height = 7,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(q)*/
    {.bitmap_index = 1788,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(r)*/
    {.bitmap_index = 1803,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(s)*/
    {.bitmap_index = 1818,	.height = 7,   .width = 6,   .ofs_x = 0, .ofs_y = 3},/*(t)*/
    {.bitmap_index = 1839,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(u)*/
    {.bitmap_index = 1854,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(v)*/
    {.bitmap_index = 1869,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(w)*/
    {.bitmap_index = 1884,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(x)*/
    {.bitmap_index = 1899,	.height = 7,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(y)*/
    {.bitmap_index = 1920,	.height = 5,   .width = 6,   .ofs_x = 0, .ofs_y = 5},/*(z)*/
    {.bitmap_index = 1935,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*({)*/
    {.bitmap_index = 1968,	.height = 12,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(|)*/
    {.bitmap_index = 2004,	.height = 11,  .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(})*/
    {.bitmap_index = 2037,	.height = 2,   .width = 6,   .ofs_x = 0, .ofs_y = 0},/*(~)*/
    {.bitmap_index = 2043,	.height = 0,   .width = 6,   .ofs_x = 0, .ofs_y = 12},/*()*/
    {.bitmap_index = 2043,	.height = 10,  .width = 12,  .ofs_x = 0, .ofs_y = 0},/*(℃)*/
    {.bitmap_index = 2103,  .height = 11,  .width = 12,  .ofs_x = 0, .ofs_y = 0},/*(℉)*/
};


static const uint16_t unicode_list_1[] = {
    0x0020,	/*( )*/
    0x0021,	/*(!)*/
    0x0022,	/*(")*/
    0x0023,	/*(#)*/
    0x0024,	/*($)*/
    0x0025,	/*(%)*/
    0x0026,	/*(&)*/
    0x0027,	/*(')*/
    0x0028,	/*(()*/
    0x0029,	/*())*/
    0x002a,	/*(*)*/
    0x002b,	/*(+)*/
    0x002c,	/*(,)*/
    0x002d,	/*(-)*/
    0x002e,	/*(.)*/
    0x002f,	/*(/)*/
    0x0030,	/*(0)*/
    0x0031,	/*(1)*/
    0x0032,	/*(2)*/
    0x0033,	/*(3)*/
    0x0034,	/*(4)*/
    0x0035,	/*(5)*/
    0x0036,	/*(6)*/
    0x0037,	/*(7)*/
    0x0038,	/*(8)*/
    0x0039,	/*(9)*/
    0x003a,	/*(:)*/
    0x003b,	/*(;)*/
    0x003c,	/*(<)*/
    0x003d,	/*(=)*/
    0x003e,	/*(>)*/
    0x003f,	/*(?)*/
    0x0040,	/*(@)*/
    0x0041,	/*(A)*/
    0x0042,	/*(B)*/
    0x0043,	/*(C)*/
    0x0044,	/*(D)*/
    0x0045,	/*(E)*/
    0x0046,	/*(F)*/
    0x0047,	/*(G)*/
    0x0048,	/*(H)*/
    0x0049,	/*(I)*/
    0x004a,	/*(J)*/
    0x004b,	/*(K)*/
    0x004c,	/*(L)*/
    0x004d,	/*(M)*/
    0x004e,	/*(N)*/
    0x004f,	/*(O)*/
    0x0050,	/*(P)*/
    0x0051,	/*(Q)*/
    0x0052,	/*(R)*/
    0x0053,	/*(S)*/
    0x0054,	/*(T)*/
    0x0055,	/*(U)*/
    0x0056,	/*(V)*/
    0x0057,	/*(W)*/
    0x0058,	/*(X)*/
    0x0059,	/*(Y)*/
    0x005a,	/*(Z)*/
    0x005b,	/*([)*/
    0x005c,	/*(\)*/
    0x005d,	/*(])*/
    0x005e,	/*(^)*/
    0x005f,	/*(_)*/
    0x0060,	/*(`)*/
    0x0061,	/*(a)*/
    0x0062,	/*(b)*/
    0x0063,	/*(c)*/
    0x0064,	/*(d)*/
    0x0065,	/*(e)*/
    0x0066,	/*(f)*/
    0x0067,	/*(g)*/
    0x0068,	/*(h)*/
    0x0069,	/*(i)*/
    0x006a,	/*(j)*/
    0x006b,	/*(k)*/
    0x006c,	/*(l)*/
    0x006d,	/*(m)*/
    0x006e,	/*(n)*/
    0x006f,	/*(o)*/
    0x0070,	/*(p)*/
    0x0071,	/*(q)*/
    0x0072,	/*(r)*/
    0x0073,	/*(s)*/
    0x0074,	/*(t)*/
    0x0075,	/*(u)*/
    0x0076,	/*(v)*/
    0x0077,	/*(w)*/
    0x0078,	/*(x)*/
    0x0079,	/*(y)*/
    0x007a,	/*(z)*/
    0x007b,	/*({)*/
    0x007c,	/*(|)*/
    0x007d,	/*(})*/
    0x007e,	/*(~)*/
    0x007f,	/*()*/
    0x2103,	/*(℃)*/
    0x2109,	/*(℉)*/
};

sgl_font_t song12 = { 
    .bitmap = sgl_ascii_song12_bitmap, 
    .table = sgl_ascii_song12_tab, 
    .font_height = 12, 
    .bpp = 4,
#ifdef SGL_CONFIG_TEXT_UTF8
    .unicode_list = unicode_list_1,
    .unicode_list_len = sizeof(unicode_list_1) / sizeof(unicode_list_1[0])
#endif    
};

#endif