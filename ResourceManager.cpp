#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
	//insert the ground texture to the map
	vector <sf::Texture> VectorOfGround(2);
	if (VectorOfGround[0].loadFromFile("NewGround3.png") && VectorOfGround[1].loadFromFile("NewGround3.png"))
		m_textures.emplace("Ground", VectorOfGround);

	//insert the background texture to the map
	vector <sf::Texture> VectorOfBackGround(2);
	if (VectorOfBackGround[0].loadFromFile("Background (2) (1).png")
		&& VectorOfBackGround[1].loadFromFile("nightBackground.png"));
		m_textures.emplace("Background", VectorOfBackGround);

	//insert the manWalk texture to the map
	vector <sf::Texture> vectorOfManWalkTexture(6);
	if (vectorOfManWalkTexture[0].loadFromFile("player0.png") &&
		vectorOfManWalkTexture[1].loadFromFile("player1.png") &&
		vectorOfManWalkTexture[2].loadFromFile("player2.png") &&
		vectorOfManWalkTexture[3].loadFromFile("player3.png") &&
		vectorOfManWalkTexture[4].loadFromFile("player4.png") &&
		vectorOfManWalkTexture[5].loadFromFile("player5.png"))
		m_textures.emplace("PlayerWalk", vectorOfManWalkTexture);

	vector <sf::Texture> vectorOfManJumpTexture(1);
	vectorOfManJumpTexture[0].loadFromFile("player0.png");
	m_textures.emplace("PlayerJump", vectorOfManJumpTexture);

	vector <sf::Texture> vectorOfManDuckTexture(1);
	vectorOfManDuckTexture[0].loadFromFile("Duck1.png");
	m_textures.emplace("PlayerDuck", vectorOfManDuckTexture);


	//vector <sf::Texture> vectorOfManJumpTexture(6);
	//vector <sf::Texture> vectorOfManDuckTexture(6);
	vector <sf::Texture> vectorOfManHopTexture(1);
	vectorOfManHopTexture[0].loadFromFile("player0.png");
	m_textures.emplace("PlayerHop", vectorOfManHopTexture);

	//insert the pig texture to the map
	vector <sf::Texture> vectorOfPigTexture(18);
	if (vectorOfPigTexture[0].loadFromFile("pig1right.png") &&
		vectorOfPigTexture[1].loadFromFile("pig2right.png") &&
		vectorOfPigTexture[2].loadFromFile("pig3right.png") &&
		vectorOfPigTexture[3].loadFromFile("pig4right.png") &&
		vectorOfPigTexture[4].loadFromFile("pig1right.png") &&
		vectorOfPigTexture[5].loadFromFile("pig2right.png") &&
		vectorOfPigTexture[6].loadFromFile("pig3right.png") &&
		vectorOfPigTexture[7].loadFromFile("pig4right.png") &&
		vectorOfPigTexture[8].loadFromFile("pig1.png") &&
		vectorOfPigTexture[9].loadFromFile("pig2.png") &&
		vectorOfPigTexture[10].loadFromFile("pig3.png") &&
		vectorOfPigTexture[11].loadFromFile("pig4.png")&&
		vectorOfPigTexture[12].loadFromFile("pig1.png") &&
		vectorOfPigTexture[13].loadFromFile("pig2.png") &&
		vectorOfPigTexture[14].loadFromFile("pig3.png") &&
		vectorOfPigTexture[15].loadFromFile("pig4.png")&&
		vectorOfPigTexture[16].loadFromFile("pig1.png") &&
		vectorOfPigTexture[17].loadFromFile("pig2.png") )
		m_textures.emplace("Demon", vectorOfPigTexture);


	//insert the coin texture to the map
	vector <sf::Texture> vectorOfCoinTexture(6);
	if (vectorOfCoinTexture[0].loadFromFile("coin1.png") &&
		vectorOfCoinTexture[1].loadFromFile("coin2.png") &&
		vectorOfCoinTexture[2].loadFromFile("coin3.png") &&
		vectorOfCoinTexture[3].loadFromFile("coin4.png") &&
		vectorOfCoinTexture[4].loadFromFile("coin5.png") &&
		vectorOfCoinTexture[5].loadFromFile("coin6.png"))
		m_textures.emplace("Coin", vectorOfCoinTexture);


	//insert the rock texture to the map
	vector <sf::Texture> vectorOfRocksTexture(2);
	if(vectorOfRocksTexture[0].loadFromFile("platformDeformed.png")&&
		vectorOfRocksTexture[1].loadFromFile("platformDeformed.png") )
		//vectorOfRocksTexture[2].loadFromFile("platformLong.png") )
		m_textures.emplace("Rock", vectorOfRocksTexture);


	//insert the theif texture to the map
	vector <sf::Texture> vectorOfThiefTexture(6);
	if (vectorOfThiefTexture[0].loadFromFile("theif1.png") &&
		vectorOfThiefTexture[1].loadFromFile("theif2.png") &&
		vectorOfThiefTexture[2].loadFromFile("theif3.png") &&
		vectorOfThiefTexture[3].loadFromFile("theif4.png") &&
		vectorOfThiefTexture[4].loadFromFile("theif5.png") &&
		vectorOfThiefTexture[5].loadFromFile("theif6.png"))
		m_textures.emplace("Thief", vectorOfThiefTexture);

	//insert the clock texture to the map
	vector <sf::Texture> vectorOfClockTexture(1);
	if(vectorOfClockTexture[0].loadFromFile("clock.png"))//the picture is of type file
		m_textures.emplace("Clock", vectorOfClockTexture);

	vector <sf::Texture> vectorOfClockTexture1(1);
	if (vectorOfClockTexture1[0].loadFromFile("unnamed.png"))//the picture is of type file
		m_textures.emplace("Clock1", vectorOfClockTexture1);

	vector <sf::Texture> vectorOfClockTexture2(1);
	if (vectorOfClockTexture2[0].loadFromFile("��u2.png"))//the picture is of type file
		m_textures.emplace("Clock2", vectorOfClockTexture2);

	//insert the bubble texture to the map
	vector <sf::Texture> vectorOfBubbleTexture(1);
	if (vectorOfBubbleTexture[0].loadFromFile("bubbleTrap2.png"))
		m_textures.emplace("PlayerFreeze", vectorOfBubbleTexture);

	//insert the bubble texture to the map
	vector <sf::Texture> vectorOfBaguetteTexture(1);
	if (vectorOfBaguetteTexture[0].loadFromFile("baguette.png"))
		m_textures.emplace("Baguette", vectorOfBaguetteTexture);

	//insert the exit texture to the map
	vector <sf::Texture> vectorOfExitButtons(1);
	if (vectorOfExitButtons[0].loadFromFile("ButtonExit.png"))
		m_textures.emplace("ButtonExit", vectorOfExitButtons);

	//insert the reset texture to the map
	vector <sf::Texture> vectorOfResetButtons(1);
	if (vectorOfResetButtons[0].loadFromFile("ButtonReset.png"))
		m_textures.emplace("ButtonReset", vectorOfResetButtons);

	//insert the help texture to the map
	vector <sf::Texture> vectorOfHelpButtons(1);
	if (vectorOfHelpButtons[0].loadFromFile("ButtonHelp.png"))
		m_textures.emplace("ButtonHelp", vectorOfHelpButtons);

	vector <sf::Texture> vectorOfWinner(1);
	if (vectorOfWinner[0].loadFromFile("unnamed.png"))
		m_textures.emplace("��winner", vectorOfWinner);

	vector <sf::Texture> vectorOfHomeScreenButtons(1);
	if (vectorOfHomeScreenButtons[0].loadFromFile("ButtonGreen.png"))
		m_textures.emplace("HomeScreenButtons", vectorOfHomeScreenButtons);
	

	vector <sf::Texture> vectorOfHomeScreen(1);
	if (vectorOfHomeScreen[0].loadFromFile("storeFrontBackground.png"))
		m_textures.emplace("HomeScreenBackground", vectorOfHomeScreen);

	vector <sf::Texture> vectorOfHelp(1);
	if (vectorOfHelp[0].loadFromFile("Help.png"))
		m_textures.emplace("Help", vectorOfHelp);

	

	vector <sf::Texture> vectorOfStore(1);
	if (vectorOfStore[0].loadFromFile("��StoreFront.png"))
		m_textures.emplace("��StoreFront", vectorOfStore);

	

	




	font.loadFromFile("212 Queenie Sans.ttf");

	font2.loadFromFile("SnackerComic_PerosnalUseOnly.ttf");
}


std::vector<sf::Texture >& ResourceManager::getTexture(std::string type)
{
	return m_textures[type];
}

sf::Font &ResourceManager::getFont()
{
	return font;
}
sf::Font & ResourceManager::getFont2()
{
	return font2;
}
ResourceManager::~ResourceManager()
{
}
