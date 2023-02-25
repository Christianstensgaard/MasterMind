#pragma once

class GameLogic
{
public:
	GameLogic(int difficulty);
	int gameOver();
	void Init();

	void analyzeInput(int* inputArray);
	int& getColor();
	int& getPlacement();
	int getRound();
		
	int difficulty;
	const int won = 0;		//- const val : won
	const int lost = 1;		//- const val : lost
	const int none = 2;		//- const val : none

private:

	int codeArray[4];		//- Holding the Code to crack
	int correctPlacement;	//- Used for the hints
	int correctColor;		//- Used for the hints
	int gameState;			//- Won, Game-over, None
	int gameRound;			//- Counting the rounds 
};

		