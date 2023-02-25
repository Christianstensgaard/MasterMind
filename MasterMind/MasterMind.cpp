// MasterMind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Console.h"
#include "GameLogic.h"
#include "Input.h"
#include "ViewRender.h"
#include <iostream>
#include <conio.h>




void startGame() {
    GameLogic gameLogic(9);
    ViewRender render;
    console::moveTo(0, 0);
    render.LoadMap("GameMap.txt");



    //- Init the Game
    gameLogic.Init();












    //- While the game is running
    while (gameLogic.gameOver() == gameLogic.none)
    {
        //- Setup Scoped Game variables //- Since all are 4 bytes only one array can be used? 
        int input[4];



        //- Keep running untilll the user has input the right type. 
        bool isValidInput = false;
        while (!isValidInput) {
            //- Take userinput
            console::moveTo(26, 2);
            console::clearFromPointer();
            std::string userInput;
            std::cin >> userInput;

            const char* input_buffer = userInput.c_str();


            //valid the length of the array, and check if it's between 0-Deficulty
            int counter = 0;
            while (input_buffer[counter] != '\0') {

                if ((input_buffer[counter] - '0') >= 0 && (input_buffer[counter] - '0') <= 9) {
                    input[counter] = input_buffer[counter++] - '0';
                }
                else break;
            }
            counter == 4 ? isValidInput = true : isValidInput = false;
        }


        render.PrintPoint(input, gameLogic.getRound());

        //- here we give the array to the game logic layer that.
        gameLogic.analyzeInput(input);


        



        console::moveTo(0, 10);
        console::print(gameLogic.getColor());
        console::print(gameLogic.getPlacement());
    }

    console::clear();
    console::print("You Won");
    //-Display Win or lose


}


void openSettings() {

}

int Menu() {
    bool isRunning = true;

    //- Calling All classes used in this scope.
    ViewRender render;
    Input input;


    //- Show the Menu

    render.LoadMap("Menu.txt"); // Loading Menu
    int placement = 11;
    char key;
    int current = 0;


    console::savePosition();
    console::moveTo(11, 18);
    console::print("X");
    console::restorePosition();




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
                return current;
                break;

            default:
                break;
            }
        }
    }


}









int main()
{
    switch (Menu())
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
        break;

    default:
        break;
    }
}
