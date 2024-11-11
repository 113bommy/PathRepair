#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)2e5 + 7;
vector<int> t(MAX);
class Dsu {
 public:
  vector<int> p;
  vector<int> mn;
  int n;
  Dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    mn.resize(n);
    for (int i = 0; i < n; ++i) mn[i] = t[i];
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      mn[y] = min(mn[y], mn[x]);
      return true;
    }
    return false;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> by_x(n, vector<int>(3));
    vector<vector<int>> by_y(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y >> t[i];
      by_x[i] = {x, y, i};
      by_y[i] = {y, x, i};
    }
    Dsu d(n);
    sort(by_x.begin(), by_x.end());
    for (int i = 1; i < n; ++i) {
      if (by_x[i][0] == by_x[i - 1][0] && by_x[i][1] - by_x[i - 1][1] <= k)
        d.unite(by_x[i][2], by_x[i - 1][2]);
    }
    sort(by_y.begin(), by_y.end());
    for (int i = 1; i < n; ++i) {
      if (by_y[i][0] == by_y[i - 1][0] && by_y[i][1] - by_y[i - 1][1] <= k)
        d.unite(by_y[i][2], by_y[i - 1][2]);
    }
    vector<bool> used(n);
    vector<int> comps;
    for (int i = 0; i < n; ++i) {
      int x = d.get(i);
      if (!used[x]) {
        comps.push_back(t[x]);
        used[x] = true;
      }
    }
    sort(comps.begin(), comps.end());
    int ans = comps.size() - 1;
    for (int i = 0; i < comps.size(); ++i) {
      ans = min(ans, max(comps[i], (int)comps.size() - i - 2));
    }
    cout << ans << "\n";
  }
  return 0;
}
