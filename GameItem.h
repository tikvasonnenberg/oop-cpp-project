#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "ResourceManager.h"
#include "Utils.h"

class GameItem
{
protected:
	sf::Vector2f m_position;
	int m_textureIndex;
	sf::Sprite m_sprite;
	int m_amountOftextures;
	bool m_isExistOnScreen;
	bool m_Collided;
	float m_duration = float();
	

public:
	
	GameItem(sf::Vector2f position, int amountOftextures);
	void draw( sf::RenderWindow &window);
	bool& getIsExistOnScreen();
	void setIsExistOnScreen(bool isExist);
	sf::Sprite &getSprite();
	int& getTextureIndex();
	int getAmountOftextures()const;
	void setAmountOftextures(const int amountOfTextures);
	void resetTextureIndex();
	void resetDuration();
	float  getDuration();
	void setDuration(float dur);
	void setCollided(bool collide);
	bool getCollided() { return m_Collided; };
	virtual ~GameItem()=0;
};

