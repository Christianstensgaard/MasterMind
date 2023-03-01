
#include <iostream>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>
#include "Console.h"
#include "GameLogic.h"
#include "ViewRender.h"

void startGame(int diff) {
    console::clear();
    GameLogic gameLogic(diff);
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

        console::moveTo(28, 1);
        console::print("Green = right placement\nRed   = right number");


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
        int round = gameLogic.getRound();
        console::moveTo(round, 0);

        render.PrintPoint(input, round);

        //- here we give the array to the game logic layer that.
        gameLogic.analyzeInput(input);
        render.PrintHints(
              gameLogic.getColor(), 
            gameLogic.getPlacement(), 
            round
        );
    }
    console::clear();
    console::print("You Won");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}
int openSettings() {
    console::clear();
    console::print("Settings :P\n");
    console::print("Note max range = 9\n\n");
    console::print("Set the code range 0 -> : ");
    int returnValue;
    {
        std::string input;
        std::cin >> input;

        const char* buffer = input.c_str();

        returnValue = buffer[0] - '0';
    }

    if (returnValue >= 0 && returnValue <= 9)
        return returnValue;
    return 4;
}
int Menu() {
    console::clear();
    bool isRunning = true;

    //- Calling All classes used in this scope.
    ViewRender render;


    //- Show the Menu

    render.LoadMap("Menu.txt"); // Loading Menu
    int placement = 11;
    char key;
    int current = 0;

    console::moveTo(28, 1);
    console::print("W = Up, S = down");

    console::savePosition();
    console::moveTo(11, 18);
    console::print("X");
    console::restorePosition();

    //This listen for key inputs
    console::restorePosition();
    while (isRunning) {
        if (_kbhit()) { // Check if a key has been pressed
            key = _getch(); // Get the pressed key
            switch (key)
            {
            case 'w':
            case 'W':
                if (placement >= 13) {

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
                if (placement < 15 && placement <= 18) {

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
        else std::this_thread::sleep_for(std::chrono::milliseconds(38));
    }

}

int main()
{
    bool active = true;
    int defficulty = 4;
    console::print("Designed by Christian Leo");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    while (active) {
        switch (Menu())
        {

        case 0:
            std::cout << "Starting Game";
            startGame(defficulty);
            break;

        case 1:
            std::cout << "Settings";
            defficulty = openSettings();
            break;

        case 2:
            std::cout << "Exit";
            active = false;
            break;

        default:
            break;
        }
    }
}
