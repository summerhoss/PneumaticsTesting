#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* piston_control;

	//Arm buttons
	Button* pistonForward;
	Button* pistonReverse;
	Button* pistonOff;

public:
	OI();
};

#endif  // OI_H
