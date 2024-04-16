#include <windows.h> // Windows头文件
#include <stdio.h>
#include "SDL.h"
#include <sgl_math.h>
#include <stdlib.h>
#include <time.h>
#include "sgl.h"
#include "sgl_draw_line.h"
#include "../draw/sgl_draw_arc.h"
#include "../draw/sgl_draw_icon.h"
#include "../draw/sgl_draw_line.h"
#include "../draw/sgl_draw_rect.h"
#include "../draw/sgl_draw_pie.h"

SDL_Event myEvent; //SDL事件

SDL_Window * m_window = NULL;
SDL_Renderer * m_renderer = NULL;


extern unsigned char sgl_logo[121800];
sgl_img_t sgl_logo_img = {.bitmap = sgl_logo, .width = 290, .height = 105,};


extern unsigned char gImage_tets[614400];
extern unsigned char gImage2_tets[614400];
extern unsigned char icon_tets[40000];

#define FRAME_BUFFER_XRES   480
#define FRAME_BUFFER_YRES   320
#define FRAME_BUFFER_XRES_VIRTUAL   480
#define FRAME_BUFFER_YRES_VIRTUAL   320

sgl_color_t sdl2_frame_buffer[FRAME_BUFFER_XRES_VIRTUAL * FRAME_BUFFER_YRES_VIRTUAL] = {0};

sgl_color_t sdl2_draw_buffer[30 * FRAME_BUFFER_XRES] = {0};

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

sgl_obj_t *two_page;
sgl_obj_t *main_page;

void btn_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        
    }
    else if(sgl_obj_get_event_status(obj) == SGL_EVENT_RELEASED) {
        printf("buttton released\n");
        sgl_page_set_active(two_page);
    };
}

void sw_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(sgl_switch_get_status(obj)) {
            printf("ON\n");
        }
        else {
            printf("OFF\n");
            sgl_page_set_active(main_page);
        }
    }
}

void chkbox_event(sgl_obj_t *obj, void *data)
{
    printf("value = %d\n", sgl_pgsbar_get_value(obj));
}

void anim_cb(sgl_anim_t *anim, void *data)
{
    anim->obj->size.w ++;
}

void anim_arcbar(sgl_anim_t *anim, void *data)
{
    static uint8_t count = 0;
    if(count > 100) {
        count = 0;
    }
    sgl_arcbar_set_value(anim->obj, count);
    count ++ ;
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


sgl_img_t bg_img = {.bitmap = gImage_tets, .width = 480, .height = 320,};
sgl_img_t bg2_img = {.bitmap = gImage2_tets, .width = 480, .height = 320,};
sgl_img_t icon_img= {.bitmap = icon_tets, .width = 80, .height = 80,};

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
    sgl_device_register(&sdl_panel, &sdl_mouse);
    
    sgl_init();

    main_page = sgl_page_create();
    two_page = sgl_page_create();
    sgl_icon_t icon = { .bitmap = test_bitmap, .width = 16, .height = 15, };

    sgl_page_set_background(main_page, &bg_img);
    sgl_page_set_background(two_page, &bg2_img);
    //sgl_draw_icon_on_bg(sgl_get_active_surf(NULL), 150,50,SGL_GREEN, &icon);

    sgl_page_set_active(main_page);

    //sgl_draw_circle_img_transp_on_bg(sgl_get_active_surf(NULL), 380, 120, 30, &icon_img, 0);

    sgl_button_t button;
    sgl_button_init(&button, main_page);
    sgl_obj_t* btn = &button.obj;
    sgl_icon_t btn_icon = {.bitmap = test_bitmap, .width = 16, .height = 15};
    sgl_style_t btn_style = {.body_color = SGL_BLUE, .text_color = SGL_RED, .radius = 25};
    //sgl_obj_t* btn = sgl_button_create(sgl_scr_active());
    sgl_obj_set_size(btn, 100, 50);
    sgl_obj_set_align(btn, SGL_ALIGN_TOP_MID);
    sgl_obj_set_style(btn, btn_style);
    sgl_obj_set_event_cb(btn, btn_event, NULL);
    sgl_button_set_toggle_color(btn, SGL_GREEN);
    sgl_button_set_icon(btn, &btn_icon);
    sgl_button_set_font(btn, &song23);
    sgl_button_set_text(btn, "Button");
    sgl_obj_set_selected(btn, true);

    sgl_style_t sw_style = {.body_color = sgl_rgb(255,0,255), .radius = 15};
    sgl_obj_t* sw = sgl_switch_create(main_page, true);
    sgl_obj_set_size(sw, 60, 30);
    sgl_obj_set_align(sw, SGL_ALIGN_CENTER_LEFT);
    sgl_obj_set_style(sw, sw_style);
    sgl_obj_set_event_cb(sw, sw_event, NULL);
    sgl_switch_set_toggle_color(sw, SGL_BLACK);
    sgl_switch_set_status(sw, false);

    sgl_obj_t* sw4 = sgl_switch_create(two_page, true);
    sgl_obj_set_size(sw4, 60, 30);
    sgl_obj_set_align(sw4, SGL_ALIGN_CENTER_RIGHT);
    sgl_obj_set_style(sw4, sw_style);
    sgl_obj_set_event_cb(sw4, sw_event, NULL);
    sgl_switch_set_toggle_color(sw4, SGL_BLACK);
    sgl_switch_set_status(sw4, true);

    sgl_style_t sw_style2 = {.body_color = SGL_BLUE, .radius = 10};
    sgl_obj_t* sw2 = sgl_switch_create(main_page, true);
    sgl_obj_set_size(sw2, 40, 20);
    sgl_obj_set_align(sw2, SGL_ALIGN_BOT_MID);
    sgl_obj_set_style(sw2, sw_style2);
    sgl_obj_set_event_cb(sw2, sw_event, NULL);
    sgl_switch_set_toggle_color(sw2, SGL_BLACK);
    sgl_switch_set_status(sw2, false);

    sgl_style_t label_style = {.body_color = SGL_BLUE, .text_color = SGL_WHITE, .radius = 10};
    sgl_obj_t* label = sgl_label_create(main_page);
    sgl_obj_set_size(label, 200, 40);
    sgl_obj_set_pos(label, 10, 20);
    sgl_obj_set_radius(label, 8);
    sgl_obj_set_style(label, label_style);

    sgl_label_set_font(label, &song23);
    sgl_label_set_text(label, "Welcome to SGL");
    sgl_label_set_text_align(label, SGL_ALIGN_CENTER_MID);
    sgl_obj_set_event_cb(label, chkbox_event, NULL);
    sgl_label_set_icon(label, &btn_icon);

    // sgl_style_t bat_style = {.body_color = SGL_RED, .text_color = SGL_BLUE, .radius = 3};
    // sgl_obj_t* bat = sgl_battery_create(main_page, 10);
    // sgl_obj_set_style(bat, bat_style);
    // sgl_obj_set_size(bat, 16, 24);
    // sgl_obj_set_pos(bat, 100, 200);
    // sgl_battery_set_border_weight(bat, 2);

    sgl_style_t chkbox_style = {.body_color = SGL_BLACK, .text_color = SGL_GREEN, .radius = 3};
    sgl_obj_t *chkbox = sgl_checkbox_create(main_page, true);
    sgl_obj_set_size(chkbox, 150, 15);
    sgl_obj_set_pos(chkbox, 0, 0);
    sgl_obj_set_event_cb(chkbox, chkbox_event, NULL);
    sgl_obj_set_style(chkbox, chkbox_style);
    sgl_checkbox_set_font(chkbox, &cascadia_mono17);
    sgl_checkbox_set_text(chkbox, "0123456");

    sgl_style_t radio_style = {.body_color = SGL_BLACK, .text_color = SGL_BLUE, .radius = 3};
    sgl_obj_t *radio = sgl_radiobtn_create(main_page, true);
    sgl_obj_set_size(radio, 150, 16);
    sgl_obj_set_pos(radio, 50, 250);
    sgl_obj_set_event_cb(radio, chkbox_event, NULL);
    sgl_obj_set_style(radio, radio_style);
    sgl_radiobtn_set_font(radio, &cascadia_mono17);
    sgl_radiobtn_set_text(radio, "This is B");

    sgl_style_t number_style = {.body_color = sgl_rgb(100,200,200), .text_color = SGL_BLUE, .radius = 5};
    sgl_obj_t *number = sgl_number_create(main_page, 2.8568);
    sgl_obj_set_size(number, 40, 40);
    sgl_number_set_text_align(number, SGL_ALIGN_CENTER_RIGHT);
    sgl_number_set_font(number, &song23);
    sgl_obj_set_style(number, number_style);
    sgl_obj_set_pos(number, 10, 200);

    sgl_anim_t amin;
    sgl_anim_set_anim_cb(&amin, anim_cb, NULL);
    sgl_anim_set_times(&amin, 100);
    sgl_anim_set_interval(&amin, 5);
    sgl_anim_bind_obj(&amin, number);
    sgl_anim_exec(&amin);
    sgl_anim_set_endless(&amin, false);

    sgl_style_t pgs_style = {.body_color = sgl_rgb(100,100,200), .text_color = SGL_GREEN, .radius = 5};
    sgl_obj_t *pgsbar = sgl_pgsbar_create(main_page, 60);
    sgl_obj_set_size(pgsbar, 200, 10);
    sgl_obj_set_style(pgsbar, pgs_style);
    sgl_obj_set_pos(pgsbar, 10, 300);
    sgl_pgsbar_set_font(pgsbar, &song10);
    sgl_obj_set_event_cb(pgsbar, chkbox_event, NULL);
    sgl_obj_set_hide(pgsbar, true);

    // sgl_draw_circle_arc_on_bg(sgl_get_active_surf(NULL), 100, 100, 50, 10, SGL_BLUE);
    // sgl_draw_line_on_bg(sgl_get_active_surf(NULL), 10,10,443,50,SGL_RED);

    sgl_rect_t rect = {.x1 = 40, .y1 = 60, .x2 = 220,  .y2 = 165};
    sgl_rect_t rect1 = {.x1 = 380, .y1 = 160, .x2 = 460,  .y2 = 240};
    //sgl_draw_round_rect_hollow_thalf_on_bg(sgl_get_active_surf(NULL), rect, 20, SGL_BLUE);

    //sgl_draw_font_string_transp_on_bg(sgl_get_active_surf(NULL), 10, 270, "123456789DKJDHEJabcddefew", SGL_GREEN, &song23, 200);

    // sgl_draw_circle_img_on_bg(sgl_get_active_surf(NULL), 100, 100, 40, &icon_img);
    // sgl_draw_circle_img_on_bg(sgl_get_active_surf(NULL), 200, 100, 40, &icon_img);
    // sgl_draw_circle_img_on_bg(sgl_get_active_surf(NULL), 300, 100, 40, &icon_img);
    // sgl_draw_circle_img_on_bg(sgl_get_active_surf(NULL), 100, 200, 40, &icon_img);
    // sgl_draw_circle_img_on_bg(sgl_get_active_surf(NULL), 200, 200, 40, &icon_img);
    // sgl_draw_circle_img_on_bg(sgl_get_active_surf(NULL), 300, 200, 40, &icon_img);

    //sgl_draw_round_rect_img_transp_on_bg(sgl_get_active_surf(NULL), rect, 25, &sgl_logo_img, 128);
    // sgl_draw_round_rect_img_transp_on_bg(sgl_get_active_surf(NULL), rect1, 25, &icon_img, 0);
    //sgl_draw_round_rect_hollow_on_bg(sgl_get_active_surf(NULL), rect, 20, SGL_BLUE);

    // sgl_style_t arcbar_style = {.body_color = sgl_rgb(100,200,200), .text_color = SGL_RED, .radius = 5};
    // sgl_obj_t *arcbar = sgl_arcbar_create(main_page, 100);
    // sgl_obj_set_size(arcbar, 100, 100);
    // sgl_obj_set_style(arcbar, arcbar_style);
    // sgl_obj_set_pos(arcbar, 300, 180);
    // sgl_arcbar_set_font(arcbar, &song23);
    // sgl_arcbar_set_thick(arcbar, 5);
    
    // sgl_anim_t amin2;
    // sgl_anim_set_anim_cb(&amin2, anim_arcbar, NULL);
    // sgl_anim_set_times(&amin2, 100);
    // sgl_anim_set_interval(&amin2, 40);
    // sgl_anim_bind_obj(&amin2, arcbar);
    // sgl_anim_set_endless(&amin2, true);
    // sgl_anim_exec(&amin2);

    // sgl_style_t arcbar2_style = {.body_color = sgl_rgb(100,200,200), .text_color = SGL_RED, .radius = 5};
    // sgl_obj_t *arcbar2 = sgl_arcbar_create(main_page, 100);
    // sgl_obj_set_size(arcbar2, 100, 100);
    // sgl_obj_set_style(arcbar2, arcbar_style);
    // sgl_obj_set_pos(arcbar2, 200, 200);
    // sgl_arcbar_set_font(arcbar2, &song23);
    // sgl_arcbar_set_thick(arcbar2, 5);

    // sgl_anim_t amin3;
    // sgl_anim_set_anim_cb(&amin3, anim_arcbar, NULL);
    // sgl_anim_set_times(&amin3, 100);
    // sgl_anim_set_interval(&amin3, 40);
    // sgl_anim_bind_obj(&amin3, arcbar2);
    // sgl_anim_set_endless(&amin3, true);
    // sgl_anim_exec(&amin3);

    //sgl_draw_circle_solid_on_bg(sgl_get_active_surf(NULL), 100, 100, 50, SGL_RED);
    //sgl_draw_circle_hollow_on_bg(sgl_get_active_surf(NULL), 200, 100, 50, SGL_BLACK);
    //sgl_draw_thick_circle(sgl_get_active_surf(NULL), 100, 100, 50, 5, SGL_BLUE, SGL_WHITE);
    // sgl_pixmap_t pixmap;
    // sgl_pixmap_init(&pixmap, sgl_scr_active(), img);
    // sgl_obj_set_pos(&pixmap.obj, 0, 0);
    // //sgl_obj_set_size(&pixmap.obj, 100, 100);
    // sgl_pixmap_draw(&pixmap.obj);

    //sgl_draw_line(sgl_get_active_surf(NULL), 10, 10, 400, 50, SGL_BLUE, SGL_WHITE);

    static uint8_t bat_qua = 0;
    SDL_TimerID timer = SDL_AddTimer(50, fb_update, NULL);//创立定时器timer
    SDL_TimerID timer_tick = SDL_AddTimer(5, sgl_system_tick, NULL);//创立定时器timer

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
        // if(myEvent.type==SDL_KEYDOWN){
        //     switch(myEvent.key.keysym.sym){
        //     case SDLK_UP:
        //         sgl_obj_event_click(sw);
        //         sgl_obj_event_press(btn);
        //         bat_qua ++;
        //         sgl_arcbar_set_value(arcbar, bat_qua);
        //         sgl_battery_set_quantity(bat, bat_qua);
        //         sgl_obj_add_dirty_list(bat);
        //         break;
        //     case SDLK_DOWN:
        //         sgl_obj_event_release(btn);
        //         bat_qua -- ;
        //         sgl_arcbar_set_value(arcbar, bat_qua);
        //         sgl_battery_set_quantity(bat, bat_qua);
        //         sgl_obj_add_dirty_list(bat);
        //         break;
        //     case SDLK_LEFT:
        //         sgl_obj_set_selected(btn, true);
        //         sgl_obj_set_selected(sw, false);
        //         sgl_obj_set_selected(label, false);
        //         sgl_obj_set_selected(chkbox, false);
        //         sgl_obj_set_selected(pgsbar, true);
        //         sgl_obj_set_selected(radio, true);
        //         break;
        //     case SDLK_RIGHT:
        //         sgl_obj_set_selected(radio, false);
        //         sgl_obj_set_selected(pgsbar, false);
        //         sgl_obj_set_selected(label, true);
        //         sgl_obj_set_selected(btn, false);
        //         sgl_obj_set_selected(sw, true);
        //         sgl_obj_set_selected(chkbox, true);
        //         break;
        //     default:
        //         break;
        //     }
        // }
        // if(myEvent.type == SDL_KEYUP) {
        //     switch(myEvent.key.keysym.sym){
        //     case SDLK_UP:
        //         sgl_obj_event_release(btn);
        //         break;
        //     case SDLK_DOWN:
                
        //         break;
        //     case SDLK_LEFT:
        //         break;
        //     case SDLK_RIGHT:
        //         break;
        //     default:
        //         break;
        //     }
        // }
    }
	SDL_RemoveTimer(timer);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
    return 1;
}
