#pragma once
#include <iostream>
#include "ResourceManager.h"
#include "Rock.h"
class Board
{
private:
	std::vector<std::unique_ptr<Rock>> m_rocks;

	//============sfml objects==========
	sf::Sprite m_background;
	sf::Sprite m_ground1;
	sf::Sprite m_ground2;
	std::vector<sf::Sprite> m_land;
	sf::Clock m_clock;
	

public:
	Board();

	//===========board Display ============
	void drawBoard(sf::RenderWindow& window);
	void drawGround(sf::RenderWindow& window);
	void MoveLand(float dt, sf::RenderWindow& window);

	//create Rock
	void createRocks();

	std::vector<std::unique_ptr<Rock>> & getRocks();
	void restart();
	bool isRockBounded(int y)const; 

	int counter = 0;
	void setBackground();
	~Board();
};

