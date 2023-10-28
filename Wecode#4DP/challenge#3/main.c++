#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<vector<int>>> dp(target + 1);
    dp[0].push_back({});
    for (int candidate : candidates)
    {
        for (int i = 1; i <= target; i++)
        {
            if (i - candidate >= 0)
            {
                for (vector<int> combination : dp[i - candidate])
                {
                    combination.push_back(candidate);
                    dp[i].push_back(combination);
                }
            }
        }
    }
    return dp[target];
}

int main()
{
    vector<int> candidates = {1, 2, 3, 4, 5, 6};
    int target;
    cin >> target;
    vector<vector<int>> cmbSum = combinationSum(candidates, target);
    cout << cmbSum.size() % (int)(1e9 + 7) << endl;
    return 0;
}
