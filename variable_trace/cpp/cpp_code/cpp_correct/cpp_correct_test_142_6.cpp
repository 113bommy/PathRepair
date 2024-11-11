#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> m >> n;
    vector<vector<long long>> p(m, vector<long long>(n));
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> p[i][j];
      }
    }
    long long ans = 1e9 + 1;
    for (long long i = 0; i < n; i++) {
      long long mx = 0;
      for (long long j = 0; j < m; j++) {
        mx = max(mx, p[j][i]);
      }
      ans = min(ans, mx);
    }
    vector<vector<long long>> mg(m, vector<long long>(n));
    long long viv = 0;
    for (long long i = 0; i < m; i++) {
      sort(p[i].rbegin(), p[i].rend());
      viv = max(viv, min(ans, p[i][1]));
    }
    cout << viv << "\n";
  }
}
