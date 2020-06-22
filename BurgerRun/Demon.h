#pragma once
#include "Enemy.h"
#include "Factory.h"
class Demon :
	public Enemy
{
private:
	static bool m_registered;
public:
	Demon(sf::Vector2f position);
	~Demon();
};
