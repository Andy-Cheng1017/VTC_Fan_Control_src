#ifndef __RS485_REGION_H_
#define __RS485_REGION_H_
#include "RS485.h"
#include "PWM_task.h"
#include "FG_task.h"

uint32_t FansCardHdle(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root);

#endif  // __RS485_REGION_H_