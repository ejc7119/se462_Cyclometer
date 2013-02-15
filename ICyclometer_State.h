/*
 * ICyclometer_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef ICYCLOMETER_STATE_H_
#define ICYCLOMETER_STATE_H_
#include "Settings.h"
#include "Calculations.h"

class ICyclometer_State {
protected:
	Settings* settings;
	Calculations* calculations;
public:
	// Parameters: Wheel Size, Speed Scale (true = km)
	ICyclometer_State(Settings* set,Calculations* calc):
		settings(set), calculations(calc) {}
	virtual ~ICyclometer_State() {};
	// Parameters: Mode, Start/Stop, Set, Mode_Start/Stop_Set Held, Mode Held, Mode_Start/Stop Held
	virtual ICyclometer_State* determine_state(int,int,int,int,int,int) = 0;
};
#endif /* ICYCLOMETER_STATE_H_ */
