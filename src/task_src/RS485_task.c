#include <stdio.h>
#include "RS485_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "RS485.h"
#include "RS485_Region_handler.h"

#define MY_485_ADDR 0x23

TaskHandle_t RS485Task_Handler;

Rs485_t RsFan = {
    .UART = USART3,
    .Mode = SLAVE,
    .BaudRate = BR_115200,
    .DataBit = USART_DATA_8BITS,
    .StopBit = USART_STOP_1_BIT,
    .ip_addr = MY_485_ADDR,
    .root = false,
};

void USART3_IRQHandler(void) {
  if (usart_interrupt_flag_get(RsFan.UART, USART_RDBF_FLAG) != RESET) {
    usart_flag_clear(RsFan.UART, USART_RDBF_FLAG);
    RS485_Rx_Data_ISR(&RsFan);

  } else if (usart_interrupt_flag_get(RsFan.UART, USART_IDLEF_FLAG) != RESET) {
    usart_flag_clear(RsFan.UART, USART_IDLEF_FLAG);
    RS485_Rx_Cplt_ISR(&RsFan);

  } else if (usart_interrupt_flag_get(RsFan.UART, USART_TDBE_FLAG) != RESET) {
    usart_flag_clear(RsFan.UART, USART_TDBE_FLAG);
    usart_interrupt_enable(RsFan.UART, USART_TDBE_INT, FALSE);
    RsFan.tx_idex--;
    RS485_Tx_Data_ISR(&RsFan);
  }
}

void RS485_task_function(void* parameter) {
  RsInit(&RsFan);
  RsFan.reg_hdle_stat = 0x80;
  RsFan.reg_hdle_end = 0x9F;
  RsRegHdle(&RsFan, FansCardHdle);

  RsError_t err;

  while (1) {
    if (RsChkAvailable(&RsFan)) {
      err = RS485Read(&RsFan);

      if (err == UNPKG_FINISH) {
        continue;
      } else if (err != RS485_OK) {
        continue;
      }
      err = RS485ReadHandler(&RsFan);

      if (err != RS485_OK) {
        continue;
      }

      err = RS485Write(&RsFan);

      if (err != RS485_OK) {
        continue;
      }
    }

    vTaskDelay(25);
  }
  vTaskDelete(NULL);
}