#include "Move.h"



Move::Move()
{
	//m_sprite.set
}
sf::Texture& Move::getNextTexture()
{
	return m_nextTexture;
}
sf::Vector2f& Move::getNextPosition()
{
	return m_nextPosition;
}

Move::~Move()
{
}
