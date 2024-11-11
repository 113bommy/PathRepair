#include <bits/stdc++.h>
using namespace std;
const int modP = 1e9 + 7;
const long long oo = 1000000000000000LL;
const int maxN = 2e5 + 10;
int n, k, res, sze[maxN], a[maxN], T[2][maxN], S[2][maxN], checkT[2][maxN],
    flag;
vector<pair<int, int>> adj[maxN];
bool elim[maxN];
void build(int u, int p) {
  sze[u] = 1;
  for (auto [v, _] : adj[u])
    if (!elim[v] && v != p) build(v, u), sze[u] += sze[v];
}
void initBIT(int t, int x) {
  if (flag != checkT[t][x]) {
    checkT[t][x] = flag;
    T[t][x] = 0;
    S[t][x] = 0;
  }
}
void updateBIT(int t, int x, int v) {
  if (x == 0) {
    initBIT(t, 0);
    ++T[t][x];
    S[t][x] = (S[t][x] + v) % modP;
    return;
  }
  for (; x <= n; x += (x & -x)) {
    initBIT(t, x);
    ++T[t][x];
    S[t][x] = (S[t][x] + v) % modP;
  }
}
pair<int, int> getBIT(int t, int x) {
  if (x < 0) return {0, 0};
  initBIT(t, 0);
  int tmpT = T[t][0], tmpS = S[t][0];
  for (; x > 0; x -= (x & (-x))) {
    initBIT(t, x);
    tmpT = (tmpT + T[t][x]) % modP;
    tmpS = (tmpS + S[t][x]) % modP;
  }
  return {tmpT, tmpS};
}
void count(int u, int p, int oc, int pc, int cnt, int sum) {
  res = (res + sum) % modP;
  {
    auto [t, s] = getBIT(oc, k - cnt);
    res = (1ll * t * sum + res) % modP;
    res = (res + s) % modP;
  }
  {
    auto [t, s] = getBIT(1 - oc, k - cnt - 1);
    res = (1ll * t * sum + res) % modP;
    res = (res + s) % modP;
  }
  for (auto [v, w] : adj[u]) {
    if (!elim[v] && v != p) {
      int ncnt = cnt + (w != pc);
      if (ncnt > k) continue;
      count(v, u, oc, w, ncnt, (sum + a[v]) % modP);
    }
  }
}
void update(int u, int p, int oc, int pc, int cnt, int sum) {
  updateBIT(oc, cnt, sum);
  for (auto [v, w] : adj[u]) {
    if (!elim[v] && v != p) {
      int ncnt = cnt + (w != pc);
      if (ncnt > k) continue;
      update(v, u, oc, w, ncnt, (sum + a[v]) % modP);
    }
  }
}
int get_centroid(int u, int p, int num) {
  for (auto [v, _] : adj[u])
    if (!elim[v] && v != p && sze[v] > num / 2) return get_centroid(v, u, num);
  return u;
}
void centroid_decomposition(int u) {
  build(u, -1);
  ++flag;
  int root = get_centroid(u, -1, sze[u]);
  for (auto [v, w] : adj[root])
    if (!elim[v]) {
      count(v, root, w, w, 0, a[root] + a[v]);
      update(v, root, w, w, 0, a[v]);
    }
  res = (res + a[root]) % modP;
  elim[root] = true;
  for (auto [v, _] : adj[root])
    if (!elim[v]) centroid_decomposition(v);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  centroid_decomposition(1);
  cout << res << endl;
}
