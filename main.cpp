#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Exceptions.h"
using namespace std;
#include <ostream>

#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#pragma comment ( lib , "sfml-audio-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )

#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#pragma comment ( lib , "sfml-audio-d.lib" )
#else
#error "Unrecognized configuration!"o
#endif




#include <iostream>
#include <sfml/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
	try {
		//define a Controller and call to run(), to run the game
		Controller c;
		c.run();
	}
	catch (const GeneralError& g)
	{
		std::cout << g.what() << std::endl;
	}
	return 0;
}