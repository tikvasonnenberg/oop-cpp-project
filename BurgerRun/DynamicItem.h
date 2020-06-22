#pragma once
#include "GameItem.h"
#include "Move.h"

class DynamicItem :
	public GameItem
{
protected:
	std::unique_ptr<Move> m_movement;

public:
	DynamicItem(sf::Vector2f position);
	~DynamicItem();
};

