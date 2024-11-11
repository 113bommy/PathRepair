#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
template <class T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
namespace MF {
struct E {
  int v, c, nxt;
  E() {}
  E(int v, int c, int nxt) : v(v), c(c), nxt(nxt) {}
} e[10101 << 1];
int n, s, t, s_e, head[1111], cur[1111], lev[1111];
int hd, tl, q[1111];
inline void a_e(int u, int v, int c) {
  e[++s_e] = E(v, c, head[u]);
  head[u] = s_e;
}
inline void add(int u, int v, int c) { a_e(u, v, c), a_e(v, u, 0); }
inline void init(int N, int S, int T) {
  s_e = 1, n = N, s = S, t = T;
  for (int i = 1; i <= n; i++) head[i] = 0;
}
inline bool BFS() {
  for (int i = 1; i <= n; i++) lev[i] = 0, cur[i] = head[i];
  hd = tl = 0;
  q[++tl] = s, lev[s] = 1;
  while (hd ^ tl) {
    int u = q[++hd];
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (!e[i].c || lev[v]) continue;
      lev[v] = lev[u] + 1;
      if (v == t) return true;
      q[++tl] = v;
    }
  }
  return false;
}
int dfs(int u, int f) {
  if (u == t) return f;
  int d = 0, used = 0;
  for (int &i = cur[u]; i; i = e[i].nxt) {
    int v = e[i].v, c = e[i].c;
    if (!c || lev[v] != lev[u] + 1) continue;
    d = dfs(v, min(f - used, c));
    if (!d) continue;
    e[i].c -= d;
    e[i ^ 1].c += d, used += d;
    if (used == f) break;
  }
  if (!used) lev[u] = 0;
  return used;
}
inline int solve() {
  int d = 0, flow = 0;
  while (BFS())
    while ((d = dfs(s, 1000000000))) flow += d;
  return flow;
}
}  // namespace MF
struct E {
  int v, nxt;
  E() {}
  E(int v, int nxt) : v(v), nxt(nxt) {}
} e[1111];
int n, m, s_e, head[1111];
int a[1111], ans[1111];
inline void a_e(int u, int v) {
  e[++s_e] = E(v, head[u]);
  head[u] = s_e;
}
int tim, vis[1111], num[1111], pos[1111];
inline std::vector<int> calc(int mid, std::vector<int> d) {
  tim++;
  int N = 0;
  for (auto i : d) {
    vis[i] = tim;
    num[i] = ++N;
    pos[N] = i;
  }
  int s = N + 1, t = N + 2;
  MF::init(t, s, t);
  for (auto u : d) {
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (vis[v] ^ tim) continue;
      MF::add(num[v], num[u], 1000000000);
    }
    if (a[u] > mid)
      MF::add(s, num[u], 1);
    else
      MF::add(num[u], t, 1);
  }
  MF::solve(), d.clear();
  for (int i = 1; i <= N; i++)
    if (MF::lev[i]) d.push_back(pos[i]);
  return d;
}
void solve(int l, int r, std::vector<int> d) {
  if (!d.size()) return;
  if (l == r) {
    for (auto i : d) ans[i] = l;
    return;
  }
  int mid = (l + r) >> 1;
  std::vector<int> A, B = calc(mid, d);
  for (auto i : B) vis[i] = 0;
  for (auto i : d)
    if (vis[i]) A.push_back(i);
  solve(l, mid, A), solve(mid + 1, r, B);
}
std::vector<int> d;
int main() {
  n = read<int>();
  m = read<int>();
  int l = 1e9, r = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read<int>();
    d.push_back(i);
    l = min(l, a[i]);
    r = max(r, a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int u = read<int>();
    int v = read<int>();
    a_e(v, u);
  }
  solve(l, r, d);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
