#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int i, n;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < 26; i++) {
      m[s[i]] = i;
    }
    string s1;
    cin >> s1;
    int count = 0;
    for (int i = 0; i < s1.size() - 1; i++) {
      count += abs(m[s1[i + 1]] - m[s1[i]]);
    }
    cout << count << endl;
  }
  return 0;
}
