#ifndef FAN_MAIN_TASK_H
#define FAN_MAIN_TASK_H

#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t FanMainTask_Handler;

typedef enum {
  ONLY_WARNING,
  WARNING_AND_STOP,
} AlarmAction_t;

typedef struct {
  AlarmAction_t act;
  int16_t delay;
  uint16_t fan_low_speed_warning_threshold;
  uint16_t fan_fg_difference_warning_threshold;
} FanAlarm_t;

typedef struct {
  bool auto_control;
  uint16_t auto_control_target_speed;
  uint16_t fan_installation_status;

  FanAlarm_t fan_alarm;

} FanCardSysSet_t;

extern FanCardSysSet_t FanCardSysSet;

typedef struct {
  uint16_t fan_board_fault_status;
  uint16_t fan_status_on_fan_board_bitfield_0_15;

} FanCardSysDisp_t;

extern FanCardSysDisp_t FanCardSysDisp;

void fan_main_task_function(void* pvParameters);

#endif /* FAN_MAIN_TASK_H */
