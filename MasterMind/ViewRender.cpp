#include "ViewRender.h"
#include <fstream>
#include <conio.h>
#include "console.h"

const static int horizontal_spacing = 8;

void ViewRender::PrintPoint(int* ptr_array, int& current_placement)
{
    //- Move the cursor to the right location. 
    console::moveTo(current_placement++, 1);
    //- Print the current point to the score board. 
    for (size_t i = 0; i < 4; i++)
    {
        //- Move cursor horizontal
        console::moveTo(current_placement, ((i + 1) * horizontal_spacing));
        console::print(*(ptr_array + i));
    }
}
void ViewRender::PrintHints(char* ptr_array, int& current_placement)
{
    console::moveTo(current_placement, 43);
    for (int i = 0; i < 4; i++)
    {
        console::print(*(ptr_array + i));
        if (i < 3)
            console::print(",");
    }
}
void ViewRender::LoadMap(const char* path)
{
    std::string filename = "Menu.txt";
    std::ifstream input_file(filename);

    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            console::printLine(line);
        }
        input_file.close();

        console::savePosition();
        console::moveTo(11, 18);
        console::print("X");
        console::restorePosition();
    }
    else {
        console::print("Unable to open file");
    }
}
