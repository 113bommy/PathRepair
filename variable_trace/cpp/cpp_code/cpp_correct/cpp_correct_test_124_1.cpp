#include <bits/stdc++.h>
#pragma GCC optimize("trapv")
using namespace std;
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
const long long mod = 1e9 + 7;
const long long INF = LLONG_MAX / 4;
const long long maxn = 2007;
const double EPS = 1e-9;
long long n;
long long dp1[maxn][2 * maxn], dp2[maxn][2 * maxn];
string s, t;
const long long OFFSET = maxn;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long _;
  cin >> _;
  while (_--) {
    cin >> n >> s >> t;
    for (long long i = 1; i <= n; ++i) {
      for (long long j = -n; j <= n; ++j)
        dp1[i][OFFSET + j] = dp2[i][OFFSET + j] = 0;
    }
    dp1[0][OFFSET] = 1;
    auto inc = [&](char s1, char s2, char t1, char t2) {
      if (s1 != '?' && s1 != t1) return 0;
      if (s2 != '?' && s2 != t2) return 0;
      return 1;
    };
    for (long long i = 1; i <= n; ++i) {
      if (i & 1) swap(s[i], t[i]);
      for (long long j = -i + 1; j <= i - 1; ++j) {
        if (inc(s[i - 1], t[i - 1], '0', '0'))
          dp1[i][j + OFFSET] =
              (dp1[i][j + OFFSET] + dp1[i - 1][j + OFFSET]) % mod,
                     dp2[i][j + OFFSET] =
                         (dp2[i][j + OFFSET] + dp2[i - 1][j + OFFSET]) % mod;
        if (inc(s[i - 1], t[i - 1], '1', '1'))
          dp1[i][j + OFFSET] =
              (dp1[i][j + OFFSET] + dp1[i - 1][j + OFFSET]) % mod,
                     dp2[i][j + OFFSET] =
                         (dp2[i][j + OFFSET] + dp2[i - 1][j + OFFSET]) % mod;
        if (inc(s[i - 1], t[i - 1], '0', '1'))
          dp1[i][j + 1 + OFFSET] =
              (dp1[i][j + 1 + OFFSET] + dp1[i - 1][j + OFFSET]) % mod,
                         dp2[i][j + 1 + OFFSET] =
                             (dp2[i][j + 1 + OFFSET] + dp2[i - 1][j + OFFSET] +
                              (j >= 0 ? -1 : 1) * i * dp1[i - 1][j + OFFSET]) %
                             mod;
        if (inc(s[i - 1], t[i - 1], '1', '0'))
          dp1[i][j - 1 + OFFSET] =
              (dp1[i][j - 1 + OFFSET] + dp1[i - 1][j + OFFSET]) % mod,
                         dp2[i][j - 1 + OFFSET] =
                             (dp2[i][j - 1 + OFFSET] + dp2[i - 1][j + OFFSET] +
                              (j <= 0 ? -1 : 1) * i * dp1[i - 1][j + OFFSET]) %
                             mod;
      }
    }
    cout << (dp2[n][OFFSET] + mod) % mod << "\n";
  }
  return 0;
}
