#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int par[N];
int main() {
  int n;
  cin >> n;
  stack<vector<int>> s;
  for (int i = 0; i < n; i++) {
    int t, x, y;
    cin >> t;
    vector<int> v;
    v.push_back(t);
    if (t == 1) {
      cin >> x;
      v.push_back(x);
    } else {
      cin >> x >> y;
      v.push_back(x);
      v.push_back(y);
    }
    s.push(v);
  }
  iota(par, par + n + 5, 0);
  vector<int> ans;
  while (!s.empty()) {
    vector<int> v = s.top();
    s.pop();
    int t = v[0];
    if (t == 1) {
      int x = v[1];
      ans.push_back(par[x]);
    } else {
      int x = v[1], y = v[2];
      par[x] = par[y];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) cout << i << " ";
  cout << '\n';
}
