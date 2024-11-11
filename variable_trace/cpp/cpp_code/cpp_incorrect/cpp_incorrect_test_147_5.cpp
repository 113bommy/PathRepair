#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[1000];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l1 = s.length();
    for (int i = 1; i < l1; i++) a[i] = 0;
    int c = 0;
    a[0] = 1;
    bool fg = true;
    for (int i = 0; i < l1; i++) {
      if (s[i] == 'N') c++;
    }
    if (c % 2 == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
