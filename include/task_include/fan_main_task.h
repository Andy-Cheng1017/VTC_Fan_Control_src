/**
 * @file fan_main_task.h
 * @author your name (you@domain.com)
 * @brief Header file for FAN main task.
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FAN_MAIN_TASK_H
#define FAN_MAIN_TASK_H

#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t FanMainTask_Handler;

void fan_main_task_function(void* pvParameters);

#endif /* FAN_MAIN_TASK_H */
