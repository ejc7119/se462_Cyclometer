/*
 * IDisplay_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef IDISPLAY_STATE_H_
#define IDISPLAY_STATE_H_
#include "Settings.h"
#include "Calculations.h"

class IDisplay_State {
protected:
	Settings* settings;
	Calculations* calculations;
public:
	IDisplay_State(Settings* set, Calculations* calc):
		settings(set), calculations(calc) {}
	virtual ~IDisplay_State() {};
	// Parameters: Mode, Start/Stop, Set, Mode_Start/Stop_Set Held, Mode Held, Mode_Start/Stop Held
	virtual IDisplay_State* determine_state(int,int,int,int,int,int) = 0;
	virtual void update_display() = 0;
};

#endif /* IDISPLAY_STATE_H_ */
