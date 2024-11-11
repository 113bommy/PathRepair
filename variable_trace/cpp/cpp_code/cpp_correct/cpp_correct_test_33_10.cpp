#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> dp((1 << 10), INT32_MAX);
  dp[0] = 0;
  for (long long i = 0; i < n; i++) {
    dp[a[i]] = min(dp[a[i]], a[i]);
    for (long long j = 0; j < dp.size(); j++) {
      if (dp[j] < a[i]) {
        long long x = (j ^ a[i]);
        dp[x] = min(dp[x], a[i]);
      }
    }
  }
  vector<long long> ans;
  for (long long i = 0; i < dp.size(); i++) {
    if (dp[i] != INT32_MAX) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << " ";
  }
}
