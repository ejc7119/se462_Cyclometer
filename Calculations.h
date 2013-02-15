/*
 * Calculations.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_
#include "Settings.h"

class Calculations{
private:
	double average_speed;
	double current_speed;
	double distance;
	double duration;
	Settings* settings;
public:
	Calculations(Settings*);
	double get_average_speed();
	double get_current_speed();
	double get_distance();
	double get_duration();
	void receive_pulse();
	int get_wheel_size();
	void reset();
	void full_reset();
};

#endif /* CALCULATIONS_H_ */
