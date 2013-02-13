#include <cstdlib>
#include <iostream>
#include "Settings.h"
#include "Calculations.h"
#include "Controller.h"

int main(int argc, char *argv[]) {

	Settings* settings = new Settings();
	Calculations* calculations = new Calculations(settings);
	Controller* controller = new Controller(settings, calculations);

}
