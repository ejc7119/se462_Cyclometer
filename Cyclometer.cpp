#include <cstdlib>
#include <iostream>
#include "Settings.h"
#include "Calculations.h"
#include "Controller.h"
#include "Sensor.h"
#include "Inputs.h"
#include <pthread.h>
#include "Display.h"

int main(int argc, char *argv[]) {

	Settings* settings = new Settings();
	Calculations* calculations = new Calculations(settings);
	Display* display = new Display(calculations);
	Controller* controller = new Controller(settings, calculations,display);
	Sensor* sensor = new Sensor(calculations);
	Inputs* inputs = new Inputs(controller);

	pthread_t inputs_thread; //the thread of the inputs
	pthread_create(&inputs_thread,NULL,Inputs::run_inputs,inputs);

	pthread_t display_thread; //the thread of the inputs
	pthread_create(&display_thread,NULL,Display::run_display,display);

	pthread_t calculations_thread;
	pthread_create(&calculations_thread,NULL,Calculations::run_calculations,calculations);

	while(1){

	}
}
