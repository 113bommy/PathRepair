#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long INF = 0x3f3f3f3f;
const long long mod = 998244353;
const double esp = 1e-7;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if ((n != 1 && m == 0) || (n != 1 && k == 2) || m < n - 1 || k < 2 ||
        m > n * (n - 1) / 2) {
      cout << "NO" << '\n';
      continue;
    }
    if (k == 3) {
      if (m == n * (n - 1) / 2) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      cout << "YES" << '\n';
    }
  }
}
