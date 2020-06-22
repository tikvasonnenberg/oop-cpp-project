#pragma once
#include <sfml/Graphics.hpp>
#include <vector>
using std::vector;
class Move
{
protected:
	std::vector<sf::Texture> m_textures;
	sf::Texture m_nextTexture;
	sf::Vector2f m_nextPosition;
public:
	Move();
	sf::Texture& getNextTexture();
	sf::Vector2f& getNextPosition();
	virtual void manageMove(sf::Vector2f currentPosition) = 0;
	~Move();
};

