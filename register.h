/*
 * register.h
 *
 *  Created on: Feb 4, 2013
 *      Author: hxk9609
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <sys/mman.h>
#include <hw/inout.h>
#include <stdint.h>
// Make Port A/B output , for output write 0 in  control register
// Make port C ( 0 - 3) input, for input write 1 in control register
// Make port C ( 4 - 7) output, for output write 0 in control register

#define SELECT_FIRST_DISPLAY		 0xFE   //PORTA.0
#define SELECT_SECOND_DISPLAY        0xFD   //PORTA.1
#define SELECT_THIRD_DISPLAY         0xFB   //PORTA.2
#define SELECT_FOURTH_DISPLAY        0xF7   //PORTA.3
#define SELECT_SEGMENT_A             0xEF   //PORTA.4
#define SELECT_SEGMENT_B             0xDF   //PORTA.5
#define SELECT_SEGMENT_C             0xBF   //PORTA.6
#define SELECT_SEGMENT_D             0x7F   //PORTA.7
#define SELECT_SEGMENT_E             0xFE   //PORTC.4
#define SELECT_SEGMENT_F             0xFD   //PORTC.5
#define SELECT_SEGMENT_G		     0xFB   //PORTC.6
#define SELECT_SEGMENT_DP            0xF7   //PORTC.7
#define SELECT_LED_0                 0xFE   //PORTB.0
#define SELECT_LED_1                 0xFD   //PORTB.1
#define SELECT_LED_2                 0xFB   //PORTB.2
#define SELECT_LED_3                 0xF7   //PORTB.3
#define SELECT_LED_4                 0xEF   //PORTB.4
#define SELECT_LED_5                 0xDF   //PORTB.5
#define SELECT_LED_6                 0xBF   //PORTB.6
#define SELECT_LED_7                 0x7F   //PORTB.7

#define READ_SET_BUTTON			     0x00   //PORTC.0
#define READ_START_BUTTON            0x00   //PORTC.1
#define READ_MODE_BUTTON             0x00   //PORTC.2


// Register Mapping
#define IO_REG_BASE_ADDR	0x280
#define IO_REG_A	(IO_REG_BASE_ADDR + 8)
#define IO_REG_B	(IO_REG_BASE_ADDR + 9)
#define IO_REG_C	(IO_REG_BASE_ADDR + 10)
#define IO_INTR		(IO_REG_BASE_ADDR + 4)
#define IO_REG_CTRL	(IO_REG_BASE_ADDR + 11)
#define IO_PORT_SIZE	1

#endif /* REGISTER_H_ */
