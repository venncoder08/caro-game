#include "source.h"


struct System
{
	int Width_PowerShell;
	int Height_PowerShell;
};

struct BoardGame
{
	int Size;
	int Width_Board;
	int Height_Board;
};

struct CELL
{
	bool locket = false;
	int Type = 0;
};

struct Player
{
	int Turn;
	std::string name;
};