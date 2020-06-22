#pragma once
#include "Gift.h"
#include "Factory.h"
class Clock :
	public Gift
{
private:
	static bool m_registeredToGiftVector;
public:
	Clock(sf::Vector2f position);
	virtual void move()override;
	~Clock();
};