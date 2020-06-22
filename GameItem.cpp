#include "GameItem.h"



GameItem::GameItem(sf::Vector2f position, int amountOftextures) :m_position(position), m_textureIndex(0), m_amountOftextures(amountOftextures), m_isExistOnScreen(true)
{
	m_sprite.setPosition(position);
}
// get/set/reset functions
//=====================================================================================
int& GameItem::getTextureIndex()
{
	return m_textureIndex;
}

//-----------------------------------------------------
bool& GameItem::getIsExistOnScreen()
{
	return m_isExistOnScreen;
}

//-----------------------------------------------------
void GameItem::setIsExistOnScreen(bool isExist)
{
	m_isExistOnScreen = isExist;
}

//-----------------------------------------------------
int GameItem::getAmountOftextures()const
{
	return m_amountOftextures;
}

//-----------------------------------------------------
sf::Sprite& GameItem::getSprite()
{
	return m_sprite;
}

//-----------------------------------------------------
void GameItem::setCollided(bool collide)
{
	m_Collided = collide;
}
//-----------------------------------------------------
void GameItem::resetDuration()
{
	m_duration = float();
}

//-----------------------------------------------------
float  GameItem::getDuration()
{
	return m_duration;
}

//-----------------------------------------------------
void GameItem::setDuration(float dur)
{
	m_duration = dur;
}

//-----------------------------------------------------
void GameItem::setAmountOftextures(const int amountOfTextures)
{
	m_amountOftextures = amountOfTextures;
}

//-----------------------------------------------------
void GameItem::resetTextureIndex()
{
	m_textureIndex = 0;
}

//========================================================================================
void GameItem::draw(sf::RenderWindow &window)
{
	if (m_isExistOnScreen)
		window.draw(m_sprite);
}
GameItem::~GameItem()
{
}
