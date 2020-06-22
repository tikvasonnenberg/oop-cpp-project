#include "Hop.h"



Hop::Hop()
{
}

//==========================================================================
std::unique_ptr<State>	Hop::handleInput(Input input)
{
	if (input ==RELEASE_RIGHT)
	{
		return std::make_unique<Walk>();
	}
	return nullptr;
}

//==========================================================================
std::string Hop::getPlayerStateInStr()const
{
	return "PlayerHop";
}

//==========================================================================
void Hop::enter(Player& player)
{
	player.getSprite().setOrigin(0, 0);
	player.setAmountOftextures(REGULAR_PLAYER_HOP_TEXTURE_AMOUNT);
	player.resetTextureIndex();
	player.setFallingSpeed(HOP_SPEED);
	
}

//==========================================================================
void Hop::move(Player& player)
{
	player.setIsPlayerFalling(true);

}

//==========================================================================
void Hop::resetJump()
{
	jumpCounter = 0;
}

//==========================================================================
Hop::~Hop()
{
}
