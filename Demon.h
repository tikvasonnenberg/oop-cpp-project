#pragma once
#include "Enemy.h"
#include "Factory.h"
#include "BidirectionalMove.h"
class Demon :
	public Enemy
{
private:
	static bool m_registeredToEnemyVector;
public:
	Demon(sf::Vector2f position);
	virtual void draw(sf::RenderWindow &window, float& duration)override;
	virtual void move()override;
	~Demon();
};
