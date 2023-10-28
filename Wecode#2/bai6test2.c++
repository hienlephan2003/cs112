#include <iostream>
using namespace std;
const int MAX = 40;
int a[MAX][MAX], n, m, f[MAX][MAX];
int getMine(int x, int y)
{ // trả về số mìn xung quanh ô (x, y)
    int cnt = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (abs(x - i) + abs(y - j) == 1)
                if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] > 0)
                {
                    cnt++;
                }
        }
    }
    return cnt;
}
void solve(int x, int y)
{ // giải bài toán đệ qui
    if (f[x][y] != -1)
        return;
    int mine = getMine(x, y);
    if (mine == 0)
    { // ô không có mìn
        f[x][y] = 0;
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i >= 0 && i < n && j >= 0 && j < m)
                {
                    solve(i, j);
                }
            }
        }
    }
    else
    { // ô có mìn
        f[x][y] = mine;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            f[i][j] = -1; // chưa xác định
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (f[i][j] == -1)
            {
                solve(i, j); // giải đệ qui
            }
        }
    }
    // in ra kết quả
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
