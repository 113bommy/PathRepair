#include <bits/stdc++.h>
using namespace std;
bool cat(string s) {
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      a++;
    else if (s[i] == 'b')
      b++;
    else
      c++;
  }
  if ((b - c) == a)
    return true;
  else
    return false;
}
int main() {
  string s;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> s;
    if (cat(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
