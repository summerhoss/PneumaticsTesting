#include "Piston_Off.h"

Piston_Off::Piston_Off() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(piston);
}

// Called just before this Command runs the first time
void Piston_Off::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Piston_Off::Execute() {
	piston->solenoidOff();
}

// Make this return true when this Command no longer needs to run execute()
bool Piston_Off::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void Piston_Off::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Piston_Off::Interrupted() {

}
