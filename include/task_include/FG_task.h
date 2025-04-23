#ifndef FG_TASK_H
#define FG_TASK_H

#include "FreeRTOS.h"
#include "task.h"

#define FG_SAMPLE_COUNT_MAX 32

extern TaskHandle_t FGTask_Handler;
typedef struct {
  uint16_t fan_fg[16];  // 0x0080
} FansCardStat_t;

extern FansCardStat_t FansCardStat;

void FG_task_function(void* parameter);

#endif