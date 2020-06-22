#pragma once
#include "GameItem.h"
class TextureChanger
{
public:
	TextureChanger();
	
	static void manageTextureChange(GameItem& item, std::string itemType, float &duration);
	~TextureChanger();
};

