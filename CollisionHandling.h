#pragma once
#include "GameItem.h"
#include <SFML/Audio.hpp>
class Level;


#include <iostream>
#include <typeinfo>
#include <memory>
#include "Baguette.h"

void processCollision(GameItem& object1, GameItem& object2, Level& level);


