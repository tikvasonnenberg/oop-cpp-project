#pragma once
#include "Command.h"
class HelpCommand :
	public Command
{
public:
	HelpCommand();
	void execute()override;
	~HelpCommand();
};

