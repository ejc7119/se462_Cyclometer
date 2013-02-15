/*
 * IDisplay_State.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef IDISPLAY_STATE_H_
#define IDISPLAY_STATE_H_
#include "Settings.h"
#include "pthread.h"
#include "Display.h"

#define AVERAGE 1
#define DISTANCE 2
#define DURATION 3
#define RESET 4
#define SPEED_SCALE 5
#define WHEEL_SIZE 6

class IDisplay_State {
protected:
	Settings* settings;
	Display* display;
public:
	IDisplay_State(Settings* set,Display* dis):
		settings(set), display(dis){}
	virtual ~IDisplay_State() {};
	// Parameters: Mode, Start/Stop, Set, Mode_Start/Stop_Set Held, Mode Held, Mode_Start/Stop Held
	virtual IDisplay_State* determine_state(int,int,int,int,int,int) = 0;
};

#endif /* IDISPLAY_STATE_H_ */
