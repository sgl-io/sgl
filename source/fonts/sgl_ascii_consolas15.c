/* source/fonts/sgl_ascii_consolas15.c
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

#if(SGL_CONFIG_FONT_CONSOLAS15 == 1)
static const uint8_t sgl_ascii_consolas15_bitmap[2900] = {
/*   */



/* ! */
0x00,0x8c,0x80,0x00,  //..+%+..
0x00,0x8c,0x80,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x00,0x00,0x00,  //.......
0x00,0x8c,0x80,0x00,  //..+%+..
0x00,0x8c,0x80,0x00,  //..+%+..


/* " */
0x0c,0xe6,0xec,0x00,  //.%@+@%.
0x0a,0xe5,0xec,0x00,  //.%@+@%.
0x0a,0xe3,0xea,0x00,  //.%@.@%.


/* # */
0x03,0xa5,0xce,0x00,  //..%+%@.
0x05,0xa5,0xcc,0x00,  //.+%+%%.
0xcf,0xff,0xff,0xe0,  //%@@@@@@
0x08,0xc3,0xea,0x00,  //.+%.@%.
0x0a,0xe3,0xc8,0x00,  //.%@.%+.
0xef,0xff,0xff,0xc0,  //@@@@@@%
0x0c,0xc5,0xa5,0x00,  //.%%+%+.
0x0e,0xa8,0xc3,0x00,  //.@%+%..


/* $ */
0x00,0x0a,0xc0,0x00,  //...%%..
0x0a,0xff,0xfe,0x00,  //.%@@@@.
0x8c,0x8e,0xa0,0x00,  //+%+@%..
0x8c,0x5c,0x80,0x00,  //+%+%+..
0x0e,0xfe,0x50,0x00,  //.@@@+..
0x00,0x5e,0xfe,0x00,  //..+@@@.
0x00,0x8c,0x5e,0xa0,  //..+%+@%
0x00,0xae,0x8c,0x80,  //..%@+%+
0xaf,0xff,0xfa,0x00,  //%@@@@%.
0x00,0xca,0x00,0x00,  //..%%...
0x00,0xc8,0x00,0x00,  //..%+...


/* % */
0x8e,0xe8,0x0a,0xe0,  //+@@+.%@
0xea,0xae,0x5a,0x50,  //@%%@+%+
0xea,0xae,0xea,0x00,  //@%%@@%.
0xaf,0xea,0xe3,0x00,  //%@@%@..
0x00,0x5c,0x80,0x00,  //..+%+..
0x00,0xec,0xef,0xc0,  //..@%@@%
0x08,0xcc,0xc8,0xc0,  //.+%%%+%
0x3c,0x8c,0xc8,0xc0,  //.%+%%+%
0xec,0x08,0xef,0xa0,  //@%.+@@%


/* & */
0x08,0xef,0xe0,0x00,  //.+@@@..
0x3e,0xa5,0xc8,0x00,  //.@%+%+.
0x3c,0x83,0xea,0x00,  //.%+.@%.
0x0e,0xea,0xe5,0x00,  //.@@%@+.
0x08,0xee,0x50,0x00,  //.+@@+..
0x8c,0xaf,0xae,0xa0,  //+%%@%@%
0xec,0x0c,0xec,0x80,  //@%.%@%+
0xce,0x00,0xee,0x30,  //%@..@@.
0x3e,0xff,0xee,0xe0,  //.@@@@@@


/* ' */
0x00,0x8e,0xa0,0x00,  //..+@%..
0x00,0x5e,0xa0,0x00,  //..+@%..
0x00,0x5c,0x80,0x00,  //..+%+..


/* ( */
0x00,0x00,0xea,0x00,  //....@%.
0x00,0x0c,0xe0,0x00,  //...%@..
0x00,0x8c,0x50,0x00,  //..+%+..
0x00,0xec,0x00,0x00,  //..@%...
0x05,0xc8,0x00,0x00,  //.+%+...
0x05,0xa5,0x00,0x00,  //.+%+...
0x05,0xa5,0x00,0x00,  //.+%+...
0x05,0xc8,0x00,0x00,  //.+%+...
0x00,0xec,0x00,0x00,  //..@%...
0x00,0x8c,0x50,0x00,  //..+%+..
0x00,0x0c,0xe0,0x00,  //...%@..
0x00,0x00,0xea,0x00,  //....@%.


/* ) */
0x08,0xc3,0x00,0x00,  //.+%....
0x00,0xee,0x00,0x00,  //..@@...
0x00,0x5c,0x80,0x00,  //..+%+..
0x00,0x0c,0xe0,0x00,  //...%@..
0x00,0x08,0xc5,0x00,  //...+%+.
0x00,0x05,0xc8,0x00,  //...+%+.
0x00,0x05,0xc8,0x00,  //...+%+.
0x00,0x08,0xc5,0x00,  //...+%+.
0x00,0x0c,0xe0,0x00,  //...%@..
0x00,0x5c,0x80,0x00,  //..+%+..
0x00,0xee,0x00,0x00,  //..@@...
0x0a,0xe0,0x00,0x00,  //.%@....


/* * */
0x00,0x38,0x30,0x00,  //...+...
0x3e,0xc8,0xce,0x30,  //.@%+%@.
0x00,0xcf,0xc0,0x00,  //..%@%..
0x3e,0xc8,0xce,0x30,  //.@%+%@.
0x00,0x38,0x30,0x00,  //...+...


/* + */
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0xcf,0xff,0xff,0xc0,  //%@@@@@%
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..


/* , */
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0x8e,0xe0,0x00,  //..+@@..
0x00,0x5e,0xa0,0x00,  //..+@%..
0x0c,0xfc,0x00,0x00,  //.%@%...


/* - */
0x0a,0xff,0xfc,0x00,  //.%@@@%.


/* . */
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0xcf,0xa0,0x00,  //..%@%..


/* / */
0x00,0x00,0x8c,0x50,  //....+%+
0x00,0x00,0xcc,0x00,  //....%%.
0x00,0x05,0xc8,0x00,  //...+%+.
0x00,0x0a,0xe0,0x00,  //...%@..
0x00,0x3c,0x80,0x00,  //...%+..
0x00,0xae,0x30,0x00,  //..%@...
0x00,0xea,0x00,0x00,  //..@%...
0x08,0xc3,0x00,0x00,  //.+%....
0x0e,0xc0,0x00,0x00,  //.@%....
0x8c,0x50,0x00,0x00,  //+%+....


/* 0 */
0x08,0xef,0xe8,0x00,  //.+@@@+.
0x5e,0xa0,0x8c,0x50,  //+@%.+%+
0xae,0x30,0xcf,0xa0,  //%@..%@%
0xce,0x0e,0xee,0xc0,  //%@.@@@%
0xce,0xee,0x0e,0xc0,  //%@@@.@%
0xaf,0xc0,0x3e,0xa0,  //%@%..@%
0x5c,0x80,0xae,0x50,  //+%+.%@+
0x08,0xef,0xe8,0x00,  //.+@@@+.


/* 1 */
0x03,0xef,0xa0,0x00,  //..@@%..
0x5c,0x8e,0xa0,0x00,  //+%+@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x5e,0xff,0xff,0xa0,  //+@@@@@%


/* 2 */
0x08,0xef,0xe8,0x00,  //.+@@@+.
0x3a,0x50,0xce,0x30,  //.%+.%@.
0x00,0x00,0xae,0x50,  //....%@+
0x00,0x00,0xce,0x00,  //....%@.
0x00,0x0a,0xe5,0x00,  //...%@+.
0x00,0xce,0x50,0x00,  //..%@+..
0x0c,0xe5,0x00,0x00,  //.%@+...
0x8e,0xff,0xff,0xa0,  //+@@@@@%


/* 3 */
0x0e,0xff,0xe8,0x00,  //.@@@@+.
0x00,0x00,0xce,0x30,  //....%@.
0x00,0x00,0xce,0x00,  //....%@.
0x05,0xef,0xe3,0x00,  //.+@@@..
0x00,0x00,0xae,0x50,  //....%@+
0x00,0x00,0x5c,0x80,  //....+%+
0x00,0x00,0xae,0x30,  //....%@.
0x5e,0xff,0xe3,0x00,  //+@@@@..


/* 4 */
0x00,0x0c,0xfa,0x00,  //...%@%.
0x00,0xae,0xea,0x00,  //..%@@%.
0x05,0xc8,0xea,0x00,  //.+%+@%.
0x0e,0xc3,0xea,0x00,  //.@%.@%.
0xae,0x03,0xea,0x00,  //%@..@%.
0xef,0xff,0xff,0xe0,  //@@@@@@@
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x03,0xea,0x00,  //....@%.


/* 5 */
0x3e,0xff,0xfe,0x00,  //.@@@@@.
0x3e,0xa0,0x00,0x00,  //.@%....
0x3e,0xa0,0x00,0x00,  //.@%....
0x3e,0xff,0xe8,0x00,  //.@@@@+.
0x00,0x00,0xce,0x50,  //....%@+
0x00,0x00,0x8c,0x80,  //....+%+
0x00,0x00,0xee,0x30,  //....@@.
0x3e,0xff,0xe3,0x00,  //.@@@@..


/* 6 */
0x00,0xaf,0xfe,0x30,  //..%@@@.
0x0c,0xe3,0x00,0x00,  //.%@....
0x5c,0x80,0x00,0x00,  //+%+....
0x8c,0xcf,0xfc,0x00,  //+%%@@%.
0x8e,0xc0,0x5c,0x80,  //+@%.+%+
0x8c,0x30,0x0e,0xa0,  //+%...@%
0x3e,0xa0,0x8c,0x80,  //.@%.+%+
0x08,0xef,0xfa,0x00,  //.+@@@%.


/* 7 */
0xaf,0xff,0xff,0xa0,  //%@@@@@%
0x00,0x00,0x5c,0x80,  //....+%+
0x00,0x00,0xce,0x00,  //....%@.
0x00,0x05,0xc8,0x00,  //...+%+.
0x00,0x0c,0xe0,0x00,  //...%@..
0x00,0x8c,0x80,0x00,  //..+%+..
0x00,0xee,0x00,0x00,  //..@@...
0x08,0xc8,0x00,0x00,  //.+%+...


/* 8 */
0x0a,0xff,0xfe,0x00,  //.%@@@@.
0x5a,0x50,0x5c,0x80,  //+%+.+%+
0x3e,0xc0,0xae,0x30,  //.@%.%@.
0x00,0xef,0xe0,0x00,  //..@@@..
0x3e,0xe0,0xee,0x30,  //.@@.@@.
0x8c,0x50,0x5e,0xa0,  //+%+.+@%
0x8c,0x80,0x8c,0x80,  //+%+.+%+
0x0c,0xff,0xfa,0x00,  //.%@@@%.


/* 9 */
0x0a,0xff,0xe5,0x00,  //.%@@@+.
0x8c,0x50,0xae,0x30,  //+%+.%@.
0xae,0x00,0x5c,0x80,  //%@..+%+
0xae,0x50,0xce,0x80,  //%@+.%@+
0x0c,0xff,0xcc,0x80,  //.%@@%%+
0x00,0x00,0x8c,0x50,  //....+%+
0x00,0x03,0xec,0x00,  //....@%.
0x3e,0xff,0xa0,0x00,  //.@@@%..


/* : */
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0x00,0x00,0x00,  //.......
0x00,0x00,0x00,0x00,  //.......
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0xaf,0xa0,0x00,  //..%@%..


/* ; */
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0x00,0x00,0x00,  //.......
0x00,0x00,0x00,0x00,  //.......
0x00,0xaf,0xc0,0x00,  //..%@%..
0x00,0x8e,0xe0,0x00,  //..+@@..
0x00,0x3e,0xc0,0x00,  //...@%..
0x0c,0xfc,0x00,0x00,  //.%@%...


/* < */
0x00,0x00,0xce,0x00,  //....%@.
0x00,0x0e,0xe3,0x00,  //...@@..
0x05,0xec,0x00,0x00,  //.+@%...
0x8e,0xa0,0x00,0x00,  //+@%....
0x05,0xee,0x00,0x00,  //.+@@...
0x00,0x0e,0xe3,0x00,  //...@@..
0x00,0x00,0xce,0x00,  //....%@.


/* = */
0x8e,0xff,0xff,0xa0,  //+@@@@@%
0x00,0x00,0x00,0x00,  //.......
0x8e,0xff,0xff,0xa0,  //+@@@@@%


/* > */
0x0c,0xc0,0x00,0x00,  //.%%....
0x00,0xee,0x30,0x00,  //..@@...
0x00,0x0c,0xe5,0x00,  //...%@+.
0x00,0x00,0xae,0x80,  //....%@+
0x00,0x0c,0xe5,0x00,  //...%@+.
0x00,0xee,0x30,0x00,  //..@@...
0x0c,0xc0,0x00,0x00,  //.%%....


/* ? */
0x05,0xef,0xa0,0x00,  //.+@@%..
0x00,0x08,0xea,0x00,  //...+@%.
0x00,0x00,0xce,0x30,  //....%@.
0x00,0x00,0xce,0x00,  //....%@.
0x00,0xcf,0xe8,0x00,  //..%@@+.
0x00,0xae,0x00,0x00,  //..%@...
0x00,0x00,0x00,0x00,  //.......
0x00,0xce,0x30,0x00,  //..%@...
0x00,0xce,0x30,0x00,  //..%@...


/* @ */
0x00,0xcf,0xfc,0x00,  //..%@@%.
0x0c,0xe3,0x3e,0xa0,  //.%@..@%
0x5a,0x50,0x08,0xc0,  //+%+..+%
0xcc,0xaf,0xfa,0xa0,  //%%%@@%%
0xc8,0xc8,0xc8,0xa0,  //%+%+%+%
0xa8,0xc5,0xa6,0xa0,  //%+%+%+%
0xaa,0xe8,0xc5,0xa0,  //%%@+%+%
0xaa,0xea,0xea,0xe0,  //%%@%@%@
0xa6,0xee,0xee,0x80,  //%+@@@@+
0xea,0x00,0x00,0x00,  //@%.....
0xae,0x30,0xaa,0x00,  //%@..%%.
0x0c,0xff,0xe5,0x00,  //.%@@@+.


/* A */
0x00,0xaf,0xc0,0x00,  //..%@%..
0x00,0xc8,0xc3,0x00,  //..%+%..
0x05,0xa3,0xc8,0x00,  //.+%.%+.
0x0a,0xc0,0xcc,0x00,  //.%%.%%.
0x3e,0xa0,0x8c,0x30,  //.@%.+%.
0x8e,0xff,0xfe,0x80,  //+@@@@@+
0xce,0x00,0x0c,0xc0,  //%@...%%
0xea,0x00,0x0a,0xe0,  //@%...%@


/* B */
0x5e,0xff,0xfa,0x00,  //+@@@@%.
0x5a,0x50,0xae,0x50,  //+%+.%@+
0x5a,0x50,0xae,0x30,  //+%+.%@.
0x5e,0xff,0xe8,0x00,  //+@@@@+.
0x5a,0x50,0x8c,0x80,  //+%+.+%+
0x5a,0x50,0x3c,0x80,  //+%+..%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5e,0xff,0xe8,0x00,  //+@@@@+.


/* C */
0x00,0xef,0xfe,0x80,  //..@@@@+
0x3e,0xe0,0x00,0x00,  //.@@....
0x8c,0x50,0x00,0x00,  //+%+....
0xce,0x30,0x00,0x00,  //%@.....
0xce,0x30,0x00,0x00,  //%@.....
0xae,0x50,0x00,0x00,  //%@+....
0x3e,0xe0,0x00,0x00,  //.@@....
0x05,0xef,0xfe,0x80,  //.+@@@@+


/* D */
0xaf,0xff,0xe5,0x00,  //%@@@@+.
0xae,0x30,0xce,0x50,  //%@..%@+
0xae,0x30,0x3e,0xc0,  //%@...@%
0xae,0x30,0x0e,0xc0,  //%@...@%
0xae,0x30,0x0e,0xc0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0xee,0x50,  //%@..@@+
0xaf,0xff,0xe3,0x00,  //%@@@@..


/* E */
0x0e,0xff,0xfe,0x50,  //.@@@@@+
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xff,0xfe,0x30,  //.@@@@@.
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xff,0xfe,0x50,  //.@@@@@+


/* F */
0x0e,0xff,0xfe,0x50,  //.@@@@@+
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xff,0xfe,0x30,  //.@@@@@.
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....


/* G */
0x03,0xef,0xff,0xa0,  //..@@@@%
0x3e,0xe0,0x00,0x00,  //.@@....
0xae,0x50,0x00,0x00,  //%@+....
0xce,0x0c,0xff,0xa0,  //%@.%@@%
0xce,0x00,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0x5e,0xc0,0x3e,0xa0,  //+@%..@%
0x05,0xef,0xfe,0x80,  //.+@@@@+


/* H */
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xaf,0xff,0xff,0xa0,  //%@@@@@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%


/* I */
0x5e,0xff,0xfe,0x50,  //+@@@@@+
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x5e,0xff,0xfe,0x50,  //+@@@@@+


/* J */
0x0e,0xff,0xfc,0x00,  //.@@@@%.
0x00,0x00,0xec,0x00,  //....@%.
0x00,0x00,0xec,0x00,  //....@%.
0x00,0x00,0xec,0x00,  //....@%.
0x00,0x00,0xec,0x00,  //....@%.
0x00,0x00,0xec,0x00,  //....@%.
0x38,0x05,0xea,0x00,  //.+.+@%.
0x0a,0xff,0xc0,0x00,  //.%@@%..


/* K */
0x5a,0x50,0x8e,0xa0,  //+%+.+@%
0x5a,0x55,0xea,0x00,  //+%++@%.
0x5a,0x5e,0xc0,0x00,  //+%+@%..
0x5a,0xae,0x00,0x00,  //+%%@...
0x5e,0xfc,0x00,0x00,  //+@@%...
0x5a,0x5e,0xc0,0x00,  //+%+@%..
0x5a,0x55,0xea,0x00,  //+%++@%.
0x5a,0x50,0x8e,0xc0,  //+%+.+@%


/* L */
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xc0,0x00,0x00,  //.%%....
0x0c,0xff,0xff,0xa0,  //.%@@@@%


/* M */
0xae,0x80,0x8e,0xa0,  //%@+.+@%
0xcc,0xc0,0xac,0xc0,  //%%%.%%%
0xcc,0x83,0x8c,0xc0,  //%%+.+%%
0xca,0xaa,0xac,0xc0,  //%%%%%%%
0xea,0x8c,0x5c,0xc0,  //@%+%+%%
0xea,0x00,0x0a,0xe0,  //@%...%@
0xea,0x00,0x0a,0xe0,  //@%...%@
0xea,0x00,0x0a,0xe0,  //@%...%@


/* N */
0xaf,0xc0,0x3e,0xa0,  //%@%..@%
0xae,0xc3,0x3e,0xa0,  //%@%..@%
0xae,0xca,0x3e,0xa0,  //%@%%.@%
0xae,0x8c,0x3e,0xa0,  //%@+%.@%
0xae,0x3c,0x8e,0xa0,  //%@.%+@%
0xae,0x3a,0xee,0xa0,  //%@.%@@%
0xae,0x33,0xce,0xa0,  //%@..%@%
0xae,0x30,0xaf,0xa0,  //%@..%@%


/* O */
0x08,0xef,0xfa,0x00,  //.+@@@%.
0x5e,0xa0,0x8c,0x80,  //+@%.+%+
0xce,0x00,0x0e,0xc0,  //%@...@%
0xec,0x00,0x0c,0xe0,  //@%...%@
0xec,0x00,0x0c,0xe0,  //@%...%@
0xce,0x00,0x0e,0xc0,  //%@...@%
0x8c,0x80,0x8c,0x80,  //+%+.+%+
0x0a,0xff,0xe8,0x00,  //.%@@@+.


/* P */
0x5e,0xff,0xfa,0x00,  //+@@@@%.
0x5a,0x50,0x8c,0x80,  //+%+.+%+
0x5a,0x50,0x3e,0xa0,  //+%+..@%
0x5a,0x50,0xae,0x80,  //+%+.%@+
0x5e,0xff,0xe8,0x00,  //+@@@@+.
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....


/* Q */
0x08,0xef,0xfa,0x00,  //.+@@@%.
0x5e,0xa0,0x8c,0x80,  //+@%.+%+
0xce,0x30,0x0e,0xc0,  //%@...@%
0xee,0x00,0x0c,0xe0,  //@@...%@
0xee,0x00,0x0c,0xe0,  //@@...%@
0xce,0x30,0x0e,0xc0,  //%@...@%
0x8e,0xa0,0xae,0x80,  //+@%.%@+
0x0a,0xff,0xe8,0x00,  //.%@@@+.
0x00,0x5c,0x80,0x00,  //..+%+..
0x00,0x0a,0xff,0xe0,  //...%@@@


/* R */
0x5e,0xff,0xe8,0x00,  //+@@@@+.
0x5c,0x80,0xce,0x30,  //+%+.%@.
0x5c,0x80,0x8c,0x50,  //+%+.+%+
0x5c,0x80,0xee,0x00,  //+%+.@@.
0x5e,0xff,0xe3,0x00,  //+@@@@..
0x5c,0x88,0xec,0x00,  //+%++@%.
0x5c,0x80,0xce,0x50,  //+%+.%@+
0x5c,0x80,0x5e,0xc0,  //+%+.+@%


/* S */
0x08,0xef,0xfe,0x00,  //.+@@@@.
0x8c,0x80,0x00,0x00,  //+%+....
0x8c,0x80,0x00,0x00,  //+%+....
0x0c,0xfe,0x30,0x00,  //.%@@...
0x00,0x0c,0xfe,0x30,  //...%@@.
0x00,0x00,0x5e,0xa0,  //....+@%
0x00,0x00,0x8c,0x80,  //....+%+
0xaf,0xff,0xfa,0x00,  //%@@@@%.


/* T */
0xcf,0xff,0xff,0xc0,  //%@@@@@%
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..


/* U */
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0xae,0x30,0x3e,0xa0,  //%@...@%
0x8c,0x80,0x8c,0x50,  //+%+.+%+
0x0c,0xff,0xe8,0x00,  //.%@@@+.


/* V */
0xea,0x00,0x0a,0xe0,  //@%...%@
0xce,0x00,0x0e,0xc0,  //%@...@%
0x8c,0x50,0x5c,0x80,  //+%+.+%+
0x3e,0xa0,0xae,0x30,  //.@%.%@.
0x0c,0xe0,0xec,0x00,  //.%@.@%.
0x08,0xc6,0xc8,0x00,  //.+%+%+.
0x03,0xea,0xe3,0x00,  //..@%@..
0x00,0xcf,0xa0,0x00,  //..%@%..


/* W */
0xea,0x00,0x0a,0xe0,  //@%...%@
0xec,0x00,0x0a,0xe0,  //@%...%@
0xcc,0x00,0x0a,0xe0,  //%%...%@
0xcc,0x5a,0x5a,0xc0,  //%%+%+%%
0xae,0xaa,0xac,0xc0,  //%@%%%%%
0xae,0xa8,0xac,0xc0,  //%@%+%%%
0xae,0xa3,0xac,0xa0,  //%@%.%%%
0x8e,0xc0,0xcf,0xa0,  //+@%.%@%


/* X */
0xce,0x50,0x3e,0xe0,  //%@+..@@
0x0e,0xe0,0xce,0x30,  //.@@.%@.
0x05,0xea,0xc8,0x00,  //.+@%%+.
0x00,0xcf,0xc0,0x00,  //..%@%..
0x00,0xcf,0xe0,0x00,  //..%@@..
0x08,0xc8,0xea,0x00,  //.+%+@%.
0x3e,0xc0,0xce,0x30,  //.@%.%@.
0xee,0x30,0x5e,0xe0,  //@@..+@@


/* Y */
0xec,0x00,0x0c,0xe0,  //@%...%@
0x8c,0x80,0x8c,0x80,  //+%+.+%+
0x0c,0xe0,0xec,0x00,  //.%@.@%.
0x05,0xea,0xc5,0x00,  //.+@%%+.
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..


/* Z */
0x8e,0xff,0xff,0xa0,  //+@@@@@%
0x00,0x00,0xae,0x00,  //....%@.
0x00,0x05,0xa5,0x00,  //...+%+.
0x00,0x0e,0xa0,0x00,  //...@%..
0x00,0xae,0x00,0x00,  //..%@...
0x03,0xa5,0x00,0x00,  //..%+...
0x0c,0xc0,0x00,0x00,  //.%%....
0x8e,0xff,0xff,0xa0,  //+@@@@@%


/* [ */
0x03,0xef,0xfa,0x00,  //..@@@%.
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xc8,0x00,0x00,  //..%+...
0x03,0xef,0xfa,0x00,  //..@@@%.


/* \ */
0x3e,0xa0,0x00,0x00,  //.@%....
0x0a,0xe0,0x00,0x00,  //.%@....
0x03,0xc8,0x00,0x00,  //..%+...
0x00,0xcc,0x00,0x00,  //..%%...
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x0e,0xc0,0x00,  //...@%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x00,0xea,0x00,  //....@%.
0x00,0x00,0xae,0x30,  //....%@.
0x00,0x00,0x3e,0xa0,  //.....@%


/* ] */
0x0a,0xff,0xe3,0x00,  //.%@@@..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x00,0x08,0xc3,0x00,  //...+%..
0x0a,0xff,0xe3,0x00,  //.%@@@..


/* ^ */
0x00,0xae,0x80,0x00,  //..%@+..
0x03,0xa8,0xc3,0x00,  //..%+%..
0x0c,0xc0,0xea,0x00,  //.%%.@%.
0x8c,0x50,0x8c,0x80,  //+%+.+%+


/* _ */
0xef,0xff,0xff,0xe0,  //@@@@@@@


/* ` */
0x0e,0xe8,0x00,0x00,  //.@@+...
0x00,0xae,0x50,0x00,  //..%@+..


/* a */
0x0e,0xff,0xfa,0x00,  //.@@@@%.
0x00,0x00,0x8c,0x50,  //....+%+
0x0a,0xff,0xfe,0x50,  //.%@@@@+
0x5c,0x80,0x8c,0x50,  //+%+.+%+
0x8c,0x80,0xee,0x50,  //+%+.@@+
0x0e,0xff,0xca,0x50,  //.@@@%%+


/* b */
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0xaf,0xfc,0x00,  //+%%@@%.
0x5e,0xe0,0x8c,0x80,  //+@@.+%+
0x5a,0x50,0x3e,0xa0,  //+%+..@%
0x5a,0x50,0x3e,0xa0,  //+%+..@%
0x5a,0x50,0xae,0x50,  //+%+.%@+
0x5e,0xff,0xe8,0x00,  //+@@@@+.


/* c */
0x00,0xef,0xfe,0x50,  //..@@@@+
0x0e,0xe0,0x00,0x00,  //.@@....
0x5c,0x80,0x00,0x00,  //+%+....
0x5c,0x80,0x00,0x00,  //+%+....
0x3e,0xe0,0x00,0x00,  //.@@....
0x03,0xef,0xfe,0x50,  //..@@@@+


/* d */
0x00,0x00,0x8c,0x50,  //....+%+
0x00,0x00,0x8c,0x50,  //....+%+
0x00,0x00,0x8c,0x50,  //....+%+
0x08,0xef,0xfe,0x50,  //.+@@@@+
0x5e,0xa0,0x8c,0x50,  //+@%.+%+
0xae,0x30,0x8c,0x50,  //%@..+%+
0xae,0x30,0x8c,0x50,  //%@..+%+
0x8c,0x83,0xee,0x50,  //+%+.@@+
0x0c,0xff,0xaa,0x50,  //.%@@%%+


/* e */
0x08,0xef,0xfa,0x00,  //.+@@@%.
0x5a,0x50,0x5c,0x80,  //+%+.+%+
0x8e,0xff,0xfe,0x80,  //+@@@@@+
0xae,0x30,0x00,0x00,  //%@.....
0x5e,0xa0,0x00,0x00,  //+@%....
0x08,0xef,0xfe,0x30,  //.+@@@@.


/* f */
0x00,0x3e,0xff,0xc0,  //...@@@%
0x00,0xae,0x30,0x00,  //..%@...
0x00,0xce,0x00,0x00,  //..%@...
0xcf,0xff,0xfe,0x50,  //%@@@@@+
0x00,0xce,0x00,0x00,  //..%@...
0x00,0xce,0x00,0x00,  //..%@...
0x00,0xce,0x00,0x00,  //..%@...
0x00,0xce,0x00,0x00,  //..%@...
0x00,0xce,0x00,0x00,  //..%@...


/* g */
0x0a,0xff,0xff,0xc0,  //.%@@@@%
0x5c,0x80,0xae,0x30,  //+%+.%@.
0x5c,0x80,0xae,0x30,  //+%+.%@.
0x0e,0xff,0xe8,0x00,  //.@@@@+.
0x8c,0x30,0x00,0x00,  //+%.....
0x0e,0xff,0xfe,0x50,  //.@@@@@+
0xae,0x50,0x0e,0xc0,  //%@+..@%
0xae,0x50,0x5e,0xa0,  //%@+.+@%
0x3e,0xff,0xfc,0x00,  //.@@@@%.


/* h */
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0xaf,0xfc,0x00,  //+%%@@%.
0x5e,0xe0,0xae,0x50,  //+@@.%@+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+


/* i */
0x00,0x8e,0xa0,0x00,  //..+@%..
0x00,0x8e,0xa0,0x00,  //..+@%..
0x00,0x00,0x00,0x00,  //.......
0x0e,0xff,0xa0,0x00,  //.@@@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x3e,0xff,0xff,0xa0,  //.@@@@@%


/* j */
0x00,0x08,0xea,0x00,  //...+@%.
0x00,0x08,0xea,0x00,  //...+@%.
0x00,0x00,0x00,0x00,  //.......
0x3e,0xff,0xfa,0x00,  //.@@@@%.
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x03,0xea,0x00,  //....@%.
0x00,0x0a,0xe5,0x00,  //...%@+.
0x8e,0xff,0xa0,0x00,  //+@@@%..


/* k */
0x3e,0xa0,0x00,0x00,  //.@%....
0x3e,0xa0,0x00,0x00,  //.@%....
0x3e,0xa0,0x00,0x00,  //.@%....
0x3e,0xa0,0xcf,0xa0,  //.@%.%@%
0x3e,0xae,0xe3,0x00,  //.@%@@..
0x3e,0xfe,0x00,0x00,  //.@@@...
0x3e,0xae,0xa0,0x00,  //.@%@%..
0x3e,0xa8,0xea,0x00,  //.@%+@%.
0x3e,0xa0,0xaf,0xc0,  //.@%.%@%


/* l */
0x0e,0xff,0xa0,0x00,  //.@@@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x00,0x3e,0xa0,0x00,  //...@%..
0x3e,0xff,0xff,0xa0,  //.@@@@@%


/* m */
0xcc,0xee,0xef,0xa0,  //%%@@@@%
0xce,0x6e,0xcc,0xc0,  //%@+@%%%
0xce,0x5c,0x8c,0xc0,  //%@+%+%%
0xce,0x5c,0x8c,0xc0,  //%@+%+%%
0xce,0x5c,0x8c,0xc0,  //%@+%+%%
0xce,0x5c,0x8c,0xc0,  //%@+%+%%


/* n */
0x5a,0xcf,0xfc,0x00,  //+%%@@%.
0x5e,0xe0,0xae,0x50,  //+@@.%@+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+


/* o */
0x08,0xef,0xfa,0x00,  //.+@@@%.
0x8c,0x80,0x8c,0x80,  //+%+.+%+
0xce,0x00,0x0e,0xa0,  //%@...@%
0xce,0x00,0x0e,0xa0,  //%@...@%
0x8c,0x80,0x8c,0x80,  //+%+.+%+
0x0a,0xff,0xe8,0x00,  //.%@@@+.


/* p */
0x5a,0xcf,0xfc,0x00,  //+%%@@%.
0x5e,0xe0,0x8c,0x80,  //+@@.+%+
0x5a,0x50,0x3e,0xa0,  //+%+..@%
0x5a,0x50,0x3e,0xa0,  //+%+..@%
0x5a,0x50,0xae,0x50,  //+%+.%@+
0x5e,0xff,0xe8,0x00,  //+@@@@+.
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....
0x5a,0x50,0x00,0x00,  //+%+....


/* q */
0x08,0xef,0xfe,0x50,  //.+@@@@+
0x5e,0xa0,0x8c,0x50,  //+@%.+%+
0xae,0x30,0x8c,0x50,  //%@..+%+
0xae,0x30,0x8c,0x50,  //%@..+%+
0x8c,0x83,0xee,0x50,  //+%+.@@+
0x0c,0xff,0xaa,0x50,  //.%@@%%+
0x00,0x00,0x8c,0x50,  //....+%+
0x00,0x00,0x8c,0x50,  //....+%+
0x00,0x00,0x8c,0x50,  //....+%+


/* r */
0x0e,0xae,0xfe,0x50,  //.@%@@@+
0x0e,0xe3,0x0e,0xa0,  //.@@..@%
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....
0x0e,0xa0,0x00,0x00,  //.@%....


/* s */
0x08,0xef,0xfc,0x00,  //.+@@@%.
0x0e,0xa0,0x00,0x00,  //.@%....
0x0c,0xfe,0x00,0x00,  //.%@@...
0x00,0x0a,0xfe,0x00,  //...%@@.
0x00,0x00,0x8c,0x50,  //....+%+
0x3e,0xff,0xfa,0x00,  //.@@@@%.


/* t */
0x03,0xea,0x00,0x00,  //..@%...
0x03,0xea,0x00,0x00,  //..@%...
0xcf,0xff,0xfe,0x80,  //%@@@@@+
0x03,0xea,0x00,0x00,  //..@%...
0x03,0xea,0x00,0x00,  //..@%...
0x03,0xea,0x00,0x00,  //..@%...
0x00,0xec,0x00,0x00,  //..@%...
0x00,0x8e,0xfe,0x80,  //..+@@@+


/* u */
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5a,0x50,0x8c,0x50,  //+%+.+%+
0x5c,0x83,0xee,0x50,  //+%+.@@+
0x0c,0xff,0xca,0x50,  //.%@@%%+


/* v */
0xce,0x30,0x0e,0xc0,  //%@...@%
0x5c,0x80,0x5a,0x50,  //+%+.+%+
0x0e,0xc0,0xce,0x00,  //.@%.%@.
0x08,0xc3,0xc8,0x00,  //.+%.%+.
0x03,0xc8,0xc3,0x00,  //..%+%..
0x00,0xaf,0xa0,0x00,  //..%@%..


/* w */
0xea,0x00,0x0a,0xe0,  //@%...%@
0xec,0x5a,0x5c,0xe0,  //@%+%+%@
0xcc,0xac,0xac,0xc0,  //%%%%%%%
0xae,0xa8,0xce,0xa0,  //%@%+%@%
0x8c,0xa3,0xac,0x80,  //+%%.%%+
0x5e,0xc0,0xce,0x50,  //+@%.%@+


/* x */
0xaf,0xa0,0x5e,0xc0,  //%@%.+@%
0x0a,0xe5,0xec,0x00,  //.%@+@%.
0x00,0xcf,0xe0,0x00,  //..%@@..
0x00,0xcc,0xe0,0x00,  //..%%@..
0x0a,0xe3,0xec,0x00,  //.%@.@%.
0xae,0x80,0x8e,0xc0,  //%@+.+@%


/* y */
0xce,0x30,0x3e,0xc0,  //%@...@%
0x5c,0x80,0x8c,0x50,  //+%+.+%+
0x0e,0xc0,0xcc,0x00,  //.@%.%%.
0x08,0xc5,0xa5,0x00,  //.+%+%+.
0x00,0xca,0xe0,0x00,  //..%%@..
0x00,0xaf,0xa0,0x00,  //..%@%..
0x00,0xae,0x30,0x00,  //..%@...
0x05,0xea,0x00,0x00,  //.+@%...
0xef,0xc0,0x00,0x00,  //@@%....


/* z */
0x3e,0xff,0xfe,0x50,  //.@@@@@+
0x00,0x00,0xc8,0x00,  //....%+.
0x00,0x0c,0xa0,0x00,  //...%%..
0x00,0xae,0x00,0x00,  //..%@...
0x05,0xa3,0x00,0x00,  //.+%....
0x3e,0xff,0xfe,0x80,  //.@@@@@+


/* { */
0x00,0x0e,0xfe,0x00,  //...@@@.
0x00,0x8c,0x50,0x00,  //..+%+..
0x00,0xae,0x30,0x00,  //..%@...
0x00,0xae,0x30,0x00,  //..%@...
0x00,0xae,0x00,0x00,  //..%@...
0x5e,0xe0,0x00,0x00,  //+@@....
0x00,0xce,0x00,0x00,  //..%@...
0x00,0xae,0x30,0x00,  //..%@...
0x00,0xae,0x30,0x00,  //..%@...
0x00,0xae,0x30,0x00,  //..%@...
0x00,0x8c,0x50,0x00,  //..+%+..
0x00,0x0c,0xfe,0x00,  //...%@@.


/* | */
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..
0x00,0x5a,0x50,0x00,  //..+%+..


/* } */
0x0c,0xfe,0x00,0x00,  //.%@@...
0x00,0x5c,0x80,0x00,  //..+%+..
0x00,0x0e,0xa0,0x00,  //...@%..
0x00,0x0e,0xa0,0x00,  //...@%..
0x00,0x0e,0xc0,0x00,  //...@%..
0x00,0x00,0xce,0x80,  //....%@+
0x00,0x0e,0xc0,0x00,  //...@%..
0x00,0x0e,0xa0,0x00,  //...@%..
0x00,0x0e,0xa0,0x00,  //...@%..
0x00,0x0e,0xa0,0x00,  //...@%..
0x00,0x5c,0x80,0x00,  //..+%+..
0x0c,0xfe,0x00,0x00,  //.%@@...


/* ~ */
0x3e,0xfa,0x0a,0xe0,  //.@@%.%@
0xae,0x5c,0x8c,0xc0,  //%@+%+%%
0xcc,0x08,0xee,0x50,  //%%.+@@+


/*  */


};


static const sgl_font_table_t sgl_ascii_consolas15_tab[] = {

    {.bitmap_index = 0,	   .height = 0, .width = 8, .ofs_x = 0, .ofs_y = 15 },/*( )*/
    {.bitmap_index = 0,	   .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(!)*/
    {.bitmap_index = 36,   .height = 3, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(")*/
    {.bitmap_index = 48,   .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(#)*/
    {.bitmap_index = 80,   .height = 11,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*($)*/
    {.bitmap_index = 124,  .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(%)*/
    {.bitmap_index = 160,  .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(&)*/
    {.bitmap_index = 196,  .height = 3, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(')*/
    {.bitmap_index = 208,  .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(()*/
    {.bitmap_index = 256,  .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*())*/
    {.bitmap_index = 304,  .height = 5, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(*)*/
    {.bitmap_index = 324,  .height = 7, .width = 8, .ofs_x = 0, .ofs_y = 5 },/*(+)*/
    {.bitmap_index = 352,  .height = 4, .width = 8, .ofs_x = 0, .ofs_y = 10 },/*(,)*/
    {.bitmap_index = 368,  .height = 1, .width = 8, .ofs_x = 0, .ofs_y = 8 },/*(-)*/
    {.bitmap_index = 372,  .height = 2, .width = 8, .ofs_x = 0, .ofs_y = 10 },/*(.)*/
    {.bitmap_index = 380,  .height = 10,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(/)*/
    {.bitmap_index = 420,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(0)*/
    {.bitmap_index = 452,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(1)*/
    {.bitmap_index = 484,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(2)*/
    {.bitmap_index = 516,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(3)*/
    {.bitmap_index = 548,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(4)*/
    {.bitmap_index = 580,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(5)*/
    {.bitmap_index = 612,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(6)*/
    {.bitmap_index = 644,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(7)*/
    {.bitmap_index = 676,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(8)*/
    {.bitmap_index = 708,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(9)*/
    {.bitmap_index = 740,  .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(:)*/
    {.bitmap_index = 764,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(;)*/
    {.bitmap_index = 796,  .height = 7, .width = 8, .ofs_x = 0, .ofs_y = 5 },/*(<)*/
    {.bitmap_index = 824,  .height = 3, .width = 8, .ofs_x = 0, .ofs_y = 7 },/*(=)*/
    {.bitmap_index = 836,  .height = 7, .width = 8, .ofs_x = 0, .ofs_y = 5 },/*(>)*/
    {.bitmap_index = 864,  .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(?)*/
    {.bitmap_index = 900,  .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(@)*/
    {.bitmap_index = 948,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(A)*/
    {.bitmap_index = 980,  .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(B)*/
    {.bitmap_index = 1012, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(C)*/
    {.bitmap_index = 1044, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(D)*/
    {.bitmap_index = 1076, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(E)*/
    {.bitmap_index = 1108, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(F)*/
    {.bitmap_index = 1140, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(G)*/
    {.bitmap_index = 1172, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(H)*/
    {.bitmap_index = 1204, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(I)*/
    {.bitmap_index = 1236, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(J)*/
    {.bitmap_index = 1268, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(K)*/
    {.bitmap_index = 1300, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(L)*/
    {.bitmap_index = 1332, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(M)*/
    {.bitmap_index = 1364, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(N)*/
    {.bitmap_index = 1396, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(O)*/
    {.bitmap_index = 1428, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(P)*/
    {.bitmap_index = 1460, .height = 10,.width = 8, .ofs_x = 0, .ofs_y = 4 },/*(Q)*/
    {.bitmap_index = 1500, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(R)*/
    {.bitmap_index = 1532, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(S)*/
    {.bitmap_index = 1564, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(T)*/
    {.bitmap_index = 1596, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(U)*/
    {.bitmap_index = 1628, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(V)*/
    {.bitmap_index = 1660, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(W)*/
    {.bitmap_index = 1692, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(X)*/
    {.bitmap_index = 1724, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(Y)*/
    {.bitmap_index = 1756, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(Z)*/
    {.bitmap_index = 1788, .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*([)*/
    {.bitmap_index = 1836, .height = 10,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(\)*/
    {.bitmap_index = 1876, .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(])*/
    {.bitmap_index = 1924, .height = 4, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(^)*/
    {.bitmap_index = 1940, .height = 1, .width = 8, .ofs_x = 0, .ofs_y = 14 },/*(_)*/
    {.bitmap_index = 1944, .height = 2, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(`)*/
    {.bitmap_index = 1952, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(a)*/
    {.bitmap_index = 1976, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(b)*/
    {.bitmap_index = 2012, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(c)*/
    {.bitmap_index = 2036, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(d)*/
    {.bitmap_index = 2072, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(e)*/
    {.bitmap_index = 2096, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(f)*/
    {.bitmap_index = 2132, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(g)*/
    {.bitmap_index = 2168, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(h)*/
    {.bitmap_index = 2204, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(i)*/
    {.bitmap_index = 2240, .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(j)*/
    {.bitmap_index = 2288, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(k)*/
    {.bitmap_index = 2324, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 3 },/*(l)*/
    {.bitmap_index = 2360, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(m)*/
    {.bitmap_index = 2384, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(n)*/
    {.bitmap_index = 2408, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(o)*/
    {.bitmap_index = 2432, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(p)*/
    {.bitmap_index = 2468, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(q)*/
    {.bitmap_index = 2504, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(r)*/
    {.bitmap_index = 2528, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(s)*/
    {.bitmap_index = 2552, .height = 8, .width = 8, .ofs_x = 0, .ofs_y = 4 },/*(t)*/
    {.bitmap_index = 2584, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(u)*/
    {.bitmap_index = 2608, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(v)*/
    {.bitmap_index = 2632, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(w)*/
    {.bitmap_index = 2656, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(x)*/
    {.bitmap_index = 2680, .height = 9, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(y)*/
    {.bitmap_index = 2716, .height = 6, .width = 8, .ofs_x = 0, .ofs_y = 6 },/*(z)*/
    {.bitmap_index = 2740, .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*({)*/
    {.bitmap_index = 2788, .height = 13,.width = 8, .ofs_x = 0, .ofs_y = 2 },/*(|)*/
    {.bitmap_index = 2840, .height = 12,.width = 8, .ofs_x = 0, .ofs_y = 3 },/*(})*/
    {.bitmap_index = 2888, .height = 3, .width = 8, .ofs_x = 0, .ofs_y = 7 },/*(~)*/
    {.bitmap_index = 2900, .height = 0, .width = 8, .ofs_x = 0, .ofs_y = 15 },/*()*/
};

sgl_font_t consolas15 = { .bitmap = sgl_ascii_consolas15_bitmap, .table = sgl_ascii_consolas15_tab, .font_height = 15, .bpp = 4};

#endif