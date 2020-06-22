#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Clock.h"
#include "Coin.h"
#include "Demon.h"
#include "Player.h"
#include "Rock.h"
#include "Thief.h"

namespace { // unnamed namespace — the standard way to make function "static"
	void playerCoin(GameItem& player, GameItem& coin){}
	void playerThief(GameItem& player, GameItem& thief){}
	void playerClock(GameItem& player, GameItem& clock){}
	void playerDemon(GameItem& player, GameItem& demon){}
	void playerRock (GameItem& player, GameItem& rock){}

	void demonPlayer(GameItem& demon, GameItem& player){}//it will call to playerDemon
	void demonThief(GameItem& demon, GameItem& thief){}
	void demonRock(GameItem& demon, GameItem&  rock){}
	void demonClock(GameItem& demon, GameItem& clock){}
	void demonCoin(GameItem& demon, GameItem& coin){}

	void thiefPlayer(GameItem& thief, GameItem& player){}//"
	void thiefDemon(GameItem& thief, GameItem& demon){}//"
	void thiefRock(GameItem& thief, GameItem& rock){}
	void thiefClock(GameItem& thief, GameItem& clock){}
	void thiefCoin(GameItem& thief, GameItem& coin){}

	using HitFunctionPtr = void(*)(GameItem&, GameItem&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Player), typeid(Demon))] = &playerDemon;
		phm[Key(typeid(Player), typeid(Thief))] = &playerThief;
		phm[Key(typeid(Player), typeid(Clock))] = &playerClock;
		phm[Key(typeid(Player), typeid(Coin))] = &playerCoin;
		phm[Key(typeid(Player), typeid(Rock))] = &playerRock;

		phm[Key(typeid(Demon), typeid(Thief))] = &demonThief;
		phm[Key(typeid(Demon), typeid(Clock))] = &demonClock;
		phm[Key(typeid(Demon), typeid(Coin))] = &demonCoin;
		phm[Key(typeid(Demon), typeid(Rock))] = &demonRock;

		phm[Key(typeid(Thief), typeid(Demon))] = &thiefDemon;
		phm[Key(typeid(Thief), typeid(Clock))] = &thiefClock;
		phm[Key(typeid(Thief), typeid(Coin))] = &thiefCoin;
		phm[Key(typeid(Thief), typeid(Rock))] = &thiefRock;
		//...
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

void processCollision(GameItem& object1, GameItem& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision(object1, object2);
	}
	phf(object1, object2);
}

