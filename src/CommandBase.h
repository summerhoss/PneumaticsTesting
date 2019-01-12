#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>
#include <iostream>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/Piston.h"



/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void initialize();

	// Create a single static instance of all of your subsystems

	static std::unique_ptr<OI> oi;
	static Piston* piston;


};

#endif  // COMMAND_BASE_H
