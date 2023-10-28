#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n, m;
int jobs[MAXN][MAXN];
int machine[MAXN];
int assignment[MAXN];

int select_optimal_machine(int k)
{
    int x = 0;
    for (int i = 0; i < m; i++)
    {
        if (jobs[i][k] != -1)
        {
            x = i;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (jobs[i][k] == -1)
        {
            continue;
        }

        if (machine[i] + jobs[i][k] < machine[x] + jobs[x][k])
            x = i;
    }
    return x;
}

void assign()
{
    // iterative each job.
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int x = select_optimal_machine(k);
        machine[x] += jobs[x][k];
        assignment[i] = x;
        k++;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> jobs[i][j];
            machine[j] = 0;
        }
    }
    assign();

    for (int i = 0; i < n; i++)
    {
        cout << assignment[i] << " ";
    }
    return 0;
}
