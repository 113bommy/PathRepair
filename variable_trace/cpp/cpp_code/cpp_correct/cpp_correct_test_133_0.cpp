#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int t, n;
string s[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    string ans;
    cin >> n;
    n -= 2;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    ans += s[0][0];
    bool sech = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i][1] != s[i + 1][0]) {
        for (int j = 0; j < n; ++j) {
          if (i + 1 == j) {
            ans += s[j];
            continue;
          }
          ans += s[j][1];
        }
        sech = 1;
        break;
      }
    }
    if (!sech) {
      for (int i = 0; i < n; ++i) {
        ans += s[i][1];
      }
      ans += "a";
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
