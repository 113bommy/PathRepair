#include <bits/stdc++.h>
int n, m, ans = 0x3f3f3f3f;
char a[402][402];
int pre[402][402];
inline int min(int x, int y) { return x < y ? x : y; }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ans = 0x3f3f3f3f;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] -= '0';
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) pre[j][i] = pre[j][i - 1] + a[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = i + 5 - 1; j <= n; j++) {
        int temp = 0x3f3f3f3f;
        for (int k = 4; k <= m; k++)
          temp = min(temp + (1 - a[i][k - 1]) + (1 - a[j][k - 1]) +
                         (pre[k - 1][j - 1] - pre[k - 1][i + 1 - 1]),
                     ((j - 1) - (i + 1) + 1 -
                      (pre[k - 3][j - 1] - pre[k - 3][i + 1 - 1])) +
                         (pre[k - 2][j - 1] - pre[k - 2][i + 1 - 1]) +
                         (pre[k - 1][j - 1] - pre[k - 1][i + 1 - 1]) +
                         (1 - a[i][k - 2]) + (1 - a[i][k - 1]) +
                         (1 - a[j][k - 2]) + (1 - a[j][k - 1])),
          ans = min(ans, temp + ((j - 1) - (i + 1) + 1 -
                                 (pre[j][j - 1] - pre[j][i + 1 - 1])));
      }
    printf("%d\n", ans);
  }
  return 0;
}
