#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'N') c++;
    }
    if (c != 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
