/*
 * main.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */

#include "main.h"

#include "sam.h"
#include "atmel_start.h"
#include "FreeRTOS.h"
#include "task.h"
#include "can_task.h"

#ifndef __TEST
int main(void)
#else
int testable_main(void)
#endif
{
	atmel_start_init();
	vCANTaskStart();
	return 0;
}


