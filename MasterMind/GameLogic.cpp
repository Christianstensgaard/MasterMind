#include "GameLogic.h"
#include "Console.h"


const int won = 0;
const int lost = 1;
const int none = 2;


int size = 4;
int* ptr_hints;
int* ptr_points;







GameLogic::GameLogic()
{
	ptr_hints = new int[size];
	ptr_points = new int[size];
}

GameLogic::~GameLogic(){}

	
int* GameLogic::getPoints()
{
	return ptr_points;
}

int* GameLogic::getHints()
{
	return ptr_hints;
}

void GameLogic::run()
{
}

int GameLogic::gameOver()
{
	return 0;
}

