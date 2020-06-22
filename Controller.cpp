#include "Controller.h"


Controller::Controller() :m_window(sf::VideoMode(1920, 1080), "Burger Run"), m_difficultyLevel(EASY), m_gameMenu(*this), m_level(m_difficultyLevel), m_currentTime(0), homeScreen(*this), gameStart(false), m_gameHelp(false)
{
	m_gameMenu.insert(std::make_unique<ExitCommand>(*this));
	m_gameMenu.insert(std::make_unique<RestartCommand>(*this));

	

	m_Store.setTexture(ResourceManager::getInstance().getTexture("HomeScreenBackground").at(0));
	m_Store.setPosition(m_window.getSize().x, 200);

	m_weapon.setTexture(ResourceManager::getInstance().getTexture("Baguette").at(0));
	m_weapon.setPosition(m_window.getSize().x - 1000, 0);
	m_weapon.rotate(50);
	m_weapon.scale(0.5, 0.5);

	levelUp.setFont(ResourceManager::getInstance().getFont2());
	levelUp.setColor(sf::Color::Black);
	levelUp.setCharacterSize(360);
	levelUp.setPosition(400, 200);
	levelUp.setString("LEVEL UP");

	coinText.setFont(ResourceManager::getInstance().getFont());
	coinText.setColor(sf::Color::White);
	coinText.setCharacterSize(120);
	coinText.setPosition(m_window.getSize().x - 800, 0);
	coinText.setString("Coins: ");

	coinCounter.setFont(ResourceManager::getInstance().getFont());
	coinCounter.setColor(sf::Color::White);
	coinCounter.setCharacterSize(120);
	coinCounter.setPosition(m_window.getSize().x - 550, 0);

	timeShow.setFont(ResourceManager::getInstance().getFont());
	timeShow.setColor(sf::Color::White);
	timeShow.setCharacterSize(120);
	timeShow.setPosition(m_window.getSize().x - 150, 0);

	timeText.setFont(ResourceManager::getInstance().getFont());
	timeText.setColor(sf::Color::White);
	timeText.setCharacterSize(120);
	timeText.setPosition(m_window.getSize().x - 370, 0);
	timeText.setString("Time:");

	m_music.openFromFile("Daybreak.ogg");

	m_endGameClock.restart();
}

//==========================================================================================
void Controller::run()
{
	homeScreen.startGame(m_window);
	if (gameStart) {
		
		m_music.play();
		m_music.setLoop(true);
		m_music.setVolume(40);
		m_winningClock.restart();
		m_complexClock.restart();
		m_board.restart();
		m_level.restart();
		m_level.createCoins(m_board.getRocks());



		while (m_window.isOpen())
		{
			m_winningTimeClock = m_winningClock.getElapsedTime();
			m_ShowTimeClock = m_ShowClock.getElapsedTime();
			checkWinning();

			manageComplex();

			dt = clock.restart();
			duration += dt.asSeconds();
			m_level.setAllDuration(duration);

			m_level.run(m_window, m_gameMenu);

			draw();

			m_level.manageCollision(m_board.getRocks());


			m_window.display();



		}
	}
}
//==========================================================================================
void Controller::restartGame()
{
	count = 0;
	levelCount = 0;
	seconds = 0;
	m_difficultyLevel = EASY;
	m_board.restart();
	m_level.restart();
	m_level.createCoins(m_board.getRocks());

	m_winningClock.restart();
	m_complexClock.restart();
	m_level.complex();

}

//==========================================================================================
void Controller::manageComplex()
{
	m_complexTime = m_complexClock.getElapsedTime();
	if (m_complexTime.asSeconds() >= LEVEL_COMPLEX_TIME)
	{
		if (levelCount == (int)LEVEL_COMPLEX_TIME || levelCount == (int)LEVEL_COMPLEX_TIME + 1)
		{
			showLevelUp = true;
			
		}

		else {
			m_board.setBackground();
			levelCount = 0;
			showLevelUp = false;
			m_difficultyLevel++;
			m_level.complex();
			m_complexClock.restart();
		}

	}
}


//==========================================================================================
sf::RenderWindow & Controller::getWindow()
{
	return m_window;
}

//==========================================================================================
void Controller::startGame(bool start)
{
	gameStart = start;
}

//==========================================================================================
void Controller::gameHelp(bool help)
{
	m_gameHelp = help;
}

//=========================================================================================
void Controller::checkWinning()
{
	if (m_ShowTimeClock.asSeconds() > 1)
	{
		m_ShowClock.restart();
		countDown = m_level.showTime();
		m_level.setLessTime();

		levelCount++;
		count++;
		if (countDown <= 3)
		{
			timeShow.setColor(sf::Color::Red);
		}
	}

	if (count == m_level.getTime())
	{
		m_won = true;
	}
}

//============================================================
void Controller::draw()
{
	m_board.drawBoard(m_window);

	m_gameMenu.draw(m_window);

	int coins = m_level.getCoinCounter();
	if (coins <= 0)
		m_level.setCoinsCounter(0);
	coinCounter.setString(std::to_string(coins));

	m_window.draw(coinText);
	m_window.draw(coinCounter);

	m_window.draw(timeShow);
	m_window.draw(timeText);
	m_level.draw(m_window, duration);
	if (m_level.isWeapon())
		m_window.draw(m_weapon);
	if (showLevelUp)
		m_window.draw(levelUp);

	timeUp();
}

//======================================================
void Controller::setWinning()
{
	m_Store.setPosition(m_window.getSize().x, 200);
	m_won = false;
	m_level.restart();
	m_difficultyLevel = EASY;
	timeText.setColor(sf::Color::White);
	count = 0;
	seconds = 0;
	countDown = GAME_TIME;
	levelCount = 0;
	m_board.setBackground();
	run();


}

void Controller::timeUp()
{
	timeShow.setString(std::to_string(countDown));
	if (countDown <= 0)
		timeShow.setString("0");
	if (m_won == true)
	{

		m_window.draw(m_Store);
		if (m_Store.getPosition().x > 50)
			m_Store.move(-6.f, 0);
		else if (m_Store.getPosition().x <= 50)
		{
			Rock::setIsMovable(false);
			m_level.endGame();
			timeShow.setString("0");
			m_window.draw(timeShow);
			m_Store.move(0, 0);

			m_endGameTime = m_endGameClock.getElapsedTime();
			if (m_endGameTime.asSeconds() > 1)
			{
				m_endGameClock.restart();

				seconds++;
			}
			if (seconds < 2)
				m_window.draw(m_Store);
			else if (seconds < 7) {

				if (m_level.getCoinCounter() >= COINS_TO_WIN)
					homeScreen.gameEnd(m_window, true);

				else if (m_level.getCoinCounter() < COINS_TO_WIN)
					homeScreen.gameEnd(m_window, false);
			}

			else if (seconds == 7)
				setWinning();

		}


	}

}

Controller::~Controller()
{
}
