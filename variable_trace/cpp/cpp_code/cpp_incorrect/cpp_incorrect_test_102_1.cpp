#include <bits/stdc++.h>
using namespace std;
string ar;
int main(void) {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, cur = 0, l = 0, r = 0, u = 0, d = 0;
    cin >> n >> m;
    cin >> ar;
    for (int i = 0; i < ar.size(); i++) {
      if (ar[i] == 'L') cur--;
      if (ar[i] == 'R') cur++;
      if (cur < 0) {
        l = max(l, abs(cur));
      }
      if (cur > 0) {
        r = max(r, abs(cur));
      }
      if (l + r >= m) {
        if (ar[i] == 'L') l--;
        if (ar[i] == 'R') r--;
        break;
      }
    }
    cur = 0;
    for (int i = 0; i < ar.size(); i++) {
      if (ar[i] == 'U') cur--;
      if (ar[i] == 'D') cur++;
      if (cur < 0) {
        u = max(u, abs(cur));
      }
      if (cur > 0) {
        d = max(d, abs(cur));
      }
      if (u + d >= n) {
        if (ar[i] == 'L') u--;
        if (ar[i] == 'R') d--;
        break;
      }
    }
    cout << 1 + u << " " << 1 + l << endl;
  }
  return 0;
}
