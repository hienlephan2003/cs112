#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int max_credits(int n, vector<vector<int>> &projects)
{
    sort(projects.begin(), projects.end(), compare);
    vector<int> dp(n, 0);
    for (int i = 0; i < projects.size(); i++)
    {
        dp[i] = projects[i][2];
    }
    dp[0] = projects[0][2];
    for (int i = 1; i < n; i++)
    {
        // int prev = -1;
        for (int j = 0; j <= i; j++)
        {
            if (projects[i][0] > projects[j][1])
            {
                dp[i] = max(dp[i], dp[j] + projects[i][2]);
                // cout << i << dp[i] << " " << j << endl;
            }
        }
        // if (prev == -1)
        // {
        //     dp[i] = max(dp[i - 1], projects[i][2]);
        // }
        // else
        // {
        //     dp[i] = max(dp[i - 1], dp[prev] + projects[i][2]);
        // }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    cout << max_credits(n, projects) << endl;
    return 0;
}
