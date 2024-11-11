#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    vector<int> v, tmp, ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      v.push_back(p);
    }
    int c = 0, l = 0;
    while (l < n - 1) {
      int id = l;
      for (int i = l + 1; i < n; i++) {
        if (v[i] < v[id]) {
          id = i;
        }
      }
      if (id != l) {
        c++;
        ans.push_back(l + 1);
        ans.push_back(id + 1);
        ans.push_back(1);
        tmp.clear();
        for (int i = 0; i < l; i++) {
          tmp.push_back(v[i]);
        }
        tmp.push_back(v[id]);
        for (int i = l; i < n; i++) {
          if (i == id) continue;
          tmp.push_back(v[i]);
        }
        v = tmp;
      }
      l++;
    }
    cout << c << "\n";
    for (int i = 0; i < ans.size(); i += 3) {
      cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << "\n";
    }
  }
  return 0;
}
