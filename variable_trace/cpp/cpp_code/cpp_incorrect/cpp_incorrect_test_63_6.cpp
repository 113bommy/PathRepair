#include <bits/stdc++.h>
using namespace std;
const int mx = 4e5 + 10;
int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (string& x : a) cin >> x;
  vector<int> bal(n), mn(n);
  vector<vector<int>> occ(n), nocc(n);
  for (int i = 0; i < n; i++) {
    int b = 0, mn0 = 1e9;
    occ[i].resize(mx * 2);
    nocc[i].resize(mx * 2);
    int mini = 1e9;
    for (char x : a[i]) {
      if (x == ')')
        b--;
      else
        b++;
      mini = min(b, mini);
      mn0 = min(mn0, b);
      occ[i][b + mx]++;
      if (b == mini) nocc[i][b + mx]++;
    }
    bal[i] = b, mn[i] = mn0;
  }
  vector<vector<int>> answer((1 << n), vector<int>(2, -1e9));
  answer[0] = {0, 0};
  vector<int> sum(1 << n);
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if ((1 << i) & mask) {
        sum[mask] = sum[mask ^ (1 << i)] + bal[i];
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if ((1 << i) & mask) {
        int nmask = (1 << i) ^ mask;
        if (sum[nmask] + mn[i] < 0) {
          answer[nmask][1] =
              max(answer[nmask][0] + nocc[i][mx - sum[nmask]], answer[mask][1]);
        } else {
          answer[mask][0] =
              max(answer[mask][0], answer[nmask][0] + occ[i][mx - sum[nmask]]);
        }
      }
    }
  }
  int ans = 0;
  for (auto x : answer) ans = max({x[0], x[1], ans});
  cout << ans;
  return 0;
}
