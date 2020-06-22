#pragma once
#include "State.h"
class Duck :
	public State
{
public:
	Duck();
	void enterState(Player& player)override;
	~Duck();
};

