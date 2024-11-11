#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, l, j, r = 0, k;
  string s, str;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    l = s.length();
    cin >> str;
    map<char, int> d;
    for (i = 0; i < l; i++) {
      d[s[i]] = i;
    }
    r = 0;
    for (i = 0; i < str.length() - 1; i++) {
      r += abs(d[str[i]] - d[str[i + 1]]);
    }
    cout << r << "\n";
  }
}
