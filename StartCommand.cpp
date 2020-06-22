#include "StartCommand.h"
#include "Controller.h"


StartCommand::StartCommand(Controller& cont) :Command(cont)
{
	m_commandRec.setTexture(ResourceManager::getInstance().getTexture("HomeScreenButtons").at(0));
	m_commandRec.setPosition(1300, 150);

	
}

void StartCommand::execute()
{
	m_controller.startGame(true);

}

StartCommand::~StartCommand()
{
}
