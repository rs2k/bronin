/**
 ******************************************************************************
 * @addtogroup Lumenier Lux support files
 * @{
 *
 * @file       lux.c 
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2014
 * @author     dRonin, http://dRonin.org/, Copyright (C) 2016
 * @brief      Start RTOS and the Modules.
 * @see        The GNU Public License (GPL) Version 3
 * 
 *****************************************************************************/
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */


/* OpenPilot Includes */
#include "openpilot.h"
#include "uavobjectsinit.h"
#include "systemmod.h"
#include "pios_thread.h"

/* Global Variables */

/* Prototype of PIOS_Board_Init() function */
extern void PIOS_Board_Init(void);
extern void Stack_Change(void);

/* Local Variables */
#define INIT_TASK_PRIORITY	PIOS_THREAD_PRIO_HIGHEST
#define INIT_TASK_STACK		1024											// XXX this seems excessive
static struct pios_thread *initTaskHandle;

/* Function Prototypes */
static void initTask(void *parameters);

/* Prototype of generated InitModules() function */
extern void InitModules(void);

/**
* OpenPilot Main function:
*
* Initialize PiOS<BR>
* Create the "System" task (SystemModInitializein Modules/System/systemmod.c) <BR>
* Start RTOS Scheduler <BR>
* If something goes wrong, blink LED1 and LED2 every 100ms
*
*/
int main()
{
	/* NOTE: Do NOT modify the following start-up sequence */
	PIOS_heap_initialize_blocks();

	halInit();
	chSysInit();
	boardInit();

	/* Brings up System using CMSIS functions, enables the LEDs. */
	PIOS_SYS_Init();

	/* For Revolution we use an RTOS task to bring up the system so we can */
	/* always rely on RTOS primitive */
	initTaskHandle = PIOS_Thread_Create(initTask, "init", INIT_TASK_STACK, NULL, INIT_TASK_PRIORITY);
	PIOS_Assert(initTaskHandle != NULL);

	PIOS_Thread_Sleep(PIOS_THREAD_TIMEOUT_MAX);

	return 0;
}
/**
 * Initialisation task.
 *
 * Runs board and module initialisation, then terminates.
 */
void
initTask(void *parameters)
{
	/* board driver init */
	PIOS_Board_Init();

	/* Initialize modules */
	MODULE_INITIALISE_ALL(PIOS_WDG_Clear);

	/* terminate this task */
	PIOS_Thread_Delete(NULL);
}

/**
 * @}
 */

