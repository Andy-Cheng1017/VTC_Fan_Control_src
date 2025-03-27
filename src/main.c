/* add user code begin Header */
/**
 **************************************************************************
 * @file     main.c
 * @brief    main program
 **************************************************************************
 *                       Copyright notice & Disclaimer
 *
 * The software Board Support Package (BSP) that is made available to
 * download from Artery official website is the copyrighted work of Artery.
 * Artery authorizes customers to use, copy, and distribute the BSP
 * software and its related documentation for the purpose of design and
 * development in conjunction with Artery microcontrollers. Use of the
 * software is governed by this copyright notice and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
 * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
 * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
 * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
 * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
 *
 **************************************************************************
 */
/* add user code end Header */

/* Includes ------------------------------------------------------------------*/
#include "at32f415_wk_config.h"
#include "wk_crc.h"
#include "wk_debug.h"
#include "wk_exint.h"
#include "wk_tmr.h"
#include "wk_usart.h"
#include "wk_system.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FG_task.h"
#include "PWM_task.h"
#include "RS485_task.h"

#define START_TASK_PRIO 1
#define START_STK_SIZE 128

#define RS485_TASK_PRIO 4
#define RS485_STK_SIZE 1024

#define PWM_TASK_PRIO 2
#define PWM_STK_SIZE 512

#define FG_TASK_PRIO 3
#define FG_STK_SIZE 512

TaskHandle_t StartTask_Handler;
void start_task(void* pvParameters);

/**
 * @brief main function.
 * @param  none
 * @retval none
 */
int main(void) {
  /* add user code begin 1 */

  /* add user code end 1 */

  /* system clock config. */
  wk_system_clock_config();

  /* config periph clock. */
  wk_periph_clock_config();

  /* init debug function. */
  wk_debug_config();

  /* nvic config. */
  wk_nvic_config();

  /* timebase config. */
  wk_timebase_init();

  /* init usart3 function. */
  wk_usart3_init();

  /* init exint function. */
  wk_exint_config();

  /* init tmr1 function. */
  wk_tmr1_init();

  /* init tmr2 function. */
  wk_tmr2_init();

  /* init tmr3 function. */
  wk_tmr3_init();

  /* init tmr4 function. */
  wk_tmr4_init();

  /* init tmr5 function. */
  wk_tmr5_init();

  /* init tmr9 function. */
  wk_tmr9_init();

  /* init tmr10 function. */
  wk_tmr10_init();

  /* init tmr11 function. */
  wk_tmr11_init();

  /* init crc function. */
  wk_crc_init();

  /* add user code begin 2 */
  // FGWork();
  // PWMInit();
  // RS485Init();
  
  // while (1) {
  //   FGWork();
  //   PWMWork();
  //   RS485Work();
  // }
  /* add user code end 2 */

  xTaskCreate((TaskFunction_t)start_task, (const char*)"start_task", (uint16_t)START_STK_SIZE, (void*)NULL, (UBaseType_t)START_TASK_PRIO,
              (TaskHandle_t*)&StartTask_Handler);
  vTaskStartScheduler();
}

void start_task(void* pvParameters) {
  vTaskDelay(100);
  xTaskCreate((TaskFunction_t)RS485_task_function, (const char*)"RS485_task", (uint16_t)RS485_STK_SIZE, (void*)NULL, (UBaseType_t)RS485_TASK_PRIO,
              (TaskHandle_t*)&RS485Task_Handler);
  vTaskDelay(100);
  xTaskCreate((TaskFunction_t)PWM_task_function, (const char*)"PWM_task", (uint16_t)PWM_STK_SIZE, (void*)NULL, (UBaseType_t)PWM_TASK_PRIO,
              (TaskHandle_t*)&PWMTask_Handler);
  vTaskDelay(250);
  xTaskCreate((TaskFunction_t)FG_task_function, (const char*)"FG_task", (uint16_t)FG_STK_SIZE, (void*)NULL, (UBaseType_t)FG_TASK_PRIO,
              (TaskHandle_t*)&FGTask_Handler);

  vTaskDelete(NULL);
}
