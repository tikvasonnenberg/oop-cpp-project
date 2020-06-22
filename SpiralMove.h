#pragma once
#include "Move.h"
class SpiralMove :
	public Move
{
public:
	SpiralMove();
	virtual void manageMove(GameItem&  mover)override;
	~SpiralMove();
};

