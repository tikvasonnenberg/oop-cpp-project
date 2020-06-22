#pragma once
#include "Move.h"
class BidirectionalMove :
	public Move
{
private:
	int m_radiusOfMove;
public:
	BidirectionalMove();
	virtual void manageMove(sf::Vector2f currentPosition)override;
	~BidirectionalMove();
};

