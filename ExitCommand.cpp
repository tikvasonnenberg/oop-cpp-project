#include "ExitCommand.h"
#include "Controller.h"


ExitCommand::ExitCommand(Controller& cont) :Command(cont)
{
	m_commandRec.setTexture(ResourceManager::getInstance().getTexture("ButtonExit").at(0));
	m_commandRec.setPosition(30, 40);
	m_commandRec.scale(0.5, 0.5);
}

//=====================================================================================
void ExitCommand::execute()
{
	m_controller.run();
}


//=====================================================================================
ExitCommand::~ExitCommand()
{
}
