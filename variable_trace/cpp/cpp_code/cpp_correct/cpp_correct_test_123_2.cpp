#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long N = 2e5 + 100;
long long add[4 * N], p[N], h[N], tin[N], ltin[N], rtin[N], euler[N], ptr = 0,
                                                                      timer = 0;
pair<long long, long long> t[4 * N];
bool bad_blue[N], chosen[N];
vector<long long> g[N];
void dfs(long long v, long long par = -1) {
  p[v] = par;
  tin[v] = timer++;
  ltin[v] = rtin[v] = tin[v];
  euler[ptr++] = v;
  if (par != -1) h[v] = h[par] + 1;
  for (long long u : g[v]) {
    if (u != par) {
      dfs(u, v);
      ltin[v] = min(ltin[v], ltin[u]);
      rtin[v] = max(rtin[v], rtin[u]);
    }
  }
}
void push(long long v) {
  t[v].first += add[v];
  add[v * 2] += add[v];
  add[v * 2 + 1] += add[v];
  add[v] = 0;
}
pair<long long, long long> get_point(long long v) {
  return {t[v].first + add[v], t[v].second};
}
void pull(long long v) { t[v] = max(get_point(v * 2), get_point(v * 2 + 1)); }
void build(long long v, long long tl, long long tr) {
  if (tl == tr)
    t[v] = {h[euler[tl]] + 1, tl};
  else {
    long long tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}
void modify(long long v, long long tl, long long tr, long long l, long long r,
            long long x) {
  if (tl > r || l > tr) return;
  if (l <= tl && tr <= r)
    add[v] += x;
  else {
    long long tm = (tl + tr) / 2;
    push(v);
    modify(v * 2, tl, tm, l, r, x);
    modify(v * 2 + 1, tm + 1, tr, l, r, x);
    pull(v);
  }
}
pair<long long, long long> get_max(long long v, long long tl, long long tr,
                                   long long l, long long r) {
  if (tl > r || l > tr) return {-inf, -1};
  if (l <= tl && tr <= r) return get_point(v);
  long long tm = (tl + tr) / 2;
  push(v);
  auto result =
      max(get_max(v * 2, tl, tm, l, r), get_max(v * 2 + 1, tm + 1, tr, l, r));
  pull(v);
  return result;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n - 1; ++i) {
    long long v, u;
    cin >> v >> u;
    g[--v].push_back(--u);
    g[u].push_back(v);
  }
  dfs(0);
  long long res = -1e18;
  build(1, 0, n - 1);
  long long not_bad = n;
  for (long long it = 1; it <= k; ++it) {
    auto f = get_max(1, 0, n - 1, 0, n - 1);
    long long id = f.second;
    long long v = euler[id];
    modify(1, 0, n - 1, id, id, -inf);
    chosen[v] = true;
    while (v != -1 && !bad_blue[v]) {
      bad_blue[v] = true;
      not_bad--;
      modify(1, 0, n - 1, ltin[v], rtin[v], -1);
      v = p[v];
    }
    long long blue = inf;
    blue = min(blue, (n - not_bad - it) * (it - not_bad));
    long long x = n - it, w = it;
    if (w <= not_bad && x - w >= 0) {
      long long left = not_bad - w;
      long long q = min(left, (x - w) / 2);
      blue = min(blue, (x - w - q) * (-q));
    }
    res = max(res, blue);
  }
  cout << res;
}
