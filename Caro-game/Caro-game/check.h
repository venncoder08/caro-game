#ifndef CHECK_HEADER
#define CHECK_HEADER

#include "source.h"

bool isVertical(CELL** board, int Size, int p, int q);
bool isHorizontal(CELL** board, int Size, int p, int q);
bool isMainDiagonal(CELL** board, int Size, int p, int q);
bool isSubDiagonal(CELL** board, int Size, int p, int q);
bool isWin(CELL** board, int Size, int i, int j);

#endif // !CHECK_HEADER
