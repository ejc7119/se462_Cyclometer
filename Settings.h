/*
 * Settings.h
 *
 *  Created on: Feb 9, 2013
 *      Author: ejc7119
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

// Class for storing the wheel size and speed scale

class Settings{
private:
	int wheel_size;
	bool km_speed_scale;
public:
	Settings();
	int get_wheel_size();
	bool is_km_speed_scale();
	void increase_wheel_size();
	void switch_speed_scale();
};
#endif /* SETTINGS_H_ */
