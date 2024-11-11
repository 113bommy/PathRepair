#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 1e7;
string intToStr(long long int x) {
  if (x == 0) return "0";
  string s = "";
  while (x) {
    s += (char)('0' + x % 10);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve() {
  string s;
  cin >> s;
  vector<long long int> same;
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == 'X') same.push_back(i);
  }
  long long int res = 0;
  for (long long int j = 0; j <= MAX; j += 25) {
    string t = intToStr(j);
    if ((long long int)t.size() == (long long int)s.size()) {
      bool ok = true;
      for (long long int i = 1; i < same.size(); i++) {
        ok &= (t[same[i - 1]] == t[same[i]]);
      }
      if (!ok) continue;
      for (long long int i = 0; i < s.size(); i++) {
        if (s[i] != 'X' && s[i] != '_') {
          ok &= (t[i] == s[i]);
        }
      }
      res += ok;
    }
  }
  cout << res << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
