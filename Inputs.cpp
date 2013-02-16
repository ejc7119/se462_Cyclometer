/*
 * Inputs.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#include "Inputs.h"

Inputs::Inputs(Controller* con){
	controller = con;
	HWregister.getIOaccess();
	HWregister.configurePort();
	cntrlHandle = HWregister.memoryMapPortC();
}

/*
 * Method for retrieving button inputs from the hardware
 */
void Inputs::get_inputs(){
	int input = whichButtonPressed();

	switch(input){
	case MODE_BUTTON:
		// If MODE press
		controller->receive_event(1,0,0,0,0,0);
		break;
	case START_BUTTON:
		// If START/STOP press
		controller->receive_event(0,1,0,0,0,0);
		break;
	case SET_BUTTON:
		// If SET press
		controller->receive_event(0,0,1,0,0,0);
		break;
	case ALL_BUTTON:
		// If MODE_START/STOP_SET Held press
		controller->receive_event(0,0,0,1,0,0);
		break;
	case CONT_PRESS_MODE:
		// If MODE Held press
		controller->receive_event(0,0,0,0,1,0);
		break;
	case MODE_START_BUTTON:
		// If MODE_START/STOP Held press
		controller->receive_event(0,0,0,0,0,1);
		break;
	case INVALID_KEY:
		break;
	default:
		break;
	}
}

void* Inputs::run_inputs(void* arg){
	Inputs* self = (Inputs*)arg;

	while(1){
		self->get_inputs();
		usleep(200000);
	}

	return NULL;
}

int Inputs::readButton(){
    int data = 0, count = 0;
    int prevData = 0;
    static int contPress = 0;

    //cout<<"Key read"<<endl;
	data = HWregister.readreg(cntrlHandle);
	prevData = data;
	usleep(80000);
	data = HWregister.readreg(cntrlHandle);
	if(data != prevData)
	{
		//cout<<"Different Key Pressed"<<endl;
		if(data != ALL_BUTTON)
		   return data;
		else if(data == ALL_BUTTON)
		{
			sleep(1);
			data = HWregister.readreg(cntrlHandle);
			//cout<<"data:"<<data;
			if(data == ALL_BUTTON)
				return ALL_BUTTON;
		}
	}
	else if (data == prevData && data != 0)
	{
		//cout<<"same key pressed"<<endl;
		if(data != MODE_BUTTON)
			return data;
		usleep(50000);
		while(MODE_BUTTON == HWregister.readreg(cntrlHandle))
		{
			//cout<<"Button is pressed :"<<count<<endl;
			count++;
			if(count == 50000)
				break;

		}

		if(count == 50000)
		{
			contPress = 1;
			return CONT_PRESS_MODE;
		}
		else
		{
		    if(contPress == 1)
		    {
		    	contPress = 0;
		    	return INVALID_KEY;
		    }
		    else
			    return MODE_BUTTON;
		}
	}


	return INVALID_KEY;
}

int Inputs::whichButtonPressed(){
	int data = readButton();
	switch(data)
	{
		case 1: return SET_BUTTON;
		case 2: return START_BUTTON;
		case 4: return MODE_BUTTON;
		case 6: return MODE_START_BUTTON;
		case 7: return ALL_BUTTON;
		case 10: return CONT_PRESS_MODE;
		case 0: return INVALID_KEY;
	default:
		break;
   }
	return 0;
}
