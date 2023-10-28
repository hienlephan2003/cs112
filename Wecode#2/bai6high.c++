#include <iostream>

#define MAXN 40
using namespace std;
int N, M;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int C[MAXN][MAXN];
int hor[4] = {-1, +1, 0, 0};
int ver[4] = {0, 0, +1, -1};
void print()
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int i, int j, int mine)
{
    if (A[i][j] == 0)
    {
        for (int k = 0; k < 4; k++)
        {
            int x = i + hor[k];
            int y = j + ver[k];
            if (((j + ver[k]) >= 0) && ((j + ver[k]) < M) && ((i + hor[k]) >= 0) && ((i + hor[k]) < N))
            {
                if (B[x][y] == -1)
                    B[x][y] = 0;
            }
        }
    }
    if (C[i][j] == A[i][j])
    {
        for (int k = 0; k < 4; k++)
        {
            int x = i + hor[k];
            int y = j + ver[k];
            if (((j + ver[k]) >= 0) && ((j + ver[k]) < M) && ((i + hor[k]) >= 0) && ((i + hor[k]) < N))
            {
                if (B[x][y] == -1)
                    B[x][y] = 1;
            }
        }
    }
    for (int k = 0; k < 4; k++)
    {
        int x = i + hor[k];
        int y = j + ver[k];
        if (((j + ver[k]) >= 0) && ((j + ver[k]) < M) && ((i + hor[k]) >= 0) && ((i + hor[k]) < N))
        {
            if (mine == 1)
            {
                // Nếu gán bom thì số bom chưa xác định giảm 1
                A[x][y]--;
                C[x][y]--;
                if (A[x][y] == 0)
                {
                    // Những ô chưa biết có bom trong B sẽ gán = 0
                }
                if (A[x][y] < 0)
                {
                    C[x][y]++;
                    A[x][y]++;
                    return false;
                }
            }
            else
            {
                // Nếu không gán bom thì số ô chưa biết giảm 1
                C[x][y]--;

                // M ~ A, Solve ~ C
                if (A[x][y] > C[x][y])
                {
                    C[x][y]++;
                    return false;
                }
            }
        }
    }
    return true;
}
bool attempt(int i, int j)
{
    if (i == N)
    {
        print();
        return true;
    }
    if (j == M)
    {
        if (attempt(i + 1, 0))
            return true;
    }
    for (int mine = 1; mine >= 0; mine--)
    {
        if (B[i][j] == -1)
        {
            B[i][j] = mine;
            if (isValid(i, j, mine))
                attempt(i, j + 1);
            B[i][j] = -1;
        }
        else
        {
            if (isValid(i, j, mine))
                attempt(i, j + 1);
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
            B[i][j] = 0;
            if (i == 0 || i == N - 1)
            {
                if (j == 0 || j == M - 1)
                    C[i][j] = 2;
                else
                    C[i][j] = 3;
            }
            else
            {
                if (j == 0 || j == M - 1)
                    C[i][j] = 3;
                else
                    C[i][j] = 4;
            }
        }
    }
    attempt(0, 0);

    return 0;
}