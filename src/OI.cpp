#include "OI.h"
#include <WPILib.h>
#include "Commands/Piston_Extend.h"
#include "Commands/Piston_Retract.h"
#include "Commands/Piston_Off.h"


OI::OI()
{
	piston_control = new Joystick(0);
	pistonForward = new JoystickButton(piston_control,6);
	pistonReverse = new JoystickButton(piston_control,7);
	pistonOff = new JoystickButton(piston_control,8);

	pistonForward->WhenPressed(new Piston_Extend());
	pistonForward->WhenReleased(new Piston_Off());
	pistonReverse->WhenPressed(new Piston_Retract());
	pistonReverse->WhenReleased(new Piston_Retract());
	pistonOff->WhenPressed(new Piston_Off());
}


