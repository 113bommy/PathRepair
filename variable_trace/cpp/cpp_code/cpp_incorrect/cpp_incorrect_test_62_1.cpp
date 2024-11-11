#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int arr[N][N];
long long dp1[N][N], dp2[N][N];
void print(long long dp[][N], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << dp[i + 1][j + 1] << ' ';
    cout << endl;
  }
  cout << "Debug" << endl;
}
void solve() {
  int n, m, k, x, y;
  cin >> n >> m >> k;
  dp1[n][m] = dp2[n][m] = 0;
  long long ans = 0;
  for (int i = n; i > 0; i--) {
    for (int j = m; j > 0; j--) {
      arr[i][j] = 0;
      dp1[i][j] = j < m ? 1 + dp2[i][j + 1] : 0;
      dp2[i][j] = i < n ? 1 + dp1[i + 1][j] : 0;
      ans += 1 + dp1[i][j] + dp2[i][j];
    }
  }
  while (k--) {
    cin >> x >> y;
    arr[x][y] ^= 1;
    if (arr[x][y]) {
      ans = ans - 1 - dp1[x][y] - dp2[x][y];
      dp1[x][y] = dp2[x][y] = 0;
      if (x > 1) {
        ans -= dp2[x - 1][y];
        dp2[x - 1][y] = 0;
      }
      if (y > 1) {
        ans -= dp1[x][y - 1];
        dp1[x][y - 1] = 0;
      }
      x -= 1, y -= 1;
    } else
      ans++;
    for (int i = x, j = y, k = 1; i > 0 and j > 0 and !arr[i][j]; k = 3 - k) {
      if (k == 1) {
        ans -= dp1[i][j];
        dp1[i][j] = (j < m and !arr[i][j + 1]) ? 1 + dp2[i][j + 1] : 0;
        ans += dp1[i][j];
        i -= 1;
      } else {
        ans -= dp2[i][j];
        dp2[i][j] = (j < m and !arr[i + 1][j]) ? 1 + dp1[i + 1][j] : 0;
        ans += dp2[i][j];
        j -= 1;
      }
    }
    for (int i = x, j = y, k = 2; i > 0 and j > 0 and !arr[i][j]; k = 3 - k) {
      if (k == 1) {
        ans -= dp1[i][j];
        dp1[i][j] = (j < m and !arr[i][j + 1]) ? 1 + dp2[i][j + 1] : 0;
        ans += dp1[i][j];
        i -= 1;
      } else {
        ans -= dp2[i][j];
        dp2[i][j] = (j < m and !arr[i + 1][j]) ? 1 + dp1[i + 1][j] : 0;
        ans += dp2[i][j];
        j -= 1;
      }
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
