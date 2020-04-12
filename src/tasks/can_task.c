#include "can_task.h"

#include "FreeRTOS.h"
#include "portmacro.h"
#include "task.h"

#define UX_CAN_TASK_STACK_SIZE 512ul
#define UX_CAN_TASK_PRIORITY 1ul

static TaskHandle_t xCANTaskHandle;
static StaticTask_t xCANTask;
static StackType_t xCANTaskStack[UX_CAN_TASK_STACK_SIZE];

static void prvCanTask(void *pvParameters);
static void prvConfigureCan(void);

void vCANTaskStart(void)
{
	xCANTaskHandle = xTaskCreateStatic(prvCanTask,
									   "CAN",
									   UX_CAN_TASK_STACK_SIZE,
									   NULL,
									   UX_CAN_TASK_PRIORITY,
									   xCANTaskStack,
									   &xCANTask);
}

static void prvCanTask(void *pvParameters)
{
}
static void prvConfigureCan(void)
{
}