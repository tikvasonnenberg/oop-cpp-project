#pragma once
#include <iostream>

const int GROUND = 0;
const int BACKGROUND = 1;
const int ROCK = 2;
const int CLOCK = 3;
const int COIN = 4;
const int PLAYER = 5;

const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;
const int NON_DIRECTION = 4;

const int EASY = 0;
const int MODERATE = 1;
const int HARD = 2;
const int SUPER_HARD = 3;

const int MIN_HEIGHT_ROCK = 100;
const int MAX_HEIGHT_ROCK = 610;
const int WINDOW_SIZE_WIDTH = 1920;
const int DEMON_TEXTURE_AMOUNT = 18;
const int THIEF_TEXTURE_AMOUNT = 6;
const int BUBBLE_PLAYER_TEXTURE_AMOUNT = 1;
const int COIN_TEXTURE_AMOUNT = 6;
const int CLOCK_TEXTURE_AMOUNT = 1;
const int BAGUETTE_TEXTURE_AMOUNT = 4;

const int REGULAR_PLAYER_WALK_TEXTURE_AMOUNT = 6;
const int REGULAR_PLAYER_DUCK_TEXTURE_AMOUNT = 1;
const int REGULAR_PLAYER_HOP_TEXTURE_AMOUNT = 1;
const int REGULAR_PLAYER_JUMP_TEXTURE_AMOUNT = 1;
const int REGULAR_PLAYER_FREEZE_TEXTURE_AMOUNT = 1;

const int DEFAULTE_TEXTURE_AMOUNT = 1;

const int START_RIGHT_DIREACTION = 0;
const int END_RIGHT_DIREACTION = 7;
const int START_LEFT_DIREACTION = 8;
const int END_LEFT_DIREACTION = 17;

const int WINDOW_SIZE_HEIGHT = 1080;
const int NUM_OF_ROCKS =2;
const int NUM_OF_ENEMIES_PER_SCREEN = 1;

const int NUM_OF_DIFFICULTY_LEVELS = 4;

const int NUM_OF_COINS_PER_SCREEN = 15;
const int NUM_OF_GIFTS_PER_SCREEN = 1;
const float LEVEL_COMPLEX_TIME = 30;

const int SIZE_OF_GROUND = 280;
const int COINS_TO_WIN = 150;

const float PLAYER_JUMP_HEIGHT = 400.f;
enum Input
{
	PRESS_UP,
	PRESS_DOWN,
	RELEASE_RIGHT,
	PRESS_SPACE,
	PRESS_RIGHT,
	RELEASE_SPACE,
	RELEASE_UP,
	BUBBLE_POP
};
const float FALL_SPEED = 6.0f;
const float HOP_SPEED = 0.5f;
const float PLAYER_BUBBLE_HEIGHT = 360.f;

const float GAME_TIME =120;


