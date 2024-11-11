#include <bits/stdc++.h>
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n, ans = 0, final;
    cin >> x >> n;
    final = n % 4;
    if (final == 0) {
      cout << 0 << endl;
    } else if (x % 2 == 0) {
      if (final == 1) {
        ans = x - (n);
      } else if (final == 2) {
        ans = x + 1;
      } else if (final == 3) {
        ans = x + 1 + n;
      }
      cout << ans << endl;
    } else {
      if (final == 1) {
        ans = x + (n);
      } else if (final == 2) {
        ans = x - 1;
      } else if (final == 3) {
        ans = x - 1 - n;
      }
      cout << ans << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
