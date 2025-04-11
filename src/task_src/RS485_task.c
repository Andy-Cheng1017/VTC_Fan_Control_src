#include "RS485_task.h"

#include <stdio.h>

#include "FreeRTOS.h"
#include "RS485.h"
#include "RS485_Region_handler.h"
#include "main.h"
#include "task.h"

#define SINGLE_DATA_MAX_SIZE 128

#define MY_485_ADDR 0x23

TaskHandle_t RS485Task_Handler;

DECLARE_RS485_BUFFERS(RsFan, SINGLE_DATA_MAX_SIZE);

Rs485_t RsFan = {
    .UART = USART3,
    .Mode = SLAVE,
    .BaudRate = BR_115200,
    .DataBit = USART_DATA_8BITS,
    .StopBit = USART_STOP_1_BIT,
    .ip_addr = MY_485_ADDR,
    .root = false,

    RS485_BUFFERS_INIT(RsFan, SINGLE_DATA_MAX_SIZE),
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
    RS485_Tx_Data_ISR(&RsFan);
  }
}

void RS485_task_function(void* parameter) {
  RsInit(&RsFan);

  RsError_t err;

  while (1) {
    if (RsChkAvailable(&RsFan)) {
      err = RS485Read(&RsFan);

      if (err == UNPKG_FINISH) {
        continue;
      } else if (err != RS485_OK) {
        continue;
      }

      xSemaphoreTake(RS485RegionMutex, RS485_SEMAPHORE_TIMEOUT);
      err = RS485ReadHandler(&RsFan);
      xSemaphoreGive(RS485RegionMutex);

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