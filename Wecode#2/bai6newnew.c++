#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> A;
vector<vector<int>> B;
int hor[4] = {-1, 0, +1, 0};
int ver[4] = {0, +1, 0, -1};
void print()
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
bool tryCase(int i, int j)
{
}
bool checkSurroundMine(int j)
{
    int count = 0;
    for (int k = 0; k < 4; k++)
    {
        if (((j + ver[k]) >= 0) && ((j + ver[k]) < M) && ((i + hor[k]) >= 0) && ((i + hor[k]) < N))
        {
            if (B[i + hor[k]][j + ver[k]] == -1)
            {
                B[i + hor[k]][j + ver[k]] = 0;
            }
            else
            {
                count += B[i + hor[k]][j + ver[k]];
            }
        }
    }
    return A[i][j] == count;
}
bool attempt(int i)
{
    if (i == N - 1)
    {
        print();
        return true;
    }
    for (int j = 0; j < M; j++)
    {
        while (!checkSurroundMine(i, j))
            switch (A[i][j])
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;

            default:
                break;
            }
    }
}
bool try_ver(int i) // `i` is column
{
    if (i == M)
    {
        return true;
    }
    if (checkSurroundMine(i))
        try_ver(i + 1);
}
bool try_hor(int i)
{
    if (i == N - 1)
    {
        print();
        return true;
    }
    if (try_ver(i))
        try_hor(i + 1);
}
int main()
{
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<vector<int>> B(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    attempt(0);
    return 0;
}