#pragma once
#include "Move.h"
#include "GameItem.h"
class BidirectionalMove :
	public Move
{
private:
	int m_radiusOfMove;
public:
	BidirectionalMove();
	virtual void manageMove(GameItem&  mover)override;
	~BidirectionalMove();
};

