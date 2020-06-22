#pragma once
#include<SFML/Graphics.hpp>
#include "Menu.h"
#include "ExitGameCommand.h"
#include "StartCommand.h"
//#include "HelpGameScreenCommand.h"
class Controller;
class HomeScreen
{
private:
	sf::Sprite backGround;
	sf::RectangleShape transparentBackGround;
	sf::Sprite m_Winner;
	sf::Sprite m_help;
	sf::RectangleShape m_lost;
	sf::Text m_lostText;
	sf::Text m_helpText;
	sf::Text m_PlayText;
	sf::Text m_ExitText;
	sf::Text m_GameText;
	sf::RenderWindow & window;
	
	Menu m_menu;


	sf::RectangleShape transparent;
	sf::Sprite helpWindow;

	sf::Text m_ExplanationText;

	sf::Clock m_clock;
	sf::Time m_time;

	bool isPressed = false;
	int timeCounter=0;

public:
	HomeScreen(Controller & c);
	void draw(sf::RenderWindow & window);
	bool startGame(sf::RenderWindow & window);
	void gameExplanation(sf::RenderWindow & window);
	void gameEnd(sf::RenderWindow & window, bool won);
	~HomeScreen();
};

