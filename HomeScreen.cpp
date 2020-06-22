#include "HomeScreen.h"
#include "Controller.h"


HomeScreen::HomeScreen(Controller & c) :m_menu(c), window(c.getWindow())
{
	transparentBackGround.setSize({ 1920, 1080 });
	transparentBackGround.setFillColor(sf::Color(253, 255, 242, 150));

	backGround.setTexture(ResourceManager::getInstance().getTexture("HomeScreenBackground").at(0));
	backGround.setPosition(0, 100);

	m_menu.insert(std::make_unique<StartCommand>(c));
	m_menu.insert(std::make_unique<ExitGAmeCommand>(c));


	m_PlayText.setFont(ResourceManager::getInstance().getFont());
	m_PlayText.setString("PLAY");
	m_PlayText.setColor(sf::Color::White);
	m_PlayText.setCharacterSize(120);
	m_PlayText.setPosition(1450, 150);

	m_ExitText.setFont(ResourceManager::getInstance().getFont());
	m_ExitText.setString("EXIT");
	m_ExitText.setColor(sf::Color::White);
	m_ExitText.setCharacterSize(120);
	m_ExitText.setPosition(1450, 650);


	m_GameText.setFont(ResourceManager::getInstance().getFont());
	m_GameText.setString("BURGER RUN");
	m_GameText.setColor(sf::Color::Red);
	m_GameText.setCharacterSize(260);
	m_GameText.setPosition(200, 300);

	m_Winner.setTexture(ResourceManager::getInstance().getTexture("Clock1").at(0));
	m_Winner.setPosition(0, 0);

	m_lost.setFillColor(sf::Color::Red);
	m_lost.setSize({ 1920,1080 });
	m_lost.setPosition(0, 0);

	m_lostText.setFont(ResourceManager::getInstance().getFont());
	m_lostText.setString("        You Didn't Get Enough Coins \n  \n            GAME OVER!!!!!!");
	m_lostText.setColor(sf::Color::Black);
	m_lostText.setCharacterSize(120);
	m_lostText.setPosition(220, 300);

	
	m_ExplanationText.setFont(ResourceManager::getInstance().getFont());
	m_ExplanationText.setString("               INSTRUCTIONS\n\n\n\n\n\n The Objective of the game is to collect\n 150 coins by the time the store shuts.\n  Use the Up key to jump, \n Space key to duck,\n And the W key to shoot your weapon\n if collected.");
	m_ExplanationText.setColor(sf::Color::Black);
	m_ExplanationText.setCharacterSize(44);
	m_ExplanationText.setPosition(480,210);


	m_helpText.setFont(ResourceManager::getInstance().getFont());
	m_helpText.setString("INSTRUCTIONS");
	m_helpText.setColor(sf::Color::White);
	m_helpText.setCharacterSize(80);
	m_helpText.setPosition(1360, 430);

	m_help.setTexture(ResourceManager::getInstance().getTexture("HomeScreenButtons").at(0));
	m_help.setPosition(1300, 400);

	m_clock.restart();
}

//==========================================================================
void HomeScreen::draw(sf::RenderWindow & window)
{

	window.draw(backGround);
	window.draw(transparentBackGround);
	m_menu.draw(window);
	window.draw(m_help);
	window.draw(m_helpText);
	window.draw(m_GameText);
	window.draw(m_PlayText);
	window.draw(m_ExitText);

}

//==========================================================================
bool HomeScreen::startGame(sf::RenderWindow & window)
{
	while (window.isOpen())
	{
		sf::Event event;
		draw(window);
		if (isPressed)
			gameExplanation(window);
		window.display();
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (m_menu.findAndExecuteRequestedCommand(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					return true;
				else if (m_help.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					isPressed = true;
				}
			}

		}

	}
	return false;
}

//==========================================================================
void HomeScreen::gameExplanation(sf::RenderWindow & window)
{
	m_time = m_clock.getElapsedTime();
	transparent.setSize({ 1920, 1080 });
	transparent.setFillColor(sf::Color(253, 255, 242, 150));
	transparent.setPosition(0, 0);

	helpWindow.setTexture(ResourceManager::getInstance().getTexture("Help").at(0));
	helpWindow.setPosition(360, 170);

	if (m_time.asSeconds() > 1)
	{
		timeCounter++;
		m_clock.restart();
	}
	if (timeCounter < 10)
	{

		window.draw(transparent);
		window.draw(helpWindow);
		window.draw(m_ExplanationText);
	}
	else {
		timeCounter = 0;
		isPressed = false;
	}

}
void HomeScreen::gameEnd(sf::RenderWindow & window, bool won)
{
	if (won)
		window.draw(m_Winner);
	else
	{
		window.draw(m_lost);
		window.draw(m_lostText);
	}
}

//==========================================================================
HomeScreen::~HomeScreen()
{
}
