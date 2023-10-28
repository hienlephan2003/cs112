#include <iostream>
#include <vector>

using namespace std;

const int n = 50;
int A[n][n], B[n][n];
int N, M;

// Hàm kiểm tra trạng thái hợp lệ
bool isValid(int B[][n])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != 0)
            {
                int s = 0;
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (abs(i - k) + abs(j - l) == 1)
                            if (k >= 0 && k < N && l >= 0 && l < M && B[k][l] == 1)
                            {
                                s += 1;
                            }
                    }
                }
                if (s != A[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// Hàm thực hiện backtracking để đánh dấu các ô chứa mìn
bool backtrack(vector<vector<int>> &mines, int idx)
{
    if (idx == mines.size())
    {
        return isValid(B);
    }
    else
    {
        int i = mines[idx][0];
        int j = mines[idx][1];
        B[i][j] = 4;
        if (isValid(B) && backtrack(mines, idx + 1))
        {
            return true;
        }
        B[i][j] = 0;
        if (backtrack(mines, idx + 1))
        {
            return true;
        }
        return false;
    }
}

// Hàm giải bài toán
void solveMine()
{
    vector<vector<int>> mines;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != 0)
            {
                mines.push_back(vector<int>{i, j});
            }
            B[i][j] = 0;
        }
    }

    bool result = backtrack(mines, 0);
    if (result)
    {
        cout << "Found solution:" << endl;
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
        cout << "No solution found." << endl;
    }
}

int main()
{
    // Khởi tạo ma trận A
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    // Giải bài toán dò mìn
    solveMine();

    return 0;
}
