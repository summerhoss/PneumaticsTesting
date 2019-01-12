#include "CommandBase.h"
#include <iostream>

#include <Commands/Scheduler.h>



// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.


Piston* CommandBase::piston = nullptr;

std::unique_ptr<OI> CommandBase::oi;



CommandBase::CommandBase(const std::string &name) {

}



void CommandBase::initialize()
{

	piston = new Piston();
	std::cout << "drivetrain constructor completed" << std::endl;
	oi = std::make_unique<OI>();
	std::cout << "commandBase initialize completed" << std::endl;


}
