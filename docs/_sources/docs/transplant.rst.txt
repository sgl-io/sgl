SGL使用指南
============================================

说明
--------------------------------------------
SGL的移植非常简单，用户只需要关注两个文件，sgl_conf.h和sgl.h文件。sgl_conf.h为SGL的配置文件，该文件中的所有宏用于配置SGL开启哪些功能或者选择哪种算法策略，sgl.h文件是用户必须包含的头文件。
对于GUI移植的用户来说，最关心的莫过于如何使用SGL，由于SGL支持多个平台，因此移植上会有微小差别，下面我们主要对MCU，Linux framebuffer和window平台来说明如何一步一步去使用SGL。
SGL和硬件相关的有两个结构体，分别是struct sgl_device_panel和struct sgl_device_panel这两个结构体。
struct sgl_device_panel结构体如下：


.. code-block:: c
   :linenos:

    typedef struct sgl_device_panel {
        sgl_color_t *framebuffer;
        int buffer_size;
        int16_t xres;
        int16_t yres;
        int16_t xres_virtual;
        int16_t yres_virtual;
        void (*flush_area)(int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t *src);

    }sgl_device_panel_t;

- framebuffer: 指向绘图缓存
- buffer_size: 绘图缓存的大小（字节）
- xres: 屏幕实际行分辨率
- yres: 屏幕实际列分辨率
- xres_virtual: 屏幕虚拟行分辨率
- yres_virtual: 屏幕虚拟列分辨率
- flush_area: 指向显示设备的绘制窗口函数，用于将缓存中的数据发送到屏幕上显示出来。

在移植的过程中，只需要使用sgl_device_register()函数注册sgl_device_panel_t和sgl_device_event_t设备即可，如果没有输入设备，可以将sgl_device_event_t设置为NULL即可，例如下面：

.. tip:: 
    注册显示屏和触摸设备可以这样：sgl_device_register(&tft_device_panel, &touch_device_event);
    仅仅只注册显示屏设备，则只需要sgl_device_register(&tft_device_panel, NULL);

SGL有一个void sgl_task_handler(void)需要一直或者定时轮询执行，可以放在while中也可以放在定时器的中断服务函数中。例如：

.. code-block:: c
   :linenos:

   #include "sgl.h"
   ...
   int main(void) {

        ...
        sgl_device_register(&tft_device_panel, NULL);
        sgl_init();
        ...

        while(1) {
            ...
            sgl_task_handler();
            ...
        }
   }



MCU平台
--------------------------------------------
1. 在用户目录下创建一个sgl_conf.h配置文件
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   该配置文件的内容是SGL源码目录下的sgl_conf_template.h文件的内容，然后做一些更改。

.. code-block:: bash  
  
    project
    /path/to/your/directory  
    ├── main.c      -----> 用户的main.c文件
    ├── sgl_conf.h  -----> 用户的配置文件（复制sgl_conf_template.h文件）
    └── source      -----> SGL源码
        ├── core
        ├──
        ...
        ├── widget
        ...
        ├── sgl_conf_template.h
        └── sgl.h
    
2. 更改sgl_conf.h配置文件
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   对于没有完整的显示缓存的MCU来说，配置文件一般如下，并且需要将该头文件的路径添加到项目的头文件路径中。

.. code-block:: c
   :linenos:

    #define SGL_CONFIG_DEBUG                      0
    #define SGL_CONFIG_LOG_LEVEL                  0


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

    //1: standard混色
    //2: fast混色
    #define SGL_CONFIG_MIXER_TYPE                 2

    //0: heap_0
    //1: heap_1
    //2: heap_2
    //3: heap_3
    //4: heap_4
    //5: heap_tlsf
    //6: libc
    #define SGL_CONFIG_HEAP_POLICY                5
    //定义内存池的大小，单位KByte
    #define SGL_CONFIG_HEAP_POOL_SIZE             64


    //定义事件的队列深度
    #define SGL_CONFIG_EVQUEUE_DEPTH              16

    //定义任务的队列深度
    #define SGL_CONFIG_TASKQUEUE_DEPTH            8


    //是否开启SGL字体
    #define SGL_CONFIG_FONT_CONSOLAS12            1
    #define SGL_CONFIG_FONT_CONSOLAS15            1
    #define SGL_CONFIG_FONT_SONG10                1
    #define SGL_CONFIG_FONT_SONG23                1
    #define SGL_CONFIG_FONT_CASCADIA_MONO17       1

    #define SGL_CONFIG_TEXT_UTF8                  0



对于初次使用SGL的用户可以先主要关注这两个宏：SGL_CONFIG_PANEL_PIXEL_DEPTH和SGL_CONFIG_FRAMEBUFFER_MMAP，其中SGL_CONFIG_PANEL_PIXEL_DEPTH宏用户配置显示屏的颜色深度，例如TFT显示屏
的颜色深度一般是16bit，因此对于MCU而言一般设置为16即可。SGL_CONFIG_FRAMEBUFFER_MMAP用户设置显示屏使用内存映射，只有对于Linuxfb或者windows的SDL2而言才设置该宏为1，对于MCU而言，设置0
即可。

.. note:: 
    有些情况下的MCU配备了外部SRAM，这个时候显示屏的缓存可以直接映射到外部的SRAM中，一般这类MCU内部自带TFT控制器。在这种情况下，SGL_CONFIG_FRAMEBUFFER_MMAP需要设置为1。


3. 注册显示显示设备
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    对于MCU而言，一般需要提供一个绘制窗口的函数，用来将缓存中的数据发送到TFT上并显示出来，这个需要根据实际的显示设备来定义struct sgl_device_panel结构体，例如TFT的型号是240*240分辨率，
    我们可以定义如下结构体：

.. code-block:: c
   :linenos:

    #include "sgl.h"

    void tft_show_window(int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t *src)
    {
        ...
    }

    ...
    sgl_color_t draw_buffer[240*40];
    sgl_device_panel_t tft_panel = {
                                    .framebuffer = draw_buffer,
                                    .buffer_size = sizeof(draw_buffer),
                                    .xres = 240,
                                    .yres = 240,
                                    .flush_area = tft_show_window,
                                    };
    
    int main(void) 
    {
        //只注册显示设备
        sgl_device_register(&tft_panel, NULL);
        //初始化sgl
        sgl_init();
        ...
        while(1) {
            ...
            //sgl的任务轮询
            sgl_task_handler();
            ...

        }
    }


4. 编译
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   编译整个工程后，需要将sgl_conf.h和sgl.h的文件所在的路径包含在项目工程的头文件路径中，编译完毕后，就可以将其下载到开发板上即可。


Linux framebuffer平台
--------------------------------------------

Windows平台
--------------------------------------------

