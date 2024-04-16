#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "sgl.h"


sgl_color_t *linux_fb;

void btn_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        printf("buttton pressed\n");
    }
    else if(sgl_obj_get_event_status(obj) == SGL_EVENT_RELEASED) {
        printf("buttton released\n");
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

const uint8_t test_bitmap[] = {

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

extern unsigned char gImage_tets[614400];

sgl_img_t bg_img = {.bitmap = gImage_tets, .width = 480, .height = 320,};


int main()
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }
    if (vinfo.bits_per_pixel != SGL_CONFIG_PANEL_PIXEL_DEPTH) {
        perror("color width not match, please update SGL_CONFIG_PANEL_PIXEL_DEPTH");
        exit(4);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    linux_fb = (sgl_color_t *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if (linux_fb == NULL) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    linux_fb += vinfo.xoffset + vinfo.yoffset * vinfo.yres_virtual;
    printf("The framebuffer device was mapped to memory successfully.\n");

    sgl_device_panel_t sdl_panel = {
                                    .framebuffer = linux_fb, 
                                    .xres = vinfo.xres,
                                    .yres = vinfo.yres,
                                    .xres_virtual = vinfo.xres_virtual,
                                    .yres_virtual = vinfo.yres_virtual,
                                    };
    
    sgl_device_register(&sdl_panel, NULL);
    sgl_init(&bg_img);

    sgl_icon_t btn_icon = {.bitmap = test_bitmap, .width = 16, .height = 15};
    sgl_style_t btn_style = {.body_color = SGL_BLUE, .text_color = SGL_RED, .radius = 25};
    sgl_obj_t* btn = sgl_button_create(sgl_scr_active());
    sgl_obj_set_size(btn, 100, 50);
    sgl_obj_set_align(btn, SGL_ALIGN_CENTER_RIGHT);
    sgl_obj_set_style(btn, btn_style);
    sgl_obj_set_event_cb(btn, btn_event, NULL);
    sgl_button_set_toggle_color(btn, SGL_GREEN);
    sgl_button_set_icon(btn, &btn_icon);
    sgl_button_set_font(btn, &song23);
    sgl_button_set_text(btn, "Button");

    sgl_style_t sw_style = {.body_color = sgl_rgb(255,0,255), .radius = 15};
    sgl_obj_t* sw = sgl_switch_create(sgl_scr_active(), true);
    sgl_obj_set_size(sw, 60, 30);
    sgl_obj_set_align(sw, SGL_ALIGN_CENTER_LEFT);
    sgl_obj_set_style(sw, sw_style);
    sgl_obj_set_event_cb(sw, sw_event, NULL);
    sgl_switch_set_toggle_color(sw, SGL_BLACK);
    sgl_switch_set_status(sw, false);

    sgl_style_t sw_style2 = {.body_color = SGL_BLUE, .radius = 10};
    sgl_obj_t* sw2 = sgl_switch_create(sgl_scr_active(), true);
    sgl_obj_set_size(sw2, 40, 20);
    sgl_obj_set_align(sw2, SGL_ALIGN_BOT_MID);
    sgl_obj_set_style(sw2, sw_style2);
    sgl_obj_set_event_cb(sw2, sw_event, NULL);
    sgl_switch_set_toggle_color(sw2, SGL_BLACK);
    sgl_switch_set_status(sw2, false);

    sgl_style_t label_style = {.body_color = SGL_BLUE, .text_color = SGL_WHITE, .radius = 15};
    sgl_obj_t* label = sgl_label_create(sgl_scr_active());
    sgl_obj_set_size(label, 200, 40);
    sgl_obj_set_pos(label, 10, 20);
    sgl_obj_set_radius(label, 8);
    sgl_obj_set_style(label, label_style);

    sgl_label_set_font(label, &song23);
    sgl_label_set_text(label, "Welcome to SGL");
    sgl_label_set_text_align(label, SGL_ALIGN_CENTER_RIGHT);
    sgl_obj_set_event_cb(label, chkbox_event, NULL);
    sgl_label_set_icon(label, &btn_icon);

    sgl_style_t bat_style = {.body_color = SGL_RED, .text_color = SGL_BLUE, .radius = 3};
    sgl_obj_t* bat = sgl_battery_create(sgl_scr_active(), 10);
    sgl_obj_set_style(bat, bat_style);
    sgl_obj_set_size(bat, 16, 24);
    sgl_obj_set_pos(bat, 100, 200);
    sgl_battery_set_border_weight(bat, 2);

    sgl_style_t chkbox_style = {.body_color = SGL_BLACK, .text_color = SGL_GREEN, .radius = 3};
    sgl_obj_t *chkbox = sgl_checkbox_create(sgl_scr_active(), true);
    sgl_obj_set_size(chkbox, 150, 15);
    sgl_obj_set_pos(chkbox, 230, 40);
    sgl_obj_set_event_cb(chkbox, chkbox_event, NULL);
    sgl_obj_set_style(chkbox, chkbox_style);
    sgl_checkbox_set_font(chkbox, &cascadia_mono17);
    sgl_checkbox_set_text(chkbox, "0123456");

    sgl_style_t radio_style = {.body_color = SGL_BLACK, .text_color = SGL_BLUE, .radius = 3};
    sgl_obj_t *radio = sgl_radiobtn_create(sgl_scr_active(), true);
    sgl_obj_set_size(radio, 150, 16);
    sgl_obj_set_pos(radio, 50, 250);
    sgl_obj_set_event_cb(radio, chkbox_event, NULL);
    sgl_obj_set_style(radio, radio_style);
    sgl_radiobtn_set_font(radio, &cascadia_mono17);
    sgl_radiobtn_set_text(radio, "This is B");

    sgl_style_t number_style = {.body_color = sgl_rgb(100,200,200), .text_color = SGL_BLUE, .radius = 5};
    sgl_obj_t *number = sgl_number_create(sgl_scr_active(), 12);
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

    sgl_style_t pgs_style = {.body_color = sgl_rgb(100,200,200), .text_color = SGL_BLUE, .radius = 5};
    sgl_obj_t *pgsbar = sgl_pgsbar_create(sgl_scr_active(), 60);
    sgl_obj_set_size(pgsbar, 200, 10);
    sgl_obj_set_style(pgsbar, pgs_style);
    sgl_obj_set_pos(pgsbar, 10, 80);
    sgl_pgsbar_set_font(pgsbar, &song10);
    sgl_obj_set_event_cb(pgsbar, chkbox_event, NULL);

    sgl_obj_t *arcbar = sgl_arcbar_create(sgl_scr_active(), 50);
    sgl_obj_set_size(arcbar, 100, 100);
    sgl_obj_set_style(arcbar, pgs_style);
    sgl_obj_set_pos(arcbar, 170, 120);
    sgl_arcbar_set_font(arcbar, &song23);
    sgl_arcbar_set_thick(arcbar, 10);

    sgl_anim_t amin2;
    sgl_anim_set_anim_cb(&amin2, anim_arcbar, NULL);
    sgl_anim_set_times(&amin2, 100);
    sgl_anim_set_interval(&amin2, 40);
    sgl_anim_bind_obj(&amin2, arcbar);
    sgl_anim_set_endless(&amin2, true);
    sgl_anim_exec(&amin2);

    while (1)
    {
        sgl_tick_inc(5);
        sgl_task_handler();
        usleep(5000);
    }

    munmap(linux_fb, screensize);
    close(fbfd);
    return 0;
}
