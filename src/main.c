/*
 * $projectname$.c
 *
 * Created: $date$
 * Author : $user$
 */ 

#include "sam.h"
#include "FreeRTOS.h"

#ifndef __TEST
int main(void)
#else
int testable_main(void)
#endif
{
    /* Initialize the SAM system */
    SystemInit();
    
    return 0;
}
