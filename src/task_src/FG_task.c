#include "FG_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FG_RPM.h"
#include "main.h"


#define SAMPLE_COUNT 8
#define MAX_BUF_MASK (SAMPLE_COUNT - 1)
#define UPDATE_IDX(idx) ((idx) = (((idx) + 1) & MAX_BUF_MASK))

TaskHandle_t FGTask_Handler;

FansCardStat_t FansCardStat = {0};

#define MOTOR_PHASE 2
#define Fan_FG_READ_PERIOD 20

FgParam_t Fan_FG[16] = {
    [0] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_2,
            .motor_phase = MOTOR_PHASE,
        },
    [1] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_11,
            .motor_phase = MOTOR_PHASE,
        },
    [2] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_8,
            .motor_phase = MOTOR_PHASE,
        },
    [3] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_9,
            .motor_phase = MOTOR_PHASE,
        },
    [4] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_4,
            .motor_phase = MOTOR_PHASE,
        },
    [5] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_5,
            .motor_phase = MOTOR_PHASE,
        },
    [6] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_0,
            .motor_phase = MOTOR_PHASE,
        },
    [7] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_1,
            .motor_phase = MOTOR_PHASE,
        },
    [8] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_6,
            .motor_phase = MOTOR_PHASE,
        },
    [9] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_7,
            .motor_phase = MOTOR_PHASE,
        },
    [10] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_10,
            .motor_phase = MOTOR_PHASE,
        },
    [11] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_12,
            .motor_phase = MOTOR_PHASE,
        },
    [12] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_3,
            .motor_phase = MOTOR_PHASE,
        },
    [13] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_13,
            .motor_phase = MOTOR_PHASE,
        },
    [14] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_14,
            .motor_phase = MOTOR_PHASE,
        },
    [15] =
        {
            .tmr_list = {TMR11, TMR10, TMR9},
            .timer_count = 3,
            .exint_line = EXINT_LINE_15,
            .motor_phase = MOTOR_PHASE,
        },
};

void TMR1_BRK_TMR9_IRQHandler(void) {
  if (tmr_flag_get(TMR9, TMR_OVF_FLAG)) {
    tmr_flag_clear(TMR9, TMR_OVF_FLAG);
    for (int i = 0; i < 16; i++) {
      FgTimerIntHandler(&Fan_FG[i], TMR9);
    }
  }
}

void TMR1_OVF_TMR10_IRQHandler(void) {
  if (tmr_flag_get(TMR10, TMR_OVF_FLAG)) {
    tmr_flag_clear(TMR10, TMR_OVF_FLAG);
    for (int i = 0; i < 16; i++) {
      FgTimerIntHandler(&Fan_FG[i], TMR10);
    }
  }
}

void TMR1_TRG_HALL_TMR11_IRQHandler(void) {
  if (tmr_flag_get(TMR11, TMR_OVF_FLAG)) {
    tmr_flag_clear(TMR11, TMR_OVF_FLAG);
    for (int i = 0; i < 16; i++) {
      FgTimerIntHandler(&Fan_FG[i], TMR11);
    }
  }
}

void EXINT0_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_0) != RESET) {
    exint_flag_clear(EXINT_LINE_0);
    FgExintIntSampling(&Fan_FG[6]);
  }
}

void EXINT1_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_1) != RESET) {
    exint_flag_clear(EXINT_LINE_1);
    FgExintIntSampling(&Fan_FG[7]);
  }
}

void EXINT2_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_2)) {
    exint_flag_clear(EXINT_LINE_2);
    FgExintIntSampling(&Fan_FG[0]);
  }
}

void EXINT3_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_3) != RESET) {
    exint_flag_clear(EXINT_LINE_3);
    FgExintIntSampling(&Fan_FG[12]);
  }
}

void EXINT4_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_4) != RESET) {
    exint_flag_clear(EXINT_LINE_4);
    FgExintIntSampling(&Fan_FG[4]);
  }
}

void EXINT9_5_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_5) != RESET) {
    exint_flag_clear(EXINT_LINE_5);
    FgExintIntSampling(&Fan_FG[5]);
  } else if (exint_flag_get(EXINT_LINE_9) != RESET) {
    exint_flag_clear(EXINT_LINE_9);
    FgExintIntSampling(&Fan_FG[3]);
  } else if (exint_flag_get(EXINT_LINE_8) != RESET) {
    exint_flag_clear(EXINT_LINE_8);
    FgExintIntSampling(&Fan_FG[2]);
  } else if (exint_flag_get(EXINT_LINE_7) != RESET) {
    exint_flag_clear(EXINT_LINE_7);
    FgExintIntSampling(&Fan_FG[9]);
  } else if (exint_flag_get(EXINT_LINE_6) != RESET) {
    exint_flag_clear(EXINT_LINE_6);
    FgExintIntSampling(&Fan_FG[8]);
  }
}

void EXINT15_10_IRQHandler(void) {
  if (exint_flag_get(EXINT_LINE_10) != RESET) {
    exint_flag_clear(EXINT_LINE_10);
    FgExintIntSampling(&Fan_FG[10]);
  } else if (exint_flag_get(EXINT_LINE_11) != RESET) {
    exint_flag_clear(EXINT_LINE_11);
    FgExintIntSampling(&Fan_FG[1]);
  } else if (exint_flag_get(EXINT_LINE_12) != RESET) {
    exint_flag_clear(EXINT_LINE_12);
    FgExintIntSampling(&Fan_FG[11]);
  } else if (exint_flag_get(EXINT_LINE_13) != RESET) {
    exint_flag_clear(EXINT_LINE_13);
    FgExintIntSampling(&Fan_FG[13]);
  } else if (exint_flag_get(EXINT_LINE_14) != RESET) {
    exint_flag_clear(EXINT_LINE_14);
    FgExintIntSampling(&Fan_FG[14]);
  } else if (exint_flag_get(EXINT_LINE_15) != RESET) {
    exint_flag_clear(EXINT_LINE_15);
    FgExintIntSampling(&Fan_FG[15]);
  }
}

uint16_t sample_fg[16][SAMPLE_COUNT] = {0};
uint8_t sample_index = {0};

void FG_task_function(void* parameter) {
  TickType_t Calu_FG_Tick;

  for (int i = 0; i < 16; i++) {
    FgInit(&Fan_FG[i]);
  }

  while (1) {
    for (int i = 0; i < 16; i++) {
      xSemaphoreTake(RS485RegionMutex, RS485_SEMAPHORE_TIMEOUT);
      FgGetRPM(&Fan_FG[i], &sample_fg[i][sample_index]);
      xSemaphoreGive(RS485RegionMutex);
      vTaskDelay(Fan_FG_READ_PERIOD);
    }
    UPDATE_IDX(sample_index);

    if(xTaskGetTickCount() - Calu_FG_Tick > pdMS_TO_TICKS(500)){
      for (int i = 0; i < 16; i++) {
        uint32_t sum = 0;
        for (int j = 0; j < SAMPLE_COUNT; j++) {
          sum += sample_fg[i][j];
        }
        FansCardStat.fan_fg[i] = sum >> 3;
      }
      Calu_FG_Tick = xTaskGetTickCount();
    }


  }
  vTaskDelete(NULL);
}
