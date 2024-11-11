#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e5 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
int n, k;
string s;
int lc[N], rc[N];
char ord[N];
int idx[N];
int p = 0;
int flag[N];
void dfs1(int u) {
  if (lc[u]) dfs1(lc[u]);
  ord[++p] = u;
  idx[u] = p;
  if (rc[u]) dfs1(rc[u]);
}
int rep[N];
int dfs2(int u, int k) {
  if (k == 0) return 0;
  int cost = 0;
  if (lc[u]) cost += dfs2(lc[u], k - cost);
  if (flag[u] || cost) {
    rep[u] = 1, cost++;
    if (rc[u]) cost += dfs2(rc[u], k - cost);
  }
  return cost;
}
void main0() {
  cin >> n >> k >> s;
  s = "$" + s;
  for (int i = 1; i <= n; ++i) {
    cin >> lc[i] >> rc[i];
  }
  dfs1(1);
  flag[ord[n]] = 0;
  for (int i = n - 1; i >= 1; --i) {
    int cur = ord[i];
    int nxt = ord[i + 1];
    flag[cur] = (s[cur] == s[nxt] ? flag[nxt] : s[cur] < s[nxt]);
  }
  dfs2(1, k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= rep[ord[i]] + 1; ++j) {
      cout << s[ord[i]];
    }
  }
  cout << endl;
}
