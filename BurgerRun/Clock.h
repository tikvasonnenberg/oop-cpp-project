#pragma once
#include "Gift.h"
#include "Factory.h"
class Clock :
	public Gift
{
private:
	static bool m_registered;
public:
	Clock(sf::Vector2f position);
	~Clock();
};/*
bool Clock::m_registered = Factory::Register("Clock",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Clock>(position); });*/

