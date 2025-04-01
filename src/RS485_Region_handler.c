#include "RS485_Region_handler.h"
#include "PWM_task.h"
#include "FG_task.h"

uint32_t FansCardHdle(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root) {
  if (func == READ_HOLDING_REGISTERS) {
    switch (addr) {
      case 0x0100:
        return FansCardStat.fan1_fb & 0xFFFF;
      case 0x0101:
        return FansCardStat.fan2_fb & 0xFFFF;
      case 0x0102:
        return FansCardStat.fan3_fb & 0xFFFF;
      case 0x0103:
        return FansCardStat.fan4_fb & 0xFFFF;
      case 0x0104:
        return FansCardStat.fan5_fb & 0xFFFF;
      case 0x0105:
        return FansCardStat.fan6_fb & 0xFFFF;
      case 0x0106:
        return FansCardStat.fan7_fb & 0xFFFF;
      case 0x0107:
        return FansCardStat.fan8_fb & 0xFFFF;
      case 0x0108:
        return FansCardStat.fan9_fb & 0xFFFF;
      case 0x0109:
        return FansCardStat.fan10_fb & 0xFFFF;
      case 0x010A:
        return FansCardStat.fan11_fb & 0xFFFF;
      case 0x010B:
        return FansCardStat.fan12_fb & 0xFFFF;
      case 0x010C:
        return FansCardStat.fan13_fb & 0xFFFF;
      case 0x010D:
        return FansCardStat.fan14_fb & 0xFFFF;
      case 0x010E:
        return FansCardStat.fan15_fb & 0xFFFF;
      case 0x010F:
        return FansCardStat.fan16_fb & 0xFFFF;
      case 0x0110:
        return FansCardCtrl.fan1_duty & 0xFFFF;
      case 0x0111:
        return FansCardCtrl.fan2_duty & 0xFFFF;
      case 0x0112:
        return FansCardCtrl.fan3_duty & 0xFFFF;
      case 0x0113:
        return FansCardCtrl.fan4_duty & 0xFFFF;
      case 0x0114:
        return FansCardCtrl.fan5_duty & 0xFFFF;
      case 0x0115:
        return FansCardCtrl.fan6_duty & 0xFFFF;
      case 0x0116:
        return FansCardCtrl.fan7_duty & 0xFFFF;
      case 0x0117:
        return FansCardCtrl.fan8_duty & 0xFFFF;
      case 0x0118:
        return FansCardCtrl.fan9_duty & 0xFFFF;
      case 0x0119:
        return FansCardCtrl.fan10_duty & 0xFFFF;
      case 0x011A:
        return FansCardCtrl.fan11_duty & 0xFFFF;
      case 0x011B:
        return FansCardCtrl.fan12_duty & 0xFFFF;
      case 0x011C:
        return FansCardCtrl.fan13_duty & 0xFFFF;
      case 0x011D:
        return FansCardCtrl.fan14_duty & 0xFFFF;
      case 0x011E:
        return FansCardCtrl.fan15_duty & 0xFFFF;
      case 0x011F:
        return FansCardCtrl.fan16_duty & 0xFFFF;
      default:
        return ILLIGAL_DATA_ADDR << 16;
    }
  } else if (func == WRITE_SINGLE_REGISTER || func == WRITE_MULTIPLE_REGISTERS) {
    if (addr >= 0x0100 && addr <= 0x010F) {
      if (root) {
        switch (addr) {
          case 0x0100:
            return FansCardStat.fan1_fb = data;
          case 0x0101:
            return FansCardStat.fan2_fb = data;
          case 0x0102:
            return FansCardStat.fan3_fb = data;
          case 0x0103:
            return FansCardStat.fan4_fb = data;
          case 0x0104:
            return FansCardStat.fan5_fb = data;
          case 0x0105:
            return FansCardStat.fan6_fb = data;
          case 0x0106:
            return FansCardStat.fan7_fb = data;
          case 0x0107:
            return FansCardStat.fan8_fb = data;
          case 0x0108:
            return FansCardStat.fan9_fb = data;
          case 0x0109:
            return FansCardStat.fan10_fb = data;
          case 0x010A:
            return FansCardStat.fan11_fb = data;
          case 0x010B:
            return FansCardStat.fan12_fb = data;
          case 0x010C:
            return FansCardStat.fan13_fb = data;
          case 0x010D:
            return FansCardStat.fan14_fb = data;
          case 0x010E:
            return FansCardStat.fan15_fb = data;
          case 0x010F:
            return FansCardStat.fan16_fb = data;
          default:
            return ILLIGAL_DATA_ADDR << 16;
        }
      } else {
        return ILLIGAL_FUNC << 16;
      }
    } else if (addr >= 0x0110 && addr <= 0x011F) {
      if (data >= 0 && data <= 1000) {
        switch (addr) {
          case 0x0110:
            return FansCardCtrl.fan1_duty = data;
          case 0x0111:
            return FansCardCtrl.fan2_duty = data;
          case 0x0112:
            return FansCardCtrl.fan3_duty = data;
          case 0x0113:
            return FansCardCtrl.fan4_duty = data;
          case 0x0114:
            return FansCardCtrl.fan5_duty = data;
          case 0x0115:
            return FansCardCtrl.fan6_duty = data;
          case 0x0116:
            return FansCardCtrl.fan7_duty = data;
          case 0x0117:
            return FansCardCtrl.fan8_duty = data;
          case 0x0118:
            return FansCardCtrl.fan9_duty = data;
          case 0x0119:
            return FansCardCtrl.fan10_duty = data;
          case 0x011A:
            return FansCardCtrl.fan11_duty = data;
          case 0x011B:
            return FansCardCtrl.fan12_duty = data;
          case 0x011C:
            return FansCardCtrl.fan13_duty = data;
          case 0x011D:
            return FansCardCtrl.fan14_duty = data;
          case 0x011E:
            return FansCardCtrl.fan15_duty = data;
          case 0x011F:
            return FansCardCtrl.fan16_duty = data;
          default:
            return ILLIGAL_DATA_ADDR << 16;
        }
      } else {
        return ILLIGAL_FUNC << 16;
      }
    } else {
      return ILLIGAL_DATA_ADDR << 16;
    }
  } else {
    return ILLIGAL_DATA_VALUE << 16;
  }
}