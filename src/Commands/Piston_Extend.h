#ifndef Piston_Extend_H
#define Piston_Extend_H

#include "../CommandBase.h"
#include "WPILib.h"

class Piston_Extend : public CommandBase {
public:
	Piston_Extend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Piston_Extend_H
