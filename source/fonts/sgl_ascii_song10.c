/* source/fonts/sgl_song10.c
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

_const uint8_t sgl_ascii_song10_bitmap[] = {
/*   */

/* ! */
0x05,0xa5,0x00,  //.+%+.
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x00,0x60,0x00,  //..+..
0x00,0x60,0x00,  //..+..
0x00,0x00,0x00,  //.....
0x05,0xa5,0x00,  //.+%+.


/* " */
0x0c,0xec,0x80,  //.%@%+
0x8a,0xc8,0x00,  //+%%+.


/* # */
0x05,0x35,0x50,  //.+.++
0x05,0x35,0x50,  //.+.++
0xef,0xff,0xe0,  //@@@@@
0x38,0x08,0x30,  //.+.+.
0xef,0xff,0xe0,  //@@@@@
0x58,0x35,0x00,  //++.+.
0x55,0x35,0x00,  //++.+.


/* $ */
0x00,0x83,0x00,  //..+..
0x0e,0xfe,0x30,  //.@@@.
0x8a,0x8c,0x80,  //+%+%+
0x3a,0xa3,0x00,  //.%%..
0x05,0xec,0x00,  //.+@%.
0x00,0x88,0x50,  //..+++
0xac,0x8a,0x80,  //%%+%+
0x5e,0xfe,0x00,  //+@@@.
0x00,0x83,0x00,  //..+..


/* % */
0xce,0x55,0x30,  //%@++.
0x88,0x88,0x00,  //++++.
0x88,0x85,0x00,  //++++.
0xce,0xce,0xc0,  //%@%@%
0x05,0x88,0x80,  //.++++
0x05,0x88,0x80,  //.++++
0x35,0x5e,0xc0,  //.++@%


/* & */
0x3e,0xe3,0x00,  //.@@..
0x88,0x85,0x00,  //++++.
0x5a,0xa0,0x00,  //+%%..
0x8c,0x8e,0xa0,  //+%+@%
0x88,0x86,0x00,  //++++.
0xa5,0xea,0x00,  //%+@%.
0xaf,0xee,0xe0,  //%@@@@


/* ' */
0xae,0x30,0x00,  //%@...
0x08,0x30,0x00,  //.+...
0xaa,0x00,0x00,  //%%...


/* ( */
0x00,0x0a,0xa0,  //...%%
0x00,0x5a,0x00,  //..+%.
0x00,0x85,0x00,  //..++.
0x00,0x83,0x00,  //..+..
0x03,0x80,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x85,0x00,  //..++.
0x00,0x5a,0x00,  //..+%.
0x00,0x0a,0xa0,  //...%%


/* ) */
0xaa,0x00,0x00,  //%%...
0x0a,0x50,0x00,  //.%+..
0x05,0x80,0x00,  //.++..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x05,0x80,0x00,  //.++..
0x08,0x50,0x00,  //.++..
0xac,0x00,0x00,  //%%...


/* * */
0x03,0xa5,0x00,  //..%+.
0xee,0x8c,0xe0,  //@@+%@
0x08,0xec,0x00,  //.+@%.
0xee,0x8c,0xe0,  //@@+%@
0x03,0xa5,0x00,  //..%+.


/* + */
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0xcf,0xff,0xe0,  //%@@@@
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..


/* , */
0xae,0x30,0x00,  //%@...
0x08,0x30,0x00,  //.+...


/* - */
0xef,0xff,0xe0,  //@@@@@


/* . */
0xae,0x30,0x00,  //%@...


/* / */
0x00,0x08,0xa0,  //...+%
0x00,0x08,0x50,  //...++
0x00,0x5a,0x00,  //..+%.
0x00,0x88,0x00,  //..++.
0x03,0x83,0x00,  //..+..
0x08,0x80,0x00,  //.++..
0x0a,0x50,0x00,  //.%+..
0x58,0x00,0x00,  //++...
0xa8,0x00,0x00,  //%+...


/* 0 */
0x0e,0xfe,0x00,  //.@@@.
0x8c,0x0c,0x80,  //+%.%+
0xca,0x0a,0xc0,  //%%.%%
0xca,0x0a,0xc0,  //%%.%%
0xca,0x0a,0xc0,  //%%.%%
0x8c,0x0c,0x80,  //+%.%+
0x0e,0xfe,0x00,  //.@@@.


/* 1 */
0x00,0x53,0x00,  //..+..
0x3e,0xe3,0x00,  //.@@..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x3e,0xfe,0x50,  //.@@@+


/* 2 */
0x5e,0xfe,0x30,  //+@@@.
0xaa,0x0c,0xa0,  //%%.%%
0x00,0x08,0x80,  //...++
0x00,0xae,0x00,  //..%@.
0x0a,0xe0,0x00,  //.%@..
0x8c,0x05,0x50,  //+%.++
0xcf,0xfe,0x80,  //%@@@+


/* 3 */
0x3e,0xfe,0x00,  //.@@@.
0x8a,0x0c,0x80,  //+%.%+
0x00,0x08,0x30,  //...+.
0x05,0xec,0x00,  //.+@%.
0x00,0x0c,0xa0,  //...%%
0xaa,0x0c,0xa0,  //%%.%%
0x5e,0xfe,0x30,  //+@@@.


/* 4 */
0x00,0x8a,0x00,  //..+%.
0x03,0xec,0x00,  //..@%.
0x0e,0xc8,0x00,  //.@%+.
0xaa,0x58,0x00,  //%%++.
0xef,0xff,0xe0,  //@@@@@
0x00,0x58,0x00,  //..++.
0x05,0xef,0xc0,  //.+@@%


/* 5 */
0x5e,0xfe,0x80,  //+@@@+
0x55,0x00,0x00,  //++...
0x3c,0xfe,0x30,  //.%@@.
0x8a,0x0c,0xa0,  //+%.%%
0x00,0x0a,0xa0,  //...%%
0xaa,0x0a,0x80,  //%%.%+
0x5e,0xfe,0x00,  //+@@@.


/* 6 */
0x0c,0xfe,0x80,  //.%@@+
0x8c,0x00,0x00,  //+%...
0xaa,0xfe,0x50,  //%%@@+
0xce,0x0a,0xa0,  //%@.%%
0xca,0x08,0xa0,  //%%.+%
0xae,0x0a,0xa0,  //%@.%%
0x0e,0xfe,0x30,  //.@@@.


/* 7 */
0x8e,0xff,0xa0,  //+@@@%
0x55,0x05,0x30,  //++.+.
0x00,0x58,0x00,  //..++.
0x00,0x85,0x00,  //..++.
0x03,0x80,0x00,  //..+..
0x08,0xc0,0x00,  //.+%..
0x08,0xc0,0x00,  //.+%..


/* 8 */
0x3e,0xfe,0x30,  //.@@@.
0xaa,0x0a,0xa0,  //%%.%%
0x8a,0x0a,0x80,  //+%.%+
0x3e,0xfc,0x00,  //.@@%.
0xa8,0x0c,0xa0,  //%+.%%
0xa8,0x0a,0xc0,  //%+.%%
0x5e,0xfe,0x30,  //+@@@.


/* 9 */
0x3e,0xfe,0x00,  //.@@@.
0xca,0x0c,0x80,  //%%.%+
0x85,0x0a,0xa0,  //++.%%
0xca,0x3e,0xc0,  //%%.@%
0x5e,0xec,0xa0,  //+@@%%
0x00,0x3a,0x50,  //...%+
0x8e,0xfa,0x00,  //+@@%.


/* : */
0x08,0xc5,0x00,  //.+%+.
0x00,0x00,0x00,  //.....
0x00,0x00,0x00,  //.....
0x00,0x00,0x00,  //.....
0x08,0xc5,0x00,  //.+%+.


/* ; */
0x05,0xa5,0x00,  //.+%+.
0x00,0x00,0x00,  //.....
0x00,0x00,0x00,  //.....
0x05,0xa5,0x00,  //.+%+.
0x03,0x80,0x00,  //..+..


/* < */
0x00,0x0c,0x80,  //...%+
0x00,0xea,0x00,  //..@%.
0x0e,0xa0,0x00,  //.@%..
0xaa,0x00,0x00,  //%%...
0x0e,0xa0,0x00,  //.@%..
0x00,0xea,0x00,  //..@%.
0x00,0x0c,0x80,  //...%+


/* = */
0xef,0xff,0xe0,  //@@@@@
0x00,0x00,0x00,  //.....
0xef,0xff,0xe0,  //@@@@@


/* > */
0x8c,0x00,0x00,  //+%...
0x0a,0xe0,0x00,  //.%@..
0x00,0xae,0x00,  //..%@.
0x00,0x0a,0xa0,  //...%%
0x00,0xae,0x00,  //..%@.
0x0a,0xe0,0x00,  //.%@..
0x8c,0x00,0x00,  //+%...


/* ? */
0x3e,0xfe,0x50,  //.@@@+
0x88,0x0a,0xc0,  //++.%%
0xcc,0x0a,0xa0,  //%%.%%
0x00,0xae,0x00,  //..%@.
0x03,0x83,0x00,  //..+..
0x00,0x00,0x00,  //.....
0x08,0xc5,0x00,  //.+%+.


/* @ */
0x0c,0xfe,0x50,  //.%@@+
0x8a,0xee,0xa0,  //+%@@%
0x88,0xa6,0x80,  //++%++
0xa8,0x68,0x80,  //%++++
0x88,0x88,0xa0,  //++++%
0xac,0xec,0x80,  //%%@%+
0x0e,0xff,0xc0,  //.@@@%


/* A */
0x05,0xa3,0x00,  //.+%..
0x08,0xa8,0x00,  //.+%+.
0x05,0x88,0x00,  //.+++.
0x38,0x5a,0x00,  //.++%.
0x5e,0xfe,0x50,  //+@@@+
0x55,0x0a,0x80,  //++.%+
0xec,0x3e,0xe0,  //@%.@@


/* B */
0xef,0xfe,0x30,  //@@@@.
0x8a,0x0a,0x80,  //+%.%+
0x8a,0x08,0x50,  //+%.++
0x8e,0xfc,0x00,  //+@@%.
0x8a,0x0c,0xa0,  //+%.%%
0x8a,0x0a,0xc0,  //+%.%%
0xef,0xfe,0x50,  //@@@@+


/* C */
0x0e,0xfe,0x80,  //.@@@+
0xae,0x0a,0xa0,  //%@.%%
0xc8,0x03,0x50,  //%+..+
0xa5,0x00,0x00,  //%+...
0xc8,0x00,0x00,  //%+...
0xac,0x08,0x80,  //%%.++
0x3e,0xfe,0x30,  //.@@@.


/* D */
0xef,0xfc,0x00,  //@@@%.
0x8a,0x3c,0x80,  //+%.%+
0x8a,0x0a,0xc0,  //+%.%%
0x8a,0x0a,0xc0,  //+%.%%
0x8a,0x0a,0xc0,  //+%.%%
0x8a,0x3c,0x80,  //+%.%+
0xef,0xfc,0x00,  //@@@%.


/* E */
0xef,0xfe,0x50,  //@@@@+
0x8a,0x08,0x80,  //+%.++
0x8a,0x58,0x00,  //+%++.
0x8e,0xfc,0x00,  //+@@%.
0x8a,0x58,0x00,  //+%++.
0x8a,0x05,0x50,  //+%.++
0xef,0xfe,0x80,  //@@@@+


/* F */
0xef,0xfe,0x80,  //@@@@+
0x8a,0x05,0x50,  //+%.++
0x8a,0x58,0x00,  //+%++.
0x8e,0xfc,0x00,  //+@@%.
0x8a,0x58,0x00,  //+%++.
0x8a,0x00,0x00,  //+%...
0xee,0x80,0x00,  //@@+..


/* G */
0x0e,0xfe,0x50,  //.@@@+
0xae,0x0a,0x80,  //%@.%+
0xc8,0x05,0x50,  //%+.++
0xa5,0x00,0x00,  //%+...
0xc8,0x8e,0xe0,  //%++@@
0xac,0x0a,0x80,  //%%.%+
0x0e,0xfe,0x80,  //.@@@+


/* H */
0xee,0x3e,0xe0,  //@@.@@
0xaa,0x0a,0xa0,  //%%.%%
0xaa,0x0a,0xa0,  //%%.%%
0xaf,0xff,0xa0,  //%@@@%
0xaa,0x0a,0xa0,  //%%.%%
0xaa,0x0a,0xa0,  //%%.%%
0xee,0x5e,0xe0,  //@@+@@


/* I */
0x5e,0xfe,0x50,  //+@@@+
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x5e,0xfe,0x50,  //+@@@+


/* J */
0x0c,0xff,0xe0,  //.%@@@
0x00,0x8a,0x00,  //..+%.
0x00,0x8a,0x00,  //..+%.
0x00,0x8a,0x00,  //..+%.
0x00,0x8a,0x00,  //..+%.
0x00,0x8a,0x00,  //..+%.
0x00,0xac,0x00,  //..%%.
0xef,0xe5,0x00,  //@@@+.


/* K */
0xee,0xcf,0xa0,  //@@%@%
0x8a,0xea,0x00,  //+%@%.
0x8e,0xa0,0x00,  //+@%..
0x8c,0xc3,0x00,  //+%%..
0x8a,0xca,0x00,  //+%%%.
0x8a,0x8c,0x30,  //+%+%.
0xee,0xcf,0xc0,  //@@%@%


/* L */
0xee,0x80,0x00,  //@@+..
0x58,0x00,0x00,  //++...
0x58,0x00,0x00,  //++...
0x58,0x00,0x00,  //++...
0x58,0x00,0x00,  //++...
0x58,0x05,0x80,  //++.++
0xef,0xff,0xa0,  //@@@@%


/* M */
0xec,0x0c,0xe0,  //@%.%@
0xae,0x3e,0xa0,  //%@.@%
0xae,0x6e,0xa0,  //%@+@%
0x8c,0x8c,0xa0,  //+%+%%
0x8a,0xca,0xa0,  //+%%%%
0x88,0xca,0xa0,  //++%%%
0xec,0x8e,0xe0,  //@%+@@


/* N */
0xee,0x5e,0xe0,  //@@+@@
0xae,0x8a,0xa0,  //%@+%%
0xaa,0xea,0xa0,  //%%@%%
0xaa,0xca,0xa0,  //%%%%%
0xaa,0xac,0xa0,  //%%%%%
0xaa,0x5e,0xa0,  //%%+@%
0xee,0x3c,0xa0,  //@@.%%


/* O */
0x0e,0xfc,0x00,  //.@@%.
0xac,0x0c,0x80,  //%%.%+
0xa8,0x0a,0xc0,  //%+.%%
0xc8,0x0a,0xc0,  //%+.%%
0xa8,0x0a,0xc0,  //%+.%%
0xac,0x0c,0x80,  //%%.%+
0x0e,0xfc,0x00,  //.@@%.


/* P */
0xef,0xfe,0x50,  //@@@@+
0x8a,0x08,0xa0,  //+%.+%
0x8a,0x0a,0xc0,  //+%.%%
0x8e,0xfe,0x50,  //+@@@+
0x8a,0x00,0x00,  //+%...
0x8a,0x00,0x00,  //+%...
0xee,0x80,0x00,  //@@+..


/* Q */
0x3e,0xfc,0x00,  //.@@%.
0xac,0x0c,0x80,  //%%.%+
0xc8,0x0a,0xc0,  //%+.%%
0xa5,0x0a,0xc0,  //%+.%%
0xa5,0x0a,0xc0,  //%+.%%
0x8c,0xea,0x80,  //+%@%+
0x3e,0xfe,0x00,  //.@@@.
0x00,0x5c,0x80,  //..+%+


/* R */
0xef,0xfe,0x30,  //@@@@.
0x58,0x0c,0xa0,  //++.%%
0x58,0x0a,0x80,  //++.%+
0x5e,0xfe,0x00,  //+@@@.
0x58,0xaa,0x00,  //++%%.
0x58,0x5a,0x50,  //+++%+
0xee,0x8c,0xe0,  //@@+%@


/* S */
0x5e,0xfe,0x50,  //+@@@+
0x85,0x08,0x80,  //++.++
0xae,0x30,0x00,  //%@...
0x0a,0xfe,0x00,  //.%@@.
0x53,0x0c,0xa0,  //+..%%
0xaa,0x08,0x80,  //%%.++
0xaf,0xfe,0x30,  //%@@@.


/* T */
0xcf,0xff,0xc0,  //%@@@%
0x83,0x83,0x80,  //+.+.+
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x0c,0xfc,0x00,  //.%@%.


/* U */
0xee,0x3e,0xe0,  //@@.@@
0xaa,0x08,0x80,  //%%.++
0xaa,0x08,0x80,  //%%.++
0xaa,0x08,0x80,  //%%.++
0xaa,0x08,0x80,  //%%.++
0xaa,0x0a,0x80,  //%%.%+
0x5e,0xfe,0x30,  //+@@@.


/* V */
0xee,0x3e,0xe0,  //@@.@@
0x8a,0x05,0x50,  //+%.++
0x5a,0x05,0x30,  //+%.+.
0x0a,0x55,0x00,  //.%++.
0x0a,0xa5,0x00,  //.%%+.
0x08,0xc5,0x00,  //.+%+.
0x03,0x80,0x00,  //..+..


/* W */
0xec,0xca,0xe0,  //@%%%@
0x85,0x83,0x50,  //+++.+
0x88,0xa5,0x30,  //++%+.
0x88,0x88,0x30,  //++++.
0x58,0x88,0x30,  //++++.
0x3a,0x6a,0x00,  //.%+%.
0x06,0x35,0x00,  //.+.+.


/* X */
0xce,0x6e,0xa0,  //%@+@%
0x38,0x38,0x00,  //.+.+.
0x08,0x88,0x00,  //.+++.
0x05,0xa0,0x00,  //.+%..
0x08,0x88,0x00,  //.+++.
0x35,0x38,0x30,  //.+.+.
0xee,0x8e,0xc0,  //@@+@%


/* Y */
0xee,0x5e,0xe0,  //@@+@@
0x8a,0x05,0x50,  //+%.++
0x0c,0x88,0x00,  //.%++.
0x08,0xc8,0x00,  //.+%+.
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x0c,0xfc,0x00,  //.%@%.


/* Z */
0x8e,0xff,0xa0,  //+@@@%
0x88,0x06,0x00,  //++.+.
0x00,0xaa,0x00,  //..%%.
0x03,0x80,0x00,  //..+..
0x08,0x80,0x00,  //.++..
0x38,0x05,0x50,  //.+.++
0xcf,0xfe,0x80,  //%@@@+


/* [ */
0x05,0xef,0xa0,  //.+@@%
0x05,0x50,0x00,  //.++..
0x05,0x50,0x00,  //.++..
0x05,0x50,0x00,  //.++..
0x05,0x50,0x00,  //.++..
0x05,0x50,0x00,  //.++..
0x05,0x50,0x00,  //.++..
0x05,0x50,0x00,  //.++..
0x05,0xef,0xa0,  //.+@@%


/* \ */
0x58,0x00,0x00,  //++...
0x08,0x30,0x00,  //.+...
0x08,0x80,0x00,  //.++..
0x03,0x80,0x00,  //..+..
0x00,0x88,0x00,  //..++.
0x00,0x58,0x00,  //..++.
0x00,0x08,0x50,  //...++
0x00,0x08,0x80,  //...++


/* ] */
0xaf,0xe5,0x00,  //%@@+.
0x00,0x55,0x00,  //..++.
0x00,0x55,0x00,  //..++.
0x00,0x55,0x00,  //..++.
0x00,0x55,0x00,  //..++.
0x00,0x55,0x00,  //..++.
0x00,0x55,0x00,  //..++.
0x00,0x55,0x00,  //..++.
0xaf,0xe5,0x00,  //%@@+.


/* ^ */
0x08,0xc8,0x00,  //.+%+.
0x0a,0x6a,0x00,  //.%+%.


/* _ */
0xef,0xff,0xe0,  //@@@@@


/* ` */
0x5c,0x80,0x00,  //+%+..
0x03,0x80,0x00,  //..+..


/* a */
0x3e,0xfe,0x30,  //.@@@.
0xaa,0x08,0x50,  //%%.++
0x5e,0xfe,0x50,  //+@@@+
0xa8,0x3a,0x50,  //%+.%+
0xaf,0xec,0xe0,  //%@@%@


/* b */
0xea,0x00,0x00,  //@%...
0x88,0x00,0x00,  //++...
0x88,0xee,0x50,  //++@@+
0x8c,0x3a,0xa0,  //+%.%%
0x88,0x08,0xa0,  //++.+%
0x8a,0x0a,0xa0,  //+%.%%
0x5c,0xfe,0x30,  //+%@@.


/* c */
0x0e,0xfe,0x30,  //.@@@.
0x8c,0x0a,0x80,  //+%.%+
0xaa,0x00,0x00,  //%%...
0xac,0x08,0x80,  //%%.++
0x0e,0xfe,0x30,  //.@@@.


/* d */
0x00,0x8c,0x80,  //..+%+
0x00,0x0a,0x80,  //...%+
0x0e,0xfc,0x80,  //.@@%+
0x8a,0x0c,0x80,  //+%.%+
0xaa,0x0a,0x80,  //%%.%+
0xac,0x0c,0x80,  //%%.%+
0x3e,0xfc,0xe0,  //.@@%@


/* e */
0x0e,0xfe,0x00,  //.@@@.
0x88,0x0a,0xa0,  //++.%%
0xaf,0xff,0xc0,  //%@@@%
0xaa,0x03,0x30,  //%%...
0x0e,0xfe,0x50,  //.@@@+


/* f */
0x05,0xef,0xc0,  //.+@@%
0x0a,0xa0,0x00,  //.%%..
0xcf,0xfe,0x30,  //%@@@.
0x0a,0xa0,0x00,  //.%%..
0x0a,0xa0,0x00,  //.%%..
0x0a,0xa0,0x00,  //.%%..
0xaf,0xfe,0x00,  //%@@@.


/* g */
0x5e,0xff,0xe0,  //+@@@@
0x5e,0xfe,0x30,  //+@@@.
0x55,0x00,0x00,  //++...
0x5e,0xfe,0x30,  //+@@@.
0x55,0x08,0xa0,  //++.+%
0x8e,0xfe,0x80,  //+@@@+


/* h */
0xec,0x00,0x00,  //@%...
0x8a,0x00,0x00,  //+%...
0x8a,0xee,0x50,  //+%@@+
0x8c,0x3a,0x80,  //+%.%+
0x8a,0x0a,0x80,  //+%.%+
0x8a,0x0a,0x80,  //+%.%+
0xee,0x6e,0xe0,  //@@+@@


/* i */
0x05,0xc8,0x00,  //.+%+.
0x00,0x00,0x00,  //.....
0x5e,0xe3,0x00,  //+@@..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x5e,0xfe,0x50,  //+@@@+


/* j */
0x00,0x5a,0x50,  //..+%+
0x00,0x00,0x00,  //.....
0x03,0xee,0x30,  //..@@.
0x00,0x08,0x30,  //...+.
0x00,0x08,0x30,  //...+.
0x00,0x08,0x30,  //...+.
0x00,0x38,0x30,  //...+.
0x8e,0xfa,0x00,  //+@@%.


/* k */
0xec,0x00,0x00,  //@%...
0x58,0x00,0x00,  //++...
0x58,0xae,0x80,  //++%@+
0x58,0x88,0x00,  //++++.
0x5e,0xe5,0x00,  //+@@+.
0x58,0x5a,0x00,  //+++%.
0xee,0x6e,0xc0,  //@@+@%


/* l */
0x5e,0xe3,0x00,  //+@@..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x03,0x83,0x00,  //..+..
0x5e,0xfe,0x50,  //+@@@+


/* m */
0xae,0xee,0xc0,  //%@@@%
0xca,0xa6,0x80,  //%%%++
0x85,0x85,0x80,  //+++++
0x85,0x85,0x80,  //+++++
0xec,0xca,0xe0,  //@%%%@


/* n */
0xec,0xee,0x50,  //@%@@+
0x8c,0x3a,0x80,  //+%.%+
0x8a,0x0a,0x80,  //+%.%+
0x8a,0x0a,0x80,  //+%.%+
0xee,0x6e,0xe0,  //@@+@@


/* o */
0x0e,0xfe,0x00,  //.@@@.
0xac,0x0c,0xa0,  //%%.%%
0xa8,0x08,0xa0,  //%+.+%
0xaa,0x0a,0xa0,  //%%.%%
0x0e,0xfe,0x00,  //.@@@.


/* p */
0xec,0xee,0x30,  //@%@@.
0x8c,0x3a,0xa0,  //+%.%%
0x8a,0x08,0xa0,  //+%.+%
0x8c,0x0a,0xa0,  //+%.%%
0x8c,0xfe,0x30,  //+%@@.
0xee,0x80,0x00,  //@@+..


/* q */
0x3e,0xfa,0x50,  //.@@%+
0xaa,0x0c,0x80,  //%%.%+
0xa8,0x0a,0x80,  //%+.%+
0xaa,0x0c,0x80,  //%%.%+
0x3e,0xfc,0x80,  //.@@%+
0x00,0x8e,0xe0,  //..+@@


/* r */
0xee,0xaf,0xc0,  //@@%@%
0x0c,0xe0,0x00,  //.%@..
0x08,0x50,0x00,  //.++..
0x08,0x50,0x00,  //.++..
0xef,0xe8,0x00,  //@@@+.


/* s */
0x0e,0xfe,0x50,  //.@@@+
0x58,0x00,0x00,  //++...
0x0c,0xfe,0x00,  //.%@@.
0x00,0x08,0x80,  //...++
0x8e,0xfe,0x50,  //+@@@+


/* t */
0x03,0x30,0x00,  //.....
0x08,0x80,0x00,  //.++..
0xaf,0xfe,0x50,  //%@@@+
0x08,0x80,0x00,  //.++..
0x08,0x80,0x00,  //.++..
0x08,0x83,0x30,  //.++..
0x05,0xee,0x50,  //.+@@+


/* u */
0xea,0x5c,0x80,  //@%+%+
0x88,0x0a,0x80,  //++.%+
0x88,0x0a,0x80,  //++.%+
0x8a,0x0c,0x80,  //+%.%+
0x5e,0xfc,0xe0,  //+@@%@


/* v */
0xee,0x5e,0xc0,  //@@+@%
0x5a,0x05,0x30,  //+%.+.
0x0e,0xaa,0x00,  //.@%%.
0x08,0xc8,0x00,  //.+%+.
0x03,0x80,0x00,  //..+..


/* w */
0xec,0xca,0xe0,  //@%%%@
0x88,0x85,0x50,  //+++++
0x8a,0xee,0x50,  //+%@@+
0x3e,0xcc,0x30,  //.@%%.
0x0a,0x68,0x00,  //.%++.


/* x */
0xaf,0xae,0xa0,  //%@%@%
0x0a,0x8a,0x00,  //.%+%.
0x05,0xa5,0x00,  //.+%+.
0x0a,0x6a,0x00,  //.%+%.
0xee,0x8e,0xc0,  //@@+@%


/* y */
0xce,0x6e,0xe0,  //%@+@@
0x05,0x35,0x30,  //.+.+.
0x05,0x68,0x00,  //.+++.
0x03,0x85,0x00,  //..++.
0x03,0x80,0x00,  //..+..
0xae,0x80,0x00,  //%@+..


/* z */
0x8e,0xfe,0x50,  //+@@@+
0x55,0x8c,0x00,  //+++%.
0x05,0xa3,0x00,  //.+%..
0x3a,0x55,0x50,  //.%+++
0xaf,0xfe,0x80,  //%@@@+


/* { */
0x00,0x3e,0xc0,  //...@%
0x00,0x58,0x00,  //..++.
0x00,0x58,0x00,  //..++.
0x00,0x58,0x00,  //..++.
0x03,0xa5,0x00,  //..%+.
0x00,0x58,0x00,  //..++.
0x00,0x58,0x00,  //..++.
0x00,0x58,0x00,  //..++.
0x00,0x3e,0xc0,  //...@%


/* | */
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..
0x00,0x83,0x00,  //..+..


/* } */
0xae,0x30,0x00,  //%@...
0x08,0x50,0x00,  //.++..
0x08,0x50,0x00,  //.++..
0x0a,0x80,0x00,  //.%+..
0x08,0xc5,0x00,  //.+%+.
0x0a,0x80,0x00,  //.%+..
0x08,0x50,0x00,  //.++..
0x08,0x50,0x00,  //.++..
0xae,0x30,0x00,  //%@...


/* ~ */
0xcf,0xe0,0x00,  //%@@..
0x00,0xef,0xc0,  //..@@%


/*  */

};


_const sgl_font_table_t sgl_ascii_song10_tab[] = {
    {.bitmap_index = 0,	   .height = 0,  .width = 6, .ofs_x = 0, .ofs_y = 10 },/*( )*/
    {.bitmap_index = 0,	   .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(!)*/
    {.bitmap_index = 21,   .height = 2,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(")*/
    {.bitmap_index = 27,   .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(#)*/
    {.bitmap_index = 48,   .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*($)*/
    {.bitmap_index = 75,   .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(%)*/
    {.bitmap_index = 96,   .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(&)*/
    {.bitmap_index = 117,  .height = 3,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(')*/
    {.bitmap_index = 126,  .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(()*/
    {.bitmap_index = 153,  .height = 8,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*())*/
    {.bitmap_index = 177,  .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 3 },/*(*)*/
    {.bitmap_index = 192,  .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 3 },/*(+)*/
    {.bitmap_index = 207,  .height = 2,  .width = 6, .ofs_x = 0, .ofs_y = 8 },/*(,)*/
    {.bitmap_index = 213,  .height = 1,  .width = 6, .ofs_x = 0, .ofs_y = 5 },/*(-)*/
    {.bitmap_index = 216,  .height = 1,  .width = 6, .ofs_x = 0, .ofs_y = 8 },/*(.)*/
    {.bitmap_index = 219,  .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(/)*/
    {.bitmap_index = 246,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(0)*/
    {.bitmap_index = 267,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(1)*/
    {.bitmap_index = 288,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(2)*/
    {.bitmap_index = 309,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(3)*/
    {.bitmap_index = 330,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(4)*/
    {.bitmap_index = 351,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(5)*/
    {.bitmap_index = 372,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(6)*/
    {.bitmap_index = 393,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(7)*/
    {.bitmap_index = 414,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(8)*/
    {.bitmap_index = 435,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(9)*/
    {.bitmap_index = 456,  .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(:)*/
    {.bitmap_index = 471,  .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 5 },/*(;)*/
    {.bitmap_index = 486,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(<)*/
    {.bitmap_index = 507,  .height = 3,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(=)*/
    {.bitmap_index = 516,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(>)*/
    {.bitmap_index = 537,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(?)*/
    {.bitmap_index = 558,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(@)*/
    {.bitmap_index = 579,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(A)*/
    {.bitmap_index = 600,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(B)*/
    {.bitmap_index = 621,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(C)*/
    {.bitmap_index = 642,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(D)*/
    {.bitmap_index = 663,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(E)*/
    {.bitmap_index = 684,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(F)*/
    {.bitmap_index = 705,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(G)*/
    {.bitmap_index = 726,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(H)*/
    {.bitmap_index = 747,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(I)*/
    {.bitmap_index = 768,  .height = 8,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(J)*/
    {.bitmap_index = 792,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(K)*/
    {.bitmap_index = 813,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(L)*/
    {.bitmap_index = 834,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(M)*/
    {.bitmap_index = 855,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(N)*/
    {.bitmap_index = 876,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(O)*/
    {.bitmap_index = 897,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(P)*/
    {.bitmap_index = 918,  .height = 8,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(Q)*/
    {.bitmap_index = 942,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(R)*/
    {.bitmap_index = 963,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(S)*/
    {.bitmap_index = 984,  .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(T)*/
    {.bitmap_index = 1005, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(U)*/
    {.bitmap_index = 1026, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(V)*/
    {.bitmap_index = 1047, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(W)*/
    {.bitmap_index = 1068, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(X)*/
    {.bitmap_index = 1089, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(Y)*/
    {.bitmap_index = 1110, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(Z)*/
    {.bitmap_index = 1131, .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*([)*/
    {.bitmap_index = 1158, .height = 8,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(\)*/
    {.bitmap_index = 1182, .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(])*/
    {.bitmap_index = 1209, .height = 2,  .width = 6, .ofs_x = 0, .ofs_y = 0 },/*(^)*/
    {.bitmap_index = 1215, .height = 1,  .width = 6, .ofs_x = 0, .ofs_y = 9 },/*(_)*/
    {.bitmap_index = 1218, .height = 2,  .width = 6, .ofs_x = 0, .ofs_y = 0 },/*(`)*/
    {.bitmap_index = 1224, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(a)*/
    {.bitmap_index = 1239, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(b)*/
    {.bitmap_index = 1260, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(c)*/
    {.bitmap_index = 1275, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(d)*/
    {.bitmap_index = 1296, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(e)*/
    {.bitmap_index = 1311, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(f)*/
    {.bitmap_index = 1332, .height = 6,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(g)*/
    {.bitmap_index = 1350, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(h)*/
    {.bitmap_index = 1371, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(i)*/
    {.bitmap_index = 1392, .height = 8,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(j)*/
    {.bitmap_index = 1416, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(k)*/
    {.bitmap_index = 1437, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(l)*/
    {.bitmap_index = 1458, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(m)*/
    {.bitmap_index = 1473, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(n)*/
    {.bitmap_index = 1488, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(o)*/
    {.bitmap_index = 1503, .height = 6,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(p)*/
    {.bitmap_index = 1521, .height = 6,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(q)*/
    {.bitmap_index = 1539, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(r)*/
    {.bitmap_index = 1554, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(s)*/
    {.bitmap_index = 1569, .height = 7,  .width = 6, .ofs_x = 0, .ofs_y = 2 },/*(t)*/
    {.bitmap_index = 1590, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(u)*/
    {.bitmap_index = 1605, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(v)*/
    {.bitmap_index = 1620, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(w)*/
    {.bitmap_index = 1635, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(x)*/
    {.bitmap_index = 1650, .height = 6,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(y)*/
    {.bitmap_index = 1668, .height = 5,  .width = 6, .ofs_x = 0, .ofs_y = 4 },/*(z)*/
    {.bitmap_index = 1683, .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*({)*/
    {.bitmap_index = 1710, .height = 10, .width = 6, .ofs_x = 0, .ofs_y = 0 },/*(|)*/
    {.bitmap_index = 1740, .height = 9,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(})*/
    {.bitmap_index = 1767, .height = 2,  .width = 6, .ofs_x = 0, .ofs_y = 1 },/*(~)*/
    {.bitmap_index = 1773, .height = 0,  .width = 6, .ofs_x = 0, .ofs_y = 10 },/*()*/
};

sgl_font_t song10 = { .bitmap = sgl_ascii_song10_bitmap, .table = sgl_ascii_song10_tab, .font_height = 10, .bpp = 4};
