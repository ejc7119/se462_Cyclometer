/*
 * Sensor.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include "Cregister.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/neutrino.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <hw/inout.h>
#include <time.h>
#include <iostream>
#include <unistd.h>

#define DIGITAL_IO_IRQ			5
#define INTERRUPT_CLR_REG 		0x280 + 0
#define INTERRUPT_ENABLE_REG 	0x280 + 0x04
#define INTERRUPT_STATUS_REG    0x280 + 0x07

#define ENABLE_DIO_INTR			0x02
#define ENABLE_TIMER_INTR		0x04
#define CLEAR_INTR_DIO			0x02
#define CLEAR_INTR_TIMER		0x04
#define IS_DIO_INTERRUPT		0x20
#define IS_TIMER_INTR			0x40

const struct sigevent* intrHandlr(void *arg, int id);
using namespace std;
class Sensor{
private:
	Cregister pulseRegister;

public:
	Sensor();
	void set_up_intr_magnetic_pulse();
	long get_count();
};

#endif /* SENSOR_H_ */
