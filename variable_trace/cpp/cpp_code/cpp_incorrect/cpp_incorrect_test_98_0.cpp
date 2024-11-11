#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  init();
  long long t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    long long cnt = 0;
    map<char, long long> mp;
    for (long long i = 0; i < s1.size(); i++) {
      if (mp[s1[i]] == 0) {
        mp[s1[i]] = i + 1;
      }
    }
    if (s2.size() == 1) {
      cout << mp[s2[0]] << "\n";
      continue;
    }
    for (long long i = 1; i < s2.size(); i++) {
      cnt += abs(mp[s2[i]] - mp[s2[i - 1]]);
    }
    cout << cnt << "\n";
  }
  return 0;
}
