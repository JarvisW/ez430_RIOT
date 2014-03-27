/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @defgroup    boards_chronos Chronos
 * @ingroup     boards
 * @brief       Support for the chronos board
 * @{
 *
 * @file        board.h
 * @brief       Header for the chronos board
 *
 * @author      unknwon
 */

#ifndef _MSB_BOARD_H
#define _MSB_BOARD_H

#include <stdint.h>


// for correct inclusion of <msp430.h>
#ifndef __CC430F6137__
#define __CC430F6137__
#endif

#define MSP430_INITIAL_CPU_SPEED    7372800uL
#define F_CPU                       MSP430_INITIAL_CPU_SPEED
#define F_RC_OSCILLATOR             32768
#define MSP430_HAS_DCOR             1
#define MSP430_HAS_EXTERNAL_CRYSTAL 1

//	Accelleration sensor input pin
#define AS_INT_PIN		BIT5

// Leave set_value() function after some seconds of user inactivity
#define INACTIVITY_TIME (30u)

//	Check if IRQ is triggered
#define IRQ_TRIGGERED(flags, bit)	((flags & bit) == bit)


// Set of button flags
typedef union
{
  struct
  {
   // Manual button events
    uint16_t star : 1; // Short STAR button press
    uint16_t num : 1; // Short NUM button press
    uint16_t up : 1; // Short UP button press
    uint16_t down : 1; // Short DOWN button press
    uint16_t backlight : 1; // Short BACKLIGHT button press
    uint16_t star_long : 1; // Long STAR button press
    uint16_t num_long : 1; // Long NUM button press
  } flag;
  uint16_t all_flags; // Shortcut to all display flags (for reset)
} s_button_flags;
/*extern*/ volatile s_button_flags button;

struct struct_button
{
	uint8_t star_timeout;	
	uint8_t num_timeout;	
	uint8_t backlight_timeout;
	uint8_t backlight_status;
	int16_t repeats;	
};
extern volatile struct struct_button sButton;

typedef uint8_t radio_packet_length_t;

uint8_t board_mng_thread_pid;
//
//	Prototypes
//
//void port2IRQ_ISR(void);
//void accelIRQ_ISR(void);

void initBoard(void);

#endif // _MSB_BOARD_H
