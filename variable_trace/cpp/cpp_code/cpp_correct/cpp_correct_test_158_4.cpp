#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        a[i][j] = (s[j] == '1');
      }
    }
    const long long inf = (long long)2e18L;
    long long res = -inf, msk = 0;
    for (int i = 0; i < (1 << n); i++) {
      long long z = 0;
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          z -= x[j];
        } else {
          z += x[j];
        }
      }
      long long ans = z;
      vector<int> cnt(m, 0);
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          for (int k = 0; k < m; k++) {
            if (a[j][k]) {
              cnt[k] += 1;
            }
          }
        } else {
          for (int k = 0; k < m; k++) {
            if (a[j][k]) {
              cnt[k] -= 1;
            }
          }
        }
      }
      sort(cnt.begin(), cnt.end());
      for (int j = 0; j < m; j++) {
        ans += cnt[j] * 1LL * (j + 1);
      }
      if (ans > res) {
        res = ans;
        msk = i;
      }
    }
    {
      vector<pair<int, int>> cnt(m);
      for (int i = 0; i < m; i++) {
        cnt[i].first = 0;
        cnt[i].second = i;
      }
      for (int j = 0; j < n; j++) {
        if ((1 << j) & msk) {
          for (int k = 0; k < m; k++) {
            if (a[j][k]) {
              cnt[k].first += 1;
            }
          }
        } else {
          for (int k = 0; k < m; k++) {
            if (a[j][k]) {
              cnt[k].first -= 1;
            }
          }
        }
      }
      sort(cnt.begin(), cnt.end());
      vector<int> p(m);
      for (int j = 0; j < m; j++) {
        p[cnt[j].second] = j + 1;
      }
      for (const auto& xx : p) {
        cout << xx << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
