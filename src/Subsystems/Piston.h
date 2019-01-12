#ifndef Piston_H
#define Piston_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Piston : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::DoubleSolenoid piston {2,3};
public:
	Piston();
	void InitDefaultCommand();
	void extend();
	void retract();
	void solenoidOff();
};

#endif  // Piston_H
