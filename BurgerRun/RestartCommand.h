#pragma once
#include "Command.h"
class RestartCommand :
	public Command
{
public:
	RestartCommand();
	void execute()override;
	~RestartCommand();
};

