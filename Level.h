#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "RegularPlayer.h"
#include "BubblePlayer.h"
#include "Gift.h"
#include "Factory.h"
#include "Utils.h"
#include "Coin.h"
#include "Rock.h"
#include <memory>
#include "Enemy.h"
#include "TextureChanger.h"
#include "CollisionHandling.h"
#include "Menu.h"
#include "ClockMove.h"
class Level
{
private:
	std::unique_ptr<Player> m_player;
	std::vector<std::unique_ptr<Gift>>m_gifts;
	std::vector<std::unique_ptr<Enemy>>m_enemies;
	std::vector<std::unique_ptr<Coin>>m_coins;
	int m_coinsCounter;
	int m_time = GAME_TIME;
	int m_showTime = GAME_TIME;
	sf::Clock m_clock;
	sf::Clock m_duckClock;
	sf::Text lowerCoins;
	bool m_duckButtonPressed;
	int& m_difficultyLevel;


	sf::Clock clockMinus;
	sf::Time MinusTime;
	int minusTime=0;
	sf::Music m_coin;
	
public:
	Level(int& difficultyLevel);
	void run(sf::RenderWindow& window, Menu& menu);

	void complex();
	void createEnemies(int difficultyLevel);
	void createGifts();
	void moveGifts(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, float &duration);

	void createCoins(std::vector<std::unique_ptr<Rock>> &rocks);
	void createCoinsInPosition(const sf::Vector2f & pos, int numOfCoins);
	void moveCoins(float dt, sf::RenderWindow& window);

	void eventHandler(sf::Event & event, sf::RenderWindow& window, Menu& menu);
	Input identifyKey(sf::Keyboard::Key key, bool release);
	void manageCollision(std::vector<std::unique_ptr<Rock>>& rockVector);
	bool checkCollisionForTwoItems(GameItem& it1, GameItem& it2);

	void enemiesMove(sf::RenderWindow& window);
	void moveGame(sf::RenderWindow& window);

	void setPlayer(std::unique_ptr<Player> player);
	void setCoinsCounter(int val);
	int  getCoinCounter();
	void setAllDuration(float dur);
	void restart();

	void resetTime();

	int getTime();
	int showTime();
	void setMoreTime();
	void setLessTime();
	bool isWeapon();

	bool minues = false;
	void showCoinsMinus();
	void endGame();

	Player* getPlayer();
	~Level();
};

