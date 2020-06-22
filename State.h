#pragma once
#include <iostream>
#include "Utils.h"
class Player;
class State
{
protected:
	 float jumpCounter = 0.0f;
	 float freezeCounter = 0.0f;
public:
	State();
	virtual std::unique_ptr<State>	handleInput(Input input) = 0;
	virtual void enter(Player& player)=0;
	virtual void move(Player& player) = 0;
	virtual std::string getPlayerStateInStr()const = 0;
	virtual void resetJump() = 0;
	~State();
};

