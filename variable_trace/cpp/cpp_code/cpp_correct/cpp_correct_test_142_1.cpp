#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> p;
bool is(int val) {
  int c = 0;
  vector<bool> pres(n, 0);
  bool flag = 0;
  for (int i = 0; i < m; i++) {
    c = 0;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= val) {
        pres[j] = true;
        c++;
      }
    }
    if (c > 1) flag = 1;
  }
  if (!flag) return false;
  bool ans = 1;
  for (bool i : pres)
    if (!i) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    p.assign(m, vector<int>(n));
    int minn = INT_MAX, maxx;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) cin >> p[i][j];
    for (int i = 0; i < n; i++) {
      maxx = -1;
      for (int j = 0; j < m; j++) {
        maxx = max(maxx, p[j][i]);
      }
      minn = min(maxx, minn);
    }
    int l = 1, r = minn + 3;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (is(mid))
        l = mid;
      else
        r = mid;
    }
    cout << l << '\n';
  }
  return 0;
}
