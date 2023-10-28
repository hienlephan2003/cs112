#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  function to check if a string is a palindrome or not
bool isPalindrome(string &s)
{
    int n = s.length();
    for (size_t i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}

//  function prints the elements of a goal_set vector
void printResult(vector<string> &goal_set)
{
    for (auto &s : goal_set)
        cout << s << " ";
    cout << endl;
}

//`i` represents the starting index of the substring that we are currently considering when finding palindrome substrings.
void separate_palindrome(int i, string &s, vector<string> &goal_set)
{
    // Base case: i is equal to s.length(). It means that all possible substrings have been checked.
    if (i == s.length())
    {
        printResult(goal_set);
        return;
    }

    // Iterate through all possible substrings from i index
    for (int j = i + 1; j <= s.length(); j++)
    {
        // If the current substring is palindrome, add it to goal_set
        string substr = s.substr(i, j - i);
        if (isPalindrome(substr))
        {
            goal_set.push_back(substr);
            separate_palindrome(j, s, goal_set);
            goal_set.pop_back();
        }
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
