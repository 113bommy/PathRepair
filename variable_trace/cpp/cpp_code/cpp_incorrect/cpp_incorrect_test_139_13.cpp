#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int flag = 0;
    int l = s.length();
    for (int i = 0; i < l / 2; i++) {
      if (s[i] != s[i + l / 2]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1 || l % 2 == 1)
      cout << "N0" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
