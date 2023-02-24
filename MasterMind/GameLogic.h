#pragma once

	class GameLogic
	{
	public:
		~GameLogic();
		GameLogic();
		int* getPoints();
		int* getHints();
		void run();
		int size{ 4 };

		int gameOver();



		int none;
		int lost;
		int won;


	private:
		int* ptr_hints;
		int* ptr_points;
	};

