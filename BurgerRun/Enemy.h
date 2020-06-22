#pragma once
#include "DynamicItem.h"
class Enemy :
	public DynamicItem
{
protected:

public:
	Enemy(sf::Vector2f position);
	~Enemy();
};
