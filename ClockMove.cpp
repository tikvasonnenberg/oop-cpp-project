#include "ClockMove.h"

double ClockMove::m_time = 0;

//================================================================================
ClockMove::ClockMove()
{
}
//================================================================================
void ClockMove::resetClock(sf::Clock & m_clock)
{
	m_time = m_clock.restart().asMilliseconds();
 }

//================================================================================
void ClockMove::manageMove(GameItem&  mover)
{
	float movement = 0.6f*m_time;
	mover.getSprite().move(-movement, 0);
	if ((mover.getSprite().getPosition().x < 0 - mover.getSprite().getGlobalBounds().width))
		mover.setIsExistOnScreen(false);
}

//================================================================================
ClockMove::~ClockMove()
{
}
