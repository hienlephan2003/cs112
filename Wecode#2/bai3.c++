#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isPalindrome(string &s)
{
    int n = s.length();
    for (size_t i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}

void printResult(vector<string> &goal_set)
{
    for (auto &s : goal_set)
        cout << s << endl;
}

void separate_palindrome(int i, string &s, vector<string> &goal_set)
{
    // Iterate through all possible substrings from i index
    for (int j = i + 1; j <= s.length(); j++)
    {
        // If the current substring is palindrome, add it to goal_set
        string substr = s.substr(i, j - i);
        if (isPalindrome(substr))
        {
            goal_set.push_back(substr);
        }
        if (i == s.length())
        {
            printResult(goal_set);
        }
        else
            separate_palindrome(j, s, goal_set);

        // Backtrack here!
        goal_set.pop_back();
    }
}

int main()
{
    // input s
    string s;
    getline(cin, s);
    vector<string> curr;
    separate_palindrome(0, s, curr);
    return 0;
}