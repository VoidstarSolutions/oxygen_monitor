/*
 * task_startup.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */

#include "task_startup.h"

#include "can_task.h"
#include "sdadc_task.h"


static StaticTask_t xIdleTask;
static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

static StaticTask_t xTimerTask;
static StackType_t xTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
    *ppxIdleTaskTCBBuffer = &xIdleTask;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
    *ppxTimerTaskTCBBuffer = &xTimerTask;
    *ppxTimerTaskStackBuffer = xTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

int vStartAllTheTasks()
{
    //vSDCADCTaskStart();
    vCANTaskStart();
    return 0;
}