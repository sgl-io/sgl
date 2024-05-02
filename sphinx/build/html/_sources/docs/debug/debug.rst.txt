调试
=====================================================================================

添加打印
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

在SGL中添加信息打印需要注册输出设备，SGL的打印信息最终将会以注册的底层接口输出。使用SGL的打印步骤如下：  

- 1. 注册底层输出函数，一般为USART或者UART等设备，用户需要使用sgl_device_stdout_register()函数来注册打印的输出设备，如下所示：


    .. code-block::

        ...
        int stdout_device(char *str)
        {
            return printf("%s\n", str);
        }
        ...

        sgl_device_stdout_t stdout_dev = {
                                        .put = stdout_device,
                                        };
        
        sgl_device_stdout_register(&stdout_dev);
        

- 2. 使用SGL_LOG相关宏来实现打印信息，SGL提供了下面一些打印等级：

    .. code-block:: c

        #define SGL_LOG_LEVEL_TRACE 0 /**< A lot of logs to give detailed information*/
        #define SGL_LOG_LEVEL_INFO  1 /**< Log important events*/
        #define SGL_LOG_LEVEL_WARN  2 /**< Log if something unwanted happened but didn't caused problem*/
        #define SGL_LOG_LEVEL_ERROR 3 /**< Only critical issue, when the system may fail*/
        #define SGL_LOG_LEVEL_USER  4 /**< Custom logs from the user*/
        #define SGL_LOG_LEVEL_NONE  5 /**< Do not log anything*/
        #define _SGL_LOG_LEVEL_NUM  6 /**< Number of log levels*/

- 3. 开启SGL_CONFIG_DEBUG宏

    在sgl_conf.h配置文件中设置SGL_CONFIG_DEBUG宏的值为1，并且需要设置打印等级SGL_CONFIG_LOG_LEVEL，默认为0  

- 4. 打印信息

    可以使用SGL_LOG_INFO()宏来打印一些信息，例如：

    .. code-block:: c

       SGL_LOG_INFO("Hello SGL!");

