#include <bits/stdc++.h>
using namespace std;
struct _IO {
  _IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
} _io;
const long long maxn = 3e5 + 10, mod = 1e9 + 7;
template <typename... T>
long long madd(T... args) {
  long long res = 0;
  for (auto i : {args...}) {
    res = (res + ((i % mod + mod) % mod)) % mod;
  }
  return res % mod;
}
template <typename... T>
long long mmul(T... args) {
  long long res = 1;
  for (auto i : {args...}) {
    res = (res * ((i % mod + mod) % mod)) % mod;
  }
  return res % mod;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
long long mpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
long long _inv(long long x) { return mpow(x, mod - 2); }
long long dsufa[maxn], fa[maxn], cnt[maxn];
vector<pair<long long, long long> > query;
vector<long long> edge[maxn];
deque<long long> res;
long long findfa(long long x) {
  return x == dsufa[x] ? x : (dsufa[x] = findfa(dsufa[x]));
}
bool mer(long long x, long long y) {
  x = findfa(x);
  y = findfa(y);
  if (x == y) return 0;
  dsufa[x] = y;
  return 1;
}
void dfs(long long u, long long p) {
  for (auto v : edge[u]) {
    if (v == p) continue;
    fa[v] = u;
    dfs(v, u);
  }
}
void path(long long x, long long y) {
  deque<long long> a(1, x), b(1, y);
  res.clear();
  while (fa[x] != x) {
    x = fa[x];
    a.push_front(x);
  }
  while (fa[y] != y) {
    y = fa[y];
    b.push_front(y);
  }
  long long len = min(a.size(), b.size());
  long long idx = 0;
  for (; idx < len && a[idx] == b[idx]; ++idx)
    ;
  res.push_back(a[idx - 1]);
  for (long long i = idx; i < a.size(); ++i) res.push_back(a[i]);
  for (long long i = idx; i < b.size(); ++i) res.push_front(b[i]);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) dsufa[i] = i;
  for (long long i = 1; i <= m; ++i) {
    long long x, y;
    cin >> x >> y;
    if (mer(x, y)) {
      edge[x].push_back(y);
      edge[y].push_back(x);
    }
  }
  dfs(1, 1);
  long long q;
  cin >> q;
  for (long long i = 1; i <= q; ++i) {
    long long x, y;
    cin >> x >> y;
    query.push_back({x, y});
    ++cnt[x];
    ++cnt[y];
  }
  bool ok = 1;
  long long oddcnt = 0;
  for (long long i = 1; i <= n; ++i) {
    if (cnt[i] & 1) {
      ok = 0;
      ++oddcnt;
    }
  }
  if (!ok) {
    cout << "NO\n";
    cout << oddcnt / 2 << '\n';
  } else {
    cout << "YES\n";
    for (auto vec : query) {
      long long x = vec.first, y = vec.second;
      path(x, y);
      cout << res.size() << '\n';
      for (long long i = 0; i < res.size(); ++i)
        cout << res[i] << " \n"[i == (long long)res.size() - 1];
    }
  }
}
int main() {
  long long T = 1;
  while (T--) solve();
  return 0;
}
