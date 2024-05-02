#include <windows.h> // Windows头文件
#include <stdio.h>
#include "SDL.h"
#include <stdlib.h>
#include <time.h>
#include "sgl.h"
#include "../source/libs/sgl_string.h"
#include "../source/draw/sgl_draw_rect.h"
#include "./button.h"
#include "./background.h"


SDL_Event myEvent; //SDL事件

SDL_Window * m_window = NULL;
SDL_Renderer * m_renderer = NULL;


#define FRAME_BUFFER_XRES   240
#define FRAME_BUFFER_YRES   320
#define FRAME_BUFFER_XRES_VIRTUAL   240
#define FRAME_BUFFER_YRES_VIRTUAL   320

sgl_color_t sdl2_frame_buffer[FRAME_BUFFER_XRES_VIRTUAL * FRAME_BUFFER_YRES_VIRTUAL] = {0};

sgl_color_t sdl2_draw_buffer[15 * FRAME_BUFFER_XRES] = {0};

static int sdl_show_windows(SDL_Window **m_window, SDL_Renderer **m_renderer)
{
    if ( SDL_CreateWindowAndRenderer( FRAME_BUFFER_XRES_VIRTUAL, FRAME_BUFFER_YRES_VIRTUAL, SDL_WINDOW_SHOWN,
                                      &(*m_window), &(*m_renderer )) != 0 )
        return -1;

    // Clear the window with a black background
    for(int i = 0; i< FRAME_BUFFER_XRES * FRAME_BUFFER_YRES; i++) {
        sdl2_frame_buffer[i] = SGL_WHITE;
    }
    SDL_SetRenderDrawColor( *m_renderer, 0, 0, 0, 255);
    SDL_RenderClear( *m_renderer );
    return 0;
}

static void sgl_disp_pixel(int16_t x, int16_t y, sgl_color_t color)
{
    sdl2_frame_buffer[y*FRAME_BUFFER_XRES_VIRTUAL + x] =  color;
}


static void sdl2_disp_area(int16_t x1, int16_t y1, int16_t x2, int16_t y2, const sgl_color_t *src)
{
    const sgl_color_t *color = src;
    int16_t x = x1, y = y1, hight = y2 - y1 + 1, width = x2 - x1 + 1;
    for(int i = y; i < (hight + y); i++ )
    {
        for(int j = x; j < (width + x) ; j ++ )
        {
           sgl_disp_pixel(j, i, *color);
           color ++;
        }
    }
}

static void update_win(SDL_Renderer * m_renderer)
{
    SDL_Texture *texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, FRAME_BUFFER_XRES_VIRTUAL, FRAME_BUFFER_YRES_VIRTUAL);
    SDL_UpdateTexture(texture, NULL, sdl2_frame_buffer, FRAME_BUFFER_XRES_VIRTUAL * 4);
    SDL_RenderCopy(m_renderer, texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}


Uint32 fb_update(Uint32 interval, void *param)//回调函数 
{
	update_win(m_renderer);
	return interval;
}

//sgl task定时器
Uint32 sgl_system_tick(Uint32 interval, void *param)//回调函数 
{
	sgl_tick_inc(5);
    sgl_task_handler();
	return interval;
}

sgl_event_pos_t sdl_mouse_get(void *data)
{
    sgl_event_pos_t ev_pos;
    SDL_Event *event = (SDL_Event*)data;
    switch (event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        ev_pos.x = event->motion.x;
        ev_pos.y = event->motion.y;
        ev_pos.type = SGL_EVENT_PRESSED;
        break;
    case SDL_MOUSEBUTTONUP:
        ev_pos.x = event->motion.x;
        ev_pos.y = event->motion.y;
        ev_pos.type = SGL_EVENT_RELEASED;
        break;
    default: ev_pos.type = SGL_EVENT_NULL;
    }
    return ev_pos;
}

// 鼠标中断处理函数
int sgl_mouse_event_interrupt(void *userdata, SDL_Event *event) 
{
    sgl_device_input_handle(event);
    return 0;
}

const uint8_t test_bitmap[]  = {

0x00,0x00,0x00,0x3e,0xc0,0x00,0x00,0x00,  //.......@%.......
0x00,0x00,0x00,0xaf,0xe5,0x00,0x00,0x00,  //......%@@+......
0x00,0x00,0x00,0xee,0xec,0x00,0x00,0x00,  //......@@@%......
0x00,0x00,0x08,0xc8,0xae,0x50,0x00,0x00,  //.....+%+%@+.....
0x00,0x35,0x8e,0xe0,0x3e,0xe8,0x53,0x00,  //...++@@..@@++...
0xef,0xff,0xca,0x50,0x08,0xce,0xff,0xfe,  //@@@@%%+..+%@@@@@
0xae,0xc0,0x00,0x00,0x00,0x00,0x3e,0xe5,  //%@%..........@@+
0x08,0xec,0x00,0x00,0x00,0x03,0xee,0x50,  //.+@%........@@+.
0x00,0x8e,0xc0,0x00,0x00,0x3e,0xe5,0x00,  //..+@%......@@+..
0x00,0x0a,0xe3,0x00,0x00,0x8c,0x80,0x00,  //...%@.....+%+...
0x00,0x0c,0xe0,0x00,0x00,0x5e,0xa0,0x00,  //...%@.....+@%...
0x00,0x0e,0xc0,0x5c,0xc3,0x3e,0xc0,0x00,  //...@%.+%%..@%...
0x00,0x3e,0xcc,0xfc,0xee,0xce,0xe0,0x00,  //...@%%@%@@%@@...
0x00,0x5e,0xfc,0x50,0x05,0xef,0xe3,0x00,  //..+@@%+..+@@@...
0x00,0x5a,0x50,0x00,0x00,0x08,0xa3,0x00,  //..+%+......+%...

};
sgl_obj_t *two_page;
sgl_obj_t *main_page;


sgl_rect_t rect1 = {.x1 = 10, .y1 = 20, .x2 = 400,  .y2= 300,};
sgl_rect_t rect2 = {.x1 = 30, .y1 = 40, .x2 = 220,  .y2= 120,};
sgl_rect_t rect3 = {.x1 = 50, .y1 = 60, .x2 = 240,  .y2= 140,};

void btn_event(sgl_obj_t *obj, void *data)
{
    if(sgl_ev_stat(obj) == SGL_EVENT_PRESSED) {
        printf("buttton pressed\n");
    }
    else if(sgl_ev_stat(obj) == SGL_EVENT_RELEASED) {
        printf("buttton released\n");
        //sgl_page_set_active(two_page);
        // sgl_draw_round_rect_transp_on_bg(sgl_get_active_surf(NULL), rect1, 20, SGL_BLUE, 150);
        // sgl_draw_round_rect_transp_on_bg(sgl_get_active_surf(NULL), rect2, 20, SGL_RED, 150);
        // sgl_draw_round_rect_transp_on_bg(sgl_get_active_surf(NULL), rect3, 20, SGL_GREEN, 150);
    };
}


sgl_img_t bg_img = {.bitmap = bg_test, .width = 240, .height = 320,};
sgl_img_t btn_img = {.bitmap = button_img, .width = 98, .height = 32,};

int stdout_device(char *str)
{
    return printf("%s\n", str);
}


int main( int argc, char * argv[] )
{
    int quit = 0;
    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0 )
        return -1;
    sdl_show_windows(&m_window, &m_renderer);

    sgl_device_panel_t sdl_panel = {
                                    //.framebuffer = sdl2_frame_buffer,
                                    .framebuffer = sdl2_draw_buffer,
                                    .buffer_size = sizeof(sdl2_draw_buffer),
                                    .xres = FRAME_BUFFER_XRES,
                                    .yres = FRAME_BUFFER_YRES,
                                    .xres_virtual = FRAME_BUFFER_XRES_VIRTUAL,
                                    .yres_virtual = FRAME_BUFFER_YRES_VIRTUAL,
                                    .flush_area = sdl2_disp_area
                                    };
    
    sgl_device_input_t sdl_mouse = {
                                    .get = sdl_mouse_get,
                                   };

    sgl_device_stdout_t stdout_dev = {
                                    .put = stdout_device,
                                    };

    sgl_device_register(&sdl_panel, &sdl_mouse);
    
    sgl_device_stdout_register(&stdout_dev);

    sgl_init();

    SGL_LOG_INFO("start sgl...");

    main_page = sgl_page_create();
    two_page = sgl_page_create();

    sgl_page_set_background(main_page, &bg_img);

    sgl_page_set_active(main_page);

    //创建一个开关样式，主体颜色为SGL_WHITE，圆角半径为16
    sgl_style_t sw_style = {.body_color = SGL_BLUE, .radius = 17};
    //创建一个开关对象，默认是开启状态
    sgl_obj_t* sw = sgl_switch_create(main_page, true);
    //设置开关的大小为宽124和高34
    sgl_obj_set_size(sw, 80, 34);
    //设置开关的位置为中心向左对齐
    sgl_obj_set_align(sw, SGL_ALIGN_CENTER_LEFT);
    //设置开关的样式
    sgl_obj_set_style(sw, &sw_style);
    //设置开关的点击事件
    sgl_obj_set_event_cb(sw, btn_event, NULL);
    //设置开关的关闭状态下的颜色
    sgl_switch_set_toggle_color(sw, sgl_rgb(50,50,50));
    //设置开关的初始状态
    sgl_switch_set_status(sw, false);
    sgl_switch_set_anim_flag(sw, true);

    // sgl_style_t icon_style = {.body_color = SGL_RED, .text_color = SGL_WHITE, .radius = 10};
    // sgl_obj_t* circle = sgl_rect_create(main_page);
    // sgl_obj_set_size(circle, 40, 40);
    // sgl_obj_set_pos(circle, 40, 40);
    // sgl_obj_set_style(circle, &icon_style);
    // sgl_obj_set_event_cb(circle, btn_event, NULL);
    // sgl_obj_set_alpha(circle, 200);
    // sgl_obj_set_bgimg(circle, &icon_img);


    SDL_TimerID timer = SDL_AddTimer(50, fb_update, NULL);//创立定时器timer
    SDL_TimerID timer_tick = SDL_AddTimer(5, sgl_system_tick, NULL);//创立定时器timer
    (void)timer_tick; //clear warning
    SDL_AddEventWatch(sgl_mouse_event_interrupt, NULL);
    while (!quit)
    {
        SDL_WaitEvent(&myEvent);
        switch (myEvent.type)
        {
                        
        case SDL_QUIT:
            quit = 1;
            break;
        }
    }
	SDL_RemoveTimer(timer);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
    return 1;
}
