#include <stdio.h>
#include "fan_main_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "PWM_task.h"
#include "FG_task.h"
#include "threshold_monitor.h"
#include "main.h"

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

    .fan_speed_sampling_interval_ms = FAN_SPEED_SAMPLING_INTERVAL,
    .weighted_moving_average_count = 8,
};

FanCardSysDisp_t FanCardSysDisp = {
    .fan_fault_status = 0,
    .fan_status_on_fan_board_bitfield_0_15 = 0,
    .fan_count = 14,
};

ThresholdMonitor_t fan_monitor[16];

uint8_t check_fan_status(int i) {
  if (under_threshold_with_delay(&fan_monitor[i], FansCardStat.fan_fg[i], FanCardSysSet.fan_alarm.fan_low_speed_warning_threshold,
                                 FanCardSysSet.fan_alarm.delay * 1000)) {
    FanCardSysDisp.fan_status_on_fan_board_bitfield_0_15 |= (1 << i);
    if (FansCardStat.fan_fg[i] == 0) {
      return FanCardSysDisp.fan_fault_status = FAN_WITHOUT_INSTALLATION;
    } else {
      return FanCardSysDisp.fan_fault_status = FAN_SPEED_TOO_LOW;
    }
  } else {
    if (FanCardSysDisp.fan_status_on_fan_board_bitfield_0_15 & (1 << i)) {
      FanCardSysDisp.fan_fault_status = FAN_OK;
    }
    FanCardSysDisp.fan_status_on_fan_board_bitfield_0_15 &= ~(1 << i);
    return FAN_OK;
  }
}

void jump_out_auto_control() {
  FanCardSysSet.auto_control = false;
  for (int i = 0; i < 16; i++) {
    FansCardCtrl.fan_pwm[i] = 0;
    clear_threshold_monitor(&fan_monitor[i]);
  }
}

void fan_main_task_function(void* pvParameters) {
  while (1) {
    vTaskDelay(100);

    xSemaphoreTake(RS485RegionMutex, RS485_SEMAPHORE_TIMEOUT);
    if (FanCardSysSet.auto_control == true) {
      FanCardSysDisp.fan_count = __builtin_popcount((unsigned)FanCardSysSet.fan_installation_status);

      for (int i = 0; i < 16; i++) {
        if (FanCardSysSet.fan_installation_status & (1 << i)) {
          FansCardCtrl.fan_pwm[i] = FanCardSysSet.auto_control_target_speed;

          if (FanCardSysSet.auto_control_target_speed > 0) {
            uint8_t ret = check_fan_status(i);
            if (ret != FAN_OK && FanCardSysSet.fan_alarm.act == WARNING_AND_STOP) {
              jump_out_auto_control();
              continue;
            }
          }
        } else {
          FansCardCtrl.fan_pwm[i] = 0;
          FanCardSysDisp.fan_status_on_fan_board_bitfield_0_15 &= ~(1 << i);
        }
      }
    }
    xSemaphoreGive(RS485RegionMutex);
  }
}