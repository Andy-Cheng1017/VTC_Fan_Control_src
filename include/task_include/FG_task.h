#ifndef FG_TASK_H
#define FG_TASK_H

#include "FreeRTOS.h"
#include "task.h"


extern TaskHandle_t FGTask_Handler;

typedef struct {
  uint16_t fan1_fb;  // 0x0080
  uint16_t fan2_fb;
  uint16_t fan3_fb;
  uint16_t fan4_fb;
  uint16_t fan5_fb;
  uint16_t fan6_fb;
  uint16_t fan7_fb;
  uint16_t fan8_fb;
  uint16_t fan9_fb;
  uint16_t fan10_fb;
  uint16_t fan11_fb;
  uint16_t fan12_fb;
  uint16_t fan13_fb;
  uint16_t fan14_fb;
  uint16_t fan15_fb;
  uint16_t fan16_fb;  // 0x008F
} FansCardStat_t;

extern FansCardStat_t FansCardStat;

void FG_task_function(void* parameter);

#endif