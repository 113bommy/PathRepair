#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  string s;
  cin >> T;
  while (T-- > 0) {
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') {
        ++a;
      } else if (s[i] == 'B') {
        ++b;
      } else {
        ++c;
      }
    }
    if (a == 0 && b == c) {
      cout << "YES" << endl;
      continue;
    }
    if (a == b && c == 0) {
      cout << "YES" << endl;
      continue;
    }
    if (b == a + c) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
