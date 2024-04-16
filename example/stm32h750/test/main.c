#include "main.h"
#include "lcd_spi_200.h" 

#include "sgl.h"

void SystemClock_Config(void);
void MPU_Config(void);

/* STM32H750 AXI RAM, size is 512KB */
sgl_color_t *fbp = (sgl_color_t *)0x24000000;

int count = 0;
int x = 0, y = 0;
long int location = 0;


#define FRAME_BUFFER_XRES   480
#define FRAME_BUFFER_YRES   320
#define FRAME_BUFFER_XRES_VIRTUAL   480
#define FRAME_BUFFER_YRES_VIRTUAL   320

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


void btn_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        //printf("buttton pressed\n");
    }
    else if(sgl_obj_get_event_status(obj) == SGL_EVENT_RELEASED) {
        //printf("buttton released\n");
    };
}

void sw_event(sgl_obj_t *obj, void *data)
{
    if(sgl_obj_get_event_status(obj) == SGL_EVENT_PRESSED) {
        if(sgl_switch_get_status(obj)) {
            //printf("ON\n");
        }
        else {
            //printf("OFF\n");
        }
    }
}

void chkbox_event(sgl_obj_t *obj, void *data)
{
    //printf("value = %d\n", sgl_pgsbar_get_value(obj));
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


void delay_dummy(int delay)
{
  for(volatile int i=0; i<delay;i++)
    for(volatile int j=0; j<100000;j++)
      ;;;
}


int main(void)
{
  MPU_Config();				
  SCB_EnableICache();		
  SCB_EnableDCache();		
  HAL_Init();				
  SystemClock_Config();	

  /* st7789v screen initialization320*240 */
  SPI_LCD_Init();

    sgl_device_panel_t tft_panel = {
                                    .framebuffer = fbp, 
                                    .xres = FRAME_BUFFER_XRES,
                                    .yres = FRAME_BUFFER_YRES,
                                    .xres_virtual = FRAME_BUFFER_XRES_VIRTUAL,
                                    .yres_virtual = FRAME_BUFFER_YRES_VIRTUAL,
                                    };
    
    sgl_device_register(&tft_panel, NULL);
    
    sgl_init();

    sgl_button_t button;
    sgl_button_init(&button, sgl_scr_active());
    sgl_obj_t* btn = &button.obj;
    sgl_icon_t btn_icon = {.bitmap = test_bitmap, .width = 16, .height = 15};
    sgl_style_t btn_style = {.body_color = SGL_BLUE, .text_color = SGL_RED, .radius = 25};

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

    sgl_style_t label_style = {.body_color = SGL_BLUE, .text_color = SGL_WHITE, .radius = 10};
    sgl_obj_t* label = sgl_label_create(sgl_scr_active());
    sgl_obj_set_size(label, 200, 40);
    sgl_obj_set_pos(label, 10, 20);
    sgl_obj_set_radius(label, 8);
    sgl_obj_set_style(label, label_style);

    sgl_label_set_font(label, &song23);
    sgl_label_set_text(label, "Welcome to SGL");
    sgl_label_set_text_align(label, SGL_ALIGN_CENTER_MID);
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
    sgl_obj_set_pos(chkbox, 0, 0);
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
    sgl_anim_set_endless(&amin, false);

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
    delay_dummy(100);
	  sgl_tick_inc(5);
    sgl_task_handler();
  }
}


/****************************************************************************************************/
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 480000000 (CPU Clock)
  *            HCLK(Hz)                       = 240000000 (AXI and AHBs Clock)
  *            AHB Prescaler                  = 2
  *            D1 APB3 Prescaler              = 2 (APB3 Clock  120MHz)
  *            D2 APB1 Prescaler              = 2 (APB1 Clock  120MHz)
  *            D2 APB2 Prescaler              = 2 (APB2 Clock  120MHz)
  *            D3 APB4 Prescaler              = 2 (APB4 Clock  120MHz)
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 5
  *            PLL_N                          = 192
  *            PLL_P                          = 2
  *            PLL_Q                          = 4
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
  
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  
  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI5;
  PeriphClkInitStruct.Spi45ClockSelection = RCC_SPI45CLKSOURCE_D2PCLK1;	// SPI CLK = 120M
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }  
}


void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  HAL_MPU_Disable();
  MPU_InitStruct.Enable 				= MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress 		= 0x24000000;
  MPU_InitStruct.Size 					= MPU_REGION_SIZE_512KB;
  MPU_InitStruct.AccessPermission 	= MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable 		= MPU_ACCESS_BUFFERABLE;
  MPU_InitStruct.IsCacheable 		= MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable 		= MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number 				= MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField 		= MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable 	= 0x00;
  MPU_InitStruct.DisableExec 		= MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);	

  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
