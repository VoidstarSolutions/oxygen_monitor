#ifndef CAN_TASK_H
#define CAN_TASK_H
#include "FreeRTOS.h"
void vCANTaskStart(uint16_t usStackSize, unsigned portBASE_TYPE uxPriority);
#endif //CAN_TASK_H