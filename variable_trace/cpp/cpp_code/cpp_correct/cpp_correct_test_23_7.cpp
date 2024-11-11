#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 11;
int n, m;
long long a[N];
vector<pair<int, long long> > e[N];
void build(int l, int r, int fa) {
  if (l > r) return;
  int pos = l;
  for (int i = l + 1; i <= r; i++)
    if (a[i] < a[pos]) pos = i;
  e[fa].push_back(make_pair(pos, a[pos] - a[fa]));
  build(l, pos - 1, pos);
  build(pos + 1, r, pos);
}
int siz[N];
long long f[N][N], g[N];
void dfs(int w, int fa) {
  siz[w] = 1;
  for (pair<int, long long> v : e[w]) {
    if (v.first == fa) continue;
    dfs(v.first, w);
    for (int i = 0; i <= siz[w] + siz[v.first]; i++) g[i] = 0;
    for (int i = 0; i <= siz[w]; i++)
      for (int j = 0; j <= siz[v.first]; j++) {
        g[i + j] =
            max(g[i + j], f[w][i] + f[v.first][j] + j * (m - j) * v.second);
      }
    siz[w] += siz[v.first];
    for (int i = 0; i <= siz[w]; i++) f[w][i] = max(f[w][i], g[i]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n, 0);
  dfs(e[0][0].first, 0);
  cout << f[e[0][0].first][m] << endl;
  return 0;
}
