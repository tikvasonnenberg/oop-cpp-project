#include "Player.h"
#include "Walk.h"

int Player::m_coinsCounter = 0;  
Player::Player(sf::Vector2f position, int amountOftextures, std::unique_ptr<State> playerState) :DynamicItem(position, amountOftextures), m_playerState(std::move(playerState)), m_PlayerFalling(false), m_weapon(nullptr), m_weaponActivated(false), m_collected(false),isTopCollide(false)
{
	
	m_sprite.scale(0.7, 0.7);
}
void Player::setFallingSpeed(const float speed)
{
	m_fallingSpeed = speed;
}
float Player::getFallingSpeed()const
{
	return m_fallingSpeed;
}
sf::Clock& Player::getClock()
{
	return m_clock;
}
 void Player::handleInput(Input input)
{
	std::unique_ptr<State> state_ = m_playerState->handleInput(input);
	if (state_)
	{
		m_playerState = std::move(state_);
		m_playerState->enter(*this);
	}
}

 sf::Vector2f  Player::playerWalkingPosition()const
 {
	 return { 400, 610 };
 }

 void Player::draw(sf::RenderWindow &window, float& duration)
 {
	 std::string playerState = m_playerState->getPlayerStateInStr();
	 TextureChanger::manageTextureChange(*this, playerState, duration);
	 GameItem::draw(window);
	 if(m_weapon!=nullptr)
	 m_weapon->draw(window);
	 //window.draw(m_sprite);
 }

 void Player::setWeapon(std::unique_ptr<Weapon> weapon)
 {
	
	 m_weapon = std::move(weapon);
	 m_weapon->setIsExistOnScreen(false);
 }
 void Player::setIsPlayerFalling(bool falling)
 {
	 m_PlayerFalling = falling;
 }
 bool Player::getIsWeaponActivated()const
 {
	 return m_weaponActivated;
 }
 bool Player::getIsWeaponCollected()const
 {
	 return m_collected;
 }
 void Player::activateWeapon()
 {
	 if (m_weaponActivated)
 		 m_weapon->weaponActivatedMove();
	
 }
 void Player::setCollectedWeapon(bool collect)
 {
	 m_collected=collect;
 }
 void Player::setIsWeaponActivated(bool active)
 {
	 m_weaponActivated = active;
	 m_weapon->setIsExistOnScreen(true);
	 m_weapon->getSprite().setPosition(playerWalkingPosition().x, playerWalkingPosition().y+50);

 }
 Weapon* Player::getWeapon()
 {
	 return m_weapon.get();
 }
 bool Player::getIsTopCollide()const
 {
	 return isTopCollide;
 }
 void Player::setIsTopCollide(bool collide)
 {
	 isTopCollide = collide;
 }
Player::~Player()
{
}
