#pragma once
#include <iostream>
#include <sfml/Graphics.hpp>
#include "Utils.h"
#include <string>
#include <cstring>
#include <map>
#include "Utils.h"
using std::iostream;
#include <vector>
using std::vector;

class ResourceManager
{
private:
	std::map<const int, std::vector<sf::Texture>> m_textures;
	sf::Font font;
public:
	ResourceManager();
	std::vector<sf::Texture >& getTexture(const int type);

	static ResourceManager &getInstance()
	{
		static ResourceManager instance;
		return instance;
	}
	~ResourceManager();
};

