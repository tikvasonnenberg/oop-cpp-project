#pragma once
#include <sfml/Graphics.hpp>
#include <vector>
#include "TextureChanger.h"

class GameItem;
using std::vector;
class Move
{
protected:
public:
	Move();

	virtual void manageMove(GameItem&  mover) = 0;
	~Move();
};

