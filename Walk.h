#pragma once
#include "State.h"
#include "Jump.h"
#include "Duck.h"
#include "Player.h"
class Walk :
	public State
{
public:
	Walk();
	virtual std::unique_ptr<State>	handleInput(Input input)override;
	virtual void move(Player& player)override;
	void enter(Player& player)override;
	virtual std::string getPlayerStateInStr()const override;
	virtual void resetJump()override;
	~Walk();
};

