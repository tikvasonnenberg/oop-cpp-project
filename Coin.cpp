#include "Coin.h"


bool Coin::m_registered = Factory::Register("Coin",
	[](sf::Vector2f position) -> std::unique_ptr<Coin> { return std::make_unique<Coin>(position); });

//===============================================================================================
Coin::Coin(sf::Vector2f position) :Gift(position, COIN_TEXTURE_AMOUNT)
{}


//===============================================================================================
void Coin::draw(sf::RenderWindow &window, float&duration)
{
	TextureChanger::manageTextureChange(*this, "Coin", duration);
	GameItem::draw(window);
}

//===============================================================================================
void Coin::move()
{
	m_move->manageMove(*this);
}

//===============================================================================================
Coin::~Coin()
{
}
