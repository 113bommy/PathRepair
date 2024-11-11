#include <bits/stdc++.h>
const long long mod = 2147483647LL;
long long read() {
  long long r = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      flag = -1LL;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = 10LL * r + (long long)c - '0';
    c = getchar();
  }
  return flag * r;
}
std::string s[2];
signed main() {
  int t = read();
  while (t--) {
    int n = read();
    bool flag = 1;
    for (int i = 0; i <= 1; ++i) std::cin >> s[i];
    for (int i = 2; i < n; ++i)
      if (s[0][i] == '1' && s[1][i] == '1') {
        puts("NO");
        flag = 0;
        break;
      }
    if (flag) puts("YES");
  }
  return 0;
}
