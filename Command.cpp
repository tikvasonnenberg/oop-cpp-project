#include "Command.h"
#include "Controller.h"


Command::Command(Controller& cont) :m_controller(cont)
{

}

//================================================================================
bool Command::isCommandRequested(sf::Vector2f v)const
{
	return(m_commandRec.getGlobalBounds().contains(v));
}

//================================================================================
void  Command::draw(sf::RenderWindow & window)
{
	window.draw(m_commandRec);
}

//================================================================================
Command::~Command()
{
}
