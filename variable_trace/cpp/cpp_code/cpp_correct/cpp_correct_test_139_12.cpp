#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int t;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int c = 1; c <= t; ++c) {
    int flag = 0;
    cin >> s;
    if (s.length() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      for (int i = 0; i <= (s.length() / 2) - 1; ++i) {
        if (s[i] != s[(s.length() / 2) + i]) {
          flag = 1;
        }
      }
      if (flag == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
