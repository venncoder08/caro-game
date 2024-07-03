#ifndef SOURCE_HEADER
#define SOURCE_HEADER

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "console.h"
#include "struct.h"
#include "designs.h"
#include "check.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ENTER_KEY 13

#define MOVE_SOUND 0
#define ENTER_SOUND 1
#define WIN_SOUND 2
#define TIE_SOUND 3

const int Width_Square = 4;
const int Height_Square = 2;
const string header = "img\\header.txt";
const string win_header = "img\\win.txt";
const string tie_header = "img\\tie.txt";

void getInfoImage(const string filename, int& Img_Width, int& Img_Height);
CELL** initializeBoard(int m, int n);
void deallocateBoard(CELL**& board, int m);
void GotoUnlock(CELL** board, int m, int n, int& i, int& j);
bool GotoUnlockSquare(CELL** board, int m, int n, int& i, int& j, int PassKey);
BoardGame calcCorrectSizeBoard(int xBoard, int yBoard, int xBorderEnd, int yBorderEnd);
void inputIndicator(const System CMD, const int xBorder, const int yBorder, const int Border_Width, const int Border_Height, BoardGame& input, Player& user1, Player& user2, int background_color, int notice_color);
bool isFull(CELL** board, int m, int n);
void StandardMode(const System CMD, int background_color);

#endif