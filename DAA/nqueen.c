#include <stdio.h>
#include <stdlib.h>

#define MAXN 20

int isSafePosition(int i, int j, char chessBoard[MAXN][MAXN], int n)
{
    int x, y;

    // Check for queens in the same column
    for (x = 0; x < i; x++)
    {
        if (chessBoard[x][j] == '1')
            return 0;
    }

    // Check for queens in the upper left diagonal
    for (x = i, y = j; x >= 0 && y >= 0; x--, y--)
    {
        if (chessBoard[x][y] == '1')
            return 0;
    }

    // Check for queens in the upper right diagonal
    for (x = i, y = j; x >= 0 && y < n; x--, y++)
    {
        if (chessBoard[x][y] == '1')
            return 0;
    }

    return 1;
}

void printChessBoard(char chessBoard[MAXN][MAXN], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", chessBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveHelper(int i, int n, char chessBoard[MAXN][MAXN])
{
    int j;
    if (i == n)
    {
        // Print the current configuration
        printChessBoard(chessBoard, n);
        return;
    }
    for (j = 0; j < n; j++)
    {
        if (isSafePosition(i, j, chessBoard, n))
        {
            chessBoard[i][j] = '1';
            solveHelper(i + 1, n, chessBoard);
            chessBoard[i][j] = '.';
        }
    }
}

void solveNQueens(int n)
{
    char chessBoard[MAXN][MAXN];

    // Initialize the chessboard
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chessBoard[i][j] = '.';
        }
    }
    solveHelper(0, n, chessBoard);
}

int main()
{
    int n;
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("Enter the size of the chessboard: ");
    scanf("%d", &n);

    if (n < 1 || n > MAXN)
    {
        printf("Invalid size of the chessboard.\n");
        return 1;
    }

    solveNQueens(n);

    return 0;
}
