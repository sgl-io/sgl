//debug mode
#define SGL_CONFIG_DEBUG               0

//poweron animation
#define SGL_CONFIG_POWERON_ANIM        0

// enable Anti-Aliasing 
#define SGL_CONFIG_AA_ENABLE           1

//配置字体抗锯齿深度，默认采用4bit抗锯齿
#define SGL_CONFIG_FONT_PIXEL_BIT      4

//显示屏面板的像素深度，默认为32bit
#define SGL_CONFIG_PANEL_PIXEL_DEPTH   16


//1: standard
//2: fast
#define SGL_CONFIG_MIXER_TYPE          2

//1: newton
//2: 
#define SGL_CONFIG_SQRT_ALGO           2

#define SGL_CONFIG_FRAMEBUFFER_MMAP    1


#define SGL_CONFIG_DRAW_STACK_MAX      128

//0: 绘图算法使用查表方式
//1: 绘图算法使用计算方式
#define SGL_CONFIG_DRAW_ALGO           1

//定义事件的队列深度
#define SGL_CONFIG_EVQUEUE_DEPTH       16


#define SGL_CONFIG_CIRCLE_RENDER_SIZE  256

#define SGL_CONFIG_FONT_CONSOLAS12     1
#define SGL_CONFIG_FONT_CONSOLAS15     1
#define SGL_CONFIG_FONT_SONG10         1
#define SGL_CONFIG_FONT_SONG23         1
#define SGL_CONFIG_FONT_CASCADIA_MONO  1
