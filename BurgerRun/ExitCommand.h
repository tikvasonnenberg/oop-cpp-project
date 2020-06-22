#pragma once
#include "Command.h"
class ExitCommand :
	public Command
{
public:
	ExitCommand();
	void execute()override;
	~ExitCommand();
};

