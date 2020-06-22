#include "Jump.h"
#include "Rock.h"


Jump::Jump()
{
}

//==========================================================================
void Jump::enter(Player& player)
{
	player.getSprite().setOrigin(0, 0);
	Rock::setIsMovable(true);
	player.setAmountOftextures(REGULAR_PLAYER_JUMP_TEXTURE_AMOUNT);
	player.resetTextureIndex();
	player.setFallingSpeed(FALL_SPEED);
	
}


//==========================================================================
std::unique_ptr<State>	Jump::handleInput(Input input)
{
	if (input == PRESS_RIGHT)
	{

		return std::make_unique<Hop>();
	}

	if (input == RELEASE_UP)
	{

		return std::make_unique<Walk>();
	}
	if (input == RELEASE_RIGHT)
	{
		return std::make_unique<Walk>();
	}

	return nullptr;
}

//==========================================================================
std::string Jump::getPlayerStateInStr()const
{
	return "PlayerJump";
}

void Jump::resetJump()
{
	jumpCounter = 0;
}
void Jump::move(Player& player)
{

	float movement = 2.f*2.f;
	jumpCounter += movement;
	if (jumpCounter < PLAYER_JUMP_HEIGHT&&player.getSprite().getPosition().y>0)
		player.getSprite().move(0.0f, -movement);
	else
	{
		player.setIsPlayerFalling(true);
		
	}
		

}
Jump::~Jump()
{
}
