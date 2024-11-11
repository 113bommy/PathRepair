#include <bits/stdc++.h>
const int N = 100005;
const int M = 200010;
using namespace std;
int n, T;
int fa[N][20], dep[N];
int cnt = 0, dfn[N], las[N];
long long a[N], sum[N], val[N];
int edge[M], lst[N], nxt[M], t = 0;
int lowbit(int x) { return x & (-x); }
void UPD(int x, long long num) {
  if (num == 0) return;
  for (; x <= n; x += lowbit(x)) val[x] += num;
}
long long GET(int x) {
  long long ans = 0;
  while (x > 0) {
    ans += val[x];
    x -= lowbit(x);
  }
  return ans;
}
void ADD(int x, int y) {
  edge[++t] = y;
  nxt[t] = lst[x];
  lst[x] = t;
}
void READ() {
  int u, v;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < 0) a[i] = -a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d", &u, &v);
    ADD(u, v);
    ADD(v, u);
  }
}
void SEARCH(int x, int pa) {
  dfn[x] = ++cnt;
  fa[x][0] = pa;
  dep[x] = dep[pa] + 1;
  sum[x] = sum[pa] + a[x];
  for (int r = lst[x]; r; r = nxt[r]) {
    if (edge[r] == pa) continue;
    SEARCH(edge[r], x);
  }
  las[x] = cnt;
}
void INIT() {
  cnt = 0;
  dep[0] = 0;
  sum[0] = 0;
  SEARCH(1, 0);
  for (int i = 1; i <= 18; i++) {
    for (int x = 1; x <= n; x++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
}
long long VAL(int x) { return sum[x] + GET(x); }
int LCA(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int de = dep[y] - dep[x];
  for (int i = 18; i >= 0; i--) {
    if ((de >> i) & 1) y = fa[y][i];
  }
  if (x == y) return x;
  for (int i = 18; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}
void SOLVE() {
  int pd, u;
  scanf("%d%d", &pd, &u);
  if (pd == 1) {
    long long v;
    scanf("%lld", &v);
    if (v < 0) v = -v;
    long long now = v - a[u];
    a[u] = v;
    UPD(dfn[u], now);
    UPD(las[u] + 1, -now);
  }
  if (pd == 2) {
    int v;
    scanf("%d", &v);
    long long ans = VAL(u) + VAL(v) - 2 * VAL(LCA(u, v)) + a[LCA(u, v)];
    ans *= 2;
    ans -= a[u] + a[v];
    printf("%lld\n", ans);
  }
}
int main() {
  READ();
  INIT();
  while (T--) SOLVE();
  return 0;
}
