#include "ExitGAmeCommand.h"
#include "Controller.h"


ExitGAmeCommand::ExitGAmeCommand(Controller& cont) :Command(cont)
{
	m_commandRec.setTexture(ResourceManager::getInstance().getTexture("HomeScreenButtons").at(0));
	m_commandRec.setPosition(1300,650);
}

//=====================================================================================
void ExitGAmeCommand::execute()
{
	m_controller.getWindow().close();
}

//=====================================================================================
ExitGAmeCommand::~ExitGAmeCommand()
{
}
