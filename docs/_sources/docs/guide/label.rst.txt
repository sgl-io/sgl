标签
========================================

添加标签
^^^^^^^^^^

添加标签需要先定义一个标签的样式，然后创建一个标签对象，如下代码：

.. code-block:: c
   :linenos:

    //定义一个样式，主体颜色为SGL_BLUE，文本颜色为SGL_RED，圆角半径为16
    sgl_style_t label_style = {.body_color = SGL_BLUE, .text_color = SGL_WHITE, .radius = 8};
    //创建一个标签对象
    sgl_obj_t* label = sgl_label_create(main_page);
    //设置标签的尺寸为宽80和高20
    sgl_obj_set_size(label, 80, 20);
    //设置标签的位置为x坐标20, y坐标220
    sgl_obj_set_pos(label, 20, 220);
    //设置标签样式
    sgl_obj_set_style(label, &label_style);
    //设置标签字体
    sgl_label_set_font(label, &song12);
    //设置标签对齐方式
    sgl_label_set_text_align(label, SGL_ALIGN_CENTER_MID);
    //设置标签显示文本
    sgl_label_set_text(label, "SGL");
    //设置标签透明度255即完全透明
    sgl_obj_set_alpha(label, 255);


.. image:: img/label_test.png
   :alt: label demo



图片标签
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
有时候我们需要为标签添加背景图片，让其显示更加丰富，只需要调用sgl_label_set_bgimg函数即可。

.. code-block:: c
   :linenos:

    //定义一个样式，主体颜色为SGL_BLUE，文本颜色为SGL_RED，圆角半径为16
    sgl_style_t label_style = {.body_color = SGL_BLUE, .text_color = SGL_WHITE, .radius = 8};
    //创建一个标签对象
    sgl_obj_t* label = sgl_label_create(main_page);
    //设置标签的尺寸为宽80和高20
    sgl_obj_set_size(label, 80, 20);
    //设置标签的位置为x坐标20, y坐标220
    sgl_obj_set_pos(label, 20, 220);
    //设置标签样式
    sgl_obj_set_style(label, &label_style);
    //设置标签字体
    sgl_label_set_font(label, &song23);
    //设置标签对齐方式
    sgl_label_set_text_align(label, SGL_ALIGN_CENTER_MID);
    //设置标签显示文本
    sgl_label_set_text(label, "SGL");
    //设置标签透明度0即不透明
    sgl_obj_set_alpha(label, 0);
    //设置标签背景图片
    sgl_obj_set_bgimg(label, &btn_img);


.. image:: img/label_bg_test.png
   :alt: label demo


标签点击事件
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
有时候我们希望标签具备点击事件，我们可以使用sgl_obj_set_event_cb函数来设置标签的点击事件，如下：

.. code-block:: c
   :linenos:

    void label_event(sgl_obj_t *obj, void *data)
    {
        if(sgl_ev_stat(obj) == SGL_EVENT_PRESSED) {
    }

    sgl_obj_set_event_cb(label, label_event, NULL);

