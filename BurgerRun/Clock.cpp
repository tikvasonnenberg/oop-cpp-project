#include "Clock.h"



Clock::Clock(sf::Vector2f position):Gift(position)
{
	m_texture = ResourceManager::getInstance().getTexture(CLOCK)[0];
}

bool Clock::m_registered = Factory::Register("Clock",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Clock>(position); });


Clock::~Clock()
{
}
