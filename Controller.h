#pragma once
#include "DynamicItem.h"
#include <iostream>
#include <algorithm>
 #include <sstream>
#include <vector>
#include <sfml/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Level.h"
#include "Board.h"
#include "Menu.h"
#include "HomeScreen.h"
#include "ResourceManager.h"

class Controller
{
private:
	sf::RenderWindow m_window;

	float duration = float();
	sf::Time dt;
	sf::Clock clock;
	sf::Music m_music;
	sf::Clock m_complexClock;
	sf::Time m_complexTime;
	float m_currentTime;
	Board m_board;
	HomeScreen homeScreen;
	int m_difficultyLevel;
	Menu m_gameMenu;
	Level m_level;

	sf::Sprite m_Store;
	sf::Sprite m_timeShow;
	
	sf::Text levelUp;
	bool showLevelUp = false;
	int levelCount = 0;

	
	sf::Sprite m_weapon;
	sf::Sprite m_lost;
	sf::Sprite m_coin;
	sf::Text timeShow;
	sf::Text timeText;
	sf::Text coinText;
	sf::Text coinCounter;
	sf::Clock m_winningClock;
	sf::Clock m_ShowClock;
	sf::Time m_winningTimeClock;
	sf::Time m_ShowTimeClock;

	sf::Clock m_endGameClock;
	sf::Time m_endGameTime;

	int countDown = GAME_TIME;
	int count = 0;
	int seconds=0;
	 bool gameStart;
	 bool m_gameHelp;
	 bool m_won = false;

public:
	Controller();
	void run();
	void restartGame();
	void manageComplex();
	sf::RenderWindow & getWindow();
	void startGame(bool start);
	void gameHelp(bool help);
	void checkWinning();
	void setWinning();
	void timeUp();
	void draw();
	~Controller();
};

