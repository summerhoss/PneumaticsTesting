#ifndef Piston_Retract_H
#define Piston_Retract_H

#include "../CommandBase.h"
#include "WPILib.h"

class Piston_Retract : public CommandBase {
public:
	Piston_Retract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Piston_Retract_H
