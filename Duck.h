#pragma once
#include "State.h"
class Walk;
class Duck :
	public State
{
public:
	Duck();
	virtual std::unique_ptr<State>	handleInput(Input input)override;
	void enter(Player& player)override;
	virtual std::string getPlayerStateInStr()const override;
	virtual void move(Player& player)override;
	virtual void resetJump()override;
	~Duck();
};

