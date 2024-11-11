#include <bits/stdc++.h>
using namespace std;
const int N = 405;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int T, n, m, ans;
char s[N][N];
int sum[N][N];
int qu[N], va[N], he, ta;
int main() {
  T = read();
  while (T--) {
    ans = 16;
    n = read(), m = read();
    for (register int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (register int j = 1; j <= m; j++)
      for (register int i = 1; i <= n; i++)
        sum[i][j] = sum[i - 1][j] + (s[i][j] == '1');
    for (register int i = 1; i <= n; i++) {
      for (register int k = i + 4; k <= n; k++) {
        ta = -1, he = 0;
        int cur = 0;
        for (register int j = 1; j <= m; j++) {
          while (he < ta && j - qu[he + 1] >= 3) he++;
          int tmp = (k - i - 1) - (sum[k - 1][j] - sum[i][j]);
          if (he <= ta && j - qu[he] >= 3)
            ans = min(ans, cur - va[qu[he]] + tmp);
          cur +=
              (sum[k - 1][j] - sum[i][j]) + (s[i][j] == '0') + (s[k][j] == '0');
          qu[++ta] = j, va[j] = cur - tmp;
          if (he < ta && qu[ta] <= qu[ta - 1]) ta--;
        }
      }
    }
    printf("%d\n", ans);
  }
}
