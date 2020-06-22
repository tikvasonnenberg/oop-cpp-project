#pragma once
#include "Player.h"
#include "Freeze.h"
class BubblePlayer :
	public Player
{
public:
	BubblePlayer(sf::Vector2f position);
	virtual void handleInput(Input input)override;
	void setWeapon(std::unique_ptr<Weapon> weapon)override;
	void move()override;
	~BubblePlayer();
};

