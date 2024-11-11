#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length() / 2 - 1;
    int k = s.length() - 1;
    int t = 0;
    while (n > 0 && k > s.length() / 2) {
      if (s[n] != s[k]) {
        t = 1;
        break;
      }
      n--;
      k--;
    }
    if (t || s.length() % 2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
