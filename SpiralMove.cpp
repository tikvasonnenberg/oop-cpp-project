#include "SpiralMove.h"



SpiralMove::SpiralMove()
{
}

void SpiralMove::manageMove(GameItem&  mover)
{
	static float rotate = 20.f;
	float movement = 2.f;
	mover.getSprite().rotate(rotate);
	mover.getSprite().move(movement, 0);
	if ((mover.getSprite().getPosition().x > WINDOW_SIZE_WIDTH))
		mover.setIsExistOnScreen(false);
}
SpiralMove::~SpiralMove()
{
}
