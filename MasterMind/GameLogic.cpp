#include "GameLogic.h"
#include "Console.h"


	int size = 4;
	int* ptr_hints;
	int* ptr_points;
	bool isHeap = false;

	GameLogic::~GameLogic()
	{
		if (isHeap) {
			delete[] ptr_hints;
			delete[] ptr_points;
			console::print("Deleted");
		}
	}

	GameLogic::GameLogic()
	{
		ptr_hints = new int[size];
		ptr_points = new int[size];
	}

	GameLogic::GameLogic(int* ptr_hints, int* ptr_points, int size)
	{
		this->size = size;
		this->ptr_hints = ptr_hints;
		this->ptr_points = ptr_points;
	}
	
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
