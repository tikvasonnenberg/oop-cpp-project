#include "Rock.h"



Rock::Rock(sf::Vector2f position):StaticItem(position)
{
}


bool Rock::m_registered = Factory::Register("Rock",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Rock>(position); });

Rock::~Rock()
{
}
