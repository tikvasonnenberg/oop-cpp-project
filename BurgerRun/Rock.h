#pragma once
#include "StaticItem.h"
#include "Factory.h"
class Rock :
	public StaticItem
{
private:
	static bool m_registered;
public:
	Rock(sf::Vector2f position);
	~Rock();
};/*
bool Rock::m_registered = Factory::Register("Rock",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Rock>(position); });*/

