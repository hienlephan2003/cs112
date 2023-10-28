#include <iostream>
#include <string>
#include <vector>
#include <gmpxx.h>

using namespace std;

bool isValid(vector<mpz_class> valid_set, string s)
{
    valid_set.push_back(mpz_class(s));
    int n = valid_set.size();
    if (n >= 3)
    {
        // Check if the last number is equal to the sum of the two previous ones
        const mpz_class &last_num = valid_set[n - 1];
        const mpz_class &sum = valid_set[n - 2] + valid_set[n - 3];
        if (last_num != sum)
            return false;
    }
    return true;
}

bool isAccepted(const string &s)
{
    if (s.empty())
        return false;
    if (s.size() > 1 && s[0] == '0')
        return false;
    return true;
}

bool checkNum(int start, const string &s, vector<mpz_class> &goal_set)
{
    int limit = s.size();
    if (start == limit && goal_set.size() >= 3)
        return true;
    for (int i = start + 1; i <= limit; i++)
    {
        // If the current substring is validated, add it to goal_set
        string substr = s.substr(start, i - start);
        if (!isAccepted(substr))
            continue;
        if (isValid(goal_set, substr))
        {
            goal_set.push_back(mpz_class(substr));
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
    vector<mpz_class> cur;

    if (s.size() < 3)
        cout << "false";
    else
    {
        bool found = checkNum(0, s, cur);
        cout << ((found) ? "true" : "false");
    }

    return 0;
}
