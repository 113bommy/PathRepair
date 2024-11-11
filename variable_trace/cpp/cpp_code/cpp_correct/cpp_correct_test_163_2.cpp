#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ksm(long long a, long long b, long long mod) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return c;
}
long long inv(int x) { return ksm(x, mod - 2, mod); }
int t, n, m, len, p, sx, sy, tx, ty, dx, dy;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> sx >> sy >> tx >> ty >> p;
    long long ans = 0, p1 = (1 - p * inv(100) % mod + mod) % mod,
              p2 = p * inv(100), P;
    dx = dy = 1;
    len = 0;
    if (sx == tx || sy == ty)
      P = p1;
    else
      P = 1;
    int tot = 0;
    for (int i = 1; i <= 4 * (n - 1) * (m - 1); i++) {
      if (sx + dx > n || sx + dx < 1) dx = -dx;
      if (sy + dy > m || sy + dy < 1) dy = -dy;
      sx += dx, sy += dy, len = (len + 1) % mod;
      if (sx == tx || sy == ty) {
        tot++;
        ans = (ans + P * len % mod) % mod;
        P = p1 * P % mod;
        len = 0;
      }
    }
    if (sx == tx || sy == ty)
      P = P * inv(p1) % mod;
    else
      ans = (ans + len * P % mod) % mod;
    cout << (ans * inv((1 - P + mod) % mod)) % mod << endl;
  }
}
