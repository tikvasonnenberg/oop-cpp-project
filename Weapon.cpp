#include "Weapon.h"



Weapon::Weapon(sf::Vector2f position, std::unique_ptr<Move> movement, const int amountOftextures):Gift(position,  amountOftextures), m_weaponMovement(std::move(movement))
{
}


Weapon::~Weapon()
{
}
