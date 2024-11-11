#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 10;
const int inf = 1e9;
int T;
int n;
char s[N];
int ans;
int main() {
  T = read();
  while (T--) {
    n = read();
    int L = 1, R = n;
    scanf("%s", s + 1);
    while (s[L] == s[R]) {
      L++;
      R--;
    }
    if (L >= R) {
      printf("0\n");
      continue;
    }
    ans = inf;
    char p = s[L];
    int l = L + 1, r = R, tmp = 1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        if (s[l] == p) {
          l++;
          tmp++;
        } else if (s[r] == p) {
          r--;
          tmp++;
        } else {
          tmp = inf;
          break;
        }
      }
    }
    ans = min(ans, tmp);
    p = s[R];
    l = L, r = R - 1, tmp = 1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        if (s[l] == p) {
          l++;
          tmp++;
        } else if (s[r] == p) {
          r--;
          tmp++;
        } else {
          tmp = inf;
          break;
        }
      }
    }
    ans = min(ans, tmp);
    printf("%d\n", ans == inf ? -1 : ans);
  }
  return 0;
}
