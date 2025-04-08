#include "RS485_Region_handler.h"
#include "PWM_task.h"
#include "FG_task.h"
#include "fan_main_task.h"

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

typedef enum {
  FAN_ALARM_MODE = FANS_CARD_SYS_SET_REG_START,
  FAN_ALARM_DELAY,
  FAN_LOW_SPEED_WARNING_THRESHOLD,
  FAN_FG_DIFFERENCE_WARNING_THRESHOLD,
  FAN_BOARD_AUTO_CONTROL,
  AUTO_CONTROL_TARGET_SPEED,
  FAN_INSTALLATION_STATUS,
} FanCardSysSetCase_t;

typedef enum {
  FAN_BOARD_FAULT_STATUS,
  FAN_STATUS_ON_FAN_BOARD_BITFIELD_0_15,
} FanCardSysDispCase_t;

uint32_t FansCard_Handler(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root) {
  if (func == READ_HOLDING_REGISTERS) {
    switch (addr) {
      case FAN_1_FEEDBACK:
        return FansCardStat.fan_fg[0] & 0xFFFF;
      case FAN_2_FEEDBACK:
        return FansCardStat.fan_fg[1] & 0xFFFF;
      case FAN_3_FEEDBACK:
        return FansCardStat.fan_fg[2] & 0xFFFF;
      case FAN_4_FEEDBACK:
        return FansCardStat.fan_fg[3] & 0xFFFF;
      case FAN_5_FEEDBACK:
        return FansCardStat.fan_fg[4] & 0xFFFF;
      case FAN_6_FEEDBACK:
        return FansCardStat.fan_fg[5] & 0xFFFF;
      case FAN_7_FEEDBACK:
        return FansCardStat.fan_fg[6] & 0xFFFF;
      case FAN_8_FEEDBACK:
        return FansCardStat.fan_fg[7] & 0xFFFF;
      case FAN_9_FEEDBACK:
        return FansCardStat.fan_fg[8] & 0xFFFF;
      case FAN_10_FEEDBACK:
        return FansCardStat.fan_fg[9] & 0xFFFF;
      case FAN_11_FEEDBACK:
        return FansCardStat.fan_fg[10] & 0xFFFF;
      case FAN_12_FEEDBACK:
        return FansCardStat.fan_fg[11] & 0xFFFF;
      case FAN_13_FEEDBACK:
        return FansCardStat.fan_fg[12] & 0xFFFF;
      case FAN_14_FEEDBACK:
        return FansCardStat.fan_fg[13] & 0xFFFF;
      case FAN_15_FEEDBACK:
        return FansCardStat.fan_fg[14] & 0xFFFF;
      case FAN_16_FEEDBACK:
        return FansCardStat.fan_fg[15] & 0xFFFF;
      case FAN_1_DUTY:
        return FansCardCtrl.fan_pwm[0] & 0xFFFF;
      case FAN_2_DUTY:
        return FansCardCtrl.fan_pwm[1] & 0xFFFF;
      case FAN_3_DUTY:
        return FansCardCtrl.fan_pwm[2] & 0xFFFF;
      case FAN_4_DUTY:
        return FansCardCtrl.fan_pwm[3] & 0xFFFF;
      case FAN_5_DUTY:
        return FansCardCtrl.fan_pwm[4] & 0xFFFF;
      case FAN_6_DUTY:
        return FansCardCtrl.fan_pwm[5] & 0xFFFF;
      case FAN_7_DUTY:
        return FansCardCtrl.fan_pwm[6] & 0xFFFF;
      case FAN_8_DUTY:
        return FansCardCtrl.fan_pwm[7] & 0xFFFF;
      case FAN_9_DUTY:
        return FansCardCtrl.fan_pwm[8] & 0xFFFF;
      case FAN_10_DUTY:
        return FansCardCtrl.fan_pwm[9] & 0xFFFF;
      case FAN_11_DUTY:
        return FansCardCtrl.fan_pwm[10] & 0xFFFF;
      case FAN_12_DUTY:
        return FansCardCtrl.fan_pwm[11] & 0xFFFF;
      case FAN_13_DUTY:
        return FansCardCtrl.fan_pwm[12] & 0xFFFF;
      case FAN_14_DUTY:
        return FansCardCtrl.fan_pwm[13] & 0xFFFF;
      case FAN_15_DUTY:
        return FansCardCtrl.fan_pwm[14] & 0xFFFF;
      case FAN_16_DUTY:
        return FansCardCtrl.fan_pwm[15] & 0xFFFF;
      default:
        return 0;
    }
  } else if (func == WRITE_SINGLE_REGISTER || func == WRITE_MULTIPLE_REGISTERS) {
    if (addr >= FAN_1_DUTY && addr <= FAN_16_DUTY) {
      if (data >= 0 && data <= 1000) {
        switch (addr) {
          case FAN_1_DUTY:
            return (FansCardCtrl.fan_pwm[0] = data) & 0xFFFF;
          case FAN_2_DUTY:
            return (FansCardCtrl.fan_pwm[1] = data) & 0xFFFF;
          case FAN_3_DUTY:
            return (FansCardCtrl.fan_pwm[2] = data) & 0xFFFF;
          case FAN_4_DUTY:
            return (FansCardCtrl.fan_pwm[3] = data) & 0xFFFF;
          case FAN_5_DUTY:
            return (FansCardCtrl.fan_pwm[4] = data) & 0xFFFF;
          case FAN_6_DUTY:
            return (FansCardCtrl.fan_pwm[5] = data) & 0xFFFF;
          case FAN_7_DUTY:
            return (FansCardCtrl.fan_pwm[6] = data) & 0xFFFF;
          case FAN_8_DUTY:
            return (FansCardCtrl.fan_pwm[7] = data) & 0xFFFF;
          case FAN_9_DUTY:
            return (FansCardCtrl.fan_pwm[8] = data) & 0xFFFF;
          case FAN_10_DUTY:
            return (FansCardCtrl.fan_pwm[9] = data) & 0xFFFF;
          case FAN_11_DUTY:
            return (FansCardCtrl.fan_pwm[10] = data) & 0xFFFF;
          case FAN_12_DUTY:
            return (FansCardCtrl.fan_pwm[11] = data) & 0xFFFF;
          case FAN_13_DUTY:
            return (FansCardCtrl.fan_pwm[12] = data) & 0xFFFF;
          case FAN_14_DUTY:
            return (FansCardCtrl.fan_pwm[13] = data) & 0xFFFF;
          case FAN_15_DUTY:
            return (FansCardCtrl.fan_pwm[14] = data) & 0xFFFF;
          case FAN_16_DUTY:
            return (FansCardCtrl.fan_pwm[15] = data) & 0xFFFF;
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

uint32_t FanCardSysSet_Handler(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root) {
  if (func == READ_HOLDING_REGISTERS) {
    switch (addr) {
      case FAN_ALARM_MODE:
        return FanCardSysSet.fan_alarm.act & 0xFFFF;
      case FAN_ALARM_DELAY:
        return FanCardSysSet.fan_alarm.delay & 0xFFFF;
      case FAN_BOARD_AUTO_CONTROL:
        return FanCardSysSet.auto_control & 0xFFFF;
      case AUTO_CONTROL_TARGET_SPEED:
        return FanCardSysSet.auto_control_target_speed & 0xFFFF;
      case FAN_INSTALLATION_STATUS:
        return FanCardSysSet.fan_installation_status & 0xFFFF;
      case FAN_LOW_SPEED_WARNING_THRESHOLD:
        return FanCardSysSet.fan_alarm.fan_low_speed_warning_threshold & 0xFFFF;
      case FAN_FG_DIFFERENCE_WARNING_THRESHOLD:
        return FanCardSysSet.fan_alarm.fan_fg_difference_warning_threshold & 0xFFFF;
      default:
        return 0;
    }
  } else if (func == WRITE_SINGLE_REGISTER || func == WRITE_MULTIPLE_REGISTERS) {
    switch (addr) {
      case FAN_ALARM_MODE:
        return (FanCardSysSet.fan_alarm.act = data) & 0xFFFF;
      case FAN_ALARM_DELAY:
        return (FanCardSysSet.fan_alarm.delay = data) & 0xFFFF;
      case FAN_BOARD_AUTO_CONTROL:
        return (FanCardSysSet.auto_control = data) & 0xFFFF;
      case AUTO_CONTROL_TARGET_SPEED:
        return (FanCardSysSet.auto_control_target_speed = data) & 0xFFFF;
      case FAN_INSTALLATION_STATUS:
        return (FanCardSysSet.fan_installation_status = data) & 0xFFFF;
      case FAN_LOW_SPEED_WARNING_THRESHOLD:
        return (FanCardSysSet.fan_alarm.fan_low_speed_warning_threshold = data) & 0xFFFF;
      case FAN_FG_DIFFERENCE_WARNING_THRESHOLD:
        return (FanCardSysSet.fan_alarm.fan_fg_difference_warning_threshold = data) & 0xFFFF;
      default:
        return ILLIGAL_DATA_ADDR << 16;
    }
  } else {
    return ILLIGAL_FUNC << 16;
  }
}

uint32_t FanCardSysDisp_Handler(RsFunc_t func, uint16_t addr, uint16_t data, uint8_t len, bool root) {
  if (func == READ_HOLDING_REGISTERS) {
    switch (addr) {
      case FAN_BOARD_FAULT_STATUS:
        return FanCardSysDisp.fan_board_fault_status & 0xFFFF;
      case FAN_STATUS_ON_FAN_BOARD_BITFIELD_0_15:
        return FanCardSysDisp.fan_status_on_fan_board_bitfield_0_15 & 0xFFFF;
      default:
        return 0;
    }
  } else {
    return ILLIGAL_FUNC << 16;
  }
}