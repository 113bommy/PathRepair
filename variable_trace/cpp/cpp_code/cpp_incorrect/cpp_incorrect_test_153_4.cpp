#include <bits/stdc++.h>
using namespace std;
long long dp[1 << 23];
string a[1005];
int cnt[26][26];
long long n;
const long long MOD = 998244353;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (auto c : a[i]) cnt[i][c - 'a']++;
  }
  for (int i = 1; i < (1 << n); i++) {
    dp[i] = 1;
    for (int z = 0; z < 26; z++) {
      int x = 1e9;
      for (int k = 0; k < n; k++)
        if (i & (1 << k)) {
          x = min(x, cnt[k][z] + 1);
        }
      dp[i] = (dp[i] * x) % MOD;
    }
    if (__builtin_popcount(i) % 2 == 0) dp[i] = MOD - dp[i];
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < (1 << n); i++) {
      if ((i & (1 << k))) {
        dp[i] += dp[i ^ (1 << i)];
        if (dp[i] >= MOD) dp[i] -= MOD;
      }
    }
  long long ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    long long v = 0;
    long long bit = 0;
    for (int k = 0; k < n; k++)
      if (i & (1 << k)) v += k + 1, bit++;
    ;
    v *= bit;
    ans ^= v * dp[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
