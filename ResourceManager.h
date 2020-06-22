#pragma once
#include <iostream>
#include <sfml/Graphics.hpp>
#include "Utils.h"
#include <string>
#include <cstring>
#include <map>
#include "Utils.h"
#include <vector>
using std::iostream;
using std::vector;

class ResourceManager
{
private:
	std::map<std::string, std::vector<sf::Texture>> m_textures;
	sf::Font font;
	sf::Font font2;
public:
	ResourceManager();
	std::vector<sf::Texture >& getTexture(std::string type);
	sf::Font&  getFont();
	sf::Font&  getFont2();


	static ResourceManager &getInstance()
	{
		static ResourceManager instance;
		return instance;
	}
	~ResourceManager();
};

