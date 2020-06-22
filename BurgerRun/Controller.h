#pragma once
#include "DynamicItem.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <sfml/Graphics.hpp>
#include "Level.h"
#include "Board.h"

class Controller
{
private:
	sf::RenderWindow m_window;
	Board m_board;
	Level m_level;
	


public:
	Controller();
	void run();

	~Controller();
};

