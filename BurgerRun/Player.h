#pragma once
#include <iostream>
#include <sfml/Graphics.hpp>
#include "DynamicItem.h"
#include "Move.h"
class Player:
	public DynamicItem
{
private:
	sf::Vector2f m_originPosition;
	sf::Vector2f m_nextPosition;

	int m_action;



public:
	Player(sf::Vector2f position);
	~Player();
};

