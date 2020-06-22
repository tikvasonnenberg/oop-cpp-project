#include "Level.h"



Level::Level():m_player(sf::Vector2f(2,2))
{
}

void Level::createItems()
{
	for (int i = 0; i < 20; i++)
		auto p = Factory::create("coin", { i + 20, 6 });
	if (p)
		p->show();
}
void Level::complex()
{

}
Level::~Level()
{
}
