#include "source.h"

bool isCorrectSizeConsole(System CMD, BoardGame input, int x, int y, int Img_Width, int Img_Height)
{
	if (x < 0 || y < 0 || input.Size <= 0 || CMD.Width_PowerShell < 0 || CMD.Height_PowerShell < 0)
	{
		return false;
	}

	return (x + input.Width_Board + Img_Width <= CMD.Width_PowerShell) || (y + input.Height_Board + Img_Height <= CMD.Height_PowerShell);
}

void getInfoImage(const string filename, int& Img_Width, int& Img_Height)
{
	Img_Width = 0;
	Img_Height = 0;
	int Compare_Width;

	ifstream fin;
	fin.open(filename.c_str());

	if (!fin)
	{
		cout << "Failed to opened the file ! \n";
		return;
	}

	while (!fin.eof())
	{
		string line = "";
		getline(fin, line, '\n');

		if (!line.empty())
		{
			Compare_Width = line.length();
			if (Compare_Width > Img_Width)
			{
				Img_Width = Compare_Width;
			}

			Img_Height++;
		}
	}

	fin.close();
}

void printHeader(System CMD, int background_color, const string filename)
{
	ifstream fin;
	fin.open(filename.c_str());

	if (!fin)
	{
		cout << "Failed to opened the file ! \n";
		return;
	}

	TextColor(background_color);
	int idx = 0;
	while (!fin.eof())
	{
		string line = "";
		getline(fin, line, '\n');
		if (!line.empty())
		{
			gotoxy(CMD.Width_PowerShell / 2 - line.length() + 7, 0 + idx++);
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
	int width_square = 4, height_square = 2;
	for (int ix = x; ix <= x + width_square; ++ix)
	{
		for (int iy = y; iy <= y + height_square; ++iy)
		{
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(x + width_square, iy);
			cout << char(179);
		}

		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + height_square);
		cout << char(196);
	}

	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + width_square, y);
	cout << char(191);
	gotoxy(x, y + height_square);
	cout << char(192);
	gotoxy(x + width_square, y + height_square);
	cout << char(217);
}

void createBoardGame(int x, int y, int n)
{
	int width_square = 4, height_square = 2;
	for (int iy = y; iy < y + (height_square * n); iy += height_square)
	{
		for (int ix = x; ix < x + (width_square * n); ix += width_square)
		{
			createSquare(ix, iy);
		}
	}

	for (int iy = y; iy < y + (height_square * n); iy += height_square)
	{
		for (int ix = x; ix < x + (width_square * n); ix += width_square)
		{
			if (ix + width_square != x + (width_square * n) && iy + height_square != y + (height_square * n))
			{
				gotoxy(ix + width_square, iy + height_square);
				cout << char(197);
			}
		}
	}

	for (int ix = x + width_square; ix < x + (width_square * n); ix += width_square)
	{
		gotoxy(ix, y);
		cout << char(194);
		gotoxy(ix, y + (height_square * n));
		cout << char(193);
	}

	for (int iy = y + height_square; iy < y + (height_square * n); iy += height_square)
	{
		gotoxy(x, iy);
		cout << char(195);
		gotoxy(x + (width_square * n), iy);
		cout << char(180);
	}
}

void TableInfor(Player user, int xTable, int yTable, int i, int j)
{
	const int Table_Width = 30;
	const int Table_Height = 10;
	const int background_color = 7;
	const int information_board_color = 15;
	const int information_color = 8;
	const int position_color = 12;

	createBox2(xTable, yTable, Table_Width, Table_Height, background_color, background_color, "");
	createBox2(xTable + 1, yTable + 1, Table_Width - 2, 2, information_board_color, information_board_color, "Information");

	TextColor(information_color);
	gotoxy(xTable + 5, yTable + 5);
	if (user.Turn == 1)
	{
		cout << "Name: " << user.name << "  Turn: [X]";
	}
	else
	{
		cout << "Name: " << user.name << "  Turn: [O]";
	}

	gotoxy(xTable + 7, yTable + 7);
	TextColor(position_color);
	cout << "Position: [" << i << "][" << j << "]";
	TextColor(background_color);
}

CELL** initializeBoard(int n)
{
	CELL** board = new CELL * [n];
	for (int i = 0; i < n; ++i)
	{
		board[i] = new CELL[n];
	}

	return board;
}

void deallocateBoard(CELL** &board, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] board[i];
	}

	delete[] board;
}

void GotoUnlock(CELL** board, int n, int& i, int& j)
{
	for (int p = 0; p < n; ++p)
	{
		for (int q = 0; q < n; ++q)
		{
			if (!board[p][q].locket)
			{
				i = p;
				j = q;
				return;
			}
		}
	}
}

int calcFullScreen(System CMD, int x, int y, int Img_Height)
{
	int n = 5;
	while ((x + (Width_Square * n) + 2 + 40 < CMD.Width_PowerShell) && (y + (Height_Square * n) + Img_Height + 2 < CMD.Height_PowerShell))
	{
		n++;
	}

	return n;
}

void clear_color(System CMD, int background_color)
{
	TextColor(background_color);
	for (int iy = 0; iy <= CMD.Height_PowerShell; ++iy)
	{
		for (int ix = 0; ix <= CMD.Width_PowerShell; ++ix)
		{
			cout << " ";
		}
	}
}

void Input(System CMD, BoardGame& input, const string filename, int background_color, int notice_color, Player& user1, Player& user2)
{
	ShowCursor();

	int LimitBorder;
	int Img_Width;
	int Img_Height;
	getInfoImage(filename, Img_Width, Img_Height);

	do
	{
		clrscr();
		TextColor(background_color);

		printHeader(CMD, background_color, filename);
		int xBoard = 1, yBoard = Img_Height + 1;
		int Border = calcFullScreen(CMD, xBoard, yBoard, Img_Height);
		LimitBorder = Border;
		int xText = CMD.Width_PowerShell / 2 - Img_Width;
		int yText = Img_Height + 3;

		//input size board
		gotoxy(xText, yText++);
		cout << "Enter size of board (" << "5 - " << Border << "): ";
		cin >> input.Size;

		//input player
		gotoxy(xText, yText++);
		cout << "Enter the name of player 1 (1 - 6 characters): ";
		cin >> user1.name;
		gotoxy(xText, yText++);
		cout << "Enter the name of player 2 (1 - 6 characters): ";
		cin >> user2.name;

		//condition loop
		if (input.Size < 5 || input.Size > Border || user1.name.length() > 6 || user2.name.length() > 6)
		{
			TextColor(notice_color);
			string ans;
			gotoxy(xText, ++yText);
			cout << "Indicators you enter incorrectly !";
			gotoxy(xText, ++yText);
			cout << "If you want re-enter or quit, say Y or Press any key: ";
			cin >> ans;
			if (ans == "Y" || ans == "y")
			{
				continue;
			}
			else
			{
				exit(0);
			}
		}

	} while (input.Size < 5 || input.Size > LimitBorder || user1.name.length() > 6 || user2.name.length() > 6);

	input.Width_Board = Width_Square * input.Size;
	input.Height_Board = Height_Square * input.Size;
}

bool isFull(CELL** board, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j].Type = 0)
			{
				return true;
			}
		}
	}

	return false;
}

void Full(const System CMD, int background_color)
{
	clear_color(CMD, background_color);
	const string path = "img\\tie.txt";
	int path_width, path_height;
	getInfoImage(path, path_width, path_height);

	clrscr();
	TextColor(background_color);
	ifstream ifs;
	ifs.open(path.c_str());
	if (!ifs.is_open())
	{
		cout << "Failed to opened the file !";
		exit(0);
	}

	int xPrintImg = CMD.Width_PowerShell / 2 - path_width;
	int yPrintImg = CMD.Height_PowerShell / 4;

	while (!ifs.eof())
	{
		string line = "";
		getline(ifs, line, '\n');

		if (!line.empty())
		{
			gotoxy(xPrintImg, yPrintImg++);
			cout << line << '\n';
		}
	}

	ifs.close();

	yPrintImg += 2;
	gotoxy(xPrintImg, yPrintImg++);
	cout << "The level is full and will end soon \n";

	exit(0);
}

void Win(const System CMD, const Player user1, int background_color)
{
	clear_color(CMD, background_color);
	const string path = "img\\win.txt";
	int path_width, path_height;
	getInfoImage(path, path_width, path_height);
	
	clrscr();
	TextColor(background_color);
	ifstream ifs;
	ifs.open(path.c_str());
	if (!ifs.is_open())
	{
		cout << "Failed to opened the file !";
		exit(0);
	}

	int xPrintImg = CMD.Width_PowerShell / 2 - path_width;
	int yPrintImg = CMD.Height_PowerShell / 4;

	while (!ifs.eof())
	{
		string line = "";
		getline(ifs, line, '\n');

		if (!line.empty())
		{
			gotoxy(xPrintImg, yPrintImg++);
			cout << line << '\n';
		}
	}

	ifs.close();
	
	yPrintImg += 2;
	gotoxy(xPrintImg, yPrintImg++);
	cout << "Congratulations ! \n";
	gotoxy(xPrintImg, yPrintImg++);
	cout << "The player ";
	TextColor(12);
	cout << user1.name;
	TextColor(background_color);
	cout << " is Win. \n";
	TextColor(background_color);

	for (int iy = yPrintImg; iy <= CMD.Height_PowerShell; ++iy)
	{
		for (int ix = xPrintImg; ix <= CMD.Width_PowerShell; ++ix)
		{
			cout << " ";
		}
	}

	exit(0);
}

void StandardMode(const System CMD, const BoardGame input, const string filename, const Player user1, const Player user2, int background_color)
{
	HideCursor();

	//Get size of header image
	int Img_Width = 0;
	int Img_Height = 0;
	getInfoImage(filename, Img_Width, Img_Height);
	
	//Indicator of board game
	int xBoardGame = 2;
	int yBoardGame = Img_Height + 2;

	//Indicator of table information
	int xTable = CMD.Width_PowerShell - 35;
	int yTable = CMD.Height_PowerShell / 4;
	int WidthTable = 40;
	int Table_Width = 30;
	int Table_Height = 10;

	//Indicator of color
	int border_color = 14;
	int locket_Turn1 = 192;
	int locket_Turn2 = 32;
	int effect_color = 128;

	//Indicator of new game
	int Turn = 1;
	int i = 0, j = 0;
	int xCursor = xBoardGame;
	int yCursor = yBoardGame;
	int xPrevCursor = xCursor;
	int yPrevCursor = yCursor;
	bool isPress = false;
	bool isEnter = false;

	clrscr();

	//Print header image
	printHeader(CMD, background_color, filename);

	//Print box contain a board game and table infor
	createBox2(1, Img_Height + 1, CMD.Width_PowerShell - input.Width_Board - Table_Width, CMD.Height_PowerShell - Img_Height - 3, border_color, border_color, "");
	TableInfor(user1, xTable, yTable, i, j);
	TextColor(background_color);

	//Print a board game
	createBoardGame(xBoardGame, yBoardGame, input.Size);
	EffectCursor(xBoardGame, yBoardGame, Width_Square, Height_Square, effect_color, "");
	
	//Initialize data
	CELL** board = initializeBoard(input.Size);

	while (1)
	{
		if (isEnter)
		{
			GotoUnlock(board, input.Size, i, j);

			if (Turn == 1)
			{
				TableInfor(user1, xTable, yTable, i, j);
				EffectCursor(xCursor, yCursor, Width_Square, Height_Square, locket_Turn1, "X");
				Turn = 2;
			}
			else
			{
				TableInfor(user1, xTable, yTable, i, j);
				EffectCursor(xCursor, yCursor, Width_Square, Height_Square, locket_Turn2, "O");
				Turn = 1;
			}

			yCursor = yBoardGame + i * Height_Square;
			xCursor = xBoardGame + j * Width_Square;
			xPrevCursor = xCursor;
			yPrevCursor = yCursor;
			EffectCursor(xCursor, yCursor, Width_Square, Height_Square, effect_color, "");
			isEnter = false;
		}

		if (isPress)
		{
			if (!board[i][j].locket)
			{
				EffectCursor(xPrevCursor, yPrevCursor, Width_Square, Height_Square, background_color, "");
				xPrevCursor = xCursor;
				yPrevCursor = yCursor;
				EffectCursor(xCursor, yCursor, Width_Square, Height_Square, effect_color, "");
			}
			else
			{
				xCursor = xPrevCursor;
				yCursor = yPrevCursor;
				i = (yCursor - yBoardGame) / Height_Square;
				j = (xCursor - xBoardGame) / Width_Square;
			}

			if (Turn == 1)
			{
				TableInfor(user1, xTable, yTable, i, j);
			}
			else
			{
				TableInfor(user1, xTable, yTable, i, j);
			}
			isPress = false;
		}

		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == UP_KEY)
				{
					if (yCursor != yBoardGame)
					{
						yCursor -= Height_Square;
						--i;
						isPress = true;
					}
					else
					{
						yCursor = yBoardGame + (Height_Square * (input.Size - 1));
						i = input.Size - 1;
						isPress = true;
					}
				}
				else if (c == DOWN_KEY)
				{
					if (yCursor != yBoardGame + (Height_Square * (input.Size - 1)))
					{
						yCursor += Height_Square;
						++i;
						isPress = true;
					}
					else
					{
						yCursor = yBoardGame;
						i = 0;
						isPress = true;
					}
				}
				else if (c == LEFT_KEY)
				{
					if (xCursor == xBoardGame)
					{
						xCursor = xBoardGame + (Width_Square * (input.Size - 1));
						j = input.Size - 1;
						isPress = true;
					}
					else
					{
						xCursor -= Width_Square;
						--j;
						isPress = true;
					}
				}
				else if (c == RIGHT_KEY)
				{
					if (xCursor == xBoardGame + (Width_Square * (input.Size - 1)))
					{
						xCursor = xBoardGame;
						j = 0;
						isPress = true;
					}
					else
					{
						xCursor += Width_Square;
						++j;
						isPress = true;
					}
				}
			}
			else if (c == ENTER_KEY)
			{
				if (!board[i][j].locket)
				{
					board[i][j].locket = true;

					if (Turn == 1)
					{
						board[i][j].Type = 1;
					}
					else
					{
						board[i][j].Type = 2;
					}

					if (isWin(board, input.Size, i, j))
					{
						if (board[i][j].Type == 1)
						{
							Win(CMD, user1, 14);
						}
						else
						{
							Win(CMD, user2, 14);
						}
						deallocateBoard(board, input.Size);
					}

					if (isFull(board, input.Size))
					{
						Full(CMD, 12);
					}

					isEnter = true;
				}
			}
		}
	}

	deallocateBoard(board, input.Size);
}