#include <bits/stdc++.h>
using namespace std;
const long long N = 555, mod = 998244353;
long long k, T, t, n, m, ans, cnt;
long long f[N][N], dp[N][N];
bool vis[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res % mod;
}
void init() {
  f[0][0] = 1;
  for (long long i = 1; i < N; i++) {
    f[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  init();
  cin >> n >> m;
  for (long long i = 2; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      if (i - 1 >= j)
        dp[i][j] = ksm(j, i);
      else {
        for (long long k = 2; k <= i; k++)
          (dp[i][j] += dp[k][j - i + 1] * ksm(i - 1, i - k) % mod * f[i][k]) %=
              mod;
        dp[i][j] = dp[i][j] + ksm(i - 1, i) % mod;
      }
    }
  cout << dp[n][m] << '\n';
  return 0;
}
