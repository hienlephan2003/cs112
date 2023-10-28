#include <iostream>
#include <string>
#include <stack>
using namespace std;

// using stack to checking whether a goal_set is approved or not.
bool isApproved(string &checking_set)
{
    stack<int> tester;
    for (auto &i : checking_set)
        if (i == '(')
            tester.push(i);
        else if (tester.empty() || tester.top() != '(')
            return false;
        else
            tester.pop();
    return tester.empty();
}

// this function for printing the result
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
    // Excepting for n = 1 when i = 1 and limit = 2 * 1 - 2 = 0
    if (i > limit)
        printResult(goal_set);

    for (char &j : selection)
    {
        // adding a bracket
        goal_set[i] = j;

        // print result when goal_set is expected fully and validated once.
        if (i == limit && isApproved(goal_set))
            printResult(goal_set);

        // unless adding more brackets.
        else if (i < limit)
            solver(i + 1, limit);

        // Change to previous state
        goal_set[i] = '\0';
    }
}

int main()
{
    // input n
    int n;
    cin >> n;
    goal_set.resize(2 * n);

    // The first and last positions of the goal_set are assigned by the opening and closing brackets.
    goal_set[0] = '(';
    goal_set[2 * n - 1] = ')';

    // solve problem using backtracking
    solver(1, 2 * n - 2);
    return 0;
}