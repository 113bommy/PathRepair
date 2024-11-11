#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long N = 1e5 + 10;
vector<long long> g[N];
vector<long long> d(N);
vector<long long> arr;
vector<long long> in(N), out(N);
long long po[20][N], t[4 * N], add[4 * N];
void dfs(long long v, long long p) {
  in[v] = arr.size();
  arr.push_back(v);
  for (auto to : g[v]) {
    if (to != p) {
      d[to] = d[v] + 1;
      po[0][to] = v;
      dfs(to, v);
    }
  }
  out[v] = (long long)(arr.size()) - 1;
}
long long lca(long long a, long long b) {
  if (d[a] < d[b]) {
    swap(a, b);
  }
  for (long long i = 19; i >= 0; i--) {
    if (d[po[i][a]] >= d[b]) {
      a = po[i][a];
    }
  }
  if (a == b) return a;
  for (long long i = 19; i >= 0; i--) {
    if (po[i][a] != po[i][b]) {
      a = po[i][a];
      b = po[i][b];
    }
  }
  return po[0][a];
}
void push(long long v) {
  t[v] += add[v];
  if (v * 2 < 4 * N) {
    add[v * 2] += add[v];
    add[v * 2 + 1] += add[v];
  }
  add[v] = 0;
}
void update(long long v, long long tl, long long tr, long long l, long long r,
            long long val) {
  push(v);
  if (l > r) return;
  if (tl == l && tr == r) {
    add[v] += val;
    push(v);
    return;
  }
  long long tm = (tl + tr) / 2;
  update(2 * v, tl, tm, l, min(r, tm), val),
      update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
}
long long get(long long v, long long l, long long r, long long pos) {
  push(v);
  if (l == r) {
    return t[v];
  }
  long long m = (l + r) / 2;
  if (pos <= m)
    return get(2 * v, l, m, pos);
  else
    return get(2 * v + 1, m + 1, r, pos);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  for (long long i = 1; i < 20; i++) {
    for (long long j = 0; j < n; j++) {
      po[i][j] = po[i - 1][po[i - 1][j]];
    }
  }
  for (long long i = 0; i < n; i++) {
    update(1, 0, n - 1, in[i], out[i], a[i]);
  }
  for (long long i = 0; i < q; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long v, c;
      cin >> v >> c;
      v--;
      update(1, 0, n - 1, in[v], out[v], -a[v]);
      a[v] = abs(c);
      update(1, 0, n - 1, in[v], out[v], a[v]);
    } else {
      long long u, v;
      cin >> u >> v;
      u--, v--;
      if (u == v) {
        cout << 0 << endl;
        return 0;
      }
      long long g = lca(u, v), ans = 0;
      if (u != g && po[0][u] != g) {
        ans += (get(1, 0, n - 1, in[po[0][u]]) - get(1, 0, n - 1, in[g])) * 2;
      }
      if (v != g && po[0][v] != g) {
        ans += (get(1, 0, n - 1, in[po[0][v]]) - get(1, 0, n - 1, in[g])) * 2;
      }
      set<long long> st{u, v, g};
      for (auto to : st) {
        ans += a[to];
      }
      if (u != g && v != g) {
        ans += a[g];
      }
      cout << ans << endl;
    }
  }
  return 0;
}
