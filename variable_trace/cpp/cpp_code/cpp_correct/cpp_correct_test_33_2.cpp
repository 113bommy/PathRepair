#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
bool dp[MAXN][601];
int n, a[MAXN], minv[601];
void solve() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  for (int i = (0); i <= (511); ++i) {
    minv[i] = 0x7f7f7f7f;
  }
  dp[0][0] = 1;
  minv[0] = -1;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (0); j <= (511); ++j)
      if ((a[i] ^ j) <= 511) {
        dp[i][j] |= (dp[i - 1][j]);
        dp[i][j] |= (minv[a[i] ^ j] < a[i]);
        if ((minv[a[i] ^ j] < a[i])) minv[j] = min(minv[j], a[i]);
      }
    dp[i][a[i]] = 1;
    minv[a[i]] = min(minv[a[i]], a[i]);
  }
  int cnt = 0;
  for (int i = (0); i <= (511); ++i) cnt += (dp[n][i]);
  cout << cnt << '\n';
  for (int i = (0); i <= (511); ++i)
    if (dp[n][i]) {
      cout << i << ' ';
    }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  _ = 1;
  while (_--) {
    solve();
  }
  return 0;
}
