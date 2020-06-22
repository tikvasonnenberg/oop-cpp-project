#include "Duck.h"
#include "Walk.h"
#include "Rock.h"


Duck::Duck()
{
	
}

//================================================================================
void Duck::enter(Player& player)
{
	Rock::setIsMovable(true);
	player.getSprite().setPosition(player.getSprite().getPosition().x, player.getSprite().getPosition().y + 80);
	player.setAmountOftextures(REGULAR_PLAYER_DUCK_TEXTURE_AMOUNT);
	player.resetTextureIndex();
}

//================================================================================
 std::unique_ptr<State>	Duck::handleInput(Input input)
{
	 if (input == RELEASE_SPACE)
	 {
		 return std::make_unique<Walk>();
	 }
	 return nullptr;
}

 //================================================================================
  void Duck::move(Player& player)
 {

 }

  //================================================================================
 std::string Duck::getPlayerStateInStr()const
 {
	 return "PlayerDuck";
 }

 //================================================================================
  void Duck::resetJump()
 {

 }

  //================================================================================
Duck::~Duck()
{
}
