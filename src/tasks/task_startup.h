/*
 * task_startup.h
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */

#ifndef TASK_STARTUP_H
#define TASK_STARTUP_H

#include "FreeRTOS.h"
#include "task.h"

// Function required by FreeRTOS when using static allocation
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize);

// Function required by FreeRTOS when using static allocation and timers
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize);

// Start all of the statically allocated tasks
int vStartAllTheTasks();

#endif // TASK_STARTUP_H
