#pragma once
#include "Gift.h"
#include "Factory.h"
class Coin :
	public Gift
{
private:
	static bool m_registered;
public:
	Coin(sf::Vector2f position);
	~Coin();
};
//
//bool Coin::m_registered = Factory::Register("Coin",
//	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Coin>(position); });