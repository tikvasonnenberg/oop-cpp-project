#pragma once
#include "GameItem.h"

#include <iostream>
#include <typeinfo>

// Sample struct for exception throwing
struct UnknownCollision
{
	UnknownCollision(GameItem& a, GameItem& b) : first(a), second(b)
	{
		std::cout << "Unkown collision of " << typeid(a).name() << " and "
			<< typeid(b).name() << std::endl;
	}
	GameItem& first;
	GameItem& second;
};

