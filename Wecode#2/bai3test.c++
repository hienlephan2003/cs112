#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void partitionHelper(string s, int start, vector<string> &currPartition, vector<vector<string>> &result)
{
    // Base case: reach the end of string
    if (start == s.length())
    {
        // Add current partition to result if all substrings are palindrome
        bool isAllPalindrome = true;
        for (string subStr : currPartition)
        {
            if (!isPalindrome(subStr))
            {
                isAllPalindrome = false;
                break;
            }
        }
        if (isAllPalindrome)
        {
            result.push_back(currPartition);
        }
        return;
    }

    // Iterate through all possible substrings from start index
    for (int i = start + 1; i <= s.length(); i++)
    {
        string subStr = s.substr(start, i - start);
        // If current substring is palindrome, add it to partition and continue partitioning recursively
        if (isPalindrome(subStr))
        {
            currPartition.push_back(subStr);
            partitionHelper(s, i, currPartition, result);
            currPartition.pop_back(); // Backtrack
        }
    }
}

vector<vector<string>> findAllPalindromicPartitions(string s)
{
    vector<vector<string>> result;
    vector<string> currPartition;
    partitionHelper(s, 0, currPartition, result);
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    vector<vector<string>> result = findAllPalindromicPartitions(s);
    for (vector<string> partition : result)
    {
        for (string subStr : partition)
        {
            cout << subStr << " ";
        }
        cout << endl;
    }
    return 0;
}
