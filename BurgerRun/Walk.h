#pragma once
#include "State.h"
class Walk :
	public State
{
public:
	Walk();
	void enterState(Player& player)override;
	~Walk();
};

