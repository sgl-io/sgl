勾选框
========================================

SGL中的勾选框可以使用如下代码实现：

.. code-block:: c
   :linenos:

    //创建一个样式，主体颜色为SGL_BLACK，文本颜色为SGL_GREEN，圆角半径为3
    sgl_style_t chkbox_style = {.body_color = SGL_BLACK, .text_color = SGL_GREEN, .radius = 3};
    //创建一个勾选框对象
    sgl_obj_t *chkbox = sgl_checkbox_create(main_page, true);
    //设置勾选框的尺寸为宽150和高15
    sgl_obj_set_size(chkbox, 150, 15);
    //设置勾选框的位置为x坐标100, y坐标40
    sgl_obj_set_pos(chkbox, 100, 40);
    //设置勾选框的点击事件回调函数
    sgl_obj_set_event_cb(chkbox, btn_event, NULL);
    //设置勾选框的样式
    sgl_obj_set_style(chkbox, &chkbox_style);
    //设置勾选框的字体
    sgl_checkbox_set_font(chkbox, &cascadia_mono17);
    //设置勾选框的文本
    sgl_checkbox_set_text(chkbox, "SGL is good");


.. image:: img/checkbox_test.png
   :alt: checkbox demo

