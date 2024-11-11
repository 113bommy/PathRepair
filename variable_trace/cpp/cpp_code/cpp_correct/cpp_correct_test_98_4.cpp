#include <bits/stdc++.h>
using namespace std;
int find(char x, string& s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == x) return i + 1;
  }
}
int main() {
  string s, x;
  int t, sum;
  cin >> t;
  while (t--) {
    cin >> s >> x;
    sum = 0;
    if (x.length() == 1) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < x.length() - 1; i++) {
      int temp = find(x[i + 1], s) - find(x[i], s);
      if (temp < 0) temp *= -1;
      sum += temp;
    }
    cout << sum << endl;
  }
}
