#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  function prints the elements of a goal_set vector
void printResult(vector<string> &goal_set)
{
    for (int i = 0; i < goal_set.size(); i++)
    {
        cout << goal_set[i];
        if (i != goal_set.size() - 1)
        {
            cout << ".";
        }
    }
    cout << endl;
}

bool isValid(string s)
{

    if (s.size() > 3)
        return false;
    if (s.size() > 1 && s[0] == '0')
        return false;

    // convert string to integer
    int value = stoi(s);
    if (value > 255 || value < 0)
        return false;

    return true;
}

// Because of each ipv4 must have 4 sections, so `start` represents the starting index of the subIP that we are currently considering when finding acceptable IPv4.
void guess(int start, string &s, vector<string> &goal_set, int remain)
{
    // Base case: `start` is equal to 4. It means that all possible substrings have been checked.
    if (start == s.size() && goal_set.size() == 4 && remain == 0)
    {
        printResult(goal_set);
        return;
    }

    for (int i = start + 1; i <= start + 3 && i <= s.size(); i++)
    {
        // If the current substring is validated, add it to goal_set
        string substr = s.substr(start, i - start);
        if (isValid(substr))
        {
            goal_set.push_back(substr);
            guess(i, s, goal_set, remain - (i - start));

            // Backtrack here
            goal_set.pop_back();
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    vector<string> cur;
    guess(0, s, cur, s.length());

    return 0;
}