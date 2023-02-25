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
void ViewRender::PrintHints(int& correct_numbers, int& correct_placement, int& current_placement)
{
    console::moveTo(current_placement, 43);
    int current = 0; //- For printing ","

    //- Printing the hints
        //- Change color for the console.
    console::colorRed();
    for (size_t i = 0; i < correct_numbers; i++)
    {
        //print the hints
        console::print("O");
        if (current++ < 3)
            console::print(",");
    }
    //- Reset Color

    //- Printing the placements
        //- Change color for the console
    console::colorGreen();
    for (size_t i = 0; i < correct_placement; i++)
    {
        console::print("O");
        if (current++ < 3)
            console::print(",");
    }
    //- Reset  color.
    console::colorWhite();

    //TODO -> Working on the Print hints function. 
}
void ViewRender::LoadMap(std::string path)
{
    std::string filename = path;
    std::ifstream input_file(filename);

    console::moveTo(0, 0);

    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            console::printLine(line);
        }
        input_file.close();
    }
    else {
        console::print("Unable to open file");
    }
}
