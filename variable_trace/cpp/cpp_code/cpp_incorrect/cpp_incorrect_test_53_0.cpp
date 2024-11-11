#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> ans;
    int p = 0, flag = 0, n;
    string s;
    char ch;
    cin >> n >> ch;
    cin >> s;
    s = " " + s;
    for (int i = 1; i < n; i++)
      if (s[i] != ch) flag = 1;
    if (!flag)
      cout << "0" << endl;
    else if (s[n] != ch) {
      int f = 0;
      for (int i = 1; i <= n; i++) {
        f = 0;
        for (int j = i; j <= n; j += i)
          if (s[j] != ch) f = 1;
        if (!f) {
          cout << "1" << endl << i << endl;
          break;
        }
      }
      if (f) cout << "2" << endl << n - 1 << " " << n << endl;
    } else
      cout << "1" << endl << n << endl;
  }
  return 0;
}
