/*
 * main.c
 *
 *  Created on: Mar 19, 2014
 *      Author: ross
 */

//#include <iostream.h>
#include <stdio.h>
#include <thread.h>
#include <kernel.h>
#include <msg.h>
#include <hwtimer.h>
#include <vtimer.h>
//#include "logic/include/display_logic.h"
#include <display_logic.h>
#include <stddef.h>

#define TRUE 		1
#define MS			1000
#define DELAY_S		1000 * MS

int main(void)
{
	//wtimer_init();
	vtimer_init();
	vtimer_t * mainTimer;
	timex_t delay;
	delay.microseconds = 0;
	delay.seconds = 1;

	int pidLCD = thread_create(LCD_Thread_Stack,
			sizeof(LCD_Thread_Stack),
			PRIORITY_MAIN-1,
			CREATE_STACKTEST | CREATE_SLEEPING | CREATE_WOUT_YIELD,
			LCD_Thread,
			"LCD thread");

	msg_t message;

	if (pidLCD < 0)
	{
		RIOT_printf("Err");
		while (1);
	}

	uint8_t count = 0;
	while (TRUE)
	{
//		hwtimer_delay(HWTIMER_TICKS(1000000));
		vtimer_set_wakeup(mainTimer, delay, thread_getpid());
		message.content.value = count++;
		thread_wakeup(pidLCD);
//		printf("Sending message\n");
		msg_send(&message, pidLCD, TRUE);
		thread_yield();
		//vtimer_usleep(DELAY_S);
	}

}




