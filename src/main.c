/*
 * $projectname$.c
 *
 * Created: $date$
 * Author : $user$
 */ 

#include "sam.h"
#include "FreeRTOS.h"
#include "task.h"
#include "StaticAllocation.h"

#ifndef __TEST
int main(void)
#else
int testable_main(void)
#endif
{
    /* Initialize the SAM system */
    SystemInit();
    vStartStaticallyAllocatedTasks();
    return 0;
}
