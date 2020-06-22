#include "TextureChanger.h"



TextureChanger::TextureChanger()
{
}

 void TextureChanger::manageTextureChange(GameItem& item, std::string itemType,float & duration)
 {
	 if (item.getDuration() > 0.1f)
	 {
		 item.resetDuration();// = 0;
		 duration = 0;
		 int& textureIndex = item.getTextureIndex();
		 item.getSprite().setTexture(ResourceManager::getInstance().getTexture(itemType).at(textureIndex),true);
		 if (textureIndex == item.getAmountOftextures() - 1)
			 textureIndex = 0;
		 else
			 textureIndex++;
	 }
}
TextureChanger::~TextureChanger()
{
}
