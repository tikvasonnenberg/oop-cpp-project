#pragma once
#include "GameItem.h"
#include "StaticItem.h"
#include "ClockMove.h"
class Gift :
	public StaticItem
{
	protected:
		std::unique_ptr<Move> m_move;
public:
	Gift(sf::Vector2f position,  const int amountOftextures = DEFAULTE_TEXTURE_AMOUNT);
	virtual void move()=0;
	virtual ~Gift()=0;
};



