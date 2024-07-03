#ifndef DESIGNS_HEADER
#define DESIGNS_HEADER

#include "source.h"

using namespace std;

void printImageHeader(System CMD, int background_color, const string filename);
void createBox(int x, int y, int width, int height, int text_color, int background_color, string text);
void createBox2(int x, int y, int width, int height, int text_color, int background_color, string text);
void EffectCursor(int x, int y, int width, int height, int background_color, string text);
void createSquare(int x, int y);
void createBoardGame(int x, int y, int m, int n);
void DrawLine(const System CMD, int x, int line_color);
void TableInfor(Player user, int xTable, int yTable, int i, int j);
void WinScreen(const System CMD, const Player user, int background_color, int text_color);
void clearScreen(const System CMD, int background_color);
void TieScreen(const System CMD, const Player user1, const Player user2, int background_color, int text_color);
void playSound(int i);

#endif
