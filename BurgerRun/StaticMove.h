#pragma once
#include "Move.h"
class StaticMove :
	public Move
{
private:
	const int m_direction;
public:
	StaticMove(const int direction);
	virtual void manageMove(sf::Vector2f currentPosition)override;
	~StaticMove();
};

