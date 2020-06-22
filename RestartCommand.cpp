#include "RestartCommand.h"
#include "Controller.h"


RestartCommand::RestartCommand(Controller& cont) :Command(cont)
{
	m_commandRec.setTexture(ResourceManager::getInstance().getTexture("ButtonReset").at(0));
	m_commandRec.setPosition(150, 40);
	m_commandRec.scale(0.5, 0.5);
}
void RestartCommand::execute()
{
	m_controller.restartGame();
}

RestartCommand::~RestartCommand()
{
}
