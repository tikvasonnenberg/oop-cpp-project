#include "HelpCommand.h"



HelpCommand::HelpCommand(Controller& cont) :Command(cont)
{
	m_commandRec.setTexture(ResourceManager::getInstance().getTexture("ButtonHelp").at(0));
	m_commandRec.setPosition(270, 45);
	m_commandRec.scale(0.5, 0.5);
}

//==========================================================================
void HelpCommand::execute()
{
	m_controller
}

//==========================================================================
HelpCommand::~HelpCommand()
{
}
