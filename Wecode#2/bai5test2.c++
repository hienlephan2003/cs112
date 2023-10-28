#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(vector<string> valid_set)
{
    int n = valid_set.size();
    if (n < 3)
        // Not enough numbers to form an additive sequence.
        return false;

    for (size_t i = 2; i < n; i++)
        // Check if the last number is equal to the sum of the two previous ones
        if (stoll(valid_set[i]) != stoll(valid_set[i - 1]) + stoll(valid_set[i - 2]))
            return false;
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
    if (start == s.size() && isValid(goal_set))
    {
        return true;
    }

    for (int i = start + 1; i <= s.size(); i++)
    {
        // If the current substring is validated, add it to goal_set
        string substr = s.substr(start, i - start);
        if (isAccepted(substr))
        {
            goal_set.push_back(substr);
            // if any additive sequence existing in the input string, we return immediately true and dont check another ways.
            if (checkNum(i, s, goal_set))
                return true;
            // Backtrack here
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