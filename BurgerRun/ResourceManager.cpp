#include "ResourceManager.h"



ResourceManager::ResourceManager()
{


		vector <sf::Texture> textures2(1);
		if(textures2[0].loadFromFile("Ground.png"))
		m_textures[GROUND] = textures2;

		vector <sf::Texture> textures3(1);
		if(textures3[0].loadFromFile("Backround.png"))
		m_textures[BACKGROUND] = textures3;


		vector <sf::Texture> vectorOfManTexture(6);
		if(vectorOfManTexture[0].loadFromFile("fatMan1.png")&&
			vectorOfManTexture[1].loadFromFile("fatMan2.png")&&
			vectorOfManTexture[2].loadFromFile("fatMan3.png")&&
			vectorOfManTexture[3].loadFromFile("fatMan4.png")&&
			vectorOfManTexture[4].loadFromFile("fatMan5.png")&&
			vectorOfManTexture[5].loadFromFile("fatMan6.png"))
			m_textures[PLAYER] = vectorOfManTexture;


		vector <sf::Texture> vectorOfCoinTexture(6);
		if (vectorOfCoinTexture[0].loadFromFile("coin1.png") &&
			vectorOfCoinTexture[1].loadFromFile("coin2.png") &&
			vectorOfCoinTexture[2].loadFromFile("coin3.png") &&
			vectorOfCoinTexture[3].loadFromFile("coin4.png") &&
			vectorOfCoinTexture[4].loadFromFile("coin5.png") &&
			vectorOfCoinTexture[5].loadFromFile("coin6.png"))
			m_textures[COIN] = vectorOfCoinTexture;
}

std::vector<sf::Texture >& ResourceManager::getTexture(const int type)
{
	return m_textures[type];
}
ResourceManager::~ResourceManager()
{
}
