/*
 * display.cpp
 *
 *  Created on: Mar 12, 2014
 *      Author: ross
 */

/*#define CHRONOS*/

#include <thread.h>
#include <kernel.h>
#include <msg.h>
//#include "logic/include/display_logic.h"
#include <display_logic.h>
//#ifdef CHRONOS
#include <display.h>
//#include <include/display.h>
/*#include "../RIOT/boards/chronos/drivers/include/display.h"*/
//#else
//#include <iostream.h>
//#include <stdio.h>
//#include <stdlib.h>
//#endif

void LCD_Thread(void)
{
	RIOT_printf("hI");

	msg_t message;

	while(1)
	{
		msg_receive(&message);
//		printf("Received message\n");
		char buf[4];
		char *p;

		p = itoa(message.content.value, 10, 0);
		for (int i=0; i<4; i++) buf[i] = *(p+i);
		RIOT_printf(buf);
//		printf("Counter: %d\n", message.content.value);
		thread_sleep();
	}
}

void RIOT_printf(const char *str)
{
//#ifdef CHRONOS
//#if (BOARD==chronos)
	/* char *p = str;*/
	display_chars(LCD_SEG_L1_3, (char*)str, SEG_ON);
//#endif
//#else
	//cout << str << "\n";
//	printf("%s\n",str);
//#endif
}

