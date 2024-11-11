#include <bits/stdc++.h>
using namespace std;
void go() {
  long long n, m, xr, yr, xd, yd;
  cin >> n >> m >> xr >> yr >> xd >> yd;
  long long dirx = 1, diry = 1;
  long long ans = 0;
  while (true) {
    if (xr == xd || yr == yd) {
      break;
    }
    xr += dirx;
    yr += diry;
    if (xr > xd) {
      dirx = -1;
      xr = n - 1;
    }
    if (yr > m) {
      diry = -1;
      yr = m - 1;
    }
    if (xr < 1) {
      xr = 2;
      dirx = 1;
    }
    if (yr < 1) {
      yr = 2;
      diry = 1;
    }
    ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
