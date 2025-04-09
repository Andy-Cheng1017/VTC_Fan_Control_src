#ifndef __RS485_REGION_H_
#define __RS485_REGION_H_
#include <stdbool.h>
#include <stdint.h>
#include "RS485_enum.h"

#define FANS_CARD_REG_START 0x00A0
#define FANS_CARD_REG_END 0x00BF
#define FANS_CARD_TOTAL_REG_NUM (FANS_CARD_REG_END - FANS_CARD_REG_START + 1)

#define FANS_CARD_WRITE_REG_START 0x00B0
#define FANS_CARD_WRITE_REG_END 0x00BF
#define FANS_CARD_WRITE_NUM (FANS_CARD_WRITE_REG_END - FANS_CARD_WRITE_REG_START + 1)

#define FANS_CARD_SYS_SET_REG_START 0x00D0
#define FANS_CARD_SYS_SET_REG_END 0x00DF
#define FANS_CARD_SYS_SET_NUM (FANS_CARD_SYS_SET_REG_END - FANS_CARD_SYS_SET_REG_START + 1)

#define FANS_CARD_SYS_DISP_REG_START 0x00E0
#define FANS_CARD_SYS_DISP_REG_END 0x00EF
#define FANS_CARD_SYS_DISP_NUM (FANS_CARD_SYS_DISP_REG_END - FANS_CARD_SYS_DISP_REG_START + 1)

uint32_t FansCard_Handler(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root);
uint32_t FanCardSysSet_Handler(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root);
uint32_t FanCardSysDisp_Handler(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root);

#endif  // __RS485_REGION_H_