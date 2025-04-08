#include <stdio.h>
#include "fan_main_task.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t FanMainTask_Handler;

FanCardSysSet_t FanCardSysSet = {
    .auto_control = true,
    .auto_control_target_speed = 0,
    .fan_installation_status = 0b0011111111111111,
    .fan_alarm =
        {
            .act = ONLY_WARNING,
            .delay = 10,
            .fan_low_speed_warning_threshold = 1000,
            .fan_fg_difference_warning_threshold = 0,
        },
};

FanCardSysDisp_t FanCardSysDisp;

void fan_main_task_function(void* pvParameters) {
  while (1) {
    vTaskDelay(pdMS_TO_TICKS(1000));  // Delay for 1 second
  }
}