#pragma once
#include <iostream>
#include <map>
#include <sfml/Graphics.hpp>
#include "GameItem.h"
#include <functional>
#include <algorithm>
typedef std::function<std::unique_ptr<GameItem>(sf::Vector2f position)> m_function;
typedef std::map<std::string, m_function> myMap;
typedef std::vector<m_function>	FactoryGiftVector;
typedef std::vector<m_function>	FactoryEnemyVector;
class Factory
{
private:
	static myMap& getMap()
	{
		static myMap  m_creationOptions;
		return m_creationOptions;
	}
	static FactoryGiftVector& getGiftVector()
	{
		static FactoryGiftVector m_creationOptions;
		return m_creationOptions;
	}
	static FactoryEnemyVector& getEnemyVector()
	{
		static FactoryEnemyVector m_creationOptions;
		return m_creationOptions;
	}
	Factory();
public:
	//create and register functions for the map;
	static bool Register(const std::string& type, m_function func);
	static std::unique_ptr<GameItem> create(const std::string& name, sf::Vector2f position);

	//create and register functions for the Enemy vector
	static bool RegisterToEnemyVector( m_function func);
	static std::unique_ptr<GameItem> createEnemy(const int DifficultyLevel, sf::Vector2f position);
	
	//create and register functions for the Gift vector
	static bool RegisterToGiftVector(m_function func);
	static std::unique_ptr<GameItem> createGift(sf::Vector2f position);
};


