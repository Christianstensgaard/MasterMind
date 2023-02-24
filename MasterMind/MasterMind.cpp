// MasterMind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Console.h"
#include "GameLogic.h"
#include "Input.h"
#include "ViewRender.h"
#include <iostream>
#include <conio.h>




void startGame() {

    console::clear();
    GameLogic gameLogic;
    ViewRender render;

    //- While the game is running
    while (gameLogic.gameOver() == gameLogic.none)
    {
        //- Setup Scoped Game variables
        int points[4];
        int hints[4];
        int input[4];


        //|BEGINING THE GAME|

        //- Take userinput
        std::string userInput;
        std::cin >> userInput;


        console::print(userInput);



        //- Send userinput to the game. 

        //- Update the render / view
    }



}


void openSettings() {

}











int main()
{
	bool isRunning = true;

	//- Calling All classes used in this scope.
	ViewRender render;
	Input input;


	//- Show the Menu

	render.LoadMap("Menu"); // Loading Menu
    int placement = 11;
    char key;
    int current = 0;

    //This listen for key inputs
    while (isRunning) {
        console::restorePosition();
        if (_kbhit()) { // Check if a key has been pressed
            key = _getch(); // Get the pressed key
            switch (key)
            {
            case 'w':
            case 'W':
                if (placement < 18) {

                    console::moveTo(placement, 18);
                    console::print(" ");

                    placement -= 2;
                    current--;
                    console::moveTo(placement, 18);
                    console::print("X");
                    console::restorePosition();
                }
                break;
            case 's':
            case 'S':
                if (placement < 15) {

                    //Removing the old X
                    console::moveTo(placement, 18);
                    console::print(" ");

                    //Printing the new X
                    placement += 2;
                    current++;
                    console::moveTo(placement, 18);
                    console::print("X");
                    console::restorePosition();
                }
                break;
            case '\r':
                //Handling the Menu-Enter Action
                switch (current)
                {

                case 0:
                    std::cout << "Starting Game";
                    startGame();
                    break;

                case 1:
                    std::cout << "Settings";
                    openSettings();
                    break;

                case 2:
                    std::cout << "Exit";
                    isRunning = false;
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
}
