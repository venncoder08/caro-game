#ifndef SOURCE_HEADER
#define SOURCE_HEADER

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include "console.h"
#include "struct.h"
#include "check.h"

using namespace std;

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ENTER_KEY 13

const int Width_Square = 4;
const int Height_Square = 2;
const string header = "img\\header.txt";

bool isCorrectSizeConsole(System CMD, BoardGame input, int x, int y, int Img_Width, int Img_Height);
void getInfoImage(const string filename, int& Img_Width, int& Img_Height);
void printHeader(System CMD, int background_color, const string filename);
void createBox(int x, int y, int width, int height, int text_color, int background_color, string text);
void createBox2(int x, int y, int width, int height, int text_color, int background_color, string text);
void EffectCursor(int x, int y, int width, int height, int background_color, string text);
void createSquare(int x, int y);
void createBoardGame(int x, int y, int n);
int calcFullScreen(System CMD, int x, int y, int Img_Height);
void Input(System CMD, BoardGame& input, const string filename, int background_color, int notice_color, Player& user1, Player& user2);
void TableInfor(Player user, int xTable, int yTable, int i, int j);
void StandardMode(const System CMD, const BoardGame input, const string filename, const Player user1, const Player user2, int background_color);
CELL** initializeBoard(int n);
void GotoUnlock(CELL** board, int n, int& i, int& j);
void deallocateBoard(CELL**& board, int n);
void Win(const System CMD, const Player user1, int background_color);
void clear_color(System CMD, int background_color);
bool isFull(CELL** board, int n);
void Full(const System CMD, int background_color);
#endif