#pragma once
#include "State.h"
class Hop :
	public State
{
public:
	Hop();
	void enterState(Player& player)override;
	~Hop();
};

