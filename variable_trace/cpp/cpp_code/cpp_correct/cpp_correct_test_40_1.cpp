#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long llread() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Edge {
  int u, v, Next;
} G[600010];
int head[300010], tot;
int fa[300010];
int st[300010], vis[300010], ans[300010], tt;
inline void add(int u, int v) {
  G[++tot] = (Edge){u, v, head[u]};
  head[u] = tot;
}
inline int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
inline void dfs(int x, int des) {
  st[++tt] = x;
  vis[x] = 1;
  if (x == des) {
    for (int i = (1); i <= (tt); ++i) {
      ans[i] = st[i];
    }
    ans[0] = tt;
    return;
  }
  for (int i = head[x]; i != -1; i = G[i].Next) {
    if (!vis[G[i].v]) {
      dfs(G[i].v, des);
    }
  }
  --tt;
}
int A[300010], B[300010], cnt[300010];
int main() {
  int n = read(), m = read();
  for (int i = (1); i <= (n); ++i) fa[i] = i;
  memset(head, -1, sizeof(head));
  for (int i = (1); i <= (m); ++i) {
    int u = read(), v = read();
    if (Find(u) != Find(v)) {
      fa[Find(u)] = Find(v);
      add(u, v), add(v, u);
    }
  }
  int q = read();
  for (int i = (1); i <= (q); ++i) {
    A[i] = read(), B[i] = read();
    cnt[A[i]]++, cnt[B[i]]++;
  }
  int res = 0;
  for (int i = (1); i <= (n); ++i) {
    if ((cnt[i] & 1)) ++res;
  }
  if (res) {
    puts("NO");
    printf("%d\n", res / 2);
    return 0;
  }
  puts("YES");
  for (int i = (1); i <= (q); ++i) {
    for (int j = (1); j <= (n); ++j) vis[j] = 0;
    tt = 0;
    dfs(A[i], B[i]);
    printf("%d\n", ans[0]);
    for (int j = (1); j <= (ans[0]); ++j) {
      printf("%d ", ans[j]);
    }
    puts("");
  }
}
