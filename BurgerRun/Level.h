#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Gift.h"
#include "Factory.h"
#include "DynamicItem.h"
class Level
{
private:
	Player m_player;
	std::vector<std::unique_ptr<Gift>>m_gifts;
	std::vector<std::unique_ptr<DynamicItem>>m_enemies;
	
public:
	Level();
	void run();
	void createItems();
	void complex();
	~Level();
};

