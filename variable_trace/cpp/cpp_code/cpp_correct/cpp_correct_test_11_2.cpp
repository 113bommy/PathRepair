#include <bits/stdc++.h>
using namespace std;
struct FenwickTree2D {
  vector<vector<int>> nodes;
  vector<vector<int>> f;
  int n;
  FenwickTree2D() {}
  FenwickTree2D(int n) : n(n) {
    nodes.resize(n + 1);
    f.resize(n + 1);
  }
  void fakeUpdate(int u, int v) {
    if (u == 0 || v == 0) {
      return;
    }
    for (int x = u; x <= n; x += x & -x) {
      nodes[x].push_back(v);
    }
  }
  void fakeGet(int u, int v) {
    if (u == 0 || v == 0) {
      return;
    }
    for (int x = u; x > 0; x -= x & -x) nodes[x].push_back(v);
  }
  void update(int u, int v, int delta) {
    if (u == 0 || v == 0) {
      return;
    }
    for (int x = u; x <= n; x += x & -x) {
      for (int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) -
                   nodes[x].begin() + 1;
           y <= nodes[x].size(); y += y & -y) {
        f[x][y] = max(f[x][y], delta);
      }
    }
  }
  int get(int u, int v) {
    if (u == 0 || v == 0) {
      return 0;
    }
    int res = 0;
    for (int x = u; x > 0; x -= x & -x)
      for (int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) -
                   nodes[x].begin();
           y > 0; y -= y & -y)
        res = max(res, f[x][y]);
    return res;
  }
  void build() {
    for (int i = 1; i <= n; ++i) {
      nodes[i].push_back(1000111000);
      sort(nodes[i].begin(), nodes[i].end());
      f[i].resize(nodes[i].size() + 3);
    }
  }
};
const int MAX = 2e5 + 5;
int n, a[MAX], b[MAX], f[MAX];
FenwickTree2D fw = FenwickTree2D(MAX);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = i - a[i] + 1;
    fw.fakeUpdate(a[i], b[i]);
    fw.fakeGet(a[i], b[i]);
  }
  fw.build();
  int rs = 0;
  for (int i = 1; i <= n; i++)
    if (b[i] > 0) {
      f[i] = fw.get(a[i] - 1, b[i]) + 1;
      rs = max(rs, f[i]);
      fw.update(a[i], b[i], f[i]);
    }
  cout << rs;
}
