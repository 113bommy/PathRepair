#include <bits/stdc++.h>
using namespace std;
int fun(char s[], char e) {
  for (int j = 1; j <= 26; j++) {
    if (e == s[j]) return j;
  }
}
int main() {
  int t;
  char keyboard[30], str[100000];
  cin >> t;
  while (t--) {
    cin >> keyboard >> str;
    int len = strlen(str);
    int ans = 0;
    for (int i = 1; i < len; i++) {
      int a1 = fun(keyboard, str[i]);
      int a2 = fun(keyboard, str[i - 1]);
      ans += abs(a1 - a2);
    }
    cout << ans << endl;
  }
}
