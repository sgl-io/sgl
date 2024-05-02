应用图标
======================================

添加APP图标启动器
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
SGL中的APP启动器可以使用如下代码实现：
首先创建图标的位图数组，位图数据通过取模软件设置，如下，

.. code-block:: c
   :linenos:

    extern unsigned char icon_test[11236];
    sgl_img_t icon_img = {.bitmap = icon_test, .width = 53, .height = 53,};

然后使用sgl_rect_create函数创建矩形对象，并设置各个属性，如下：

.. code-block:: c
   :linenos:

    //定义一个样式，主体颜色为SGL_BLUE，文本颜色为SGL_RED，圆角半径为16
    sgl_style_t app_icon_style = {.body_color = SGL_RED, .text_color = SGL_WHITE, .radius = 12};
    //创建一个APP图标对象
    sgl_obj_t* app = sgl_rect_create(main_page);
    //设置APP图标的尺寸为宽40和高40
    sgl_obj_set_size(app, 40, 40);
    //设置APP图标的位置为x坐标10, y坐标10
    sgl_obj_set_pos(app, 10, 10);
    //设置APP图标样式
    sgl_obj_set_style(app, &app_icon_style);
    //设置APP图标的点击事件
    sgl_obj_set_event_cb(app, btn_event, NULL);
    //设置APP图标的透明度，即不透明
    sgl_obj_set_alpha(app, 0);
    //设置APP图标的背景图片
    sgl_obj_set_bgimg(app, &icon_img);

.. image:: img/app_test.png
   :alt: app icon demo

