/* source/sgl_conf_template.h
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


//是否开启DEBUG模式：TODO
#define SGL_CONFIG_DEBUG                      0

//开启动画：TODO
#define SGL_CONFIG_POWERON_ANIM               0

//配置字体抗锯齿深度，默认采用4bit抗锯齿
#define SGL_CONFIG_FONT_PIXEL_BIT             4

//显示屏面板的像素颜色深度，默认为32bit
#define SGL_CONFIG_PANEL_PIXEL_DEPTH          32

//FrameBuffer是否是内存映射方式
#define SGL_CONFIG_FRAMEBUFFER_MMAP           1

//默认page背景颜色
#define SGL_CONFIG_PAGE_COLOR                 SGL_WHITE

//RGB颜色交换
#define SGL_CONFIG_COLOR16_SWAP               0

//1: 开平方函数使用newton
//2: 开平方函数使用fast
#define SGL_CONFIG_SQRT_ALGO                  2

//1: standard混色
//2: fast混色
#define SGL_CONFIG_MIXER_TYPE                 2

//定义事件的队列深度
#define SGL_CONFIG_EVQUEUE_DEPTH              16

//定义任务的队列深度
#define SGL_CONFIG_TASKQUEUE_DEPTH            8

//是否开启SGL字体
#define SGL_CONFIG_FONT_CONSOLAS12            1
#define SGL_CONFIG_FONT_CONSOLAS15            1
#define SGL_CONFIG_FONT_SONG10                1
#define SGL_CONFIG_FONT_SONG23                1
#define SGL_CONFIG_FONT_CASCADIA_MONO         1
