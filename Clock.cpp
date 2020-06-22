#include "Clock.h"


bool Clock::m_registeredToGiftVector = Factory::RegisterToGiftVector(
	[](sf::Vector2f position) -> std::unique_ptr<Clock> { return std::make_unique<Clock>(position); });

//========================================================================================
Clock::Clock(sf::Vector2f position):Gift(position)
{
	m_sprite.setTexture( ResourceManager::getInstance().getTexture("Clock")[0]);
	m_sprite.setScale({ 0.7, 0.7 });
}


//========================================================================================
void Clock::move()
{
	m_move->manageMove(*this);
}
//========================================================================================
Clock::~Clock()
{
}
