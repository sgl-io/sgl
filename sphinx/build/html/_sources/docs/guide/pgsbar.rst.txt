进度条
=====================================

SGL中的进度条可以使用如下代码实现：

.. code-block:: c
   :linenos:

    //创建进度条样式
    sgl_style_t pgs_style = {.body_color = sgl_rgb(100,200,200), .text_color = SGL_BLUE, .radius = 5};
    //创建一个进度条对象
    sgl_obj_t *pgsbar = sgl_pgsbar_create(main_page, 60);
    //设置进度条的尺寸为宽200和高10
    sgl_obj_set_size(pgsbar, 200, 10);
    //设置进度条样式
    sgl_obj_set_style(pgsbar, &pgs_style);
    //设置进度条的位置为x坐标10, y坐标80
    sgl_obj_set_pos(pgsbar, 10, 80);
    //设置进度条字体
    sgl_pgsbar_set_font(pgsbar, &song10);
    //设置进度条点击事件的回调函数
    sgl_obj_set_event_cb(pgsbar, pgsbar_event, NULL);


.. image:: img/pgsbar_test.png
   :alt: pgsbar demo

