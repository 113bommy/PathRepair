#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  string s;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int c = 1;
    cin >> s;
    int n = s.length();
    if (n % 2 == 0) {
      for (int j = 0; j < n / 2; j++) {
        if (s[j] != s[n / 2 + j]) c = 0;
      }
      if (c != 1)
        cout << "no" << endl;
      else
        cout << "yes" << endl;
    } else
      cout << "no" << endl;
  }
}
