#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    int orig = v[i];
    v[i] = (i + 1) - v[i];
    if (v[i] >= 0) {
      vec.push_back(make_pair(v[i], orig));
    }
  }
  sort(vec.begin(), vec.end());
  vector<int> pos;
  for (pair<int, int> i : vec) {
    pos.push_back(i.second);
  }
  vector<int> ans;
  n = pos.size();
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(ans.begin(), ans.end(), pos[i]);
    if (it == ans.end()) {
      ans.push_back(pos[i]);
    } else {
      *it = pos[i];
    }
  }
  cout << ans.size() - 1 << endl;
}
