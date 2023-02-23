#include "Console.h"
#include <iostream>
#include <string>
namespace console
{
    void print(const char* text)
    {
        std::cout << text;
    }

    void print(const int* text) {
        std::cout << text;
    }





    void printLine(const char* text) {
        std::cout << text << std::endl;
    }

    void read(const char* output) {
        using std::string;
        string buffer;
        std::cin >> buffer;
        output = buffer.c_str();
    }

    void moveTo(int x, int y) {
        std::cout << "\033[" << x << ";" << y << "H";
    }

    void clearFromPointer() {
        std::cout << "\033[K";
    }

    void savePosition() {
        std::cout << "\033[s";
    }

    void restorePosition() {
        std::cout << "\033[u";
    }
}