#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int n, q, e[maxn + 5], dep[maxn + 5], key[maxn + 5], cnt;
vector<pair<int, int> > G[maxn + 5];
int fa[maxn + 5][20], mx[maxn + 5][20];
struct Edge {
  int u, v, c, w;
} E[maxn + 5];
vector<pair<int, int> > Q[maxn + 5];
vector<Edge> M[maxn + 5];
pair<int, int> ans[maxn + 5];
int FA[maxn + 5], MXE[maxn + 5], MXV[maxn + 5], P[maxn + 5];
int find(int x) { return FA[x] == x ? x : FA[x] = find(FA[x]); }
void dfs(int u, int pre) {
  for (auto x : G[u]) {
    int v = x.first, w = x.second;
    if (v == pre) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u);
    fa[v][0] = u;
    mx[v][0] = w;
  }
}
pair<int, int> ask(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int ret = 0;
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] && dep[fa[u][i]] >= dep[v]) {
      ret = max(ret, mx[u][i]);
      u = fa[u][i];
    }
  }
  if (u == v) {
    return {u, ret};
  }
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      ret = max(mx[u][i], ret);
      ret = max(ret, mx[v][i]);
      u = fa[u][i], v = fa[v][i];
    }
  }
  return {fa[u][0], max(ret, max(mx[u][0], mx[v][0]))};
}
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  if (MXE[fx] < MXE[fy]) swap(fx, fy);
  if (MXE[fx] > MXE[fy]) {
    FA[fy] = fx;
  } else {
    pair<int, int> o = ask(P[fx], P[fy]);
    FA[fy] = fx;
    MXV[fx] = max(MXV[fx], max(MXV[fy], o.second));
    P[fx] = o.first;
  }
}
pair<int, int> query(int u) {
  int fu = find(u);
  return {MXE[fu], max(MXV[fu], ask(u, P[fu]).second)};
}
int main() {
  scanf("%d %d", &n, &q);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &e[i]);
    P[i] = i, MXE[i] = e[i];
    MXV[i] = 0;
    FA[i] = i;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d %d", &E[i].u, &E[i].v, &E[i].c, &E[i].w);
    key[++cnt] = E[i].c;
    G[E[i].u].push_back({E[i].v, E[i].w});
    G[E[i].v].push_back({E[i].u, E[i].w});
  }
  dep[1] = 1;
  dfs(1, 0);
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
      mx[i][j] = max(mx[i][j - 1], mx[fa[i - 1][j - 1]][j - 1]);
    }
  }
  sort(key + 1, key + cnt + 1);
  key[++cnt] = 1e9 + 1;
  cnt = unique(key + 1, key + cnt + 1) - key - 1;
  for (int i = 1; i < n; i++) {
    E[i].c = lower_bound(key + 1, key + cnt + 1, E[i].c) - key;
    M[E[i].c].push_back(E[i]);
  }
  for (int i = 1; i <= q; i++) {
    int v, x;
    scanf("%d %d", &v, &x);
    v = lower_bound(key + 1, key + cnt + 1, v) - key;
    Q[v].push_back({x, i});
  }
  for (int i = cnt; i >= 1; i--) {
    for (auto eg : M[i]) {
      Union(eg.u, eg.v);
    }
    for (auto que : Q[i]) {
      ans[que.second] = query(que.first);
    }
  }
  for (int i = 1; i <= q; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
