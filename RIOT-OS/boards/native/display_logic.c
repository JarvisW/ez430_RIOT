/*
 * display.cpp
 *
 *  Created on: Mar 12, 2014
 *      Author: ross
 */


#include <thread.h>
#include <kernel.h>
#include <msg.h>
//#include "logic/include/display_logic.h"
#include <display_logic.h>
//#include <iostream>
#include <stdio.h>
#include <stddef.h>
//#include <stdlib.h>

char * itoa(uint32_t value, uint8_t count, uint8_t foo)
{
	char buf[count];
	char * p = buf[0];
	sprintf(buf, "%d", value);
	return buf;
}

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
	//cout << str << "\n";
	printf("%s\n",str);
}