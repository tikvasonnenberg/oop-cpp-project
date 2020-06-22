#include "Board.h"



Board::Board() 
{ 
	
	m_background.setTexture( ResourceManager::getInstance().getTexture("Background").at(0));

	m_ground1.setTexture(ResourceManager::getInstance().getTexture("Ground").at(0));
	m_ground2.setTexture(ResourceManager::getInstance().getTexture("Ground").at(1));
	
	m_ground1.setPosition(0, 800);
	m_ground2.setPosition(m_ground1.getGlobalBounds().width - 70, 800);

	m_land.push_back(m_ground1);
	m_land.push_back(m_ground2);


}

//draw and move functions
//==================================================================================
void Board::drawBoard(sf::RenderWindow& window)
{
	double time = m_clock.restart().asMilliseconds();
	window.draw(m_background);
	MoveLand(time,window);
	drawGround(window);

}
//--------------------------------------------------------------
void Board::drawGround(sf::RenderWindow& window)
{
	for (unsigned short int i = 0; i < m_land.size(); i++)
	{
		window.draw(m_land.at(i));
	}
	for (unsigned short int i = 0; i < m_rocks.size(); i++)
	{
		m_rocks.at(i)->draw(window);
	}
}

//--------------------------------------------------------------

void Board::MoveLand(float dt, sf::RenderWindow& window)
{
	if (Rock::getIsMovable())
	{
		for (unsigned short int i = 0; i < m_land.size(); i++)
		{
			float movement = 0.6f*dt;
			m_land.at(i).move(-movement, 0.0f);

			if (m_land.at(i).getPosition().x < 0 - m_land.at(i).getGlobalBounds().width+100)
			{
				sf::Vector2f position(window.getSize().x, m_land.at(i).getPosition().y);
				m_land.at(i).setPosition(position);
			}
		}

		for (unsigned short int i = 0; i < m_rocks.size(); i++)
		{
			float movement = 0.6f*dt;
			m_rocks.at(i)->getSprite().move(-movement, 0.0f);


			if (m_rocks.at(i)->getSprite().getPosition().x < 0 - m_rocks.at(i)->getSprite().getGlobalBounds().width + 20)
			{
				int index = std::rand() % 2;
				m_rocks.at(i)->getSprite().setTexture(ResourceManager::getInstance().getTexture("Rock").at(index), true);
				sf::Vector2f position(window.getSize().x, m_rocks.at(i)->getSprite().getPosition().y);
				m_rocks.at(i)->getSprite().setPosition(position);
			}
		}
	}

}

//==================================================================================
void Board::restart()
{
	m_clock.restart();
	m_rocks.clear();
	createRocks();
	m_background.setTexture(ResourceManager::getInstance().getTexture("Background").at(0), true);
}

void Board::setBackground()
{
	counter++;
	if (counter % 2 != 0)
		m_background.setTexture(ResourceManager::getInstance().getTexture("Background").at(1), true);
	else
		m_background.setTexture(ResourceManager::getInstance().getTexture("Background").at(0), true);
}


//===================================================================================
void Board::createRocks()
{
	std::vector<int>  YvaluesForRocks;
	sf::Vector2f position;
	for (auto i = 1; i < NUM_OF_ROCKS+1; i++)
	{
		position.x = 2000 / i;
		position.y = 350 + i * 100;
		std::unique_ptr<Rock>p(static_cast<Rock*>(Factory::create("Rock", position).release()));
		
		if (p)
		{
			m_rocks.emplace_back(std::move(p));
			
		}
	}

	
	
		
}


//===================================================================================
bool Board::isRockBounded(int y)const

{
	return y > MIN_HEIGHT_ROCK && y < MAX_HEIGHT_ROCK ? true : false;
}

//===================================================================================
std::vector<std::unique_ptr<Rock>> & Board::getRocks()
{
	return m_rocks;
}
Board::~Board()
{
}
