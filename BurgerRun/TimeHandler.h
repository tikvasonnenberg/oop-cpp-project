#pragma once
#include <iostream>
#include <sfml/Graphics.hpp>
class TimeHandler
{
private:
	sf::Clock m_clock;
	std::unique_ptr<sf::Texture>m_texture;
	int m_condition;
public:
	TimeHandler();
	~TimeHandler();
};

