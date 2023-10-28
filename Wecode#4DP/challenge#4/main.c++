#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int count_safe_paths(int n, vector<string> &grid)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    dp[1][1] = (grid[0][0] == '.') ? 1 : 0;

    // Duyệt qua cột bên trái đầu tiên (gặp chốt thì dừng) chỉ đi xuống
    for (int i = 1; i <= n; i++)
    {
        if (grid[i - 1][0] == '*')
        {
            break;
        }
        dp[i][1] = 1;
    }

    // Duyệt qua hàng đầu tiên (gặp chốt thì dừng) chỉ đi qua phải
    for (int j = 1; j <= n; j++)
    {
        if (grid[0][j - 1] == '*')
        {
            break;
        }
        dp[1][j] = 1;
    }

    // Với mỗi ô còn lại, nếu như ô hiện tại không phải là chốt thì cập nhật giá trị dp[i][j] bằng ô trên + ô trái
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (grid[i - 1][j - 1] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    return dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int result = count_safe_paths(n, grid);
    cout << result << endl;
    return 0;
}