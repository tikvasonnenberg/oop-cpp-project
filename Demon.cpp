#include "Demon.h"

bool Demon::m_registeredToEnemyVector = Factory::RegisterToEnemyVector(
	[](sf::Vector2f position) -> std::unique_ptr<Demon> { return std::make_unique<Demon>(position); });

//==========================================================================================
Demon::Demon(sf::Vector2f position):Enemy(position, DEMON_TEXTURE_AMOUNT)
{
	m_movement = std::make_unique <BidirectionalMove>();
	m_sprite.setPosition({1000,650});
}


//==========================================================================================
void Demon::draw(sf::RenderWindow &window, float &duration)
{
	TextureChanger::manageTextureChange(*this, "Demon", duration);
	GameItem::draw(window);
}

//==========================================================================================
void Demon::move()
{
	m_movement->manageMove(*this);
}

//==========================================================================================
Demon::~Demon()
{
}
