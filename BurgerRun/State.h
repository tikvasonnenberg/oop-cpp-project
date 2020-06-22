#pragma once
#include "Player.h"
class State
{
public:
	State();
	virtual void enterState(Player& player)=0;
	~State();
};

