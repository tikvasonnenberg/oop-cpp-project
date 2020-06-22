#pragma once
#include "Gift.h"
#include "Move.h"
class Weapon :
	public Gift
{
protected:
	std::unique_ptr<Move> m_weaponMovement;
public:
	Weapon(sf::Vector2f position, std::unique_ptr<Move> movement, const int amountOftextures = DEFAULTE_TEXTURE_AMOUNT);
	virtual void weaponActivatedMove() = 0;
	~Weapon();
};

