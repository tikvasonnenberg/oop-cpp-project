#pragma once
#include <iostream>
#include <map>
#include <sfml/Graphics.hpp>
#include "GameItem.h"
#include <functional>
#include <algorithm>
typedef std::function<std::unique_ptr<GameItem>(sf::Vector2f position)> m_function;
typedef std::map<std::string, m_function> myMap;
class Factory
{
private:
	static myMap& getMap()
	{
		static myMap  m_creationOptions;
		return m_creationOptions;
	}
	Factory();
public:
	static bool Register(const std::string& type, m_function func);
	static std::unique_ptr<GameItem> create(const std::string& name, sf::Vector2f position);
	
	//~Factory();
};


