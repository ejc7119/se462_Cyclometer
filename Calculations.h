/*
 * Calculations.h
 *
 *  Created on: Feb 4, 2013
 *      Author: ejc7119
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_
#include "Settings.h"
#include "pthread.h"

class Calculations{
private:
	double average_speed;
	double current_speed;
	double distance;
	double duration;
	Settings* settings;
	bool calculating;
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
	void start_calculations();
	void stop_calculations();
	bool is_calculating();
	static void* run_calculations(void*);
};

#endif /* CALCULATIONS_H_ */
