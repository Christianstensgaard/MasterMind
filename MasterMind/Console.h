#pragma once
namespace console
{
    void print(const char* text);
    void printLine(const char* text);
    void read(const char*);
    void moveTo(int x, int y);
    void clearFromPointer();
    void savePosition();
    void restorePosition();
}