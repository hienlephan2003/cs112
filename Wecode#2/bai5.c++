#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isValid(vector<string> valid_set, string s)
{
    valid_set.push_back(s);
    int n = valid_set.size();
    if (n >= 3)
    {
        // Check if the last number is equal to the sum of the two previous ones
        long long last_num = stoll(valid_set[n - 1]);
        long long sum = stoll(valid_set[n - 2]) + stoll(valid_set[n - 3]);
        if (last_num != sum)
            return false;
    }
    return true;
}
bool isAccepted(string s)
{
    if (s.empty())
        return false;
    if (s.size() > 1 && s[0] == '0')
        return false;
    return true;
}

bool checkNum(int start, string &s, vector<string> &goal_set)
{
    if (start == s.size() && goal_set.size() >= 3)
        return true;
    for (int i = start + 1; i <= s.size(); i++)
    {
        // If the current substring is validated, add it to goal_set
        string substr = s.substr(start, i - start);
        if (!isAccepted(substr))
            continue;
        if (isValid(goal_set, substr))
        {
            goal_set.push_back(substr);
            if (checkNum(i, s, goal_set))
                return true;
            goal_set.pop_back();
        }
    }
    // if there is no existed additive sequence in the input string
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    vector<string> cur;

    if (s.size() < 3)
        cout << "false";
    else
    {
        bool found = checkNum(0, s, cur);
        cout << ((found) ? "true" : "false");
    }

    return 0;
}