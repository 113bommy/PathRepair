#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long l = 0, r = 0;
  for (l = 0; l < n - 1; l++)
    if (arr[l] > arr[l + 1]) break;
  for (r = 0; r < n - 1; r++)
    if (arr[n - 1 - r] > arr[n - 2 - r]) break;
  if (l % 2 == 0 || r % 2 == 0)
    cout << "Alice\n";
  else
    cout << "Bob\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  for (long long i = 0; i < tc; i++) solve();
}
