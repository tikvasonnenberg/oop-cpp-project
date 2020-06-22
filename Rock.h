#pragma once
#include "StaticItem.h"
#include "Factory.h"

class Rock :
	public StaticItem
{
private:
	static bool m_registered;
	static bool m_isMovable;
public:

	Rock(sf::Vector2f position);
	static bool getIsMovable(){ return m_isMovable; }
	static void setIsMovable(bool is_movable);
	~Rock();
};
