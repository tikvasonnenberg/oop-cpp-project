#include "StaticMove.h"

#include "GameItem.h"


StaticMove::StaticMove()
{
}

void StaticMove::manageMove(GameItem& mover)
{
	float movement = 1.f;
	mover.getSprite().move(-movement, 0.0f);
	if ((mover.getSprite().getPosition().x < 0 - mover.getSprite().getGlobalBounds().width))
		mover.setIsExistOnScreen(false);
}
StaticMove::~StaticMove()
{
}
