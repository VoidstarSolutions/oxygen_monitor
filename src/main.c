/*
 * main.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */

#include "main.h"

#include "sam.h"
#include "atmel_start.h"

#ifndef __TEST
int main(void)
#else
int testable_main(void)
#endif
{
	atmel_start_init();
	return 0;
}


