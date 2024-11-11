#include <bits/stdc++.h>
template <typename T>
bool umin(T &a, const T &b) {
  return (a > b ? a = b, 1 : 0);
}
template <typename T>
bool umax(T &a, const T &b) {
  return (a < b ? a = b, 1 : 0);
}
using namespace std;
const int N = 1001;
int n, k;
int colors[N][N];
int diff = 0;
void slv(vector<vector<int> > sts) {
  if ((int)(sts).size() == 1) return;
  int i = 0;
  diff++;
  vector<vector<int> > nw;
  while (i < (int)(sts).size()) {
    vector<int> current;
    int l = i, r = min((int)(sts).size(), i + k) - 1;
    for (int x = l; x <= r; ++x) {
      for (int y = l + 1; y <= r; ++y) {
        for (auto &a : sts[x]) {
          for (auto &b : sts[y]) {
            colors[a][b] = diff;
          }
        }
      }
    }
    for (int x = l; x <= r; ++x) {
      for (auto u : sts[x]) current.push_back(u);
    }
    nw.push_back(current);
    i = r + 1;
  }
  slv(nw);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  vector<vector<int> > sts;
  for (int i = 0; i < n; ++i) {
    sts.push_back({i});
  }
  slv(sts);
  cout << diff << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cout << colors[i][j] << ' ';
    }
  }
  return 0;
}
