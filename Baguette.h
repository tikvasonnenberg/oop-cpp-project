#pragma once
#include "Weapon.h"
#include "Factory.h"
#include "SpiralMove.h"
class Baguette :
	public Weapon
{
protected:
	static bool m_registeredToGiftVector;
public:
	Baguette(sf::Vector2f position);
	virtual void weaponActivatedMove()override;
	virtual void move()override;
	~Baguette();
};

