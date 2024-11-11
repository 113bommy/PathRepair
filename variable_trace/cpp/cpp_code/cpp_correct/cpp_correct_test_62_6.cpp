#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005][2];
bool ban[1005][1005];
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = dp[i - 1][j][1] + 1;
      dp[i][j][1] = dp[i][j - 1][0] + 1;
      ans += (dp[i][j][0] + dp[i][j][1]);
    }
  }
  int open = n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (!ban[x][y]) {
      long long a = dp[x][y][0];
      long long b = dp[x][y][1];
      dp[x][y][0] = 0;
      dp[x][y][1] = 0;
      open--;
      ans -= (a + b);
      bool last = 1;
      int tmp = x, tmp2 = y;
      while (x <= n && y <= m && !ban[x][y]) {
        if (!last) {
          x++;
        } else
          y++;
        if (x <= n && y <= m && !ban[x][y]) {
          dp[x][y][last] -= a;
          ans -= a;
        }
        last = !last;
      }
      x = tmp, y = tmp2;
      last = 0;
      while (x <= n && y <= m && !ban[x][y]) {
        if (!last) {
          x++;
        } else
          y++;
        if (x <= n && y <= m && !ban[x][y]) {
          dp[x][y][last] -= b;
          ans -= b;
        }
        last = !last;
      }
      ban[tmp][tmp2] = 1;
    } else {
      long long a = dp[x - 1][y][1] + 1;
      long long b = dp[x][y - 1][0] + 1;
      dp[x][y][0] = a;
      dp[x][y][1] = b;
      open++;
      ans += (a + b);
      bool last = 1;
      int tmp = x, tmp2 = y;
      ban[x][y] = 0;
      while (x <= n && y <= m && !ban[x][y]) {
        if (!last) {
          x++;
        } else
          y++;
        if (x <= n && y <= m && !ban[x][y]) {
          dp[x][y][last] += a;
          ans += a;
        }
        last = !last;
      }
      x = tmp, y = tmp2;
      last = 0;
      while (x <= n && y <= m && !ban[x][y]) {
        if (!last) {
          x++;
        } else
          y++;
        if (x <= n && y <= m && !ban[x][y]) {
          dp[x][y][last] += b;
          ans += b;
        }
        last = !last;
      }
    }
    cout << ans - open << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
