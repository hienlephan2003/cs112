#include <iostream>
#include <vector>
using namespace std;

void generate(int n, int open, int close, char *v, int i)
{
    if (i == 2 * n)
    {
        cout << v << endl;
        return;
    }
    if (open < n)
    {
        v[i] = '(';
        generate(n, open + 1, close, v, i + 1);
    }
    if (close < open)
    {
        v[i] = ')';
        generate(n, open, close + 1, v, i + 1);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    char v[2 * n + 1];
    v[2 * n] = '\0';
    for (int i = 0; i < n; i++)
    {
        v[i] = '(';
        v[2 * n - i - 1] = ')';
    }
    generate(n, 0, 0, v, n);
    return 0;
}
