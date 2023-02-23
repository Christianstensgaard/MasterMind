#include "Game.h"
#include "Console.h"

namespace coreGame
{
	void loadMap(const char* path) {

	}



	/// <summary>
	/// Containing all renders for the menu
	/// </summary>
	class Menu
	{

	};


	/// <summary>
	/// contains all the renders for the game
	/// </summary>
	class Game
	{
	public:
		void PrintPoint(int* ptr_array, int& current_placement)
		{
			//- Move the cursor to the right location. 
			//std::cout << "\033[" << (current_placement++) << "; 1H";
			console::moveTo(current_placement++, 1);
			//- Print the current point to the score board. 
			for (size_t i = 0; i < 4; i++)
			{
				//- Move cursor horizontal
				std::cout << "\033[" << current_placement << ";" << ((i + 1) * horizontal_spacing) << "H";
				std::cout << *(ptr_array + i);
				console::print(*(ptr_array + i));
			}
		}


	private:
		const static int horizontal_spacing = 8;



	};



}


