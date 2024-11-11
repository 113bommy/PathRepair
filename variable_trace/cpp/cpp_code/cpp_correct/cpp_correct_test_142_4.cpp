#include <bits/stdc++.h>
using namespace std;
int m, n;
bool possible(vector<vector<unsigned long long>>& data, long long h) {
  vector<bool> vld(n);
  bool pair = false;
  for (int i = 0; i < m; i++) {
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (data[i][j] >= h) {
        vld[j] = true;
        c++;
      }
    }
    if (c > 1) {
      pair = true;
    }
  }
  if (!pair && n > 1) {
    return false;
  } else {
    return std::all_of(vld.begin(), vld.end(), [](bool x) { return x; });
  }
}
long long max_possible(vector<vector<unsigned long long>>& data,
                       unsigned long long mx) {
  long long l = 0, r = mx + 1;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (possible(data, mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l - 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    vector<vector<unsigned long long>> data(m, vector<unsigned long long>(n));
    unsigned long long mx = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> data[i][j];
        mx = max(mx, data[i][j]);
      }
    }
    long long res = max_possible(data, mx);
    cout << res << endl;
  }
  return 0;
}
