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
		cout << "MODE PRESS" << endl;
		break;
	case START_BUTTON:
		// If START/STOP press
		controller->receive_event(0,1,0,0,0,0);
		cout << "START/STOP PRESS" << endl;
		break;
	case SET_BUTTON:
		// If SET press
		controller->receive_event(0,0,1,0,0,0);
		cout << "SET PRESS" << endl;
		break;
	case ALL_BUTTON:
		// If MODE_START/STOP_SET Held press
		controller->receive_event(0,0,0,1,0,0);
		cout << "ALL BUTTON PRESS" << endl;
		break;
	case CONT_PRESS_MODE:
		// If MODE Held press
		controller->receive_event(0,0,0,0,1,0);
		cout << "MODE HELD" << endl;
		break;
	case MODE_START_BUTTON:
		// If MODE_START/STOP Held press
		controller->receive_event(0,0,0,0,0,1);
		cout << "MODE START/STOP HELD" << endl;
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

int Inputs::whichButtonPressed(){
	int data = HWregister.readreg(cntrlHandle);
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
