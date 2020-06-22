#include "Demon.h"



Demon::Demon(sf::Vector2f position):Enemy(position)
{
}


bool Demon::m_registered = Factory::Register("Demon",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Demon>(position); });

Demon::~Demon()
{
}
