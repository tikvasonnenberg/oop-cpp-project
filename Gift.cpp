#include "Gift.h"



Gift::Gift(sf::Vector2f position,const int amountOftextures) :StaticItem(position, amountOftextures), m_move(std::make_unique<ClockMove>())
{
}


Gift::~Gift()
{
}
