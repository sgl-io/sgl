#include <windows.h> // Windows头文件
#include <stdio.h>
#include "SDL.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "sgl.h"

SDL_Event myEvent; //SDL事件

SDL_Window * m_window = NULL;
SDL_Renderer * m_renderer = NULL;

#define FRAME_BUFFER_XRES   240
#define FRAME_BUFFER_YRES   340
#define FRAME_BUFFER_XRES_VIRTUAL   800
#define FRAME_BUFFER_YRES_VIRTUAL   400

sgl_color_t sdl2_frame_buffer[FRAME_BUFFER_XRES_VIRTUAL * FRAME_BUFFER_YRES_VIRTUAL] = {0};

sgl_color_t sdl2_draw_buffer[20 * FRAME_BUFFER_XRES] = {0};

static int sdl_show_windows(SDL_Window **m_window, SDL_Renderer **m_renderer)
{
    if ( SDL_CreateWindowAndRenderer( FRAME_BUFFER_XRES_VIRTUAL, FRAME_BUFFER_YRES_VIRTUAL, SDL_WINDOW_SHOWN,
                                      &(*m_window), &(*m_renderer )) != 0 )
        return -1;

    // Clear the window with a black background
    SDL_SetRenderDrawColor( *m_renderer, 0, 0, 0, 255);
    SDL_RenderClear( *m_renderer );
    return 0;
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



sgl_style_t number_style = {.body_color = sgl_rgb(100, 100, 100), .text_color = SGL_BLACK, .radius = 5};
sgl_style_t btn_style = {.body_color = sgl_rgb(150, 150, 150), .radius = 25};
sgl_style_t btn_result_style = {.body_color = sgl_rgb(150, 150, 150), .radius = 25};

void btn_init(sgl_obj_t* obj, int x, int y, void (*callback)(sgl_obj_t *, void *), const char *text)
{
    sgl_obj_set_size(obj, 50, 50);
    sgl_obj_set_pos(obj, x, y);
    sgl_obj_set_style(obj, btn_style);
    sgl_obj_set_event_cb(obj, callback, NULL);
    sgl_button_set_toggle_color(obj, sgl_rgb(180,180,180));
    sgl_button_set_font(obj, &song23);
    sgl_button_set_text(obj, text);
}

void btn_result_init(sgl_obj_t* obj, int x, int y, void (*callback)(sgl_obj_t *, void *), const char *text)
{
    sgl_obj_set_size(obj, 50, 105);
    sgl_obj_set_pos(obj, x, y);
    sgl_obj_set_style(obj, btn_result_style);
    sgl_obj_set_event_cb(obj, callback, NULL);
    sgl_button_set_toggle_color(obj, sgl_rgb(180,180,180));
    sgl_button_set_font(obj, &song23);
    sgl_button_set_text(obj, text);
}

void btn_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        printf("buttton pressed\n");
    }
    else if(sgl_obj_get_event_status(obj) == SGL_EVENT_RELEASED) {
        printf("buttton released\n");
    };
}

int result=0;
bool flag=false;
//1: add 
//2: sub
//3: mult
//4: div
//5: mod
int opt = 0;
int number_1=0;
int number_2=0;
sgl_obj_t* number;

void btn0_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 0;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 0;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn1_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 1;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 1;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn2_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 2;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 2;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn3_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 3;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 3;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn4_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 4;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 4;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn5_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 5;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 5;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn6_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 6;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 6;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn7_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 7;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 7;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn8_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 8;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 8;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn9_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 = number_1*10 + 9;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 = number_2*10 + 9;
            sgl_number_set_value(number, number_2);  
        }
    }
}

void btn_mult_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        flag = true;
        opt = 3;
    }
}

void btn_div_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        flag = true;
        opt = 4;
    }
}

void btn_add_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        flag = true;
        opt = 1;
    }
}

void btn_sub_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        flag = true;
        opt = 2;
    }
}

void btn_mod_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        flag = true;
        opt = 5;
    }
}

void btn_dot_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        
    }
}

void btn_clear_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        sgl_number_set_value(number, 0);
        number_1 = 0;
        number_2 = 0;
        flag = false;
    }
}

void btn_backsp_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(!flag) {
            number_1 /= 10;
            sgl_number_set_value(number, number_1);
        }
        else {
            number_2 /= number_2;
            sgl_number_set_value(number, number_2);  
        }
    }
}

//1: add 
//2: sub
//3: mult
//4: div
void btn_result_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        flag = false;
        if(opt == 1) {
            sgl_number_set_value(number, number_1 + number_2);
        }
        else if(opt == 2) {
            sgl_number_set_value(number, number_1 - number_2);
        }
        else if(opt == 3) {
            sgl_number_set_value(number, number_1 * number_2);
        }
        else if(opt == 4) {
            sgl_number_set_value(number, number_1 / number_2);
        }
        else if(opt == 5) {
            sgl_number_set_value(number, number_1 % number_2);
        }
        number_1 = 0;
        number_2 = 0;
    }
}


int main( int argc, char * argv[] )
{
    int quit = 0;
    if ( SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER) != 0 )
        return -1;
    sdl_show_windows(&m_window, &m_renderer);
    SDL_SetWindowTitle(m_window, "SGL计算器");

    sgl_device_panel_t sdl_panel = {
                                    .framebuffer = sdl2_frame_buffer, 
                                    .xres = FRAME_BUFFER_XRES,
                                    .yres = FRAME_BUFFER_YRES,
                                    .xres_virtual = FRAME_BUFFER_XRES_VIRTUAL,
                                    .yres_virtual = FRAME_BUFFER_YRES_VIRTUAL,
                                    };
    
    sgl_device_register(&sdl_panel, NULL);
    sgl_init();
    sgl_set_scr_active_color(sgl_rgb(50,50,50));
    
    number = sgl_number_create(sgl_scr_active(), 0);
    sgl_obj_t* btn_0 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_1 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_2 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_3 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_4 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_5 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_6 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_7 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_8 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_9 = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_mod = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_dot = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_add = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_sub = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_mult = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_div = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_result = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_clear = sgl_button_create(sgl_scr_active());
    sgl_obj_t* btn_backsp = sgl_button_create(sgl_scr_active());

    sgl_obj_set_size(number, 220, 40);
    sgl_obj_set_pos(number, 10, 10);
    sgl_obj_set_style(number, number_style);
    sgl_number_set_font(number, &song23);
    sgl_number_set_text_align(number, SGL_ALIGN_CENTER_RIGHT);
    btn_init(btn_clear, 10, 60, btn_clear_event, "C");
    btn_init(btn_div, 65, 60, btn_div_event, "/");
    btn_init(btn_mult, 120, 60, btn_mult_event, "*");
    btn_init(btn_backsp, 175, 60, btn_backsp_event, "<");

    btn_init(btn_7, 10, 115, btn7_event, "7");
    btn_init(btn_8, 65, 115, btn8_event, "8");
    btn_init(btn_9, 120, 115, btn9_event, "9");
    btn_init(btn_sub, 175, 115, btn_sub_event, "-");

    btn_init(btn_4, 10, 170, btn4_event, "4");
    btn_init(btn_5, 65, 170, btn5_event, "5");
    btn_init(btn_6, 120, 170, btn6_event, "6");
    btn_init(btn_add, 175, 170, btn_add_event, "+");

    btn_init(btn_1, 10, 225, btn1_event, "1");
    btn_init(btn_2, 65, 225, btn2_event, "2");
    btn_init(btn_3, 120, 225, btn3_event, "3");

    btn_init(btn_mod, 10, 280, btn_mod_event, "%");
    btn_init(btn_0, 65, 280, btn0_event, "0");
    btn_init(btn_dot, 120, 280, btn_event, ".");

    btn_result_init(btn_result, 175, 225, btn_result_event, "=");
    

    SDL_TimerID timer = SDL_AddTimer(20, fb_update, NULL);//创立定时器timer
    while (!quit)
    {
        sgl_task_handler();
        SDL_WaitEvent(&myEvent);
        switch (myEvent.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(myEvent.button.button == SDL_BUTTON_LEFT) {
                sgl_event_pos_t pos;
                pos.x = myEvent.motion.x; // 获取鼠标X轴位置
                pos.y = myEvent.motion.y; // 获取鼠标Y轴位置
                pos.type = SGL_EVENT_PRESSED;
                sgl_event_queue_push(pos);
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if(myEvent.button.button == SDL_BUTTON_LEFT) {
                sgl_event_pos_t pos;
                pos.x = myEvent.motion.x; // 获取鼠标X轴位置
                pos.y = myEvent.motion.y; // 获取鼠标Y轴位置
                pos.type = SGL_EVENT_RELEASED;
                sgl_event_queue_push(pos);
            }
            break;
        }
    }
	SDL_RemoveTimer(timer);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
    return 1;
}

