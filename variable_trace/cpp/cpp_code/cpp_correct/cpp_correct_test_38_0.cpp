#include <bits/stdc++.h>
using namespace std;
void nos() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int n, m;
vector<vector<char> > mat;
void read() {
  cin >> n >> m;
  mat.clear();
  mat.resize(n + 1);
  int i, j;
  mat[0].resize(m + 1);
  for (i = 1; i <= n; i++) {
    mat[i].resize(m + 1);
    for (j = 1; j <= m; j++) cin >> mat[i][j];
  }
}
void solve() {
  int i, j;
  vector<int> fools(m + 1);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (mat[i - 1][j] == 'X' and mat[i][j - 1] == 'X') fools[j]++;
  vector<int> sp(m + 1);
  for (j = 1; j <= m; j++) sp[j] = sp[j - 1] + fools[j];
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int foolcnt = sp[y] - sp[x];
    cout << (foolcnt ? "NO" : "YES") << '\n';
  }
}
void restart() {}
int32_t main() {
  nos();
  read();
  solve();
  restart();
  return 0;
}
