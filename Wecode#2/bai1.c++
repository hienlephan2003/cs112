#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// declaring the coef array to store the coefficient of each column
vector<int> coef;
vector<double> goal_set;

// score_set is that all score which can be used to be filled in each column of mark table.
double score_set[41] = {0.25, 0.5, 0.75,
                        1, 1.25, 1.5, 1.75,
                        2, 2.25, 2.5, 2.75,
                        3, 3.25, 3.5, 3.75,
                        4, 4.25, 4.5, 4.75,
                        5, 5.25, 5.5, 5.75,
                        6, 6.25, 6.5, 6.75,
                        7, 7.25, 7.5, 7.75,
                        8, 8.25, 8.5, 8.75,
                        9, 9.25, 9.5, 9.75,
                        10};

// this function for printing out result
void printVector(const vector<double> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

double calculateResult(const vector<int> coef, const vector<double> goal_set)
{
    double result = 0.0;
    for (size_t i = 0; i < goal_set.size(); i++)
        result += coef[i] * goal_set[i];

    // dividing result to 100 cause the input of coef was integers.
    result /= 100;
    // this step to rounds the result to the nearest multiple of 0.1.
    result = round(result * 10) / 10.0;
    return result;
}

void solver(int i, double mark)
{
    // because the score_set was sorted ascending so whenever a score of a column calculated has been more than the mark, all scores after this score were not certainly acceptable, thus we can return if this event has happened

    double rest = mark - calculateResult(coef, goal_set);
    if (rest < 0)
        return;

    // loop for each score in score_set that can be approved
    for (int j = 0; j < 40; j++)
    {

        // adding a score to goal_set
        goal_set[i] = score_set[j];

        // check if that goal_set is expected fully
        if (i == goal_set.size() - 1)
        {
            // calculate the result is the expected goal or not
            double result = calculateResult(coef, goal_set);

            // check result is equal to goal mark
            if (result == mark)
                printVector(goal_set);
        }
        // unless continue to adding more scores.
        else
            solver(i + 1, mark);

        // Change to previous state
        goal_set[i] = 0;
    }
}

int main()
{
    // declaring the number of score columns
    int n;
    cin >> n;

    coef.resize(n);
    goal_set.resize(n);
    // setting the coefficient for each column
    for (int i = 0; i < n; i++)
    {
        cin >> coef[i];
    }

    // input the mark of project.
    double mark;
    cin >> mark;

    // Solve the problem using backtracking
    solver(0, mark);

    return 0;
}