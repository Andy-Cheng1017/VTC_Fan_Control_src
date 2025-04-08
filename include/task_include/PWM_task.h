#ifndef PWM_TASK_H
#define PWM_TASK_H

#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t PWMTask_Handler;

typedef struct {
  uint16_t fan_pwm[16];
} FansCardCtrl_t;

extern FansCardCtrl_t FansCardCtrl;

void PWM_task_function(void* parameter);

#endif