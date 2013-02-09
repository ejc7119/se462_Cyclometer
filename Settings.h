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
	bool manual_mode;
	bool initializing;
public:
	Settings();
	int get_wheel_size();
	bool is_km_speed_scale();
	bool is_manual_mode();
	bool is_initializing();
	void increase_wheel_size();
	void switch_speed_scale();
	void switch_manual_mode();
	void switch_initializing();
};
#endif /* SETTINGS_H_ */
