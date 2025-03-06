#include "PWM_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Duty_PWM.h"

#define PWM_WRITE_PERIOD 500

TaskHandle_t PWMTask_Handler;

FansCardCtrl_t FansCardCtrl = {0};

PwmParam_t Fan1_PWM = {
    .channel = TMR_SELECT_CHANNEL_3,
    .tmr_x = TMR2,
    .tmr_period_val = 59999,
};

PwmParam_t Fan2_PWM = {
    .channel = TMR_SELECT_CHANNEL_1,
    .tmr_x = TMR1,
    .tmr_period_val = 59999,
};

PwmParam_t Fan3_PWM = {
    .channel = TMR_SELECT_CHANNEL_2,
    .tmr_x = TMR1,
    .tmr_period_val = 59999,
};

PwmParam_t Fan4_PWM = {
    .channel = TMR_SELECT_CHANNEL_3,
    .tmr_x = TMR1,
    .tmr_period_val = 59999,
};

PwmParam_t Fan5_PWM = {
    .channel = TMR_SELECT_CHANNEL_1,
    .tmr_x = TMR5,
    .tmr_period_val = 59999,
};

PwmParam_t Fan6_PWM = {
    .channel = TMR_SELECT_CHANNEL_2,
    .tmr_x = TMR5,
    .tmr_period_val = 59999,
};

PwmParam_t Fan7_PWM = {
    .channel = TMR_SELECT_CHANNEL_3,
    .tmr_x = TMR5,
    .tmr_period_val = 59999,
};

PwmParam_t Fan8_PWM = {
    .channel = TMR_SELECT_CHANNEL_4,
    .tmr_x = TMR5,
    .tmr_period_val = 59999,
};

PwmParam_t Fan9_PWM = {
    .channel = TMR_SELECT_CHANNEL_1,
    .tmr_x = TMR2,
    .tmr_period_val = 59999,
};

PwmParam_t Fan10_PWM = {
    .channel = TMR_SELECT_CHANNEL_2,
    .tmr_x = TMR3,
    .tmr_period_val = 59999,
};

PwmParam_t Fan11_PWM = {
    .channel = TMR_SELECT_CHANNEL_1,
    .tmr_x = TMR3,
    .tmr_period_val = 59999,
};

PwmParam_t Fan12_PWM = {
    .channel = TMR_SELECT_CHANNEL_4,
    .tmr_x = TMR1,
    .tmr_period_val = 59999,
};

PwmParam_t Fan13_PWM = {
    .channel = TMR_SELECT_CHANNEL_1,
    .tmr_x = TMR4,
    .tmr_period_val = 59999,
};

PwmParam_t Fan14_PWM = {
    .channel = TMR_SELECT_CHANNEL_2,
    .tmr_x = TMR4,
    .tmr_period_val = 59999,
};

PwmParam_t Fan15_PWM = {
    .channel = TMR_SELECT_CHANNEL_3,
    .tmr_x = TMR4,
    .tmr_period_val = 59999,
};

PwmParam_t Fan16_PWM = {
    .channel = TMR_SELECT_CHANNEL_4,
    .tmr_x = TMR4,
    .tmr_period_val = 59999,
};

void PWM_task_function(void* parameter) {
  TickType_t xLastWakeTime = xTaskGetTickCount();

  PwmInit(&Fan1_PWM);
  PwmInit(&Fan2_PWM);
  PwmInit(&Fan3_PWM);
  PwmInit(&Fan4_PWM);
  PwmInit(&Fan5_PWM);
  PwmInit(&Fan6_PWM);
  PwmInit(&Fan7_PWM);
  PwmInit(&Fan8_PWM);
  PwmInit(&Fan9_PWM);
  PwmInit(&Fan10_PWM);
  PwmInit(&Fan11_PWM);
  PwmInit(&Fan12_PWM);
  PwmInit(&Fan13_PWM);
  PwmInit(&Fan14_PWM);
  PwmInit(&Fan15_PWM);
  PwmInit(&Fan16_PWM);

  while (1) {
    // vTaskDelay(PWM_WRITE_PERIOD);
    vTaskDelayUntil(&xLastWakeTime, PWM_WRITE_PERIOD);
    PwmSetDuty(&Fan1_PWM, FansCardCtrl.fan1_duty);
    PwmSetDuty(&Fan2_PWM, FansCardCtrl.fan2_duty);
    PwmSetDuty(&Fan3_PWM, FansCardCtrl.fan3_duty);
    PwmSetDuty(&Fan4_PWM, FansCardCtrl.fan4_duty);
    PwmSetDuty(&Fan5_PWM, FansCardCtrl.fan5_duty);
    PwmSetDuty(&Fan6_PWM, FansCardCtrl.fan6_duty);
    PwmSetDuty(&Fan7_PWM, FansCardCtrl.fan7_duty);
    PwmSetDuty(&Fan8_PWM, FansCardCtrl.fan8_duty);
    PwmSetDuty(&Fan9_PWM, FansCardCtrl.fan9_duty);
    PwmSetDuty(&Fan10_PWM, FansCardCtrl.fan10_duty);
    PwmSetDuty(&Fan11_PWM, FansCardCtrl.fan11_duty);
    PwmSetDuty(&Fan12_PWM, FansCardCtrl.fan12_duty);
    PwmSetDuty(&Fan13_PWM, FansCardCtrl.fan13_duty);
    PwmSetDuty(&Fan14_PWM, FansCardCtrl.fan14_duty);
    PwmSetDuty(&Fan15_PWM, FansCardCtrl.fan15_duty);
    PwmSetDuty(&Fan16_PWM, FansCardCtrl.fan16_duty);
  }
  vTaskDelete(NULL);
}