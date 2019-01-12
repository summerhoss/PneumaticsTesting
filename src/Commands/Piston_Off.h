#ifndef Piston_Off_H
#define Piston_Off_H

#include "../CommandBase.h"
#include "WPILib.h"

class Piston_Off : public CommandBase {
public:
	Piston_Off();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Piston_Off_H
