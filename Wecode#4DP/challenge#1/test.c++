#include <iostream>
using namespace std;

#define MAX_N 1000000

long long A[MAX_N];
long long M[MAX_N];
long long n, q;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  scanf("%lld %lld", &n, &q);

  // input
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &A[i]);
    if (i == 0)
      M[i] = A[i];
    else
      M[i] = M[i - 1] + A[i];
  }

  /*
  1 2 3
  a = 2. b = 3
  M[b-1] = M[2] = 6
  M[a-1] = M[1] = 3
  A[a - 1] = A[1] = 2
  sum = 6 - 3 + 2 = 5
  */

  // processing
  for (int i = 0; i < q; i++)
  {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long prefixSum = (a == 1) ? M[b - 1] : M[b - 1] - M[a - 2];
    printf("%lld\n", prefixSum);
  }

  return 0;
}
