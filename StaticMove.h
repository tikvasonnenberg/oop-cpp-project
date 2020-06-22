#pragma once
#include "Move.h"
class StaticMove :
	public Move
{
private:

public:
	StaticMove();
	virtual void manageMove(GameItem&  mover)override;
	~StaticMove();
};

