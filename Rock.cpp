#include "Rock.h"


bool Rock::m_isMovable = true;
//bool Rock::m_playerRockTopCollide = false;
Rock::Rock(sf::Vector2f position):StaticItem(position)
{
	
	int index = std::rand() % 2;
	m_sprite.setTexture( ResourceManager::getInstance().getTexture("Rock").at(index));
}

void Rock::setIsMovable(bool is_movable)
{
	m_isMovable = is_movable;

}
// void Rock::setIsCollide(bool isCollide)
//{
//	 m_playerRockTopCollide = isCollide;
//}
bool Rock::m_registered = Factory::Register("Rock",
	[](sf::Vector2f position) -> std::unique_ptr<Rock> { return std::make_unique<Rock>(position); });




Rock::~Rock()
{
}
