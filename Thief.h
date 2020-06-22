#pragma once
#include "Enemy.h"
#include "Factory.h"
#include "StaticMove.h"
class Thief :
	public Enemy
{
private:
	
	static bool m_registeredToEnemyVector;
public:
	Thief(sf::Vector2f position);
	virtual void draw(sf::RenderWindow &window, float& duration)override;
	virtual void move()override;

	~Thief();
};/*
bool Thief::m_registered = Factory::Register("Thief",
	[](sf::Vector2f position) -> std::unique_ptr<GameItem> { return std::make_unique<Thief>(position); });
*/
