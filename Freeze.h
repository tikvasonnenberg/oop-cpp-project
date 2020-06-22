#pragma once
#include "State.h"
#include "Player.h"
#include "Rock.h"
#include "Walk.h"
class Freeze :
	public State
{
public:
	Freeze();
	virtual std::unique_ptr<State>	handleInput(Input input)override;
	virtual void enter(Player& player)override;
	virtual std::string getPlayerStateInStr()const override;
	virtual void move(Player& player)override;
	virtual void resetJump()override;
	~Freeze();
};

