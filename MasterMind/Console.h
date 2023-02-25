#pragma once
#include <string>
namespace console
{
    void print(const char* text);
    void print(const int& text);
    void print(const bool& text);
    void print(std::string text);
    void printLine(const char* text);
    void printLine(std::string text);
    void colorRed();
    void colorGreen();
    void colorWhite();
    void moveTo(int x, int y);
    void clearFromPointer();
    void savePosition();
    void restorePosition();
    void clear();
}