#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    if (n & 1) {
      cout << "NO" << '\n';
      continue;
    }
    string t;
    for (int i = 0; i < n / 2; i++) {
      t += s[i];
    }
    cout << (t == s ? "YES" : "NO") << '\n';
  }
  return 0;
}
