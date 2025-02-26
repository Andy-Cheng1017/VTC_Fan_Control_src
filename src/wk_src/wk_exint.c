/* add user code begin Header */
/**
  **************************************************************************
  * @file     wk_exint.c
  * @brief    work bench config program
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
#include "wk_exint.h"

/* add user code begin 0 */

/* add user code end 0 */

/**
  * @brief  init exint function.
  * @param  none
  * @retval none
  */
void wk_exint_config(void)
{
  /* add user code begin exint_config 0 */

  /* add user code end exint_config 0 */

  gpio_init_type gpio_init_struct;
  exint_init_type exint_init_struct;

  /* add user code begin exint_config 1 */

  /* add user code end exint_config 1 */

  /* configure the EXINT0 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_0;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOB, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOB, GPIO_PINS_SOURCE0);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_0;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT0 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT0 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_0, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT0_IRQHandler(void)
   */

  /* configure the EXINT1 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_1;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOB, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOB, GPIO_PINS_SOURCE1);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_1;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT1 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT1 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_1, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT1_IRQHandler(void)
   */

  /* configure the EXINT2 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_2;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOB, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOB, GPIO_PINS_SOURCE2);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_2;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT2 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT2 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_2, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT2_IRQHandler(void)
   */

  /* configure the EXINT3 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_3;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOB, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOB, GPIO_PINS_SOURCE3);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_3;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT3 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT3 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_3, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT3_IRQHandler(void)
   */

  /* configure the EXINT4 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_4;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PINS_SOURCE4);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_4;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT4 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT4 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_4, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT4_IRQHandler(void)
   */

  /* configure the EXINT5 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_5;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PINS_SOURCE5);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_5;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT5 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT5 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_5, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT9_5_IRQHandler(void)
   */

  /* configure the EXINT6 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_6;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOF, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOF, GPIO_PINS_SOURCE6);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_6;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT6 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT6 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_6, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT9_5_IRQHandler(void)
   */

  /* configure the EXINT7 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_7;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOF, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOF, GPIO_PINS_SOURCE7);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_7;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT7 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT7 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_7, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT9_5_IRQHandler(void)
   */

  /* configure the EXINT8 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_8;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PINS_SOURCE8);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_8;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT8 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT8 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_8, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT9_5_IRQHandler(void)
   */

  /* configure the EXINT9 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_9;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PINS_SOURCE9);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_9;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT9 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT9 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_9, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT9_5_IRQHandler(void)
   */

  /* configure the EXINT10 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_10;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PINS_SOURCE10);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_10;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT10 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT10 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_10, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT15_10_IRQHandler(void)
   */

  /* configure the EXINT11 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_11;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOB, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOB, GPIO_PINS_SOURCE11);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_11;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT11 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT11 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_11, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT15_10_IRQHandler(void)
   */

  /* configure the EXINT12 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_12;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PINS_SOURCE12);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_12;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT12 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT12 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_12, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT15_10_IRQHandler(void)
   */

  /* configure the EXINT13 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_13;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOC, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOC, GPIO_PINS_SOURCE13);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_13;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT13 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT13 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_13, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT15_10_IRQHandler(void)
   */

  /* configure the EXINT14 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_14;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOC, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOC, GPIO_PINS_SOURCE14);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_14;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT14 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT14 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_14, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT15_10_IRQHandler(void)
   */

  /* configure the EXINT15 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_15;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOC, &gpio_init_struct);

  gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOC, GPIO_PINS_SOURCE15);

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_15;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT15 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT15 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_15, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f415_int.c file.
   *     --void EXINT15_10_IRQHandler(void)
   */

  /* add user code begin exint_config 2 */

  /* add user code end exint_config 2 */

  /* add user code begin exint_config 3 */

  /* add user code end exint_config 3 */
}

/* add user code begin 1 */

/* add user code end 1 */
