/*
 * sdadc_task.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */

#include "sdadc_task.h"

#include "FreeRTOS.h"
#include "atmel_start.h"
#include "task.h"

#define UX_SDADC_TASK_STACK_SIZE ((uint16_t) 128)
#define UX_SDADC_TASK_PRIORITY ((uint16_t) 1)

static TaskHandle_t xSDADCTaskHandle;
static StaticTask_t xSDADCTask;
static StackType_t  xSDADCTaskStack[UX_SDADC_TASK_STACK_SIZE];


static void prvSDADCTask(void *pvParameters);

void vSDADCTaskStart(void)
{
	xSDADCTaskHandle = xTaskCreateStatic(prvSDADCTask, "SDADC", UX_SDADC_TASK_STACK_SIZE, NULL, UX_SDADC_TASK_PRIORITY,
	                                     xSDADCTaskStack, &xSDADCTask);
}

static void prvSDADCTask(void *pvParameters)
{

}
