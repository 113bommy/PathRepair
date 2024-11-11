#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int n, m;
bool check(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m) return 0;
  return 1;
}
int e[N];
int pos(int x, int y) { return x * m + y; }
bool vis[N];
int in[N];
int d = 0;
int ti[N], cnt;
void dfs(int u, int depx) {
  d = max(d, depx);
  vis[u] = 1;
  ti[u] = ++cnt;
  int v = e[u];
  if (!ti[v] && v != 0) {
    dfs(v, depx + 1);
  }
  ti[u] = 0;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n * m; i++) {
    e[i] = 0;
    vis[i] = 0;
    in[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'L' && check(i, j - 1))
        e[pos(i, j)] = pos(i, j - 1), in[pos(i, j - 1)]++;
      else if (s[j] == 'R' && check(i, j + 1))
        e[pos(i, j)] = pos(i, j + 1), in[pos(i, j + 1)]++;
      else if (s[j] == 'U' && check(i - 1, j))
        e[pos(i, j)] = pos(i - 1, j), in[pos(i - 1, j)]++;
      else if (s[j] == 'D' && check(i + 1, j))
        e[pos(i, j)] = pos(i + 1, j), in[pos(i + 1, j)]++;
    }
  }
  d = 0;
  int ans = 0, x = 0, y = 0;
  for (int i = 0; i < n * m; i++) {
    if (in[i] == 0) {
      d = 0;
      dfs(i, 1);
      if (d > ans) {
        ans = d, x = i / m, y = i % m;
      }
    }
  }
  for (int i = 0; i < n * m; i++) {
    if (!vis[i]) {
      dfs(i, 1);
      if (d > ans) {
        ans = d, x = i / m, y = i % m;
      }
    }
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
