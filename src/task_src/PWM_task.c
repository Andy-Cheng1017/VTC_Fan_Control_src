#include "PWM_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Duty_PWM.h"

#define PWM_WRITE_PERIOD 200

#define PWM_MIN_DUTY 100
#define PWM_MAX_DUTY 1000

TaskHandle_t PWMTask_Handler;

FansCardCtrl_t FansCardCtrl = {0};

PwmParam_t Fan_PWM[16] = {
    [0] =
        {
            .channel = TMR_SELECT_CHANNEL_3,
            .tmr_x = TMR2,
            .tmr_period_val = 59999,
        },
    [1] =
        {
            .channel = TMR_SELECT_CHANNEL_1,
            .tmr_x = TMR1,
            .tmr_period_val = 59999,
        },
    [2] =
        {
            .channel = TMR_SELECT_CHANNEL_2,
            .tmr_x = TMR1,
            .tmr_period_val = 59999,
        },
    [3] =
        {
            .channel = TMR_SELECT_CHANNEL_3,
            .tmr_x = TMR1,
            .tmr_period_val = 59999,
        },
    [4] =
        {
            .channel = TMR_SELECT_CHANNEL_1,
            .tmr_x = TMR5,
            .tmr_period_val = 59999,
        },
    [5] =
        {
            .channel = TMR_SELECT_CHANNEL_2,
            .tmr_x = TMR5,
            .tmr_period_val = 59999,
        },
    [6] =
        {
            .channel = TMR_SELECT_CHANNEL_3,
            .tmr_x = TMR5,
            .tmr_period_val = 59999,
        },
    [7] =
        {
            .channel = TMR_SELECT_CHANNEL_4,
            .tmr_x = TMR5,
            .tmr_period_val = 59999,
        },
    [8] =
        {
            .channel = TMR_SELECT_CHANNEL_1,
            .tmr_x = TMR2,
            .tmr_period_val = 59999,
        },
    [9] =
        {
            .channel = TMR_SELECT_CHANNEL_2,
            .tmr_x = TMR3,
            .tmr_period_val = 59999,
        },
    [10] =
        {
            .channel = TMR_SELECT_CHANNEL_1,
            .tmr_x = TMR3,
            .tmr_period_val = 59999,
        },
    [11] =
        {
            .channel = TMR_SELECT_CHANNEL_4,
            .tmr_x = TMR1,
            .tmr_period_val = 59999,
        },
    [12] =
        {
            .channel = TMR_SELECT_CHANNEL_1,
            .tmr_x = TMR4,
            .tmr_period_val = 59999,
        },
    [13] =
        {
            .channel = TMR_SELECT_CHANNEL_2,
            .tmr_x = TMR4,
            .tmr_period_val = 59999,
        },
    [14] =
        {
            .channel = TMR_SELECT_CHANNEL_3,
            .tmr_x = TMR4,
            .tmr_period_val = 59999,
        },
    [15] =
        {
            .channel = TMR_SELECT_CHANNEL_4,
            .tmr_x = TMR4,
            .tmr_period_val = 59999,
        },
};

void PWM_task_function(void* parameter) {
  TickType_t xLastWakeTime = xTaskGetTickCount();

  for (int i = 0; i < 16; i++) {
    PwmInit(&Fan_PWM[i]);
  }

  while (1) {
    vTaskDelayUntil(&xLastWakeTime, PWM_WRITE_PERIOD);

    for (int i = 0; i < 16; i++) {
      if (FansCardCtrl.fan_pwm[i] < PWM_MIN_DUTY && FansCardCtrl.fan_pwm[i] != 0) {
        FansCardCtrl.fan_pwm[i] = PWM_MIN_DUTY;
      } else if (FansCardCtrl.fan_pwm[i] > PWM_MAX_DUTY) {
        FansCardCtrl.fan_pwm[i] = PWM_MAX_DUTY;
      }
      PwmSetDuty(&Fan_PWM[i], FansCardCtrl.fan_pwm[i]);
    }
  }
  vTaskDelete(NULL);
}
