#pragma once
#include "GameItem.h"
#include "StaticItem.h"
class Gift :
	public StaticItem
{
	protected:
public:
	Gift(sf::Vector2f position);
	~Gift();
};



