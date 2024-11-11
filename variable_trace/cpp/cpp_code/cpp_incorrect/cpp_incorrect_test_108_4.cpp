#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g, g_rev;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  for (long long q = 0; q < t; q++) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    map<long long, long long> ma, mb;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      ma[a[i]] = i;
    }
    for (long long i = 0; i < n; i++) {
      cin >> b[i];
      mb[b[i]] = i;
    }
    set<long long> winners;
    vector<long long> a_add, b_add;
    a_add.push_back(prev(ma.end())->second);
    winners.insert(prev(ma.end())->second);
    ma.erase(prev(ma.end()));
    long long cnt = 1;
    while (cnt > 0) {
      cnt = 0;
      for (auto &e : a_add) {
        while (mb.lower_bound(b[e]) != mb.end()) {
          b_add.push_back(mb.lower_bound(b[e])->second);
          winners.insert(mb.lower_bound(b[e])->second);
          cnt++;
          mb.erase(mb.lower_bound(b[e]));
        }
      }
      a_add.clear();
      for (auto &e : b_add) {
        while (ma.lower_bound(a[e]) != ma.end()) {
          a_add.push_back(ma.lower_bound(a[e])->second);
          winners.insert(mb.lower_bound(a[e])->second);
          cnt++;
          ma.erase(ma.lower_bound(a[e]));
        }
      }
      b_add.clear();
    }
    for (long long i = 0; i < n; i++) {
      if (winners.count(i)) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << '\n';
  }
  return 0;
}
