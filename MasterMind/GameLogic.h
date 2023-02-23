#pragma once

	class GameLogic
	{
	public:
		~GameLogic();
		GameLogic();
		GameLogic(int* ptr_hints, int* ptr_points, int size);
		int* getPoints();
		int* getHints();
		void run();
		int size;

	private:

		int* ptr_hints;
		int* ptr_points;
	};

