#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n, m;
int jobs[MAXN];
int machine[MAXN];
int temp[MAXN];
int assignment[MAXN];

int select_optimal_machine()
{
    int x = 0;
    for (int i = 0; i < m; i++)
    {
        if (machine[i] < machine[x])
            x = i;
    }
    return x;
}

void assign()
{
    // iterative each job.
    for (int i = n - 1; i >= 0; i--)
    {
        int x = select_optimal_machine();
        machine[x] += temp[i];
        assignment[i] = x;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i];
        temp[i] = jobs[i];
        machine[i] = 0;
    }

    sort(temp, temp + n);
    assign();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (jobs[i] == temp[j])
            {
                cout << assignment[j] << " ";
                break;
            }
        }
    }
    return 0;
}
