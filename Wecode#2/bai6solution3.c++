#include <iostream>
#include <vector>
using namespace std;

#define MAXN 40

int row, col;
int board[MAXN][MAXN];
vector<vector<int>> mine;

bool possible(int i, int j)
{
    int count = 0;
    for (int u = max(0, i - 1); u <= min(row - 1, i + 1); u++) // check adjacent squares
        for (int v = max(0, j - 1); v <= min(col - 1, j + 1); v++)
            count += mine[u][v];
    return count == board[i][j];
}

bool solve(int i, int j)
{
    if (j >= col)
    {
        j = 0;
        i++;
    }
    if (i >= row)
        return true; // solution found
    mine[i][j] = 0;
    if (possible(i, j) && solve(i, j + 1))
        return true;
    mine[i][j] = 1;
    if (possible(i, j) && solve(i, j + 1))
        return true;
    mine[i][j] = 0; // reset to 0 if no solution
    return false;
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

int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> board[i][j];
    mine.assign(row, vector<int>(col, 0));
    if (solve(0, 0))
        print();
    else
        cout << "No solution found" << endl;
    return 0;
}
