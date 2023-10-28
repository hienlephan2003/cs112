#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isApproved(string &checking_set)
{
    stack<int> tester;
    for (auto &i : checking_set)
        if (i == '(')
            tester.push(i);
        else
            tester.pop();
    return tester.empty();
}
void printResult(string vec)
{
    for (auto &i : vec)
        cout << i;
    cout << endl;
}
// this vector is used to store brackets: 0 = '(' and 1 = ')'
string goal_set;
string selection = "()";
void solver(int i, int limit)
{

    for (char &j : selection)
    {
        // adding a bracket
        goal_set[i] = j;
        if (i < limit)
        {
            solver(i + 1, limit);
        }
        else
        {
            if (isApproved(goal_set))
                printResult(goal_set);
        }
        goal_set[i] = '\0';
    }
}

int main()
{
    // input n
    int n;
    cin >> n;
    goal_set.resize(2 * n);

    // solve problem using backtracking
    goal_set[0] = '(';
    goal_set[2 * n - 1] = ')';
    solver(1, 2 * n - 2);
    return 0;
}