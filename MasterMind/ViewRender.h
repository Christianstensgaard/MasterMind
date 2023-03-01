#pragma once
#include <string>
class ViewRender
{
public:
	void PrintPoint(int* ptr_array, int& current_placement);
	void PrintHints(int& correct_numbers, int& correct_placement, int& current_placement);
	void LoadMap(std::string path);

private:
	void hintprinter(const int type, const int current);

};

