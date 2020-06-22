#pragma once
#include "Command.h"
class Controller;
class StartCommand :
	public Command
{
public:
	StartCommand(Controller& cont);
	void execute()override;
	~StartCommand();
};

