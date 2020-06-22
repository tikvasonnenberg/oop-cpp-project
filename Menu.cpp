#include "Menu.h"



Menu::Menu(Controller& cont)
{
	
}
void Menu::insert(std::unique_ptr<Command> c)
{
	m_commands.emplace_back(std::move (c));
}

bool Menu::findAndExecuteRequestedCommand(sf::Vector2f v)
{
	for (auto& i : m_commands)
		if (i->isCommandRequested(v))
		{
			i->execute();
			return true;
		}
	return false;
}
void  Menu::draw(sf::RenderWindow & window)
{
	for (auto & i : m_commands)
		i->draw(window);
}
Menu::~Menu()
{
}
