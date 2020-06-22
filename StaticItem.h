#pragma once
#include "GameItem.h"
class StaticItem :
	public GameItem
{
protected:

public:
	StaticItem(sf::Vector2f position, const int amountOftextures = DEFAULTE_TEXTURE_AMOUNT);
	~StaticItem();
};

