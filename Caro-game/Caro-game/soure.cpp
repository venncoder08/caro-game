#include "source.h"

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

CELL** initializeBoard(int m, int n)
{
	CELL** board = new CELL * [m];
	for (int i = 0; i < m; ++i)
	{
		board[i] = new CELL[n];
	}

	return board;
}

void deallocateBoard(CELL** &board, int m)
{
	for (int i = 0; i < m; ++i)
	{
		delete[] board[i];
	}

	delete[] board;
}

void GotoUnlock(CELL** board, int m, int n, int& i, int& j)
{
	//Check the vertical line
	for (int p = i - 1; p >= 0; --p)
	{
		if (!board[p][j].locket)
		{
			i = p;
			return;
		}
	}

	for (int p = i + 1; p < m; ++p)
	{
		if (!board[p][j].locket)
		{
			i = p;
			return;
		}
	}

	//Check the horizontal line
	for (int q = j - 1; q >= 0; --q)
	{
		if (!board[i][q].locket)
		{
			j = q;
			return;
		}
	}

	for (int q = j + 1; q < n; ++q)
	{
		if (!board[i][q].locket)
		{
			j = q;
			return;
		}
	}

	//Check the main diagonal
	for (int p = i - 1, q = j - 1; p >= 0 && q >= 0; --p, --q)
	{
		if (!board[p][q].locket)
		{
			i = p;
			j = q;
			return;
		}
	}

	for (int p = i + 1, q = j + 1; p < m && q < n; ++p, ++q)
	{
		if (!board[p][q].locket)
		{
			i = p;
			j = q;
			return;
		}
	}

	//Check the sub diagonal
	for (int p = i + 1, q = j - 1; p < m && q >= 0; ++p, --q)
	{
		if (!board[p][q].locket)
		{
			i = p;
			j = q;
			return;
		}
	}

	for (int p = i - 1, q = j + 1; p >= 0 && q < n; ++p, --q)
	{
		if (!board[p][q].locket)
		{
			i = p;
			j = q;
			return;
		}
	}
}

BoardGame calcCorrectSizeBoard(int xBoard, int yBoard, int xBorderEnd, int yBorderEnd)
{
	BoardGame temp;
	temp.mSize = 5;
	temp.nSize = 5;

	while ((xBoard + (Width_Square * temp.nSize) < xBorderEnd) || (yBoard + (Height_Square * temp.mSize) < yBorderEnd))
	{
		if (xBoard + (Width_Square * temp.nSize) < xBorderEnd)
		{
			temp.nSize++;
		}

		if (yBoard + (Height_Square * temp.mSize) < yBorderEnd)
		{
			temp.mSize++;
		}
	}

	temp.Width_Board = temp.nSize * Width_Square;
	temp.Height_Board = temp.mSize * Height_Square;

	return temp;
}

void inputIndicator(const System CMD, const int xBorder, const int yBorder, const int Border_Width, const int Border_Height, BoardGame& input, Player& user1, Player& user2, int background_color, int notice_color)
{
	ShowCursor();

	//Declare a variable to compare (conditional) & temp variable
	BoardGame compare = calcCorrectSizeBoard(xBorder + 1, yBorder + 1, Border_Width, Border_Height);
	BoardGame temp;
	Player temp_user1, temp_user2;

	//Information about image header
	int Width_Img = 0, Height_Img = 0;
	getInfoImage(header, Width_Img, Height_Img);

	//Input
	do
	{
		clrscr();
		printImageHeader(CMD, background_color, header);
		TextColor(background_color);

		int xInput = 1;
		int yInput = Height_Img + 1;

		gotoxy(xInput, yInput++);
		cout << "Enter the size of board game (5 - " << compare.mSize << ", 5 - " << compare.nSize << "): ";
		cin >> temp.mSize >> temp.nSize;
		gotoxy(xInput, yInput++);
		cout << "Enter the name of player 1: ";
		cin >> temp_user1.name;
		gotoxy(xInput, yInput++);
		cout << "Enter the name of player 2: ";
		cin >> temp_user2.name;

		temp_user1.Turn = 1;
		temp_user2.Turn = 2;

		if (temp.mSize < 5 || temp.nSize < 5 || temp.mSize > compare.mSize || temp.nSize > compare.nSize || temp_user1.name.length() > 6 || temp_user2.name.length() > 6)
		{
			string ans;
			yInput += 2;
			TextColor(notice_color);
			gotoxy(xInput, yInput++);
			cout << "The values you entered do not meet the requirements";
			gotoxy(xInput, yInput);
			cout << "If you want re-enter or quit, say Y/y or Any key: ";
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
		else
		{
			break;
		}

	} while (true);

	input = temp;
	user1 = temp_user1;
	user2 = temp_user2;
}

bool isFull(CELL** board,int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j].Type == 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool GotoUnlockSquare(CELL** board, int m, int n, int& i, int& j, int PassKey)
{
	if (PassKey == 1)
	{
		for (int p = i - 1; p >= 0; --p)
		{
			if (!board[p][j].locket)
			{
				i = p;
				return true;
			}
		}
	}
	else if (PassKey == 2)
	{
		for (int p = i + 1; p < m; ++p)
		{
			if (!board[p][j].locket)
			{
				i = p;
				return true;
			}
		}
	}
	else if (PassKey == 3)
	{
		for (int q = j - 1; q >= 0; --q)
		{
			if (!board[i][q].locket)
			{
				j = q;
				return true;
			}
		}
	}
	else
	{
		for (int q = j + 1; q < n; ++q)
		{
			if (!board[i][q].locket)
			{
				j = q;
				return true;
			}
		}
	}

	return false;
}

void StandardMode(const System CMD, int background_color)
{
	//Declare input
	BoardGame input;
	Player user1, user2;

	//Get size of header image
	int Img_Width = 0;
	int Img_Height = 0;
	getInfoImage(header, Img_Width, Img_Height);
	
	//Indicator of board game
	int xBoardGame = 2;
	int yBoardGame = Img_Height + 2;

	//Indicator of table information
	int xTable = CMD.Width_PowerShell - 35;
	int yTable = 1;
	int WidthTable = 42;
	int Table_Width = 30;
	int Table_Height = 10;

	//Indicator of separation line
	int xSeparationLine1 = xTable - 5;
	int xSeparationLine2 = xTable - 4;

	//Indicator of box contains board game
	int xBorder = 1;
	int yBorder = Img_Height + 1;
	int Border_Width = xSeparationLine1 - 5;
	int Border_Height = CMD.Height_PowerShell - Img_Height - 3;

	//Indicator of color
	int notice_color = 12;
	int separationLine_color1 = 80;
	int separationLine_color2 = 208;
	int border_color = 14;
	int locketTurn1_color = 192;
	int locketTurn2_color = 32;
	int effect_color = 128;

	//Indicator of new game
	int Turn = 1;
	int i = 0, j = 0;
	int xCursor = xBoardGame;
	int yCursor = yBoardGame;
	int xPrevCursor = xCursor;
	int yPrevCursor = yCursor;
	int PassKey = 0;
	bool isPress = false;
	bool isEnter = false;
	bool checkFull = false;

	inputIndicator(CMD, xBorder, yBorder, Border_Width - 1, Border_Height + yBorder - 2, input, user1, user2, background_color, notice_color);

	clrscr();

	//Print header image
	printImageHeader(CMD, background_color, header);

	//Print box contain a board game and table infor
	createBox2(xBorder, yBorder, Border_Width, Border_Height, border_color, border_color, "");
	TableInfor(user1, xTable, yTable, i, j);
	TextColor(background_color);

	//Print a board game
	createBoardGame(xBoardGame, yBoardGame, input.mSize, input.nSize);
	EffectCursor(xBoardGame, yBoardGame, Width_Square, Height_Square, effect_color, "");

	//Print a separation line
	DrawLine(CMD, xSeparationLine1, separationLine_color1);
	DrawLine(CMD, xSeparationLine2, separationLine_color2);
	
	//Initialize data
	CELL** board = initializeBoard(input.mSize, input.nSize);

	HideCursor();
	while (1)
	{
		if (isFull(board, input.mSize, input.nSize))
		{
			clearScreen(CMD, background_color);
			TieScreen(CMD, user1, user2, background_color, 14);
		}

		if (isEnter)
		{
			GotoUnlock(board, input.mSize, input.nSize, i, j);

			if (Turn == 1)
			{
				TableInfor(user2, xTable, yTable, i, j);
				EffectCursor(xCursor, yCursor, Width_Square, Height_Square, locketTurn1_color, "X");
				Turn = 2;
			}
			else
			{
				TableInfor(user1, xTable, yTable, i, j);
				EffectCursor(xCursor, yCursor, Width_Square, Height_Square, locketTurn2_color, "O");
				Turn = 1;
			}

			yCursor = yBoardGame + i * Height_Square;
			xCursor = xBoardGame + j * Width_Square;
			xPrevCursor = xCursor;
			yPrevCursor = yCursor;
			EffectCursor(xCursor, yCursor, Width_Square, Height_Square, effect_color, "");
			isEnter = false;
			checkFull = true;
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

				if (GotoUnlockSquare(board, input.mSize, input.nSize, i, j, PassKey))
				{
					xCursor = j * Width_Square + xBoardGame;
					yCursor = i * Height_Square + yBoardGame;
					EffectCursor(xPrevCursor, yPrevCursor, Width_Square, Height_Square, background_color, "");
					xPrevCursor = xCursor;
					yPrevCursor = yCursor;
					EffectCursor(xCursor, yCursor, Width_Square, Height_Square, effect_color, "");
				}
			}

			if (Turn == 1)
			{
				TableInfor(user1, xTable, yTable, i, j);
			}
			else
			{
				TableInfor(user2, xTable, yTable, i, j);
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
					PassKey = 1;
					if (yCursor != yBoardGame)
					{
						yCursor -= Height_Square;
						--i;
						playSound(MOVE_SOUND);
						isPress = true;
					}
					else
					{
						yCursor = yBoardGame + (Height_Square * (input.mSize - 1));
						i = input.mSize - 1;
						playSound(MOVE_SOUND);
						isPress = true;
					}
				}
				else if (c == DOWN_KEY)
				{
					PassKey = 2;
					if (yCursor != yBoardGame + (Height_Square * (input.mSize - 1)))
					{
						yCursor += Height_Square;
						++i;
						playSound(MOVE_SOUND);
						isPress = true;
					}
					else
					{
						yCursor = yBoardGame;
						i = 0;
						playSound(MOVE_SOUND);
						isPress = true;
					}
				}
				else if (c == LEFT_KEY)
				{
					PassKey = 3;
					if (xCursor == xBoardGame)
					{
						xCursor = xBoardGame + (Width_Square * (input.nSize - 1));
						j = input.nSize - 1;
						playSound(MOVE_SOUND);
						isPress = true;
					}
					else
					{
						xCursor -= Width_Square;
						--j;
						playSound(MOVE_SOUND);
						isPress = true;
					}
				}
				else if (c == RIGHT_KEY)
				{
					PassKey = 4;
					if (xCursor == xBoardGame + (Width_Square * (input.nSize - 1)))
					{
						xCursor = xBoardGame;
						j = 0;
						playSound(MOVE_SOUND);
						isPress = true;
					}
					else
					{
						xCursor += Width_Square;
						++j;
						playSound(MOVE_SOUND);
						isPress = true;
					}
				}
			}
			else if (c == ENTER_KEY)
			{
				if (!board[i][j].locket)
				{
					playSound(ENTER_SOUND);
					board[i][j].locket = true;

					if (Turn == 1)
					{
						board[i][j].Type = 1;
					}
					else
					{
						board[i][j].Type = 2;
					}

					if (isWin(board, input.mSize, input.nSize, i, j))
					{
						if (board[i][j].Type == 1)
						{
							clearScreen(CMD, background_color);
							WinScreen(CMD, user1, background_color, 14);
						}
						else
						{
							clearScreen(CMD, background_color);
							WinScreen(CMD, user2, background_color, 14);
						}
					}

					isEnter = true;
				}
			}
		}
	}
}