#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  map<char, int> mp;
  while (t--) {
    string x;
    cin >> x;
    for (int i = 1; i <= 26; i++) {
      mp[x[i - 1]] = i;
    }
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
      ans += abs(mp[s[i]] - mp[s[i - 1]]);
    }
    cout << ans << endl;
  }
}
