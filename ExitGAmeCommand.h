#pragma once
#pragma once
#include "Command.h"
class Controller;
class ExitGAmeCommand :
	public Command
{
public:
	ExitGAmeCommand(Controller& cont);
	void execute()override;
	~ExitGAmeCommand();
};

