#include <iostream>
using namespace std;

#define MAX_N 1000000

int A[MAX_N];
long long M[MAX_N];
int n, q;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> q;

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
    if (i == 0)
    {
      M[i] = A[i];
    }
    else
    {
      M[i] = M[i - 1] + A[i];
    }
  }

  // processing
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
      cout << M[b - 1] << endl;
    }
    else
    {
      cout << M[b - 1] - M[a - 2] << endl;
    }
  }

  return 0;
}
