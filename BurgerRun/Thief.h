#pragma once
#include "Enemy.h"
#include "Factory.h"
class Thief :
	public Enemy
{
private:
	static bool m_registered;
public:
	Thief(sf::Vector2f position);
	~Thief();
};/*
bool Thief::m_registered = Factory::Register("Thief",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Thief>(position); });
*/
