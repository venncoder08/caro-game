#include "check.h"

bool isVertical(CELL** board, int m, int n, int p, int q)
{
	int VerticalLine = 0;
	for (int i = p - 1; i >= 0 && i > p - 5; --i)
	{
		if (board[i][q].Type == board[p][q].Type)
		{
			VerticalLine++;
		}
		else
		{
			break;
		}
	}

	for (int i = p + 1; i < m && i < p + 5; ++i)
	{
		if (board[i][q].Type == board[p][q].Type)
		{
			VerticalLine++;
		}
		else
		{
			break;
		}
	}

	if (VerticalLine + 1 >= 5)
	{
		return true;
	}

	return false;
}

bool isHorizontal(CELL** board, int m, int n, int p, int q)
{
	int HorizontalLine = 0;
	for (int j = q - 1; j >= 0 && j > q - 5; --j)
	{
		if (board[p][j].Type == board[p][q].Type)
		{
			HorizontalLine++;
		}
		else
		{
			break;
		}
	}

	for (int j = q + 1; j < n && j < q + 5; ++j)
	{
		if (board[p][j].Type == board[p][q].Type)
		{
			HorizontalLine++;
		}
		else
		{
			break;
		}
	}

	if (HorizontalLine + 1 >= 5)
	{
		return true;
	}

	return false;
}

bool isMainDiagonal(CELL** board, int m, int n, int p, int q)
{
	int MainDiagonal = 0;
	for (int i = p - 1, j = q - 1; i >= 0 && i > p - 5 && j >= 0 && j > q - 5; --i, --j)
	{
		if (board[i][j].Type == board[p][q].Type)
		{
			MainDiagonal++;
		}
		else
		{
			break;
		}
	}

	for (int i = p + 1, j = q + 1; i < m && i < p + 5 && j < n && j < q + 5; ++i, ++j)
	{
		if (board[i][j].Type == board[p][q].Type)
		{
			MainDiagonal++;
		}
		else
		{
			break;
		}
	}

	if (MainDiagonal + 1 >= 5)
	{
		return true;
	}

	return false;
}

bool isSubDiagonal(CELL** board, int m, int n, int p, int q)
{
	int SubDiagonal = 0;
	for (int i = p + 1, j = q - 1; i < m && i < p + 5 && j >= 0 && j > q - 5; ++i, --j)
	{
		if (board[i][j].Type == board[p][q].Type)
		{
			SubDiagonal++;
		}
		else
		{
			break;
		}
	}

	for (int i = p - 1, j = q + 1; i >= 0 && i > p - 5 && j < n && j < q + 5; --i, ++j)
	{
		if (board[i][j].Type == board[p][q].Type)
		{
			SubDiagonal++;
		}
		else
		{
			break;
		}
	}

	if (SubDiagonal + 1 >= 5)
	{
		return true;
	}

	return false;
}

bool isWin(CELL** board, int m, int n, int i, int j)
{
	if (isVertical(board, m, n, i, j)) return true;
	if (isHorizontal(board, m, n, i, j)) return true;
	if (isMainDiagonal(board, m, n, i, j)) return true;
	if (isSubDiagonal(board, m, n, i, j)) return true;

	return false;
}