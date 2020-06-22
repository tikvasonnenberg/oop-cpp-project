#include "Factory.h"


Factory::Factory()
{
}

//register and create to coin and rock
//=====================================================================================
std::unique_ptr<GameItem> Factory::create(const std::string& name, sf::Vector2f position) {
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(position);
}


//-------------------------------------------------------------------------
bool Factory::Register(const std::string& name, m_function func) {
	getMap().emplace(name, func);
	return true;
}
//register and create to enemy
//=====================================================================================
 bool Factory::RegisterToEnemyVector(m_function func)
{
	 getEnemyVector().push_back(func);//can not do emplace. why??
	 return true;
}

 //------------------------------------------------------------------------------
 std::unique_ptr<GameItem> Factory::createEnemy(const int DifficultyLevel, sf::Vector2f position)
{

	 if (DifficultyLevel >= 0 && DifficultyLevel < NUM_OF_DIFFICULTY_LEVELS)
		 return getEnemyVector().at(DifficultyLevel)(position);
	 return nullptr;
}

 //register and create to gift
 //=====================================================================================
 bool Factory::RegisterToGiftVector(m_function func)
 {
	 getGiftVector().push_back(func);
	 return true;
 }

 //-----------------------------------------------------------------------
 std::unique_ptr<GameItem> Factory::createGift( sf::Vector2f position)
 {
	 std::srand(std::time(NULL));
	 int num = std::rand() % getGiftVector().size();
	 if (num >= 0 && num < NUM_OF_DIFFICULTY_LEVELS)
		 return getGiftVector().at(num)(position);
	 return nullptr;
 }