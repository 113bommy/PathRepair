#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
inline int qp(long long a, long long b) {
  long long ans = 1;
  for (; b;) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (; t--;) {
    int n, m, bx, by, dx, dy;
    long long p;
    cin >> n >> m >> bx >> by >> dx >> dy >> p;
    int cx = -1, cy = -1;
    long long u = 0, d = 1;
    p = (1 - p * qp(100, mod - 2) % mod + mod) % mod;
    for (int i = 0; i != 4 * (n - 1) * (m - 1); ++i) {
      if (bx + cx == 0 || bx + cx > n) cx = -cx;
      if (by + cy == 0 || by + cy > m) cy = -cy;
      bx += cx;
      by += cy;
      u = (u + 1) % mod;
      if (bx == dx || by == dy) {
        u = u * p % mod;
        d = d * p % mod;
      }
    }
    d = (1 - d + mod) % mod;
    cout << u * qp(d, mod - 2) % mod << '\n';
  }
}
