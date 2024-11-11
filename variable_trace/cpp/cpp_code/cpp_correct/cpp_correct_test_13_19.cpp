#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length(), counta = 0, countb = 0, countc = 0, i;
    for (i = 0; i < l; i++) {
      if (s[i] == 'A') counta++;
      if (s[i] == 'B') countb++;
      if (s[i] == 'C') countc++;
    }
    if (countb == counta + countc)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
