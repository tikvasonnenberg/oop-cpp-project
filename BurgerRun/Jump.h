#pragma once
#include "State.h"
class Jump :
	public State
{
public:
	Jump();
	void enterState(Player& player)override;
	~Jump();
};

