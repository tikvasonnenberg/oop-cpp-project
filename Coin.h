#pragma once
#include "Gift.h"
#include "Factory.h"
#include "TextureChanger.h"
class Coin :
	public Gift
{
private:
	static bool m_registered;
public:
	Coin(sf::Vector2f position);
	void draw(sf::RenderWindow &window, float&duration);
	virtual void move()override;
	~Coin();
};
