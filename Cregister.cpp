/*
 * Cregister.cpp
 *
 *  Created on: Feb 13, 2013
 *      Author: ejc7119
 */

/*
 * register.cc
 *
 *  Created on: Feb 4, 2013
 *      Author: hxk9609
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/neutrino.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <hw/inout.h>
#include "register.h"
#include "Cregister.h"

int Cregister::getIOaccess()
{
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
	 {
	   perror("Failed to get I/O access permission");
	   return -1;
	 }
	return 0;
}

//  PortB - OUT, portA - OUT
// PORTC0.3 - IN, PORTC4.7 - OUT
int Cregister::configurePort( )
{
	uintptr_t ctrlHandle;

	ctrlHandle = mmap_device_io(IO_PORT_SIZE, IO_REG_CTRL);
		if(ctrlHandle == MAP_DEVICE_FAILED)
		 {
		   perror("Failed to map control register");
		   return -1;
		 }
	out8(ctrlHandle, 0x81);
	return 0;
}

// Map port B
uintptr_t Cregister::memoryMapPortB()
{
	uintptr_t ctrlHandle_B;

	ctrlHandle_B = mmap_device_io(IO_PORT_SIZE, IO_REG_B);
	if(ctrlHandle_B == MAP_DEVICE_FAILED)
		 {
		   perror("Failed to map control register");
		   return -1;
		 }
     return ctrlHandle_B;
}

// Map port A
uintptr_t Cregister::memoryMapPortA()
{
	uintptr_t ctrlHandle_A;

	ctrlHandle_A = mmap_device_io(IO_PORT_SIZE, IO_REG_A);
	if(ctrlHandle_A == MAP_DEVICE_FAILED)
		 {
		   perror("Failed to map control register");
		   return -1;
		 }
     return ctrlHandle_A;
}

// Map port C
uintptr_t Cregister::memoryMapPortC()
{
	uintptr_t ctrlHandle_C;

	ctrlHandle_C = mmap_device_io(IO_PORT_SIZE, IO_REG_C);
	if(ctrlHandle_C == MAP_DEVICE_FAILED)
		 {
		   perror("Failed to map control register");
		   return -1;
		 }
     return ctrlHandle_C;
}

int Cregister::readreg(uintptr_t ctrlHandle)
{
	int val;

	val = in8(ctrlHandle);

	return (val & 0xff);
}

void Cregister::writeRegister(uintptr_t ctrlHandle, int val)
{
	out8(ctrlHandle, (val & 0xff));
}

