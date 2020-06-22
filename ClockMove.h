#pragma once
#include "Move.h"
class ClockMove :
	public Move
{
protected:
	
	static double m_time;
public:
	ClockMove();
	virtual void manageMove(GameItem&  mover)override;
	static void resetClock(sf::Clock &m_clock);
	~ClockMove();
};

