#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i];
    }

    // sắp xếp danh sách công việc theo thứ tự tăng dần thời gian hoàn thành
    sort(tasks.begin(), tasks.end());

    vector<int> machines(m, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        // tìm máy trống sớm nhất để phân công công việc
        int machine_idx = 0;
        for (int j = 1; j < m; j++)
        {
            if (machines[j] < machines[machine_idx])
                machine_idx = j;
        }
        // phân công công việc vào máy đó
        machines[machine_idx] += tasks[i];
    }

    // in ra kết quả
    for (int i = 0; i < n; i++)
    {
        int machine_idx = 0;
        for (int j = 1; j < m; j++)
        {
            if (machines[j] < machines[machine_idx])
                machine_idx = j;
        }
        cout << machine_idx << " ";
        machines[machine_idx] += tasks[i];
    }
    cout << endl;

    return 0;
}
