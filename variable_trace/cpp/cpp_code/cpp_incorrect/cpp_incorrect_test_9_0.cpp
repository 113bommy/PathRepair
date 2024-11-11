#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[1000 + 5][1000 + 5];
signed main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
  while (k--) {
    long long ci;
    scanf("%lld", &ci);
    long long nx = 1, ny = ci;
    while (nx != n) {
      long long x = nx, y = ny;
      if (a[x][y] == 1)
        nx = x, ny = y + 1;
      else if (a[x][y] == 2)
        nx = x + 1, ny = y;
      else if (a[x][y] == 3)
        nx = x, ny = y - 1;
      a[x][y] = 2;
    }
    a[nx][ny] = 2;
    printf("%lld ", ny);
  }
  return 0;
}
