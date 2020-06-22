#pragma once
#include "DynamicItem.h"
class Enemy :
	public DynamicItem
{
protected:
	std::unique_ptr<Move> m_movement;

public:
	Enemy(sf::Vector2f position, int amountOftexture);
	virtual void move() = 0;
	
	~Enemy();
};
