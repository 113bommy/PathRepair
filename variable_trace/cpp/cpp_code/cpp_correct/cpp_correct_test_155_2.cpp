#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> fi, se;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        fi.push_back({p[i], i});
      } else {
        se.push_back({p[i], i});
      }
    }
    sort(fi.rbegin(), fi.rend());
    sort(se.rbegin(), se.rend());
    vector<int> q(n);
    int cnt = n;
    for (auto i : se) {
      q[i.second] = cnt--;
    }
    for (auto i : fi) {
      q[i.second] = cnt--;
    }
    for (int i = 0; i < n; ++i) {
      cout << q[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
