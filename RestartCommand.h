#pragma once
#include "Command.h"
class Controller;
class RestartCommand :
	public Command
{
public:
	RestartCommand(Controller& cont);
	void execute()override;
	~RestartCommand();
};

