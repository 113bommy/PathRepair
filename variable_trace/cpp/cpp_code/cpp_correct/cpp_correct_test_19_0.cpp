#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
using namespace std;
const int INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  const int mx = *max_element(a.begin(), a.end()) << 1;
  vector<int> dp(mx + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> new_dp(mx + 1, INF);
    for (int j = 0; j <= mx; ++j) {
      if (dp[j] == INF) continue;
      new_dp[max(0, j - a[i])] = min(new_dp[max(0, j - a[i])], dp[j] + a[i]);
      if (j + a[i] <= mx)
        new_dp[j + a[i]] = min(new_dp[j + a[i]], max(dp[j] - a[i], 0));
    }
    dp = new_dp;
  }
  int ans = INF;
  for (int i = 0; i <= mx; ++i) ans = min(ans, i + dp[i]);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
