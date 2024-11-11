#include <bits/stdc++.h>
using namespace std;
char p[1000005], q[1000005];
long long nxt[1000][2] = {0};
long long dp[2][505][505];
string x;
int main() {
  long long t, n, m, i, j, k, l;
  cin >> n >> m;
  scanf("%s", p + 1);
  scanf("%s", q + 1);
  q[m + 1] = '2';
  nxt[0][q[1] - '0'] = 1;
  for (i = 1; i <= m; i++) {
    for (l = 0; l <= 1; l++) {
      for (j = 1; j <= i + 1; j++) {
        string z = "", y = "";
        for (k = j; k <= i; k++) z += q[k];
        z += l + '0';
        for (k = 1; k <= i - j + 2; k++) y += q[k];
        if (y == z) nxt[i][l] = max(nxt[i][l], i - j + 2);
      }
    }
  }
  for (i = 0; i <= 1; i++)
    for (j = 0; j <= 502; j++)
      for (k = 0; k <= 502; k++) dp[i][j][k] = 1e17;
  dp[0][0][0] = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j <= n; j++) {
      for (k = 0; k <= m; k++) {
        dp[!(i % 2)][j][k] = 1e17;
      }
    }
    for (j = 0; j <= n; j++) {
      for (k = 0; k <= m; k++) {
        if (dp[i % 2][j][k] != 1e17) {
          dp[!(i % 2)][j + (k == m)][nxt[k][0]] =
              min(dp[!(i % 2)][j + (k == m)][nxt[k][0]],
                  dp[i % 2][j][k] + (p[i + 1] == '0' ? 0 : 1));
          dp[!(i % 2)][j + (k == m)][nxt[k][1]] =
              min(dp[!(i % 2)][j + (k == m)][nxt[k][1]],
                  dp[i % 2][j][k] + (p[i + 1] == '1' ? 0 : 1));
        }
      }
    }
    for (j = 0; j <= n; j++) {
      for (k = 0; k <= m; k++) {
      }
    }
  }
  long long ans;
  for (i = 0; i <= n - m + 1; i++) {
    ans = 1e17;
    for (j = 0; j < m; j++) {
      ans = min(ans, dp[n % 2][i][j]);
    }
    if (i != 0) ans = min(ans, dp[n % 2][i - 1][m]);
    if (ans == 1e17) ans = -1;
    printf("%lld ", ans);
  }
  return 0;
}
