
#pragma once
#include "Player.h"
#include "Walk.h"
#include "Weapon.h"
#include "Rock.h"
class RegularPlayer :
	public Player
{
protected:
	
public:
	RegularPlayer(sf::Vector2f position);
	virtual void handleInput(Input input)override;
	void move()override;
	void setWeapon(std::unique_ptr<Weapon> weapon)override;
	void managePlayerFalling();
	~RegularPlayer();
};

