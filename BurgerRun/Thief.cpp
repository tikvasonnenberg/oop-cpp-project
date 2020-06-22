#include "Thief.h"



Thief::Thief(sf::Vector2f position):Enemy(position)
{
}

bool Thief::m_registered = Factory::Register("Thief",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Thief>(position); });



Thief::~Thief()
{
}
