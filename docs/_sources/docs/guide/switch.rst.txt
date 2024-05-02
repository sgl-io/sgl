开关按钮
======================================

添加开关按钮对象
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
创建一个开关按钮对象代码如下：

.. code-block:: c
   :linenos:

    //创建一个开关样式，主体颜色为SGL_WHITE，圆角半径为16
    sgl_style_t sw_style = {.body_color = SGL_WHITE, .radius = 17};
    //创建一个开关对象，默认是开启状态
    sgl_obj_t* sw = sgl_switch_create(main_page, true);
    //设置开关的大小为宽124和高34
    sgl_obj_set_size(sw, 80, 34);
    //设置开关的位置为中心向左对齐
    sgl_obj_set_align(sw, SGL_ALIGN_CENTER_LEFT);
    //设置开关的样式
    sgl_obj_set_style(sw, &sw_style);
    //设置开关的点击事件
    sgl_obj_set_event_cb(sw, sw_event, NULL);
    //设置开关的关闭状态下的颜色
    sgl_switch_set_toggle_color(sw, sgl_rgb(50,50,50));
    //设置开关的初始状态
    sgl_switch_set_status(sw, false);


.. image:: img/sw_test.png
   :alt: switch demo


图片开关
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
有时候我们需要让开关按钮看起来更美观，这时就可以使用贴图的方式，我们只需要使用sgl_obj_set_bgimg和sgl_switch_set_toggle_img函数用来设置开关的图片：


.. code-block:: c
   :linenos:

    //创建一个开关样式，主体颜色为SGL_WHITE，圆角半径为16
    sgl_style_t sw_style = {.body_color = SGL_WHITE, .radius = 17};
    //创建一个开关对象，默认是开启状态
    sgl_obj_t* sw = sgl_switch_create(main_page, true);
    //设置开关的大小为宽124和高34
    sgl_obj_set_size(sw, 80, 34);
    //设置开关的位置为中心向左对齐
    sgl_obj_set_align(sw, SGL_ALIGN_CENTER_LEFT);
    //设置开关的样式
    sgl_obj_set_style(sw, &sw_style);
    //设置开关的点击事件
    sgl_obj_set_event_cb(sw, sw_event, NULL);
    //设置开关的关闭状态下的颜色
    sgl_switch_set_toggle_color(sw, sgl_rgb(50,50,50));
    //设置开关的初始状态
    sgl_switch_set_status(sw, false);
    //设置开关的打开状态下的背景图片
    sgl_obj_set_bgimg(sw, &sw_on_img);
    //设置开关的关闭状态下的背景图片
    sgl_switch_set_toggle_img(sw, &sw_off_img);


.. image:: img/sw_bg_test.png
   :alt: switch background demo
