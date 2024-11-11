#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, ans;
  string s;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ans = 0;
    map<char, int> chars;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      chars.insert(make_pair(s[j], j));
    }
    cin >> s;
    for (int j = 0; j < s.size() - 1; j++) {
      ans += abs(chars[s[j + 1]] - chars[s[j]]);
    }
    cout << ans << "\n";
  }
}
