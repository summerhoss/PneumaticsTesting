#include "Piston.h"
#include "../RobotMap.h"
#include <iostream>

Piston::Piston() : Subsystem("Piston") {
}

void Piston::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Piston::extend(){
	piston.Set(frc::DoubleSolenoid::Value::kForward);
	std::cout << "piston GetAll" << piston.GetAll() << std::endl;
}
void Piston::retract(){
	piston.Set(frc::DoubleSolenoid::Value::kReverse);
}
void Piston::solenoidOff(){
	piston.Set(frc::DoubleSolenoid::Value::kOff);
}
