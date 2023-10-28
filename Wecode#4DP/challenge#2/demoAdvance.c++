#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  // input data
  for (int &x : a)
    cin >> x;

  // b[] used for stored the current longest increment subsequence
  // so that b[k] is the lasted element of this sequence, hence k is the length of the sequence
  vector<int> b(n + 1, INT_MAX);
  b[0] = INT_MIN;
  int result = 0;
  for (int x : a)
  {
    // lower_bound() to find the position `k` where `x` should be inserted in the `b` vector to maintain a sorted order.
    // the value returned by this function will be minus to b.begin() to convert `k` to int
    int k = lower_bound(b.begin(), b.end(), x) - b.begin();
    b[k] = x;
    result = max(result, k);
  }

  cout << result;
  return 0;

  // Source: https://vietcodes.github.io/code/82/index.html#main.cpp
}