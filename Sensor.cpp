/*
 * Sensor.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Sensor.h"
unsigned long pulseCnt = 0;

void Sensor::pulse_interrupt(){

}
int Sensor::getPulseFrmSensor(uintptr_t cntrlHandle)
{
	int data;

	data = pulseRegister.readreg(cntrlHandle);
	return (data & 0x08);
}

const struct sigevent* intrHandlr(void *arg, int id)
{
	Sensor* self = (Sensor*)arg;
	pulseCnt++;
	out8(self->cntrlHandleCL, 0x02);// reset interrupt to get successive interrupt
	return NULL;
}

void Sensor::set_up_intr_magnetic_pulse(){
	int intrID;

   cntrlHandleS = mmap_device_io(1,INTERRUPT_STATUS_REG );
   if(cntrlHandleS == MAP_DEVICE_FAILED)
   {
	 perror("Failed to map control register");
	 return;
   }
   cntrlHandleC = mmap_device_io(1, INTERRUPT_ENABLE_REG);
   if(cntrlHandleC == MAP_DEVICE_FAILED)
   {
	 perror("Failed to map control register");
	 return;
   }
   cntrlHandleCL = mmap_device_io(1, INTERRUPT_CLR_REG);
   if(cntrlHandleCL == MAP_DEVICE_FAILED)
   {
	 perror("Failed to map control register");
	 return;
   }

   out8(cntrlHandleC, ENABLE_DIO_INTR); // Enable Digital IO interrupt
   out8(cntrlHandleCL, 0x02); // clear digital IO interrupt

   intrID = InterruptAttach(DIGITAL_IO_IRQ, intrHandlr, NULL, 0, 0);
   if(intrID == -1)
   {
	   cout << "Failed to attach IRQ5" << endl;
	   exit(EXIT_FAILURE);
   }
}
