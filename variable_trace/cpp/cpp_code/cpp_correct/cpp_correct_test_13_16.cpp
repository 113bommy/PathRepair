#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += s[i] == 'B';
    }
    if (cnt + cnt == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
