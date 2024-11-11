#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  if ((s.length()) % 2 == 0) {
    for (int i = 0; i <= (s.length() - 1) / 2; i++) {
      if (s[i] != s[i + (s.length()) / 2]) {
        cout << "NO"
             << "\n";
        return;
      }
    }
  } else {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "yes"
       << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
