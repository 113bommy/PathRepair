#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (m > n * (n - 1) / 2 || m < n - 1)
    cout << "NO\n";
  else if (k == 3 && m == n * (n - 1) / 2 || k > 3 && m >= n - 1 ||
           n == 1 && k > 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main(void) {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
