# include <stdio.h>
# include "fan_main_task.h"
# include "FreeRTOS.h"
# include "task.h"

TaskHandle_t FanMainTask_Handler;

void fan_main_task_function(void* pvParameters) {
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}