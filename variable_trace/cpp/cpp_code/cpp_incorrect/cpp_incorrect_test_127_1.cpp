#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t_cases;
  cin >> t_cases;
  string s, t;
  int ac, bc, cc, b_index, c_index;
  while (t_cases--) {
    ac = 0;
    bc = 0;
    cc = 0;
    b_index = 0;
    c_index = 0;
    cin >> s >> t;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a') ac++;
      if (s[i] == 'b') {
        bc++;
        b_index = i;
      }
      if (s[i] == 'c') {
        cc++;
        c_index = i;
      }
    }
    if (ac == 0 || bc == 0 || cc == 0) {
      cout << s << endl;
      continue;
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < 3; i++) {
      mp[t[i]] = i;
    }
    if (mp['a'] == 0 && mp['b'] == 1 && mp['c'] == 2) {
      int b_start = b_index - bc;
      int c_start = c_index - cc;
      int i = b_start;
      for (int j = 0; j < cc; j++) {
        s[i] = 'c';
        i++;
      }
      for (int x = 0; x < bc; x++) {
        s[i] = 'b';
        i++;
      }
    }
    cout << s << endl;
  }
}
