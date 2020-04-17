#ifndef OSAPI_H
#define OSAPI_H

#ifdef __TEST
#include "FreeRTOS.h"

typedef void *TaskHandle_t;

TaskHandle_t xTaskCreateStatic(
    TaskFunction_t    pxTaskCode,
    const char *const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    const uint32_t ulStackDepth, void *const pvParameters, UBaseType_t uxPriority, StackType_t *const puxStackBuffer,
    StaticTask_t *const pxTaskBuffer);
#else
#include "FreeRTOS.h"
#include "task.h"
#endif
#endif //OSAPI