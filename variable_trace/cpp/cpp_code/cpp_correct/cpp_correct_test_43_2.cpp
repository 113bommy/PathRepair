#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
inline int read() {
  int s = 0, f = 1;
  char x = getchar();
  while (!isdigit(x)) f = (x == '-' ? -1 : 1), x = getchar();
  while (isdigit(x)) s = s * 10 + x - '0', x = getchar();
  return s * f;
}
int f[400005];
int mi[200005], mx[200005], ma[200005];
int dfn[400005];
int a[200005];
struct hlydl {
  int x, y, c, t;
} ed[200005], q[200005];
int fa[400005][20];
vector<int> e[400005];
int tot;
int fd(int x) { return f[x] == x ? x : f[x] = fd(f[x]); }
void merge(int x, int y) {
  int fx = fd(x), fy = fd(y);
  f[fy] = fx;
}
void merge2(int x, int y) {
  int fx = fd(x), fy = fd(y);
  if (ma[fx] == ma[fy])
    mx[fx] = max(mx[fx], mx[fy]);
  else
    mx[fx] = (ma[fx] > ma[fy] ? mx[fx] : mx[fy]);
  if (ma[fx] == ma[fy])
    mi[fx] = min(mi[fx], mi[fy]);
  else
    mi[fx] = (ma[fx] > ma[fy] ? mi[fx] : mi[fy]);
  ma[fx] = max(ma[fx], ma[fy]);
  f[fy] = fx;
}
int dep[400005];
int val[400005];
int idfn[400005];
int lca(int x, int y) {
  if (x == y) return x;
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int idx;
void dfs(int x, int ft) {
  dfn[x] = ++idx;
  idfn[idx] = x;
  for (int i = 1; i <= 19; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (auto to : e[x]) {
    if (to == ft) continue;
    dep[to] = dep[x] + 1;
    fa[to][0] = x;
    dfs(to, x);
  }
}
int ans[200005], ans2[200005];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read(), f[i] = i;
  for (int i = n + 1; i <= 2 * n; i++) f[i] = i;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), c = read(), t = read();
    ed[i] = (hlydl){x, y, c, t};
  }
  sort(ed + 1, ed + n, [](hlydl x, hlydl y) { return x.t < y.t; });
  tot = n;
  for (int i = 1; i < n; i++)
    tot++, val[tot] = ed[i].t, e[tot].push_back(fd(ed[i].x)),
           e[tot].push_back(fd(ed[i].y)), merge(tot, ed[i].x),
           merge(tot, ed[i].y);
  fa[tot][0] = tot;
  dfs(tot, tot);
  for (int i = 1; i <= n; i++)
    f[i] = i, ma[i] = a[i], mi[i] = dfn[i], mx[i] = dfn[i];
  sort(ed + 1, ed + n, [](hlydl x, hlydl y) { return x.c > y.c; });
  int now = 1;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    q[i] = (hlydl){x, y, i, 0};
  }
  sort(q + 1, q + m + 1, [](hlydl x, hlydl y) { return x.x > y.x; });
  for (int i = 1; i <= m; i++) {
    while (ed[now].c >= q[i].x && now < n) merge2(ed[now].x, ed[now].y), now++;
    int fx = fd(q[i].y);
    ans[q[i].c] = ma[fx];
    ans2[q[i].c] =
        max(val[lca(idfn[mi[fx]], q[i].y)], val[lca(idfn[mx[fx]], q[i].y)]);
  }
  for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i], ans2[i]);
  return 0;
}
