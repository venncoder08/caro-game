#include "designs.h"

void printImageHeader(System CMD, int background_color, const string filename)
{
	ifstream fin;
	fin.open(filename.c_str());

	if (!fin)
	{
		cout << "Failed to opened the file ! \n";
		return;
	}

	TextColor(background_color);
	int yPrint = 0;

	while (!fin.eof())
	{
		string line = "";
		getline(fin, line, '\n');
		if (!line.empty())
		{
			gotoxy(CMD.Width_PowerShell / 2 - line.length() + 7, 0 + yPrint++);
			cout << line << '\n';
		}
	}

	fin.close();
}

void createBox(int x, int y, int width, int height, int text_color, int background_color, string text)
{
	if (height <= 1 || width <= 1)
	{
		return;
	}

	TextColor(background_color);
	for (int iy = y + 1; iy <= y + height - 1; ++iy)
	{
		for (int ix = x + 1; ix <= x + width - 1; ++ix)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}

	TextColor(text_color);
	gotoxy((x + width / 2) - text.length() / 2, y + height / 2);
	cout << text;

	TextColor(background_color);

	for (int ix = x; ix <= x + width; ++ix)
	{
		for (int iy = y; iy <= y + height; ++iy)
		{
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(x + width, iy);
			cout << char(179);
		}

		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + height);
		cout << char(196);
	}

	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + width, y);
	cout << char(191);
	gotoxy(x, y + height);
	cout << char(192);
	gotoxy(x + width, y + height);
	cout << char(217);
}

void createBox2(int x, int y, int width, int height, int text_color, int background_color, string text)
{
	if (height <= 1 || width <= 1)
	{
		return;
	}

	TextColor(background_color);
	for (int iy = y + 1; iy <= y + height - 1; ++iy)
	{
		for (int ix = x + 1; ix <= x + width - 1; ++ix)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}

	TextColor(text_color);
	gotoxy((x + width / 2) - text.length() / 2, y + height / 2);
	cout << text;

	TextColor(background_color);

	for (int ix = x; ix <= x + width; ++ix)
	{
		for (int iy = y; iy <= y + height; ++iy)
		{
			gotoxy(x, iy);
			cout << char(186);
			gotoxy(x + width, iy);
			cout << char(186);
		}

		gotoxy(ix, y);
		cout << char(205);
		gotoxy(ix, y + height);
		cout << char(205);
	}

	gotoxy(x, y);
	cout << char(201);
	gotoxy(x + width, y);
	cout << char(187);
	gotoxy(x, y + height);
	cout << char(200);
	gotoxy(x + width, y + height);
	cout << char(188);
}

void EffectCursor(int x, int y, int width, int height, int background_color, string text)
{
	TextColor(background_color);
	for (int iy = y + 1; iy <= y + height - 1; ++iy)
	{
		for (int ix = x + 1; ix <= x + width - 1; ++ix)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}

	TextColor(background_color);
	gotoxy((x + width / 2) - text.length() / 2, y + height / 2);
	cout << text;
}

void createSquare(int x, int y)
{
	for (int ix = x; ix <= x + Width_Square; ++ix)
	{
		for (int iy = y; iy <= y + Height_Square; ++iy)
		{
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(x + Width_Square, iy);
			cout << char(179);
		}

		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + Height_Square);
		cout << char(196);
	}

	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + Width_Square, y);
	cout << char(191);
	gotoxy(x, y + Height_Square);
	cout << char(192);
	gotoxy(x + Width_Square, y + Height_Square);
	cout << char(217);
}

void createBoardGame(int x, int y, int m, int n)
{
	for (int iy = y; iy < y + (Height_Square * m); iy += Height_Square)
	{
		for (int ix = x; ix < x + (Width_Square * n); ix += Width_Square)
		{
			createSquare(ix, iy);
		}
	}

	for (int iy = y; iy < y + (Height_Square * m); iy += Height_Square)
	{
		for (int ix = x; ix < x + (Width_Square * n); ix += Width_Square)
		{
			if (ix + Width_Square != x + (Width_Square * n) && iy + Height_Square != y + (Height_Square * n))
			{
				gotoxy(ix + Width_Square, iy + Height_Square);
				cout << char(197);
			}
		}
	}

	for (int ix = x + Width_Square; ix < x + (Width_Square * n); ix += Width_Square)
	{
		gotoxy(ix, y);
		cout << char(194);
		gotoxy(ix, y + (Height_Square * m));
		cout << char(193);
	}

	for (int iy = y + Height_Square; iy < y + (Height_Square * m); iy += Height_Square)
	{
		gotoxy(x, iy);
		cout << char(195);
		gotoxy(x + (Width_Square * n), iy);
		cout << char(180);
	}
}

void DrawLine(const System CMD, int x, int line_color)
{
	TextColor(line_color);

	for (int iy = 0; iy < CMD.Height_PowerShell - 1; ++iy)
	{
		gotoxy(x, iy);
		cout << " ";
	}
}

void playSound(int i)
{
	static vector<const wchar_t*> soundFile{ L"sound\\move.wav", L"sound\\enter.wav", L"sound\\win.wav", L"sound\\lose.wav" };
	PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
}

void TableInfor(Player user, int xTable, int yTable, int i, int j)
{
	//Indicator of board
	const int Table1_Width = 32;
	const int Table1_Height = 10;
	const int Table2_Width = 32;
	const int Table2_Height = 12;
	const int Button_Width = 4;
	const int Button_Height = 2;

	//Indicator of color
	const int background_color = 7;
	const int information_board_color = 14;
	const int information_color = 7;
	const int position_color = 12;
	const int guide_board_color = 9;
	const int guide_color = 14;

	createBox2(xTable, yTable, Table1_Width, Table1_Height, background_color, background_color, "");
	createBox2(xTable + 1, yTable + 1, Table1_Width - 2, 2, information_board_color, information_board_color, "Information");

	TextColor(information_color);
	gotoxy(xTable + 5, yTable + 5);
	if (user.Turn == 1)
	{
		cout << "Name: " << user.name << "  -  Turn: [X]";
	}
	else
	{
		cout << "Name: " << user.name << "  -  Turn: [O]";
	}

	gotoxy(xTable + 8, yTable + 8);
	TextColor(position_color);
	cout << "Position: [" << i << "][" << j << "]";
	TextColor(background_color);

	createBox2(xTable , yTable + Table1_Height + 1, Table2_Width, Table2_Height, background_color, background_color, "");
	createBox2(xTable + 1, yTable + Table1_Height + 2, Table2_Width - 2, 2, guide_board_color, guide_board_color, "Guide");

	createBox(xTable + (Table2_Width - 2) / 2 - 1, yTable + Table2_Height + 3, Button_Width, Button_Height, background_color, background_color, "^");
	createBox(xTable + (Table2_Width - 2) / 2 - 1, yTable + Table2_Height + 4 + Button_Height, Button_Width, Button_Height, background_color, background_color, "v");
	createBox(xTable + (Table2_Width - 2) / 2 - Button_Width - 2, yTable + Table2_Height + Button_Height + 4, Button_Width, Button_Height, background_color, background_color, "<");
	createBox(xTable + (Table2_Width - 2) / 2 + Button_Width, yTable + Table2_Height + Button_Height + 4, Button_Width, Button_Height, background_color, background_color, ">");

	TextColor(guide_color);
	gotoxy(xTable + 2, yTable + Table2_Height + 6);
	cout << "MOVE:";
	gotoxy(xTable + 2, yTable + Table2_Height + 10);
	if (user.Turn == 1)
	{
		cout << "ENTER: chossing [" << i << "][" << j << "] is [X]";
	}
	else
	{
		cout << "ENTER: chossing [" << i << "][" << j << "] is [O]";
	}
}

void WinScreen(const System CMD, const Player user, int background_color, int text_color)
{
	//Sound
	playSound(WIN_SOUND);

	//Get information of img
	int Img_Width, Img_Height;
	getInfoImage(win_header, Img_Width, Img_Height);

	//Print header of screen
	printImageHeader(CMD, background_color, win_header);

	//Declare text
	string text1 = "Congratulations !";
	string text2 = "The winner is: " + user.name;

	//Print a text
	TextColor(text_color);
	int xText = (CMD.Width_PowerShell - Img_Width) / 2 + Img_Width / 3 - 3;
	int yText = Img_Height + 2;
	gotoxy(xText-- - text1.length(), yText++);
	cout << "Congratulations !";
	gotoxy(xText - text2.length(), yText++);
	cout << "The winner is: ";
	TextColor(12);
	cout << user.name;

	//Create a space
	for (int iy = yText; iy < CMD.Height_PowerShell / 2; ++iy)
	{
		gotoxy(xText, iy);
		cout << " ";
	}

	TextColor(background_color);
	Sleep(2000);
	exit(0);
}

void TieScreen(const System CMD, const Player user1, const Player user2, int background_color, int text_color)
{
	//Sound
	playSound(TIE_SOUND);

	//Get information of img
	int Img_Width, Img_Height;
	getInfoImage(tie_header, Img_Width, Img_Height);

	//Print header of screen
	printImageHeader(CMD, background_color, tie_header);

	//Declare text
	string text1 = "Oh! The square are full";
	string text2 = user1.name + " and " + user2.name + " is draw";

	//Print a text
	TextColor(text_color);
	int xText = (CMD.Width_PowerShell - Img_Width) / 2 + Img_Width - 10;
	int yText = Img_Height + 2;
	gotoxy(xText-- - text1.length(), yText++);
	cout << text1;
	gotoxy(xText - text2.length(), yText++);
	cout << text2;

	//Create a space
	for (int iy = yText; iy < CMD.Height_PowerShell / 2; ++iy)
	{
		gotoxy(xText, iy);
		cout << " ";
	}

	TextColor(background_color);
	Sleep(2000);
	exit(0);
}

void clearScreen(const System CMD, int background_color)
{
	TextColor(background_color);
	for (int iy = 0; iy < CMD.Height_PowerShell - 1; ++iy)
	{
		for (int ix = 0; ix < CMD.Width_PowerShell - 1; ++ix)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}
}