#pragma once
#include "GameItem.h"
#include "Move.h"

class DynamicItem :
	public GameItem
{
protected:

	
public:
	DynamicItem(sf::Vector2f position, int amountOftextures);
	virtual void draw(sf::RenderWindow &window, float &duration)=0;
	~DynamicItem();
};

