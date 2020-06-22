#include "Level.h"



Level::Level(int& difficultyLevel) :m_player(std::make_unique<RegularPlayer>(sf::Vector2f(400, 610))), m_coinsCounter(0), m_duckButtonPressed(false), m_difficultyLevel(difficultyLevel)
{
	lowerCoins.setFont(ResourceManager::getInstance().getFont());
	lowerCoins.setString(" -10");
	lowerCoins.setColor(sf::Color::White);
	lowerCoins.setCharacterSize(80);
	lowerCoins.setPosition({ 400,400 });

	clockMinus.restart();

}

//=================================================================================================
void Level::run(sf::RenderWindow& window, Menu& menu)
{

	sf::Event event;
	eventHandler(event, window, menu);
	moveGame(window);
	m_player->activateWeapon();

}

//=================================================================================================
void Level::eventHandler(sf::Event & event, sf::RenderWindow& window, Menu& menu)
{
	if (m_duckButtonPressed) {


		if (m_player->getClock().getElapsedTime().asSeconds() > 1)
		{
			m_player->handleInput(RELEASE_SPACE);
			m_duckButtonPressed = false;
			m_player->getClock().restart();
		}
		else
			m_player->handleInput(PRESS_SPACE);
	}

	else
		while (window.pollEvent(event))//&& !m_duckButtonPressed)
		{


			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}


			else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W))
			{
				if (m_player->getIsWeaponCollected())
				{
					m_player->setIsWeaponActivated(true);
					m_player->setCollectedWeapon(false);
				}
			}


			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					m_player->getClock().restart();

					m_duckButtonPressed = true;
				}

				m_player->handleInput(identifyKey(event.key.code, false));
			}

			else if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					m_duckButtonPressed == true;

				}
				else
					m_player->handleInput(identifyKey(event.key.code, true));



			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_player->getSprite().getOrigin().x == 50)
			{
				if (m_player->getSprite().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))	//m_player->handleInput(identifyKey(sf::Keyboard::B, true));
				{
					m_player = std::make_unique<RegularPlayer>(m_player->playerWalkingPosition());
					Rock::setIsMovable(true);
				}

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				menu.findAndExecuteRequestedCommand(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			}

		}

}

//=================================================================================================
Input Level::identifyKey(sf::Keyboard::Key key, bool release)
{
	switch (key)
	{

	case sf::Keyboard::Space:
	{

		if (release)
			return RELEASE_SPACE;
		return PRESS_SPACE;
	}
	case sf::Keyboard::Up:
		return PRESS_UP;
	case sf::Keyboard::Right:
		if (release)
			return RELEASE_RIGHT;
		return PRESS_RIGHT;
	case sf::Keyboard::B:
		if (release)
			return BUBBLE_POP;
	default:
		break;
	}
}

///=============================================================================
void Level::complex()
{
	
	std::srand(std::time(NULL));
	//call to create enemy function that does the below:
	if (m_difficultyLevel != EASY)
	{
		//create enemies
		if (m_difficultyLevel == MODERATE)
			createEnemies(m_difficultyLevel);
		if (m_difficultyLevel == HARD || m_difficultyLevel == SUPER_HARD || m_difficultyLevel > SUPER_HARD)
		{
			//multiply the amount of enemies and:
			createGifts();
			createEnemies(m_difficultyLevel);
		}
	}




}
//=========================================================================================
//create functions
void Level::createEnemies(int difficultyLevel)
{
	float x = 1000;
	float y = 470;
	sf::Vector2f position = { x, y };
	float density = 500 - (difficultyLevel*75.0f);
	for (int i = 0; i < (NUM_OF_ENEMIES_PER_SCREEN*difficultyLevel); i++)
	{
		position.x = x + density + i * 1000;

		int num = std::rand() % 2;
		std::cout << num;
		std::unique_ptr<Enemy>p(static_cast<Enemy*>(Factory::createEnemy(num, position).release()));

		if (p)
		{
			m_enemies.emplace_back(std::move(p));

		}
	}


}
//---------------------------------------------------------
void Level::createGifts()
{
	m_gifts.clear();
	float x = 2300;
	float y = 400;
	sf::Vector2f position = { x, y };
	float density = 500 - (m_difficultyLevel*75.0f);
	for (int i = 0; i < 1; i++)
	{
		position.x = x + density + i * 1000;
		std::unique_ptr<Gift>p(static_cast<Gift*>(Factory::createGift(position).release()));

		if (p)
		{
			m_gifts.emplace_back(std::move(p));

		}
	}


}

//-------------------------------------------------------------------
void Level::createCoins(std::vector<std::unique_ptr<Rock>>& rocks)
{
	for (int i = 0; i < rocks.size(); i++)
	{

		createCoinsInPosition(rocks.at(i)->getSprite().getPosition(), 3);
	}

	createCoinsInPosition({ 0,WINDOW_SIZE_HEIGHT - SIZE_OF_GROUND }, 10);

}

//---------------------------------------------------------------------------------------
void Level::createCoinsInPosition(const sf::Vector2f & pos, int numOfCoins)
{
	sf::Vector2f position = pos;
	//position.x = 0;
	position.y = position.y - 100;
	for (int i = 0; i < numOfCoins; i++)
	{
		position.x += 150;

		std::unique_ptr<Coin>p(static_cast<Coin*>(Factory::create("Coin", position).release()));
		if (p)
		{
			m_coins.emplace_back(std::move(p));

		}
	}
}



//=================================================================================================
void Level::setAllDuration(float dur)
{
	for (auto &i : m_coins)
		i->setDuration(dur);
	for (auto &i : m_enemies)
		i->setDuration(dur);
	m_player->setDuration(dur);
}

//move functions
//=================================================================================================

void Level::moveGame(sf::RenderWindow& window)
{
	m_player->move();
	enemiesMove(window);
	ClockMove::resetClock(m_clock);
	moveGifts(window);
	moveCoins(0, window);
}
//--------------------------------------------------------------------------
void Level::enemiesMove(sf::RenderWindow& window)
{
	for (auto &i : m_enemies)
	{
		i->move();
		if (i->getSprite().getPosition().x < 0 - i->getSprite().getGlobalBounds().width + 20)
		{
			sf::Vector2f position(window.getSize().x, (i)->getSprite().getPosition().y);
			(i)->getSprite().setPosition(position);
			i->setIsExistOnScreen(true);
			i->setCollided(false);
		}
	}
}

///-------------------------------------------------------------------------
void Level::moveCoins(float dt, sf::RenderWindow& window)
{

	if (Rock::getIsMovable())
	{
		for (auto &i : m_coins)
		{
			i->move();
			if (i->getSprite().getPosition().x < 0 - i->getSprite().getGlobalBounds().width)
			{


				sf::Vector2f position(window.getSize().x + 300, i->getSprite().getPosition().y);
				i->getSprite().setPosition(position);
				i->setIsExistOnScreen(true);
			}

		}
	}

}

//--------------------------------------------------------------------------
void Level::moveGifts(sf::RenderWindow& window)
{

	if (Rock::getIsMovable())
	{
		int counterExits = 0;
		for (auto &i : m_gifts)
		{
			i->move();
			if (i->getSprite().getPosition().x < 0 - i->getSprite().getGlobalBounds().width + 20)
			{
				counterExits++;
			}
		}
		if (counterExits == m_gifts.size())
			createGifts();
	}
}


//collision functions
//=================================================================================================
void Level::manageCollision(std::vector<std::unique_ptr<Rock>>& rockVector)
{
	int collideCounter = 0;
	bool collide = false;
	float rockLength;
	//check collision rocks VS player
	for (auto &r : rockVector)
		if (checkCollisionForTwoItems(*r, *m_player))
		{
			processCollision(*m_player, *r, *this);
		}
		else
		{
			collideCounter++;
		}
	if (collideCounter == rockVector.size() && m_player->getIsTopCollide())
	{
		m_player->getSprite().setPosition(m_player->playerWalkingPosition());
		m_player->setIsTopCollide(false);
	}
	////check collision gifts VS player
	for (auto &g : m_gifts)
		if (checkCollisionForTwoItems(*g, *m_player))
		{
			collide = true;
			processCollision(*m_player, *g, *this);
		}

	//check collision enemies VS player
	for (auto& en : m_enemies)
		if (checkCollisionForTwoItems(*en, *m_player))
		{
			collide = true;
			processCollision(*m_player, *en, *this);
		}

	for (auto& c : m_coins)
		if (checkCollisionForTwoItems(*c, *m_player))
			processCollision(*m_player, *c, *this);

	for (auto& en : m_enemies)
		if (m_player->getWeapon())
			if (checkCollisionForTwoItems(*m_player->getWeapon(), *en))
				processCollision(*en, *m_player->getWeapon(), *this);
}

//--------------------------------------------------------------------
bool Level::checkCollisionForTwoItems(GameItem& it1, GameItem& it2)
{
	//return Collision::PixelPerfectTest(it1.getSprite(), it2.getSprite());
	return it1.getSprite().getGlobalBounds().intersects(it2.getSprite().getGlobalBounds());
}

//set and get functions
//=====================================================================================
void Level::setPlayer(std::unique_ptr<Player> player)
{
	m_player = std::move(player);
}

//--------------------------------------------------
void Level::setCoinsCounter(int val)
{
	m_coin.openFromFile("coin.wav");
	m_coin.play();

	if (m_coinsCounter + val >= 0)
		m_coinsCounter += val;
	else
		m_coinsCounter = 0;
}

//------------------------------------------------------
Player* Level::getPlayer()
{
	return m_player.get();
}

//----------------------------------------------------
bool Level::isWeapon()
{
	if (m_player->getIsWeaponCollected())
		return true;
	return false;
}

int Level::getTime()
{
	return m_time;
}

void Level::setMoreTime()
{
	m_time += 5;
	m_showTime += 5;
}
int Level::showTime()
{
	return m_showTime;
}

void Level::setLessTime()
{
	m_showTime -= 1;
}

int Level::getCoinCounter()
{
	return m_coinsCounter;
}

void Level::showCoinsMinus()
{
	minues = true;
}

void Level::restart()
{
	m_coins.clear();
	m_enemies.clear();
	m_gifts.clear();
	m_player = std::make_unique<RegularPlayer>(m_player->playerWalkingPosition());
	m_coinsCounter = 0;
	m_time = GAME_TIME;
	m_showTime = GAME_TIME;
	m_clock.restart();
}

void Level::endGame()
{

	m_coins.clear();
	m_enemies.clear();
	m_gifts.clear();
}

void Level::resetTime()
{
	if (m_duckClock.getElapsedTime().asSeconds() > 2)
		m_duckButtonPressed = false;
}

void Level::draw(sf::RenderWindow& window, float &duration)
{

	float dur = duration;

	m_player->draw(window, duration);

	if (m_difficultyLevel > 0)
	{
		setAllDuration(dur);
		for (auto &i : m_enemies)
		{

			i->draw(window, dur);
		}
		for (auto &i : m_gifts)
		{

			i->draw(window);
		}
	}


	for (unsigned short int i = 0; i < m_coins.size(); i++)
	{
		m_coins.at(i)->draw(window, dur);
	}


	MinusTime = clockMinus.getElapsedTime();
	if (minues)
	{

		if (MinusTime.asSeconds() > 1)
		{
			minusTime++;
			clockMinus.restart();

		}
		if (minusTime <3)
		{
			lowerCoins.move(0, -5);
			window.draw(lowerCoins);

		}
		else
		{
			lowerCoins.setPosition({ 400,400 });
			minusTime = 0;
			minues = false;
		}

	}
}





Level::~Level()
{
}