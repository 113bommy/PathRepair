#include <bits/stdc++.h>
using namespace std;
vector<int> idxs[8192];
int dp[8192];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, 0x7f, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    idxs[x].emplace_back(i);
  }
  dp[0] = -1;
  for (int i = 0; i < 8192; i++) {
    for (int j = 0; j < 8192; j++) {
      auto it = upper_bound(idxs[i].begin(), idxs[i].end(), dp[j]);
      if (it == idxs[i].end()) continue;
      dp[j ^ i] = min(dp[j ^ i], *it);
    }
  }
  int ans = 0;
  for (int i = 0; i < 8192; i++) {
    if (dp[i] != 0x7f7f7f7f) ++ans;
  }
  cout << ans << "\n";
  for (int i = 0; i < 8192; i++) {
    if (dp[i] != 0x7f7f7f7f) cout << i << " ";
  }
  cout << "\n";
}
