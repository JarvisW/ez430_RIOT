/*
 * display_logic.h
 *
 *  Created on: Mar 19, 2014
 *      Author: ross
 */

#ifndef DISPLAY_LOGIC_H_
#define DISPLAY_LOGIC_H_

char LCD_Thread_Stack[2 * KERNEL_CONF_STACKSIZE_DEFAULT];

msg_t LCD_Thread_msg;

extern void RIOT_printf(const char *str);
void LCD_Thread(void);

#endif /* DISPLAY_LOGIC_H_ */