#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  while (T--) {
    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    long long low = 1, high = 1e18;
    while (low <= high) {
      long long mid = (low + high) / 2;
      long long t = h;
      for (long long i = 1; i < n; ++i) {
        t -= min(a[i] - a[i - 1], mid);
      }
      t -= mid;
      if (t > 0)
        low = mid + 1;
      else
        high = mid - 1;
    }
    cout << high + 1 << '\n';
  }
}
