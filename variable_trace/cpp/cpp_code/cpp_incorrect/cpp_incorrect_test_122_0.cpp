#include <bits/stdc++.h>
using namespace std;
int t, n, m, flag;
int vis[200010], xo[200010];
struct node {
  int a, b, c;
} tr[200010];
vector<pair<int, int>> g[200010];
int count(int x) {
  int s = 0;
  while (x) {
    s += (x & 1);
    x >>= 1;
  }
  return s;
}
void dfs(int u) {
  vis[u]++;
  for (int i = 0; i < g[u].size(); i++) {
    auto p = g[u][i];
    int v = p.first, va = p.second;
    if (vis[v]) {
      if (xo[v] == xo[u] ^ va) continue;
      flag++;
      return;
    } else {
      xo[v] = xo[u] ^ va;
      dfs(v);
    }
  }
}
int main() {
  cin >> t;
  while (t--) {
    flag = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) vis[i] = xo[i] = 0, g[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      tr[i] = {a, b, c};
      if (c != -1) {
        g[a].push_back({b, count(c) % 2});
        g[b].push_back({a, count(c) % 2});
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) dfs(i);
    }
    if (flag) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 1; i < n; i++) {
      if (tr[i].c == -1) {
        tr[i].c = xo[tr[i].a] ^ xo[tr[i].b];
      }
      cout << tr[i].a << ' ' << tr[i].b << ' ' << tr[i].c << '\n';
    }
  }
}
