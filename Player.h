#pragma once
#include <iostream>
#include <sfml/Graphics.hpp>
#include "DynamicItem.h"
#include "Move.h"
#include "StaticMove.h"
#include "State.h"
#include "Weapon.h"
class Walk;
class Player:
	public DynamicItem
{

protected:
	sf::Vector2f m_originPosition;
	sf::Vector2f m_currentPosition;
	std::unique_ptr<State> m_playerState;
	bool m_PlayerFalling;
	
	float m_fallingSpeed;
	int m_action;
	static 	int m_coinsCounter;
	std::unique_ptr<Weapon> m_weapon;
	bool m_weaponActivated;
	bool m_collected;

	bool isTopCollide;
	sf::Clock m_clock;
public:
	Player(sf::Vector2f position, int amountOftextures, std::unique_ptr<State> playerState);
	virtual void handleInput(Input input)=0;
	void draw(sf::RenderWindow &window, float& duration);
	sf::Vector2f playerWalkingPosition()const;
	void setFallingSpeed(const float speed);
	float getFallingSpeed()const;
	void setIsPlayerFalling(bool falling);
	virtual void setWeapon(std::unique_ptr<Weapon> weapon)=0;
	bool getIsWeaponActivated()const;
	void setIsWeaponActivated(bool active);
	void activateWeapon();
	void setCollectedWeapon(bool collect);
	bool getIsWeaponCollected()const;
	Weapon* getWeapon();
	sf::Clock& getClock();
    virtual void move()=0;

	bool getIsTopCollide()const;
	void setIsTopCollide(bool collide);


	~Player();
};

