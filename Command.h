#pragma once
class Controller;
#include <sfml/Graphics.hpp>
#include "ResourceManager.h"

class Command
{
protected:
	Controller& m_controller;
	sf::Sprite m_commandRec;
public:
	Command(Controller& cont);
	bool isCommandRequested(sf::Vector2f v)const;
	virtual void execute() = 0;
	virtual void draw(sf::RenderWindow & window);
	~Command();
};

