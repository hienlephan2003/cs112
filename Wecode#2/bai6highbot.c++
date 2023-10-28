#include <iostream>
#include <vector>

#define MAXN 40

using namespace std;

enum CellState
{
    UNKNOWN = -1,
    BOMB = 0,
    CLEAR = 1
};

int N, M;
int A[MAXN][MAXN];
CellState B[MAXN][MAXN];

int hor[4] = {-1, +1, 0, 0};
int ver[4] = {0, 0, +1, -1};

bool isValid(int i, int j, CellState state)
{
    if (state == BOMB)
    {
        for (int k = 0; k < 8; k++)
        {
            int x = i + hor[k];
            int y = j + ver[k];
            if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
            {
                if (B[x][y] == UNKNOWN)
                    B[x][y] = CLEAR;
                else if (B[x][y] == BOMB)
                    continue;
                A[x][y]--;
                if (A[x][y] < 0)
                    return false;
                if ((A[x][y] == 0) && (B[x][y] == UNKNOWN))
                    B[x][y] = CLEAR;
            }
        }
    }
    else if (state == CLEAR)
    {
        for (int k = 0; k < 8; k++)
        {
            int x = i + hor[k];
            int y = j + ver[k];
            if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
            {
                if (B[x][y] == BOMB)
                    A[i][j]--;
                else if (B[x][y] == UNKNOWN)
                    continue;
            }
        }
        if (A[i][j] < 0)
            return false;
        if (A[i][j] == 0)
        {
            for (int k = 0; k < 8; k++)
            {
                int x = i + hor[k];
                int y = j + ver[k];
                if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
                {
                    if (B[x][y] == UNKNOWN)
                        B[x][y] = CLEAR;
                }
            }
        }
    }
    return true;
}

bool attempt(int i, int j)
{
    if (i == N)
        return true;
    if (j == M)
        return attempt(i + 1, 0);
    for (CellState state : {BOMB, CLEAR})
    {
        if (B[i][j] == UNKNOWN)
        {
            B[i][j] = state;
            if (isValid(i, j, state))
            {
                if (attempt(i, j + 1))
                    return true;
            }
            B[i][j] = UNKNOWN;
        }
        else if (isValid(i, j, state))
        {
            if (attempt(i, j + 1))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
            B[i][j] = UNKNOWN;
        }
    }
    if (attempt(0, 0))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found" << endl;
    }
    return 0;
}
