按钮
===========================================

添加按钮对象
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
在使用SGL之前必须包含sgl.h头文件。在创建button之前先定义一个button需要用到的回调函数，该回调函数如下所示：

.. code-block:: c
   :linenos:

    void btn_event(sgl_obj_t *obj, void *data)
    {
        if(sgl_ev_stat(obj) == SGL_EVENT_PRESSED) {
            ...
            //按键按下需要执行的
        }
        else if(sgl_ev_stat(obj) == SGL_EVENT_RELEASED) {
            ...
            //按键释放后需要执行的
        };
    }

然后在main.c函数中添加如下代码用户创建按钮：

.. code-block:: c
   :linenos:

    //定义一个样式，主体颜色为SGL_BLUE，文本颜色为SGL_RED，圆角半径为16
    sgl_style_t btn_style = {.body_color = SGL_BLUE, .text_color = SGL_RED, .radius = 16};
    //创建一个按钮对象
    sgl_obj_t* btn = sgl_button_create(main_page);
    //设置按钮的尺寸为宽98和高32
    sgl_obj_set_size(btn, 98, 32);
    //设置按钮的位置为x坐标100, y坐标50
    sgl_obj_set_pos(btn, 100, 50);
    //设置按钮的样式为btn_style
    sgl_obj_set_style(btn, &btn_style);
    //设置按钮的事件回调函数为btn_event，参数无
    sgl_obj_set_event_cb(btn, btn_event, NULL);
    //设置按钮的按下后的颜色为SGL_GREEN
    sgl_button_set_toggle_color(btn, SGL_GREEN);
    //设置按钮的字体为song12
    sgl_button_set_font(btn, &song12);
    //设置按钮的显示文本为Button
    sgl_button_set_text(btn, "Button");


.. image:: img/button_test.png
   :alt: button demo


图片按钮
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
有些特殊的场合，我们需要让按钮看起来更加美观，这个时候就需要使用图片按钮了，即按钮的表面使用图片来填充。

1. 首先我们需要定义一个按钮的图片结构体，位图数组使用取模软件获取

.. code-block:: c
   :linenos:

    extern unsigned char button_img[12544];
    sgl_img_t btn_img = {.bitmap = button_img, .width = 98, .height = 32,};

2. 使用sgl_obj_set_bgimg函数来设置按钮图片，使用sgl_button_set_toggle_img函数来设置按下之后的图片

.. code-block:: c
   :linenos:

    //定义一个样式，主体颜色为SGL_BLUE，文本颜色为SGL_RED，圆角半径为16
    sgl_style_t btn_style = {.radius = 16};
    //创建一个按钮对象
    sgl_obj_t* btn = sgl_button_create(main_page);
    //设置按钮的尺寸为宽98和高32
    sgl_obj_set_size(btn, 98, 32);
    //设置按钮的位置为x坐标100, y坐标50
    sgl_obj_set_pos(btn, 100, 50);
    //设置按钮的样式为btn_style
    sgl_obj_set_style(btn, &btn_style);
    //设置按钮的事件回调函数为btn_event，参数无
    sgl_obj_set_event_cb(btn, btn_event, NULL);
    //设置按钮的按下后的颜色为SGL_GREEN
    sgl_button_set_toggle_color(btn, SGL_GREEN);
    //设置按钮的字体为song12
    sgl_button_set_font(btn, &song12);
    //设置按钮图片
    sgl_obj_set_bgimg(btn, &btn_img);
    //设置按钮按下之后的图片
    sgl_button_set_toggle_img(btn, &btn_img);


.. image:: img/button_bg_test.png
   :alt: button demo


