#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
int n, k, t[N];
int fa[N], w[N];
void init(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i, w[i] = t[i];
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    w[fy] = min(w[fy], w[fx]);
    fa[fx] = fy;
  }
}
void solve() {
  cin >> n >> k;
  map<int, vector<pair<int, int>>> mpx, mpy;
  for (int i = 1, x, y; i <= n; i++) {
    cin >> x >> y >> t[i];
    mpx[x].push_back({y, i});
    mpy[y].push_back({x, i});
  }
  init(n);
  for (auto mp : {mpx, mpy}) {
    for (auto tt : mp) {
      vector<pair<int, int>> ve = tt.second;
      sort(ve.begin(), ve.end());
      for (int i = 1; i < ve.size(); i++) {
        if (ve[i].first - ve[i - 1].first <= k) {
          merge(ve[i].second, ve[i - 1].second);
        }
      }
    }
  }
  set<int> se;
  vector<int> ve;
  for (int i = 1; i <= n; i++) {
    se.insert(find(i));
  }
  for (auto i : se) {
    ve.push_back(w[i]);
  }
  int ans = ve.size() - 1;
  sort(ve.begin(), ve.end());
  for (int i = 0; i < ve.size(); i++) {
    ans = min(ans, max(ve[i], (int)ve.size() - 1 - i));
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
