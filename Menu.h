#pragma once
#include "Command.h"
#include "ExitCommand.h"
#include "RestartCommand.h"

class Menu
{
private:
	std::vector<std::unique_ptr<Command>> m_commands;
public:
	Menu(Controller& cont);
	void insert( std::unique_ptr<Command> c);
	bool findAndExecuteRequestedCommand(sf::Vector2f v);
	void draw(sf::RenderWindow & window);
	~Menu();
};

