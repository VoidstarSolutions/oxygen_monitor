#include "can_task.h"

void vCANTaskStart( uint16_t usStackSize, unsigned portBASE_TYPE uxPriority )
{
	/* Create that task that handles the console itself. */
	xTaskCreate( 	prvCanTask,			/* The task that implements the command console. */
					"CLI",								/* Text name assigned to the task.  This is just to assist debugging.  The kernel does not use this name itself. */
					usStackSize,						/* The size of the stack allocated to the task. */
					NULL,								/* The parameter is not used, so NULL is passed. */
					uxPriority,							/* The priority allocated to the task. */
					NULL );								/* A handle is not required, so just pass NULL. */
}