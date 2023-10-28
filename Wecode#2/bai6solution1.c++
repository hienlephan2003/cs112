#include <stdio.h>
#include <iostream>
#include <iomanip>

#define MAXN 40
using namespace std;

int row, col;
int board[MAXN][MAXN];
int mine[MAXN][MAXN];
int hor[4] = {-1, +0, +1, +0};
int ver[4] = {+0, -1, +0, +1};

void input()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }
}

void initialization()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mine[i][j] = 0;
        }
    }
}

void print()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mine[i][j] << " ";
        }
        cout << endl;
    }
}

int possible(int j) // j la cot
{
    int count;
    for (int i = 0; i < row; i++) // i la hang
    {
        count = 0;
        mine[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            if (((j - 1 + ver[k]) >= 0) && ((j - 1 + ver[k]) < col) && ((i + hor[k]) >= 0) && ((i + hor[k]) < row))
            {
                count += mine[i + hor[k]][j - 1 + ver[k]];
            }
        }
        switch (board[i][j - 1] - count)
        {
        case 0:
            mine[i][j] = 0;
            break;
        case 1:
            mine[i][j] = 1;
            break;
        default:
            return false;
            break;
        }
    }
    return true;
}
void try_hor(int i)
{
    if (i == col)
    {
        print();
        return;
    }
    else
    {
        for (int j = 0; j <= 1; j++)
        {
            mine[0][i] = j;
            if (possible(i))
                try_hor(i + 1);
        }
    }
}
void try_ver(int i)
{
    if (i == row)
        try_hor(1);
    else
    {
        for (int j = 1; j >= 0; j--)
        {
            mine[i][0] = j;
            try_ver(i + 1);
        }
    }
}

int main()
{
    input();
    initialization();
    try_ver(0);

    cin.get();
    return 0;
}