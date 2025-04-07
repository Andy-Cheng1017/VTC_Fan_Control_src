#include "RS485_Region_handler.h"
#include "PWM_task.h"
#include "FG_task.h"

typedef enum {
  FAN_1_FEEDBACK = FANS_CARD_REG_START,
  FAN_2_FEEDBACK,
  FAN_3_FEEDBACK,
  FAN_4_FEEDBACK,
  FAN_5_FEEDBACK,
  FAN_6_FEEDBACK,
  FAN_7_FEEDBACK,
  FAN_8_FEEDBACK,
  FAN_9_FEEDBACK,
  FAN_10_FEEDBACK,
  FAN_11_FEEDBACK,
  FAN_12_FEEDBACK,
  FAN_13_FEEDBACK,
  FAN_14_FEEDBACK,
  FAN_15_FEEDBACK,
  FAN_16_FEEDBACK,
  FAN_1_DUTY,
  FAN_2_DUTY,
  FAN_3_DUTY,
  FAN_4_DUTY,
  FAN_5_DUTY,
  FAN_6_DUTY,
  FAN_7_DUTY,
  FAN_8_DUTY,
  FAN_9_DUTY,
  FAN_10_DUTY,
  FAN_11_DUTY,
  FAN_12_DUTY,
  FAN_13_DUTY,
  FAN_14_DUTY,
  FAN_15_DUTY,
  FAN_16_DUTY,
} FansCardCase_t;

uint32_t FansCardHdle(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root) {
  if (func == READ_HOLDING_REGISTERS) {
    switch (addr) {
      case FAN_1_FEEDBACK:
        return FansCardStat.fan_fb[0] & 0xFFFF;
      case FAN_2_FEEDBACK:
        return FansCardStat.fan_fb[1] & 0xFFFF;
      case FAN_3_FEEDBACK:
        return FansCardStat.fan_fb[2] & 0xFFFF;
      case FAN_4_FEEDBACK:
        return FansCardStat.fan_fb[3] & 0xFFFF;
      case FAN_5_FEEDBACK:
        return FansCardStat.fan_fb[4] & 0xFFFF;
      case FAN_6_FEEDBACK:
        return FansCardStat.fan_fb[5] & 0xFFFF;
      case FAN_7_FEEDBACK:
        return FansCardStat.fan_fb[6] & 0xFFFF;
      case FAN_8_FEEDBACK:
        return FansCardStat.fan_fb[7] & 0xFFFF;
      case FAN_9_FEEDBACK:
        return FansCardStat.fan_fb[8] & 0xFFFF;
      case FAN_10_FEEDBACK:
        return FansCardStat.fan_fb[9] & 0xFFFF;
      case FAN_11_FEEDBACK:
        return FansCardStat.fan_fb[10] & 0xFFFF;
      case FAN_12_FEEDBACK:
        return FansCardStat.fan_fb[11] & 0xFFFF;
      case FAN_13_FEEDBACK:
        return FansCardStat.fan_fb[12] & 0xFFFF;
      case FAN_14_FEEDBACK:
        return FansCardStat.fan_fb[13] & 0xFFFF;
      case FAN_15_FEEDBACK:
        return FansCardStat.fan_fb[14] & 0xFFFF;
      case FAN_16_FEEDBACK:
        return FansCardStat.fan_fb[15] & 0xFFFF;
      case FAN_1_DUTY:
        return FansCardCtrl.fan_duty[0] & 0xFFFF;
      case FAN_2_DUTY:
        return FansCardCtrl.fan_duty[1] & 0xFFFF;
      case FAN_3_DUTY:
        return FansCardCtrl.fan_duty[2] & 0xFFFF;
      case FAN_4_DUTY:
        return FansCardCtrl.fan_duty[3] & 0xFFFF;
      case FAN_5_DUTY:
        return FansCardCtrl.fan_duty[4] & 0xFFFF;
      case FAN_6_DUTY:
        return FansCardCtrl.fan_duty[5] & 0xFFFF;
      case FAN_7_DUTY:
        return FansCardCtrl.fan_duty[6] & 0xFFFF;
      case FAN_8_DUTY:
        return FansCardCtrl.fan_duty[7] & 0xFFFF;
      case FAN_9_DUTY:
        return FansCardCtrl.fan_duty[8] & 0xFFFF;
      case FAN_10_DUTY:
        return FansCardCtrl.fan_duty[9] & 0xFFFF;
      case FAN_11_DUTY:
        return FansCardCtrl.fan_duty[10] & 0xFFFF;
      case FAN_12_DUTY:
        return FansCardCtrl.fan_duty[11] & 0xFFFF;
      case FAN_13_DUTY:
        return FansCardCtrl.fan_duty[12] & 0xFFFF;
      case FAN_14_DUTY:
        return FansCardCtrl.fan_duty[13] & 0xFFFF;
      case FAN_15_DUTY:
        return FansCardCtrl.fan_duty[14] & 0xFFFF;
      case FAN_16_DUTY:
        return FansCardCtrl.fan_duty[15] & 0xFFFF;
      default:
        return 0;
    }
  } else if (func == WRITE_SINGLE_REGISTER || func == WRITE_MULTIPLE_REGISTERS) {
    if (addr >= FAN_1_DUTY && addr <= FAN_16_DUTY) {
      if (data >= 0 && data <= 1000) {
        switch (addr) {
          case FAN_1_DUTY:
            return (FansCardCtrl.fan_duty[0] = data) & 0xFFFF;
          case FAN_2_DUTY:
            return (FansCardCtrl.fan_duty[1] = data) & 0xFFFF;
          case FAN_3_DUTY:
            return (FansCardCtrl.fan_duty[2] = data) & 0xFFFF;
          case FAN_4_DUTY:
            return (FansCardCtrl.fan_duty[3] = data) & 0xFFFF;
          case FAN_5_DUTY:
            return (FansCardCtrl.fan_duty[4] = data) & 0xFFFF;
          case FAN_6_DUTY:
            return (FansCardCtrl.fan_duty[5] = data) & 0xFFFF;
          case FAN_7_DUTY:
            return (FansCardCtrl.fan_duty[6] = data) & 0xFFFF;
          case FAN_8_DUTY:
            return (FansCardCtrl.fan_duty[7] = data) & 0xFFFF;
          case FAN_9_DUTY:
            return (FansCardCtrl.fan_duty[8] = data) & 0xFFFF;
          case FAN_10_DUTY:
            return (FansCardCtrl.fan_duty[9] = data) & 0xFFFF;
          case FAN_11_DUTY:
            return (FansCardCtrl.fan_duty[10] = data) & 0xFFFF;
          case FAN_12_DUTY:
            return (FansCardCtrl.fan_duty[11] = data) & 0xFFFF;
          case FAN_13_DUTY:
            return (FansCardCtrl.fan_duty[12] = data) & 0xFFFF;
          case FAN_14_DUTY:
            return (FansCardCtrl.fan_duty[13] = data) & 0xFFFF;
          case FAN_15_DUTY:
            return (FansCardCtrl.fan_duty[14] = data) & 0xFFFF;
          case FAN_16_DUTY:
            return (FansCardCtrl.fan_duty[15] = data) & 0xFFFF;
          default:
            return ILLIGAL_DATA_ADDR << 16;
        }
      } else {
        return ILLIGAL_DATA_VALUE << 16;
      }
    } else {
      return ILLIGAL_DATA_ADDR << 16;
    }
  } else {
    return ILLIGAL_FUNC << 16;
  }
}