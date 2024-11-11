#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, rd, cb, cd, i, ans = 0, flag1 = 1, flag2 = 1;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    while ((rb != rd) && (cb != cd)) {
      ans++;
      if (flag1)
        rb++;
      else
        rb--;
      if (rb > n) {
        rb -= 2;
        flag1 = 0;
      }
      if (rb < 1) {
        rb += 2;
        flag1 = 1;
      }
      if (flag2)
        cb++;
      else
        cb--;
      if (cb > m) {
        cb -= 2;
        flag2 = 0;
      }
      if (cb < 1) {
        cb += 2;
        flag1 = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
