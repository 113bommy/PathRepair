#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, q, ans, f[N][N][2], g[N][N];
bool st[N][N];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j][0] = (j == 1) ? 0 : (f[i][j - 1][1] + 1);
      f[i][j][1] = (i == 1) ? 0 : (f[i - 1][j][0] + 1);
      g[i][j] = f[i][j][0] + f[i][j][1] + 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ans += g[i][j];
    }
  }
  for (int i = 0; i <= n; ++i) {
    st[i][0] = st[i][m + 1] = 1;
  }
  for (int i = 0; i <= m; ++i) {
    st[0][i] = st[n + 1][i] = 1;
  }
  while (q--) {
    int x, y, sign;
    scanf("%d %d", &x, &y);
    sign = st[x][y] ? 1 : -1;
    int A = min(x - 1, y - 1);
    int B = min(n - x, m - x);
    int p = 0, q = 0, s = 0, t = 0;
    for (int i = 1; i <= A + 1; ++i) {
      if (st[x - i][y - i + 1]) break;
      ++p;
      if (st[x - i][y - i]) break;
      ++p;
    }
    for (int i = 1; i <= A + 1; ++i) {
      if (st[x - i + 1][y - i]) break;
      ++q;
      if (st[x - i][y - i]) break;
      ++q;
    }
    for (int i = 1; i <= B + 1; ++i) {
      if (st[x + i - 1][y + i]) break;
      ++s;
      if (st[x + i][y + i]) break;
      ++s;
    }
    for (int i = 1; i <= B + 1; ++i) {
      if (st[x + i][y + i - 1]) break;
      ++t;
      if (st[x + i][y + i]) break;
      ++t;
    }
    ans += (p * s + q * t + s + p + q + t + 1) * sign;
    st[x][y] ^= 1;
    printf("%d\n", ans);
  }
  return 0;
}
