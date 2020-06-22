#include "BubblePlayer.h"



BubblePlayer::BubblePlayer(sf::Vector2f position) :Player(position, BUBBLE_PLAYER_TEXTURE_AMOUNT, std::make_unique<Freeze>())
{
}

//===================================================================================
void BubblePlayer::handleInput(Input input)
{

}

//===================================================================================
void BubblePlayer::setWeapon(std::unique_ptr<Weapon> weapon)
{
}

//===================================================================================
void BubblePlayer::move()
{
	m_playerState->move(*this);
}

//===================================================================================
BubblePlayer::~BubblePlayer()
{
}
