#ifndef __RS485_REGION_H_
#define __RS485_REGION_H_
#include <stdint.h>
#include "RS485.h"

#define FANS_CARD_REG_START 0x00A0
#define FANS_CARD_REG_END 0x00BF
#define FANS_CARD_TOTAL_REG_NUM (FANS_CARD_REG_END - FANS_CARD_REG_START + 1)

#define FANS_CARD_WRITE_REG_START 0x00AF
#define FANS_CARD_WRITE_REG_END 0x00BF
#define FANS_CARD_WRITE_NUM (FANS_CARD_WRITE_REG_END - FANS_CARD_WRITE_REG_START + 1)

uint32_t FansCardHdle(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root);

#endif  // __RS485_REGION_H_