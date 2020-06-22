#include "Thief.h"

bool Thief::m_registeredToEnemyVector = Factory::RegisterToEnemyVector(
	[](sf::Vector2f position) -> std::unique_ptr<Thief> { return std::make_unique<Thief>(position); });


//==========================================================================================
Thief::Thief(sf::Vector2f position):Enemy(position, THIEF_TEXTURE_AMOUNT)
{
	m_movement = std::make_unique <StaticMove>();
	m_sprite.scale(0.8, 0.8);
	m_sprite.setPosition(position.x, position.y + 60);
}


//==========================================================================================
void Thief::draw(sf::RenderWindow &window, float&duration)
{
	TextureChanger::manageTextureChange(*this, "Thief", duration);
	GameItem::draw(window);
}

//==========================================================================================
void Thief::move()
{
	m_movement->manageMove(*this);
}

//==========================================================================================
Thief::~Thief()
{
}
