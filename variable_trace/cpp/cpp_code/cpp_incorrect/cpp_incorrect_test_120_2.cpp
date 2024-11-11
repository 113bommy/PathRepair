#include <bits/stdc++.h>
using namespace std;
long long solver() {
  int l, r;
  cin >> l >> r;
  if (l == r) {
    return 0;
  }
  int ans = INT_MAX;
  for (int i = 1; i <= 18; ++i) {
    int m = 0;
    for (int j = 18; j > i; --j) {
      if ((l & (1 << j)) > 0) {
        m = m | (1 << j);
      }
    }
    int t = 1 << (i + 1);
    int tp = 1 << i;
    int d = r - m + 1;
    int c = (d / t) * tp + min(d % t, tp);
    int d2 = l - m;
    int c2 = (d2 / t) * tp + min(d2 % t, tp);
    ans = min(ans, c - c2);
  }
  return ans;
}
int main() {
  int q = 1;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cout << solver();
    cout << '\n';
  }
}
