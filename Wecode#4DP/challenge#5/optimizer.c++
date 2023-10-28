#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const vector<long long> &a, const vector<long long> &b)
{
    return a[1] < b[1];
}

long long binarySearch(const vector<vector<long long>> &projects, long long left, long long right, long long target)
{
    long long result = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (projects[mid][1] < target)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

long long max_credits(long long n, vector<vector<long long>> &projects)
{
    sort(projects.begin(), projects.end(), compare);
    vector<long long> dp(n, 0);
    dp[0] = projects[0][2];
    for (long long i = 1; i < n; i++)
    {
        long long prev = binarySearch(projects, 0, i - 1, projects[i][0]);
        if (prev != -1)
        {
            dp[i] = max(dp[i - 1], dp[prev] + projects[i][2]);
        }
        else
        {
            dp[i] = max(dp[i - 1], projects[i][2]);
        }
    }
    return dp[n - 1];
}

int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>> projects(n, vector<long long>(3));
    for (long long i = 0; i < n; i++)
    {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    cout << max_credits(n, projects) << endl;
    return 0;
}
