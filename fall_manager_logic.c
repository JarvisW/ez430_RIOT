/*
 * fall_manager_logic.c
 *
 *  Created on: Mar 28, 2014
 *      Author: ross
 */
#include <thread.h>
#include <kernel.h>
#include <msg.h>
#include <stdio.h>
#include <vtimer.h>
#include <stdlib.h>
#include "fall_manager_logic.h"

#define ENABLE_DEBUG (0)
#include "debug.h"

char fall_stack[KERNEL_CONF_STACKSIZE_MAIN];
sAccellerometerData_t accelData;

void fall_mng_thread(void);

void initFallManager(void)
{
	fall_mng_thread_pid = thread_create(fall_stack,
			sizeof(fall_stack),
			PRIORITY_MAIN+2,
			CREATE_WOUT_YIELD | CREATE_STACKTEST,
			fall_mng_thread,
			"Fall Mng");

	if(fall_mng_thread_pid < 0)
	{
		DEBUG("Error creating thread");
	//	printf("Error creating thread\n");
		while (true) ;
	}

	/*
	 * Send connection request
	 */
	// < Put connection code here >

	// init_accelleration();
}

void fall_mng_thread(void)
{
	msg_t message;

	uint8_t count = 0;
	DEBUG ("Fall Manager Thread started");
	while (true)
	{
		DEBUG("New fall cycle");
		thread_sleep();
		//vtimer_usleep(5000 * 1000);
		printf("Fall manager thread -> %d\n", count++);
		// fill data
		for(int i = 0; i < SAMPLE_ARRAY_DEPTH; i++)
		{
			accelData.xyzData[i].x = 255 * rand();
			accelData.xyzData[i].y = 255 * rand();
			accelData.xyzData[i].z = 255 * rand();
		}
		message.content.ptr = (char *) & accelData;
		msg_t foo;
		msg_receive(&foo);
	}
}
