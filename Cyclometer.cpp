#include <cstdlib>
#include <iostream>
#include "Settings.h"
#include "Calculations.h"
#include "Controller.h"
#include "Sensor.h"
#include "Inputs.h"
#include <pthread.h>

int main(int argc, char *argv[]) {

	Settings* settings = new Settings();
	Calculations* calculations = new Calculations(settings);
	Controller* controller = new Controller(settings, calculations);
	Sensor* sensor = new Sensor(calculations);
	Inputs* inputs = new Inputs(controller);

	pthread_t inputs_thread; //the thread of the inputs
	pthread_create(&inputs_thread,NULL,Inputs::run_inputs,inputs);

}
