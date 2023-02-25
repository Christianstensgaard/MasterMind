#include "Console.h"
#include <iostream>
#include <string>
namespace console
{
    void print(const char* text)
    {
        std::cout << text;
    }

    void print(char text) {
        std::cout << text;
    }


    void print(std::string text) {
        std::cout << text;
    }
    void print(const int& text) {
        std::cout << text;
    }
    void print(const bool& text) {
        std::cout << (text? "true" : "false");
    }
    void printLine(const char* text) {
        std::cout << text << std::endl;
    }
    void printLine(std::string text) {
        std::cout << text << std::endl;
    }
    void colorRed()
    {
        std::cout << "\033[31m";
    }
    void colorGreen()
    {
        std::cout << "\033[32m";
    }
    void colorWhite()
    {
        std::cout << "\033[37m";
    }
    //- This do not work, will return at a later point.
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
    void clear()
    {
        std::cout << "\033[2J";
        moveTo(0, 0);
    }
}