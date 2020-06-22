#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "ResourceManager.h"

class GameItem
{
protected:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	

public:
	
	GameItem(sf::Vector2f position);
	void draw( sf::RenderWindow &window)const;
	void show();
	~GameItem();
};

