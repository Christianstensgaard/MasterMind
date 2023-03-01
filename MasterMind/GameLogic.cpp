#include "GameLogic.h"
#include "Console.h"
#include <random>

		GameLogic	::GameLogic(int difficulty) {
	this->difficulty = difficulty;
	this->correctColor = 0;
	this->correctPlacement = 0;
	this->gameState = 2;
	this->gameRound = 0;
}
int		GameLogic	::gameOver()
{
	return gameState;
}
void	GameLogic	::Init()
{

	//- Generating a code between 0 and difficulty
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr(0, difficulty);

	for (size_t i = 0; i < 4; i++)
	{
		codeArray[i] = distr(gen);
	}


	//debug only printing the code top-left
	console::moveTo(0, 0);
	for (size_t i = 0; i < 4; i++)
	{
		console::print(codeArray[i]);
	}



}
void	GameLogic	::analyzeInput(int* inputArray)
{
	correctColor = 0;
	correctPlacement = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if (inputArray[i] == codeArray[i]) {
			correctPlacement++;
			
		}
		else for (size_t c = 0; c < 4; c++)
		{
			if (inputArray[i] == codeArray[c]) {
				correctColor++;
				break;
			}
		}
	}

	if (correctPlacement == 4)
		gameState = 0;

}
int&	GameLogic	::getColor()
{
	return correctColor;
}
int&	GameLogic	::getPlacement()
{
	return correctPlacement;
}
int		GameLogic	::getRound()
{
	int returnvalue = gameRound + 2;
	gameRound++;
	return returnvalue;
}