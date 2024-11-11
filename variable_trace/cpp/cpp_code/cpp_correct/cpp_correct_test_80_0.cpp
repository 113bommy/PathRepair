#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, m, a[N], b[N], v[N], t, cnt, tag[N << 2], mn[N << 2], c[N];
long long ans;
struct node {
  int x, l, r, op;
} p[N << 1];
void add(int x, int y) {
  for (int i = x; i; i -= i & (-i)) c[i] += y;
}
int query(int x) {
  int ans = 0;
  for (int i = x; i <= t; i += i & (-i)) ans += c[i];
  return ans;
}
void build(int p, int l, int r) {
  tag[p] = 0;
  if (l == r) {
    mn[p] = l - 1;
    return;
  }
  int mid = (l + r) / 2;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
}
void pushdown(int p) {
  if (!tag[p]) return;
  tag[p << 1] += tag[p], tag[p << 1 | 1] += tag[p], mn[p << 1] += tag[p],
      mn[p << 1 | 1] += tag[p];
  tag[p] = 0;
}
void modify(int p, int l, int r, int lx, int rx, int v) {
  if (l >= lx && r <= rx) {
    mn[p] += v, tag[p] += v;
    return;
  }
  int mid = (l + r) / 2;
  pushdown(p);
  if (lx <= mid) modify(p << 1, l, mid, lx, rx, v);
  if (rx > mid) modify(p << 1 | 1, mid + 1, r, lx, rx, v);
  mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
}
signed main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m), cnt = ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]), v[i] = a[i];
      p[++cnt] = {a[i], i + 1, n + 1, -1}, p[++cnt] = {a[i] + 1, 1, i, 1};
    }
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(v + 1, v + 1 + n), t = unique(v + 1, v + 1 + n) - v - 1,
                            fill(c + 1, c + 1 + t, 0);
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(v + 1, v + 1 + t, a[i]) - v;
      ans += query(a[i] + 1), add(a[i], 1);
    }
    sort(b + 1, b + 1 + m),
        sort(p + 1, p + 1 + cnt, [](node x, node y) { return x.x < y.x; }),
        build(1, 1, n + 1);
    for (int i = 1, j = 1; i <= m; i++) {
      while (j <= cnt && p[j].x <= b[i])
        modify(1, 1, n + 1, p[j].l, p[j].r, p[j].op), j++;
      ans += mn[1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
