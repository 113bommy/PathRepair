#include <bits/stdc++.h>
using namespace std;
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long int n, m, a, b, cnt = 0;
    string s1, s2, res;
    cin >> s1 >> n >> s2 >> m;
    if (s1.size() + n > s2.size() + m)
      cout << ">";
    else if (s1.size() + n < s2.size() + m)
      cout << "<";
    else {
      int ok = 0;
      a = min(s1.size(), s2.size());
      for (int i = 0; i < a; i++) {
        if (s1[i] > s2[i]) {
          cout << ">";
          ok = 1;
          break;
        } else if (s1[i] < s2[i]) {
          cout << "<";
          ok = 1;
          break;
        }
      }
      if (ok == 0) {
        int x = min(s1.size(), s2.size());
        if (s1.size() < s2.size()) {
          for (int i = x; i < s2.size(); i++) {
            if (s2[i] != '0') {
              cout << "<";
              ok = 1;
              break;
            }
          }
        }
        if (s1.size() > s2.size()) {
          for (int i = x; i < s1.size(); i++) {
            if (s2[i] != '0') {
              cout << ">";
              ok = 1;
              break;
            }
          }
        }
        if (ok == 0) cout << "=";
      }
    }
    cout << endl;
  }
  return 0;
}
