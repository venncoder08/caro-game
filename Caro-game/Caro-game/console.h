#ifndef CONSOLE_HEADER
#define CONSOLE_HEADER

#include <windows.h>
#include <iostream>

void gotoxy(int x, int y);
void SetColor(int textColor, int bgColor);
void TextColor(int color);
void HideCursor();
void ShowCursor();
void TableColor();
void clrscr();

#endif
