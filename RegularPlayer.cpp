#include "RegularPlayer.h"



RegularPlayer::RegularPlayer(sf::Vector2f position) :Player(position, REGULAR_PLAYER_WALK_TEXTURE_AMOUNT, std::make_unique<Walk>())
{
	m_sprite.setTexture(ResourceManager::getInstance().getTexture(m_playerState->getPlayerStateInStr())[0]);
	
}


void RegularPlayer::handleInput(Input input)
{
	Player::handleInput(input);
}
void RegularPlayer::move()
{
	if (m_playerState != nullptr)
	{
		m_playerState->move(*this);
		if (m_PlayerFalling == true)
			managePlayerFalling();
	}
	//if (!Rock::getIsCollide() && m_PlayerFalling == false)
	//{
	///*	m_PlayerFalling = true;
	//	managePlayerFalling();*/
	//	getSprite().setPosition(playerWalkingPosition());
	//}

}
 void RegularPlayer::managePlayerFalling()
 {
	
		 Rock::setIsMovable(true);
		 if (m_sprite.getPosition().y < (WINDOW_SIZE_HEIGHT - SIZE_OF_GROUND-200))
		 {
			 float movement = m_fallingSpeed*2.f;
			 m_sprite.move(0.0f, movement);
		 }
		 else
		 {
			 m_PlayerFalling = false;
			 m_playerState->resetJump();
			 /*if(m_sprite.getPosition() == playerWalkingPosition())
				 m_playerState = std::make_unique<Duck>();
			 else*/
				 m_playerState = std::make_unique<Walk>();
			 m_playerState->enter(*this);
		 }
	 
 }
 void RegularPlayer::setWeapon(std::unique_ptr<Weapon> weapon)
 {
	 Player::setWeapon(std::move(weapon));
	// m_weapon = std::move(weapon);
 }
RegularPlayer::~RegularPlayer()
{
}
