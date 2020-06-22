#include "Walk.h"



Walk::Walk()
{
	
}
void Walk::enter(Player& player)
{
	player.getSprite().setOrigin(0, 0);
	player.getSprite().setPosition(player.playerWalkingPosition());
	player.setAmountOftextures(REGULAR_PLAYER_WALK_TEXTURE_AMOUNT);
	player.resetTextureIndex();
}
std::unique_ptr<State>	Walk::handleInput(Input input)
{
	if (input == PRESS_UP)
	{

		return std::make_unique<Jump>();
	}
	if (input == PRESS_SPACE)
	{

		return std::make_unique<Duck>();
	}
	return nullptr;
}
std::string Walk::getPlayerStateInStr()const
{
	return "PlayerWalk";
}
void Walk::move(Player& player)
{

}

void Walk::resetJump()
{

}
Walk::~Walk()
{
}
