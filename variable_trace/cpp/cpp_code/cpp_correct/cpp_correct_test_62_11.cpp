#include <bits/stdc++.h>
using namespace std;
ifstream in("in.in");
ofstream out("out.out");
const int nmax = 1005;
int n, m, q, sol;
int dp[2][nmax][nmax];
vector<vector<int>> a;
void calc(int i, int j) {
  dp[0][i][j] = dp[1][i][j] = 0;
  if (a[i][j] == 0) return;
  if (j < m - 1 && a[i][j + 1]) {
    dp[0][i][j] += dp[1][i][j + 1] + 1;
  }
  if (i < n - 1 && a[i + 1][j]) {
    dp[1][i][j] += dp[0][i + 1][j] + 1;
  }
}
void traverse(int i, int j, int dir) {
  if (i < 0 || j < 0) return;
  int oldDp = dp[0][i][j] + dp[1][i][j];
  calc(i, j);
  int newDp = dp[0][i][j] + dp[1][i][j];
  sol += newDp - oldDp;
  if (dir == 0) {
    traverse(i, j - 1, 1);
  } else {
    traverse(i - 1, j, 0);
  }
}
int main() {
  cin >> n >> m >> q;
  a = vector<vector<int>>(n, vector<int>(m, 1));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      calc(i, j);
    }
  }
  sol = 0;
  int nrFree = n * m;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      sol += dp[0][i][j] + dp[1][i][j];
    }
  }
  for (int i = 0; i < q; i++) {
    int y, x;
    cin >> y >> x;
    y--;
    x--;
    a[y][x] = 1 - a[y][x];
    if (a[y][x] == 0) {
      sol -= dp[0][y][x] + dp[1][y][x];
      dp[0][y][x] = dp[1][y][x] = 0;
      nrFree--;
    } else {
      calc(y, x);
      sol += dp[0][y][x] + dp[1][y][x];
      nrFree++;
    }
    traverse(y - 1, x, 0);
    traverse(y, x - 1, 1);
    cout << sol + nrFree << "\n";
  }
  return 0;
}
