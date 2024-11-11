#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], f[1005][1005], ans;
inline bool in(int x, int l, int r) { return l <= x && x <= r; }
int calc(int x, int y, int dx, int dy, int t) {
  if (t == 0) dx = -dx, dy = -dy;
  int cnt = 0;
  while (in(x + dx, 1, n) && in(y + dy, 1, m)) {
    x += dx, y += dy;
    if (!a[x][y]) break;
    ++cnt;
    if (dx != 0)
      dy = dx, dx = 0;
    else
      dx = dy, dy = 0;
  }
  return cnt;
}
signed main() {
  int q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ans += 1 + calc(i, j, 0, 1, 1) + calc(i, j, 1, 0, 1);
  while (q--) {
    int i, j;
    cin >> i >> j;
    int sum = (1 + calc(i, j, 0, 1, 1)) * (1 + calc(i, j, 1, 0, 0)) +
              (1 + calc(i, j, 1, 0, 1)) * (1 + calc(i, j, 0, 1, 0)) - 1;
    if (a[i][j])
      ans -= sum;
    else
      ans += sum;
    a[i][j] ^= 1;
    cout << ans << "\n";
  }
}
