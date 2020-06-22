#include "Coin.h"



Coin::Coin(sf::Vector2f position) :Gift(position)
{
	//m_texture=ResourceManager::getInstance().getTexture()
	
}


bool Coin::m_registered = Factory::Register("Coin",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Coin>(position); });
Coin::~Coin()
{
}
