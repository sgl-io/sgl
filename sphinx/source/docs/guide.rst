用户指导
======================================


添加按钮
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
首先定义一个回调函数，该回调函数如下所示：

.. code-block:: c
   :linenos:

    void btn_event(sgl_obj_t *obj, void *data)
    {
        if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
            ...
            //your code
        }
        else if(sgl_obj_get_event_status(obj) == SGL_EVENT_RELEASED) {
            ...
            //your code
        };
    }

然后在main.c函数中添加如下代码用户创建按钮：
1. 静态创建  

.. code-block:: c
   :linenos:
   
    //定义button样式
    sgl_style_t btn_style = {.body_color = SGL_BLUE, .text_color = SGL_RED, .radius = 25};
    //定义一个button结构体
    sgl_button_t button;
    //定义一个button的obj指针
    sgl_obj_t *btn = &button.obj;
    //按钮初始化
    sgl_button_init(&button, sgl_scr_active());
    //设置按钮大小，注意：当绘图缓存的大小不大时，按钮的大小不应该设置过大
    sgl_obj_set_size(btn, 100, 50);
    //设置按钮的位置，这里使用相对位置
    sgl_obj_set_align(btn, SGL_ALIGN_CENTER_RIGHT);
    //设置按钮的样式
    sgl_obj_set_style(btn, btn_style);
    //设置按钮的事件回调
    sgl_obj_set_event_cb(btn, btn_event, NULL);
    //设置按钮的toggle颜色
    sgl_button_set_toggle_color(btn, SGL_GREEN);
    //设置按钮的字体
    sgl_button_set_font(btn, &song23);
    //设置按钮的text
    sgl_button_set_text(btn, "Button");


2. 动态创建（MCU还未实现）



