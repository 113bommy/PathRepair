#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long infinity = 1000000000000000000;
const int inf = 1e9 + 5;
const int maxn = 2005;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  vector<int> dp1(maxn, 0), dp2(maxn, 0);
  int l = a[0], r = maxn - 1;
  int opt = r + 1;
  while (l <= r) {
    int mid = ((r - l) >> 1) + l;
    dp1.assign(mid + 1, 0);
    for (int i = a[0]; i < mid + 1; i++) {
      dp1[i] = 1;
      dp2[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < mid + 1; j++) {
        if (dp1[j]) {
          if (j - a[i] >= 0) {
            dp2[j - a[i]] = 1;
          }
          if (j + a[i] <= mid) {
            dp2[j + a[i]] = 1;
          }
        }
      }
      swap(dp1, dp2);
      dp2.assign(mid + 1, 0);
    }
    int yes = 0;
    for (int i = 0; i < mid + 1; i++) {
      if (dp1[i]) {
        yes = 1;
        break;
      }
    }
    if (yes) {
      opt = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << opt << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC = 1;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    solve();
  }
  return 0;
}
