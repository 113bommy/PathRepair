#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, l[200500], r[200500], siz[200500], tp[200500], it,
    id[200500], dep[200500], sb[200500], fa[200500];
char s[200500];
int q[200500];
string res;
void dfs0(int x, int d) {
  if (!x) return;
  dep[x] = d;
  fa[l[x]] = fa[r[x]] = x;
  dfs0(l[x], d + 1);
  q[++it] = x;
  dfs0(r[x], d + 1);
  siz[x] = 1 + siz[l[x]] + siz[r[x]];
}
void dfs01(int x, int to) {
  if (!x) return;
  tp[x] = to;
  id[x] = ++it;
  if (siz[l[x]] >= siz[r[x]]) {
    dfs01(l[x], to);
    dfs01(r[x], r[x]);
  } else {
    dfs01(r[x], to);
    dfs01(l[x], l[x]);
  }
}
struct SB {
  int f[800500], t[805000];
  void push(int id, int l, int r) {
    t[(id << 1)] = t[((id << 1) + 1)] = t[id];
    f[(id << 1)] = ((t[id] < 1) ? -1000000 : (((l + r) >> 1) - l + 1));
    f[((id << 1) + 1)] = ((t[id] < 1) ? -1000000 : (r - ((l + r) >> 1)));
    t[id] = 0;
  }
  void ass(int id, int l, int r, int x, int y, int w) {
    if (x <= l && r <= y) {
      t[id] = w;
      f[id] = ((w < 1) ? -1000000 : (r - l + 1));
      return;
    }
    if (t[id]) {
      push(id, l, r);
    }
    if (x <= ((l + r) >> 1)) ass((id << 1), l, ((l + r) >> 1), x, y, w);
    if (y > ((l + r) >> 1))
      ass(((id << 1) + 1), ((l + r) >> 1) + 1, r, x, y, w);
    f[id] = max(-1000000, f[(id << 1)] + f[((id << 1) + 1)]);
  }
  int get(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return f[id];
    }
    if (t[id]) {
      push(id, l, r);
    }
    if (y <= ((l + r) >> 1)) return get((id << 1), l, ((l + r) >> 1), x, y);
    if (x > ((l + r) >> 1))
      return get(((id << 1) + 1), ((l + r) >> 1) + 1, r, x, y);
    return max(-1000000, get((id << 1), l, ((l + r) >> 1), x, y) +
                             get(((id << 1) + 1), ((l + r) >> 1) + 1, r, x, y));
  }
} SB;
void hld_ass(int x, int w) {
  while (x) {
    SB.ass(1, 1, n, id[tp[x]], id[x], 1);
    x = fa[tp[x]];
  }
}
int hld_get(int x, int w = 0) {
  while (x) {
    w += SB.get(1, 1, n, id[tp[x]], id[x]);
    w = max(w, -1000000);
    x = fa[tp[x]];
  }
  return w;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> s + 1;
  for (i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  dfs0(1, 1);
  it = 0;
  dfs01(1, 1);
  for (i = n; i >= 1; i--) {
    if (s[q[i]] == s[q[i + 1]]) {
      sb[i] = sb[i + 1];
    } else {
      sb[i] = (s[q[i]] < s[q[i + 1]]);
    }
  }
  for (i = 1; i <= n; i++) {
    res += s[q[i]];
    if (SB.get(1, 1, n, id[q[i]], id[q[i]])) {
      res += s[q[i]];
      continue;
    }
    if (sb[i]) {
      k = hld_get(q[i]);
      if (k + m >= dep[q[i]]) {
        res += s[q[i]];
        m -= (dep[q[i]] - k);
        hld_ass(q[i], 1);
      }
    } else {
      SB.ass(1, 1, n, id[q[i]], id[q[i]], -1000000);
    }
  }
  cout << res;
}
