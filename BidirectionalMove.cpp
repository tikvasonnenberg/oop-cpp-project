#include "BidirectionalMove.h"


//============================================================================================
BidirectionalMove::BidirectionalMove()
{
}

//============================================================================================
void BidirectionalMove::manageMove(GameItem&  mover)
{
	float movement = 1.f;
	if (mover.getTextureIndex() >= START_RIGHT_DIREACTION && mover.getTextureIndex() <= 5)
	{
		mover.getSprite().move(movement, 0.0f);
	}

	else if (mover.getTextureIndex() >= START_LEFT_DIREACTION && mover.getTextureIndex() <= END_LEFT_DIREACTION)
	{
		mover.getSprite().move(-movement, 0.0f);
	}
	
	if ((mover.getSprite().getPosition().x < 0 - mover.getSprite().getGlobalBounds().width))
		mover.setIsExistOnScreen(false);

}

//============================================================================================
BidirectionalMove::~BidirectionalMove()
{
}
