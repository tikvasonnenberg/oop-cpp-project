#include "Baguette.h"

bool Baguette::m_registeredToGiftVector = Factory::RegisterToGiftVector(
	[](sf::Vector2f position) -> std::unique_ptr<Baguette> { return std::make_unique<Baguette>(position); });


//============================================================================================
Baguette::Baguette(sf::Vector2f position):Weapon(position,  std::make_unique <SpiralMove>(), BAGUETTE_TEXTURE_AMOUNT)
{
	m_sprite.setTexture(ResourceManager::getInstance().getTexture("Baguette").at(0));
	m_sprite.setScale({ 0.5, 0.5 });
	m_sprite.rotate(20);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
}


//============================================================================================
void Baguette::weaponActivatedMove()
{
	m_weaponMovement->manageMove(*this);
}

//============================================================================================
void Baguette::move()
{
	m_move->manageMove(*this);
}

//============================================================================================
Baguette::~Baguette()
{
}
