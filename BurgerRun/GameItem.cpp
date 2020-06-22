#include "GameItem.h"



GameItem::GameItem(sf::Vector2f position) :m_position(position)
{
}

void GameItem::draw(sf::RenderWindow &window)const
{
	
}
void GameItem::show()
{
	std::cout << "factory works ";
}
GameItem::~GameItem()
{
}
