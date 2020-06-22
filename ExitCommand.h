#pragma once
#include "Command.h"
class Controller;
class ExitCommand :
	public Command
{
public:
	ExitCommand(Controller& cont);
	void execute()override;
	~ExitCommand();
};

