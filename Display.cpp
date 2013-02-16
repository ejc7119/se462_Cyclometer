/*
 * Display.cpp
 *
 *  Created on: Feb 13, 2013
 *      Author: ejc7119
 */
#include "Display.h"

Display::Display(Calculations* calc){
	calculations = calc;
	state = RESET;
	HWregister.getIOaccess();
	HWregister.configurePort();
	cntrlHandle_A = HWregister.memoryMapPortA();
	cntrlHandle_B = HWregister.memoryMapPortB();
}

void Display::set_state(int st){
	state = st;
}

void* Display::run_display(void* arg){
	Display* self = (Display*)arg;
	while(1){
		switch(self->state){
		case AVERAGE:
			self->displayAvgSpeed(self->calculations->get_average_speed());
			self->displayCurrSpeed(self->calculations->get_current_speed());
			self->updateDisplay(self->unit,self->tenth,self->isFraction,self->port_u, self->port_t, 0);
			self->updateDisplay(self->unit_c,self->tenth_c, self->isFraction_c, self->portCurr_u, self->portCurr_t, 0);
			break;
		case DISTANCE:
			self->displayTripDistance(self->calculations->get_distance());
			self->updateDisplay(self->unit_c,self->tenth_c, self->isFraction_c, self->portCurr_u, self->portCurr_t, 0);
			self->updateDisplay(self->unit,self->tenth,self->isFraction,self->port_u, self->port_t, 0);
			break;
		case DURATION:
			self->displayTripTime(self->calculations->get_duration());
			self->updateDisplay(self->unit_c,self->tenth_c, self->isFraction_c, self->portCurr_u, self->portCurr_t, 1);
			self->updateDisplay(self->unit,self->tenth,self->isFraction,self->port_u, self->port_t, 0);
			break;
		case RESET:
			break;
		case SPEED_SCALE:
			self->displaySpeedScale();
			break;
		case WHEEL_SIZE:
			self->displayWheelSize(self->calculations->get_wheel_size());
			self->updateDisplay(self->unit_c,self->tenth_c, self->isFraction_c, self->portCurr_u, self->portCurr_t, 0);
			self->updateDisplay(self->unit,self->tenth,self->isFraction,self->port_u, self->port_t, 0);
			break;
		default:
			break;
		}
	}
	return NULL;
}

void Display::displayAvgSpeed (float data)
{
	breakDatainDigits(data);
	displayelapsedTime = 0;
    displayelapsedDistance = 0;
	displayWheel = 0;
	displayAvSpeed = 1;
	port_u = 0xFE;
	port_t = 0xFD;
    return;
}

void Display::displayCurrSpeed(float data)
{
	breakCurrSpeed(data);
	displayCurrentSpeed = 1;
	portCurr_u = 0xFB;
	portCurr_t = 0xF7;
    return;
}

void Display::displayTripTimeMin(float data)
{
	breakCurrSpeed(data);
	displayelapsedTime = 1;
	portCurr_u = 0xFB;
	portCurr_t = 0xF7;
	isFraction_c = 1;
}

void Display::displayTripTimeSec(float data)
{
	breakDatainDigits(data);
	displayelapsedTime = 1;
	port_u = 0xFE;
	port_t = 0xFD;
	isFraction = 0;
}

void Display::displayTripDistanceUpper(float data)
{
	breakCurrSpeed(data);
	displayelapsedDistance = 1;
	portCurr_u = 0xFB;
	portCurr_t = 0xF7;
	isFraction_c = 0;
}

void Display::displayTripDistancelower(float data)
{
	breakDatainDigits(data);
	displayelapsedDistance = 1;
	port_u = 0xFE;
	port_t = 0xFD;
	isFraction = 1;
}

void Display::displayWheelSizeUpper(int data)
{
	breakCurrSpeed(data);
	displayWheel = 1;
	portCurr_u = 0xFB;
	portCurr_t = 0xFF;
	isFraction_c = 0;
}

void Display::displayWheelSizelower(int data)
{
	breakDatainDigits(data);
	displayWheel = 1;
	port_u = 0xFE;
	port_t = 0xFD;
	isFraction = 0;
}

void Display::displayWheelSize(int data)
{
	displayelapsedDistance = 0;
	displayWheelSizeUpper(data/100);
	displayWheelSizelower(data%100);
}

void Display::displayTripTime(float data)
{
  displayCurrentSpeed = 0;
  displayAvSpeed = 0;
  displayTripTimeMin(data/100);
  displayTripTimeSec((int)data%100);
}

void Display::displaySpeedScale(){
	//breakDatainDigits(data);
	port_u = 0xFE;
	isFraction = 0;
}

void Display::displayTripDistance(float data)
{
	displayelapsedTime = 0;
	displayTripDistanceUpper(data/100);
	displayTripDistancelower((int)data%100);
}

void Display::breakDatainDigits(float data)
{
    int temp;

    if(data >= 10)
    {
     data = (int)data;
     unit = (int)data % 10;
     tenth = (int) (data / 10);
     isFraction = 0;
    }
    else
    {
    	tenth = (int)data % 10;
    	unit =  ((int)(data * 10) % 10);
    	isFraction = unit;
    	if(isFraction == 0)
    	{
    	  temp = unit;
    	  unit = tenth;
    	  tenth =  temp;
    	}
    }
}

void Display::breakCurrSpeed(float data)
{
	int temp;

    if(data >= 10)
    {
     data = (int)data;
     unit_c = (int)data % 10;
     tenth_c = (int) (data / 10);
     isFraction_c = 0;
    }
    else
    {
    	tenth_c = (int)data % 10;
       	unit_c =  ((int)(data * 10) % 10);
    	isFraction_c = unit_c;
    	if(isFraction_c == 0)
    	{
    	   temp = unit_c;
    	   unit_c = tenth_c;
    	   tenth_c =  temp;
    	}
    }
    return;
}

void Display::updateDisplay(int unit, int tenth, int isFraction, int port_u, int port_t, int isTime)
{
   selectSegment(unit, 0, port_u);
   usleep(100);
   selectSegment(tenth, 0, port_t);
   usleep(100);
   if(isFraction)
   {
	  if(isTime == 0)
	   selectSegment(isFraction, 1, port_t);
	  else
	   selectSegment(isFraction, 1, port_u);
   }
   usleep(100);
   return;
}

void Display::selectSegment(int digit, int point, int displayPos)
{
	HWregister.writeRegister(cntrlHandle_A, 0xFF & displayPos);
	HWregister.writeRegister(cntrlHandle_B, 0xFF);

	switch(point)
		{
		case 1: HWregister.writeRegister(cntrlHandle_B, ( SELECT_SEGMENT_DP ));
		        break;
		default: break;

		}
	if(point) return;

	switch(digit)
	{
	case 1: HWregister.writeRegister(cntrlHandle_A, SELECT_SEGMENT_B & SELECT_SEGMENT_C & displayPos);
	        break;
	case 2: HWregister.writeRegister(cntrlHandle_A, SELECT_SEGMENT_A & SELECT_SEGMENT_B & SELECT_SEGMENT_D & displayPos);
	        HWregister.writeRegister(cntrlHandle_B, SELECT_SEGMENT_E & SELECT_SEGMENT_G );
	        break;
	case 3: HWregister.writeRegister(cntrlHandle_A, SELECT_SEGMENT_A & SELECT_SEGMENT_B & SELECT_SEGMENT_C & SELECT_SEGMENT_D & displayPos);
	        HWregister.writeRegister(cntrlHandle_B,SELECT_SEGMENT_G);
	        break;
	case 4: HWregister.writeRegister(cntrlHandle_A, SELECT_SEGMENT_B & SELECT_SEGMENT_C & displayPos);
	        HWregister.writeRegister(cntrlHandle_B,SELECT_SEGMENT_F & SELECT_SEGMENT_G );
	        break;
	case 5: HWregister.writeRegister(cntrlHandle_A, SELECT_SEGMENT_A & SELECT_SEGMENT_C & SELECT_SEGMENT_D & displayPos);
	        HWregister.writeRegister(cntrlHandle_B, SELECT_SEGMENT_F & SELECT_SEGMENT_G );
	        break;
	case 6: HWregister.writeRegister(cntrlHandle_A, SELECT_SEGMENT_A & SELECT_SEGMENT_D & SELECT_SEGMENT_C & displayPos);
	        HWregister.writeRegister(cntrlHandle_B, SELECT_SEGMENT_F & SELECT_SEGMENT_E & SELECT_SEGMENT_G );
	        break;
	case 7: HWregister.writeRegister(cntrlHandle_A, (SELECT_SEGMENT_A & SELECT_SEGMENT_B & SELECT_SEGMENT_C & displayPos));
	        break;
	case 8: HWregister.writeRegister(cntrlHandle_A, (SELECT_SEGMENT_A & SELECT_SEGMENT_B & SELECT_SEGMENT_C & SELECT_SEGMENT_D & displayPos));
	        HWregister.writeRegister(cntrlHandle_B, (SELECT_SEGMENT_E & SELECT_SEGMENT_F & SELECT_SEGMENT_G ));
	        break;
	case 9: HWregister.writeRegister(cntrlHandle_A, (SELECT_SEGMENT_A & SELECT_SEGMENT_B & SELECT_SEGMENT_C & SELECT_SEGMENT_D & displayPos));
	        HWregister.writeRegister(cntrlHandle_B, (SELECT_SEGMENT_F & SELECT_SEGMENT_G ));
	        break;
	case 0: HWregister.writeRegister(cntrlHandle_A, (SELECT_SEGMENT_A & SELECT_SEGMENT_B & SELECT_SEGMENT_C & SELECT_SEGMENT_D & displayPos));
	        HWregister.writeRegister(cntrlHandle_B, (SELECT_SEGMENT_E & SELECT_SEGMENT_F & displayPos));
	        break;
	default: break;

	}

	return;
}

