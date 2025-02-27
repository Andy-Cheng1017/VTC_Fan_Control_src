#ifndef PWM_TASK_H
#define PWM_TASK_H

#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t PWMTask_Handler;

typedef struct {
  uint16_t fan1_duty;  // 0x0090
  uint16_t fan2_duty;
  uint16_t fan3_duty;
  uint16_t fan4_duty;
  uint16_t fan5_duty;
  uint16_t fan6_duty;
  uint16_t fan7_duty;
  uint16_t fan8_duty;
  uint16_t fan9_duty;
  uint16_t fan10_duty;
  uint16_t fan11_duty;
  uint16_t fan12_duty;
  uint16_t fan13_duty;
  uint16_t fan14_duty;
  uint16_t fan15_duty;
  uint16_t fan16_duty;  // 0x009F
} FansCardCtrl_t;

extern FansCardCtrl_t FansCardCtrl;

void PWM_task_function(void* parameter);

#endif