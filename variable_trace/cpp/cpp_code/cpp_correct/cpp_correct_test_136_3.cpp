#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 2e3 + 100;
const long long MOD = 1e9 + 7;
const long long inf = 2e9;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    long long k = n * (n + 1) / 2;
    if (sum % k) {
      cout << "NO" << '\n';
      continue;
    }
    long long s = sum / k;
    vector<long long> v(n);
    bool ok = 1;
    for (long long i = 0; i < n && ok; ++i) {
      long long j = i - 1;
      if (j < 0) j = n - 1;
      long long x = a[i] - a[j] - s;
      x = -x;
      if (x % n || x / n <= 0)
        ok = 0;
      else
        v[i] = x / n;
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES\n";
    for (auto to : v) cout << to << ' ';
    cout << '\n';
  }
  return 0;
}
