#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000000

vector<long long> A(MAX_N);

int n;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  scanf("%d", &n);
  vector<int> M(n, 1);

  // input
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &A[i]);
  }

  // processing
  int res = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (A[i] > A[j])
      {
        M[i] = max(M[j] + 1, M[i]);
      }
      res = max(res, M[i]);
    }
  }
  return 0;
}