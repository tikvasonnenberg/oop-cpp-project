#include "Freeze.h"



Freeze::Freeze()
{
	
}

//=====================================================================================
void Freeze::enter(Player& player)
{
	player.setAmountOftextures(REGULAR_PLAYER_FREEZE_TEXTURE_AMOUNT);
	player.resetTextureIndex();
	Rock::setIsMovable(false);
}

//=====================================================================================
std::unique_ptr<State>	Freeze::handleInput(Input input)
{
	return nullptr;
}

//=====================================================================================
std::string Freeze::getPlayerStateInStr()const
{
	return "PlayerFreeze";
}

//=====================================================================================
void Freeze::move(Player& player)
{
	static int enterData = 0;
	if(enterData==0)
		enter(player);
	float movement = 1.f*1.f;
	freezeCounter += movement;
	if (freezeCounter < PLAYER_BUBBLE_HEIGHT&&player.getSprite().getPosition().y>0)
		player.getSprite().move(0.0f, -movement);
	else
	{
		player.getSprite().setOrigin(50,50);
		player.getSprite().rotate(1);
	}
	enterData++;
}

//=====================================================================================
void Freeze::resetJump()
{

}

//=====================================================================================
Freeze::~Freeze()
{
}
