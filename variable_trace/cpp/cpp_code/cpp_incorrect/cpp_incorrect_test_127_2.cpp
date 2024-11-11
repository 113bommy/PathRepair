#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j;
  int t;
  cin >> t;
  while (t--) {
    string s, t, no;
    cin >> s >> t;
    no = "NO";
    if (t != "abc") {
      sort(s.begin(), s.end());
      cout << s << endl;
    } else {
      vector<long long int> cnt(26, 0);
      for (auto ch : s) {
        cnt[ch - 'a']++;
      }
      if (cnt[0] > 0 and cnt[1] > 0 and cnt[2] > 0) {
        no = "";
        for (i = 1; i < cnt[0]; i++) no += 'a';
        for (i = 1; i < cnt[2]; i++) no += 'c';
        for (i = 1; i < cnt[1]; i++) no += 'b';
        for (i = 3; i < 25; i++) {
          char ch = 'a';
          ch += i;
          for (j = 1; j < cnt[i]; j++) {
            no += ch;
          }
        }
        cout << no << endl;
      } else {
        sort(s.begin(), s.end());
        cout << s << endl;
      }
    }
  }
  return 0;
}
