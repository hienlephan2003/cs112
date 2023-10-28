#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n, m;
int jobs[MAXN];
int machine[MAXN] = {0};
int temp[MAXN];
int assignment[MAXN] = {-1};
int ans[MAXN] = {0};
int min_time = 100000;
int k = 0;
int findMax()
{
    int max = machine[0];
    for (int i = 1; i < m; i++)
    {
        if (machine[i] > max)
            max = machine[i];
    }
    return max;
}
void assign(int i)
{
    // iterative each job.
    for (int j = 0; j < m; j++)
    {
        assignment[k] = j;
        k++;
        machine[j] += jobs[i];
        if (i < n)
            assign(i + 1);
        else
        {
            int job_time = findMax();
            if (job_time < min_time)
            {
                min_time = job_time;
                for (int i = 0; i < n; i++)
                {
                    ans[i] = assignment[i];
                }
            }
        }
        machine[j] -= jobs[i];
        assignment[i] = -1;
        k--;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i];
    }

    assign(0);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
