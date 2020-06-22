#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeindex>
#include <typeinfo>
#include "Clock.h"
#include "Coin.h"
#include "Demon.h"
#include "RegularPlayer.h"
#include "BubblePlayer.h"
#include "Rock.h"
#include "Thief.h"
#include "Baguette.h"
#include "Level.h"

namespace {
	using HitFunctionPtr = void(*)(GameItem&, GameItem&, Level& level);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;
	
	
	void RegularPlayerCoin(GameItem& RegularPlayer, GameItem& coin, Level& level){
		if (coin.getIsExistOnScreen())
		{
			coin.setIsExistOnScreen(false);
			level.setCoinsCounter(1);
		
		}
	}
	void RegularPlayerThief(GameItem& RegularPlayer, GameItem& thief, Level& level){
		if (thief.getIsExistOnScreen() && !thief.getCollided())
		{
			thief.setCollided(true);
			level.setCoinsCounter(-10);
			level.showCoinsMinus();
		}
	}
	void RegularPlayerClock(GameItem& RegularPlayer, GameItem& clock, Level& level){
		if (clock.getIsExistOnScreen())
		{
			clock.setIsExistOnScreen(false);
			level.setMoreTime();
		}
	}
	void RegularPlayerDemon(GameItem& RegularPlayer, GameItem& demon, Level& level){
		if(demon.getIsExistOnScreen())
          		level.setPlayer(std::make_unique<BubblePlayer>(RegularPlayer.getSprite().getPosition()));
	}

	//===============================================================================================
	void RegularPlayerRock(GameItem& RegularPlayer, GameItem& rock, Level& level) {
	
		//the player is on the top of the rock
		if (RegularPlayer.getSprite().getPosition().y < rock.getSprite().getPosition().y)
		{	
			level.getPlayer()->setIsTopCollide(true);
			level.getPlayer()->setIsPlayerFalling(false);
			level.getPlayer()->handleInput(RELEASE_RIGHT);
			level.getPlayer()->getSprite().setPosition(level.getPlayer()->getSprite().getPosition().x, rock.getSprite().getPosition().y - level.getPlayer()->getSprite().getGlobalBounds().height+60);
		}

		//the player is on the rock left
		else if (RegularPlayer.getSprite().getPosition().x <
			rock.getSprite().getPosition().x)
		{
			Rock::setIsMovable(false);
		}

	
	
		//the player is on the bottom of the rock
		else if (RegularPlayer.getSprite().getPosition().y  >
			rock.getSprite().getPosition().y )
		{

				level.getPlayer()->setIsPlayerFalling(true);
		}
		else if (RegularPlayer.getSprite().getPosition().x >
			rock.getSprite().getPosition().x + rock.getSprite().getGlobalBounds().width )
		{

			Rock::setIsMovable(false);
		}
	}

	//==============================================================================================
	void RegularPlayerBaguette(GameItem& RegularPlayer, GameItem& baguette, Level& level) {
		baguette.setIsExistOnScreen(false);
		level.getPlayer()->setWeapon(std::make_unique<Baguette>(sf::Vector2f{ 0,0 }));
		level.getPlayer()->setCollectedWeapon(true);
		
	}

	//=====================================================================================
	void demonBaguette(GameItem& demon, GameItem& Baguette, Level& level) {
		if(level.getPlayer()->getIsWeaponActivated())
		demon.setIsExistOnScreen(false);
	}

	//=====================================================================================
	void thiefBaguette(GameItem& thief, GameItem& Baguette, Level& level) {
		if (level.getPlayer()->getIsWeaponActivated())
		thief.setIsExistOnScreen(false); 
	}


	//=====================================================================================
	HitMap initializeCollisionMap()
	{
		
		HitMap phm;
		phm[Key(typeid(RegularPlayer), typeid(Demon))] = &RegularPlayerDemon;
		phm[Key(typeid(RegularPlayer), typeid(Thief))] = &RegularPlayerThief;
		phm[Key(typeid(RegularPlayer), typeid(Clock))] = &RegularPlayerClock;
		phm[Key(typeid(RegularPlayer), typeid(Coin))] = &RegularPlayerCoin;
		phm[Key(typeid(RegularPlayer), typeid(Rock))] = &RegularPlayerRock;
		phm[Key(typeid(RegularPlayer), typeid(Baguette))] = &RegularPlayerBaguette;

		phm[Key(typeid(Demon), typeid(Baguette))] = &demonBaguette;
		phm[Key(typeid(Thief), typeid(Baguette))] = &thiefBaguette;


		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
		
			return nullptr;
		}
		return mapEntry->second;
	}

} // end namespace

void processCollision(GameItem& object1, GameItem& object2, Level& level)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		return;
	}
	phf(object1, object2, level);
}