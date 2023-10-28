#include <iostream>
#include <vector>
#include <map>
#include <set>
#define MAXN 40
using namespace std;
int N, M;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int checked[MAXN][MAXN];
map<pair<int, int>, set<pair<int, int>>> memo;
int hor[4] = {-1, +1, 0, 0};
int ver[4] = {0, 0, +1, -1};

int COUNT = 0;
bool attempt(int, int);
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
bool checkSurroundMine(int i, int j)
{
    int count = 0;
    for (int k = 0; k < 4; k++)
    {
        if (((j + ver[k]) >= 0) && ((j + ver[k]) < M) && ((i + hor[k]) >= 0) && ((i + hor[k]) < N))
        {
            count += B[i + hor[k]][j + ver[k]];
        }
    }
    COUNT = count;
    return A[i][j] == count;
}
void checkedAll(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        if (((j + ver[k]) >= 0) && ((j + ver[k]) < M) && ((i + hor[k]) >= 0) && ((i + hor[k]) < N))
        {
            if (!checked[i + hor[k]][j + ver[k]])
            {
                checked[i + hor[k]][j + ver[k]] = 1;
                memo[{i, j}].insert({i + hor[k], j + ver[k]});
            }
        }
    }
}
int checkSurroundAvailable(int i, int j)
{
    int avail = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + hor[k];
        int y = j + ver[k];
        if (((y) >= 0) && ((y) < M) && ((x) >= 0) && ((x) < N))
        {
            if (!checked[x][y])
                avail++;
        }
    }
    return avail;
}
void removedAll(int i, int j)
{
    for (auto p : memo[{i, j}])
    {
        int x = p.first;
        int y = p.second;
        checked[x][y] = 0;
    }
    memo[{i, j}].clear();
}
bool isValid(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        int x = i + hor[k];
        int y = j + ver[k];
        if (((y) >= 0) && ((y) < M) && ((x) >= 0) && ((x) < N))
        {
            checkSurroundMine(x, y);
            if (COUNT > A[x][y] || COUNT + checkSurroundAvailable(x, y) < A[x][y])
            {
                return false;
            }
        }
    }
    return true;
}
bool tryCase(int mine, int i, int j)
{
    switch (mine)
    {
    case 1:
        checkSurroundMine(i, j);
        if (COUNT > A[i][j] || COUNT + checkSurroundAvailable(i, j) < A[i][j])
        {
            return false;
        }
        for (int k = 0; k < 4; k++)
        {
            int x = i + hor[k];
            int y = j + ver[k];
            if (((y) >= 0) && ((y) < M) && ((x) >= 0) && ((x) < N))
            {
                if (!checked[x][y])
                {
                    B[x][y] = 1;
                    checkSurroundMine(x, y);
                    if (COUNT > A[x][y] || COUNT + checkSurroundAvailable(x, y) < A[x][y])
                    {
                        B[x][y] = 0;
                        return false;
                    }
                    // Check if validation
                    if (x + 1 < N)
                    {
                        checkSurroundMine(x + 1, y);
                        if (COUNT > A[x + 1][y] || COUNT + checkSurroundAvailable(x + 1, y) < A[x + 1][y])
                        {
                            B[x][y] = 0;
                            continue;
                        }
                    }
                    if (x - 1 >= 0)
                    {
                        checkSurroundMine(x - 1, y);
                        if (COUNT > A[x - 1][y] || COUNT + checkSurroundAvailable(x - 1, y) < A[x - 1][y])
                        {
                            B[x][y] = 0;
                            continue;
                        }
                    }
                    if (y + 1 < M)
                    {
                        checkSurroundMine(x, y + 1);
                        if (COUNT > A[x][y + 1] || COUNT + checkSurroundAvailable(x, y + 1) < A[x][y + 1])
                        {
                            B[x][y] = 0;
                            continue;
                        }
                    }
                    if (y - 1 >= 0)
                    {
                        checkSurroundMine(x, y - 1);
                        if (COUNT > A[x][y - 1] || COUNT + checkSurroundAvailable(x, y - 1) < A[x][y - 1])
                        {
                            B[x][y] = 0;
                            continue;
                        }
                    }
                    // print();
                    checkedAll(i, j);
                    if (checkSurroundMine(i, j) && attempt(i, j + 1))
                        return true;
                    removedAll(i, j);
                    B[x][y] = 0;
                }
            }
        }
        if (!checkSurroundMine(i, j))
            return false;
        return attempt(i, j + 1);
    case 2:
        checkSurroundMine(i, j);
        if (COUNT > A[i][j] || COUNT + checkSurroundAvailable(i, j) < A[i][j])
        {
            return false;
        }
        int x1 = i + hor[1];
        int y1 = j + ver[1];
        int x2 = i + hor[2];
        int y2 = j + ver[2];
        if (((y1) >= 0) && ((y1) < M) && ((x1) >= 0) && ((x1) < N))
        {
            if (((y2) >= 0) && ((y2) < M) && ((x2) >= 0) && ((x2) < N))
            {
                if (!checked[x1][y1] && !checked[x2][y2])
                {
                    B[x1][y1] = 1;
                    B[x2][y2] = 1;
                    // Check if validation
                    checkSurroundMine(x1, y1);
                    if (COUNT > A[x1][y1] || COUNT + checkSurroundAvailable(x1, y1) < A[x1][y1])
                    {
                        B[x1][y1] = 0;
                        B[x2][y2] = 0;
                        return false;
                    }
                    checkSurroundMine(x2, y2);
                    if (COUNT > A[x2][y2] || COUNT + checkSurroundAvailable(x2, y2) < A[x2][y2])
                    {
                        B[x1][y1] = 0;
                        B[x2][y2] = 0;
                        return false;
                    }
                    if (x1 + 1 < N)
                    {
                        checkSurroundMine(x1 + 1, y1);
                        if (COUNT > A[x1 + 1][y1] || COUNT + checkSurroundAvailable(x1 + 1, y1) < A[x1 + 1][y1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (x2 + 1 < N)
                    {
                        checkSurroundMine(x2 + 1, y1);
                        if (COUNT > A[x2 + 1][y1] || COUNT + checkSurroundAvailable(x2 + 1, y1) < A[x2 + 1][y1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (y1 + 1 < M)
                    {
                        checkSurroundMine(x1, y1 + 1);
                        if (COUNT > A[x1][y1 + 1] || COUNT + checkSurroundAvailable(x1, y1 + 1) < A[x1][y1 + 1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (y2 + 1 < M)
                    {
                        checkSurroundMine(x2, y2 + 1);
                        if (COUNT > A[x2][y2 + 1] || COUNT + checkSurroundAvailable(x2, y2 + 1) < A[x2][y2 + 1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (y2 - 1 >= 0)
                    {
                        checkSurroundMine(x2, y2 - 1);
                        if (COUNT > A[x2][y2 - 1] || COUNT + checkSurroundAvailable(x2, y2 - 1) < A[x2][y2 - 1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (y1 - 1 >= 0)
                    {
                        checkSurroundMine(x2, y1 - 1);
                        if (COUNT > A[x2][y1 - 1] || COUNT + checkSurroundAvailable(x2, y1 - 1) < A[x2][y1 - 1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (x1 - 1 >= 0)
                    {
                        checkSurroundMine(x1 - 1, y1);
                        if (COUNT > A[x1 - 1][y1] || COUNT + checkSurroundAvailable(x1 - 1, y1) < A[x1 - 1][y1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    if (x2 - 1 >= 0)
                    {
                        checkSurroundMine(x2 - 1, y1);
                        if (COUNT > A[x2 - 1][y1] || COUNT + checkSurroundAvailable(x2 - 1, y1) < A[x2 - 1][y1])
                        {
                            B[x1][y1] = 0;
                            B[x2][y2] = 0;
                            return false;
                        }
                    }
                    checkedAll(i, j);
                    // print();
                    if (checkSurroundMine(i, j) && attempt(i, j + 1))
                        return true;
                    removedAll(i, j);
                    B[x2][y2] = 0;
                    B[x1][y1] = 0;
                }
            }
        }
        if (!checkSurroundMine(i, j))
            return false;
        return attempt(i, j + 1);
    }
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

    // New state
    if (checkSurroundMine(i, j))
    {
        checkedAll(i, j);
        if (attempt(i, j + 1))
            return true;
        removedAll(i, j);
    }
    if (!isValid(i, j))
        return false;
    checkSurroundMine(i, j);
    switch (COUNT)
    {
    case 0:
        switch (A[i][j])
        {
        case 1:
            return tryCase(1, i, j);
        case 2:
            if ((i == 0 && j == 1) || (i == 1 && j == 0))
            {
                B[0][0] = 1;
                checked[0][0] = 1;
                if (!tryCase(1, i, j))
                {
                    B[0][0] = 0;
                    checked[0][0] = 0;
                    return tryCase(2, i, j);
                }
            }
            else
            {
                return tryCase(2, i, j);
            }
            break;

        case 3:
            if ((i == 0 && j == 1) || (i == 1 && j == 0))
            {
                B[0][0] = 1;
                checked[0][0] = 1;
                return tryCase(2, i, j);
            }
            break;
        default:
            return false;
        }
        break;
    case 1:
        switch (A[i][j])
        {
        case 2:
            return tryCase(1, i, j);
        case 3:
            return tryCase(2, i, j);
        default:
            return false;
        }
        break;
    case 2:
        switch (A[i][j])
        {
        case 3:
            return tryCase(1, i, j);
        case 4:
            return tryCase(2, i, j);
        default:
            return false;
        }
        break;
    case 3:
        switch (A[i][j])
        {
        case 4:
            return tryCase(1, i, j);
        default:
            return false;
        }
        break;
    default:
        break;
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
            B[i][j] = 0;
            checked[i][j] = 0;
        }
    }
    attempt(0, 0);

    return 0;
}