#pragma once
class ViewRender
{
public:
	void PrintPoint(int* ptr_array, int& current_placement);
	void PrintHints(char* ptr_array, int& current_placement);
	void LoadMap(const char* path);
};

