#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, d;
    cin >> s >> d;
    int j, c = 0, k, i;
    for (i = 0; i < s.length(); i++) {
      for (k = 0; k < s.length(); k++) {
        for (j = 0; j < d.length() - 1; j++) {
          if (s[i] == d[j] && s[k] == d[j + 1]) c = c + abs(i - k);
        }
      }
    }
    cout << c << "\n";
  }
  return 0;
}
