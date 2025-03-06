#include "FG_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FG_RPM.h"

TaskHandle_t FGTask_Handler;

FansCardStat_t FansCardStat = {0};

#define MOTOR_PHASE 6
#define Fan_FG_READ_PERIOD 500

FgParam_t Fan1_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_2,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan2_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_11,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan3_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_8,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan4_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_9,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan5_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_4,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan6_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_5,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan7_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_0,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan8_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_1,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan9_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_6,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan10_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_7,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan11_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_10,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan12_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_12,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan13_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_3,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan14_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_13,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan15_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_14,
    .motor_phase = MOTOR_PHASE,
};

FgParam_t Fan16_FG = {
    .timer_count = 3,
    .tmr_list = {TMR11, TMR10, TMR9},
    .exint_line = EXINT_LINE_15,
    .motor_phase = MOTOR_PHASE,
};

void TMR1_BRK_TMR9_IRQHandler(void) {
  if (tmr_flag_get(TMR9, TMR_OVF_FLAG)) {
    tmr_flag_clear(TMR9, TMR_OVF_FLAG);
    FgTimerIntHandler(&Fan1_FG, TMR9);
    FgTimerIntHandler(&Fan2_FG, TMR9);
    FgTimerIntHandler(&Fan3_FG, TMR9);
    FgTimerIntHandler(&Fan4_FG, TMR9);
    FgTimerIntHandler(&Fan5_FG, TMR9);
    FgTimerIntHandler(&Fan6_FG, TMR9);
    FgTimerIntHandler(&Fan7_FG, TMR9);
    FgTimerIntHandler(&Fan8_FG, TMR9);
    FgTimerIntHandler(&Fan9_FG, TMR9);
    FgTimerIntHandler(&Fan10_FG, TMR9);
    FgTimerIntHandler(&Fan11_FG, TMR9);
    FgTimerIntHandler(&Fan12_FG, TMR9);
    FgTimerIntHandler(&Fan13_FG, TMR9);
    FgTimerIntHandler(&Fan14_FG, TMR9);
    FgTimerIntHandler(&Fan15_FG, TMR9);
    FgTimerIntHandler(&Fan16_FG, TMR9);
  }
}

void TMR1_OVF_TMR10_IRQHandler(void) {
  if (tmr_flag_get(TMR10, TMR_OVF_FLAG)) {
    tmr_flag_clear(TMR10, TMR_OVF_FLAG);
    FgTimerIntHandler(&Fan1_FG, TMR10);
    FgTimerIntHandler(&Fan2_FG, TMR10);
    FgTimerIntHandler(&Fan3_FG, TMR10);
    FgTimerIntHandler(&Fan4_FG, TMR10);
    FgTimerIntHandler(&Fan5_FG, TMR10);
    FgTimerIntHandler(&Fan6_FG, TMR10);
    FgTimerIntHandler(&Fan7_FG, TMR10);
    FgTimerIntHandler(&Fan8_FG, TMR10);
    FgTimerIntHandler(&Fan9_FG, TMR10);
    FgTimerIntHandler(&Fan10_FG, TMR10);
    FgTimerIntHandler(&Fan11_FG, TMR10);
    FgTimerIntHandler(&Fan12_FG, TMR10);
    FgTimerIntHandler(&Fan13_FG, TMR10);
    FgTimerIntHandler(&Fan14_FG, TMR10);
    FgTimerIntHandler(&Fan15_FG, TMR10);
    FgTimerIntHandler(&Fan16_FG, TMR10);
  }
}

void TMR1_TRG_HALL_TMR11_IRQHandler(void) {
  if (tmr_flag_get(TMR11, TMR_OVF_FLAG)) {
    tmr_flag_clear(TMR11, TMR_OVF_FLAG);
    FgTimerIntHandler(&Fan1_FG, TMR11);
    FgTimerIntHandler(&Fan2_FG, TMR11);
    FgTimerIntHandler(&Fan3_FG, TMR11);
    FgTimerIntHandler(&Fan4_FG, TMR11);
    FgTimerIntHandler(&Fan5_FG, TMR11);
    FgTimerIntHandler(&Fan6_FG, TMR11);
    FgTimerIntHandler(&Fan7_FG, TMR11);
    FgTimerIntHandler(&Fan8_FG, TMR11);
    FgTimerIntHandler(&Fan9_FG, TMR11);
    FgTimerIntHandler(&Fan10_FG, TMR11);
    FgTimerIntHandler(&Fan11_FG, TMR11);
    FgTimerIntHandler(&Fan12_FG, TMR11);
    FgTimerIntHandler(&Fan13_FG, TMR11);
    FgTimerIntHandler(&Fan14_FG, TMR11);
    FgTimerIntHandler(&Fan15_FG, TMR11);
    FgTimerIntHandler(&Fan16_FG, TMR11);
  }
}

void EXINT0_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_0) != RESET) {
    exint_flag_clear(EXINT_LINE_0);
    FgExintIntSampling(&Fan7_FG);
  }
}

void EXINT1_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_1) != RESET) {
    exint_flag_clear(EXINT_LINE_1);
    FgExintIntSampling(&Fan8_FG);
  }
}

void EXINT2_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_2)) {
    exint_flag_clear(EXINT_LINE_2);
    FgExintIntSampling(&Fan1_FG);
  }
}

void EXINT3_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_3) != RESET) {
    exint_flag_clear(EXINT_LINE_3);
    FgExintIntSampling(&Fan13_FG);
  }
}

void EXINT4_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_4) != RESET) {
    exint_flag_clear(EXINT_LINE_4);
    FgExintIntSampling(&Fan5_FG);
  }
}

void EXINT9_5_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_5) != RESET) {
    exint_flag_clear(EXINT_LINE_5);
    FgExintIntSampling(&Fan6_FG);
  } else if (exint_flag_get(EXINT_LINE_9) != RESET) {
    exint_flag_clear(EXINT_LINE_9);
    FgExintIntSampling(&Fan4_FG);
  } else if (exint_flag_get(EXINT_LINE_8) != RESET) {
    exint_flag_clear(EXINT_LINE_8);
    FgExintIntSampling(&Fan3_FG);
  } else if (exint_flag_get(EXINT_LINE_7) != RESET) {
    exint_flag_clear(EXINT_LINE_7);
    FgExintIntSampling(&Fan10_FG);
  } else if (exint_flag_get(EXINT_LINE_6) != RESET) {
    exint_flag_clear(EXINT_LINE_6);
    FgExintIntSampling(&Fan9_FG);
  }
}

void EXINT15_10_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_10) != RESET) {
    exint_flag_clear(EXINT_LINE_10);
    FgExintIntSampling(&Fan11_FG);
  } else if (exint_flag_get(EXINT_LINE_11) != RESET) {
    exint_flag_clear(EXINT_LINE_11);
    FgExintIntSampling(&Fan2_FG);
  } else if (exint_flag_get(EXINT_LINE_12) != RESET) {
    exint_flag_clear(EXINT_LINE_12);
    FgExintIntSampling(&Fan12_FG);
  } else if (exint_flag_get(EXINT_LINE_13) != RESET) {
    exint_flag_clear(EXINT_LINE_13);
    FgExintIntSampling(&Fan14_FG);
  } else if (exint_flag_get(EXINT_LINE_14) != RESET) {
    exint_flag_clear(EXINT_LINE_14);
    FgExintIntSampling(&Fan15_FG);
  } else if (exint_flag_get(EXINT_LINE_15) != RESET) {
    exint_flag_clear(EXINT_LINE_15);
    FgExintIntSampling(&Fan16_FG);
  }
}

void FG_task_function(void* parameter) {
  TickType_t xLastWakeTime = xTaskGetTickCount();

  FgInit(&Fan1_FG);
  FgInit(&Fan2_FG);
  FgInit(&Fan3_FG);
  FgInit(&Fan4_FG);
  FgInit(&Fan5_FG);
  FgInit(&Fan6_FG);
  FgInit(&Fan7_FG);
  FgInit(&Fan8_FG);
  FgInit(&Fan9_FG);
  FgInit(&Fan10_FG);
  FgInit(&Fan11_FG);
  FgInit(&Fan12_FG);
  FgInit(&Fan13_FG);
  FgInit(&Fan14_FG);
  FgInit(&Fan15_FG);
  FgInit(&Fan16_FG);

  while (1) {
    vTaskDelayUntil(&xLastWakeTime, Fan_FG_READ_PERIOD);

    FgGetRPM(&Fan1_FG, &FansCardStat.fan1_fb);
    FgGetRPM(&Fan2_FG, &FansCardStat.fan2_fb);
    FgGetRPM(&Fan3_FG, &FansCardStat.fan3_fb);
    FgGetRPM(&Fan4_FG, &FansCardStat.fan4_fb);
    FgGetRPM(&Fan5_FG, &FansCardStat.fan5_fb);
    FgGetRPM(&Fan6_FG, &FansCardStat.fan6_fb);
    FgGetRPM(&Fan7_FG, &FansCardStat.fan7_fb);
    FgGetRPM(&Fan8_FG, &FansCardStat.fan8_fb);
    FgGetRPM(&Fan9_FG, &FansCardStat.fan9_fb);
    FgGetRPM(&Fan10_FG, &FansCardStat.fan10_fb);
    FgGetRPM(&Fan11_FG, &FansCardStat.fan11_fb);
    FgGetRPM(&Fan12_FG, &FansCardStat.fan12_fb);
    FgGetRPM(&Fan13_FG, &FansCardStat.fan13_fb);
    FgGetRPM(&Fan14_FG, &FansCardStat.fan14_fb);
    FgGetRPM(&Fan15_FG, &FansCardStat.fan15_fb);
    FgGetRPM(&Fan16_FG, &FansCardStat.fan16_fb);
  }
  vTaskDelete(NULL);
}