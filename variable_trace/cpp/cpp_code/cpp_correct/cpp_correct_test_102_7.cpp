#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, ans;
char s[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int sx = 1, sy = 1, l = sy, r = sy, u = sx, d = sx;
    int nowx = sx, nowy = sy;
    bool isOK = true;
    for (int now = 1; now <= len; ++now) {
      if (s[now] == 'L') {
        int xx = nowx, yy = nowy - 1;
        if (xx < 1 || xx > n || yy < 1 || yy > m) {
          int syy = sy + 1, rr = r + 1;
          if (syy > m || rr > m) {
            isOK = false;
            break;
          }
          sy = syy, r = rr;
        } else
          nowx = xx, nowy = yy, l = min(l, nowy);
      } else if (s[now] == 'R') {
        int xx = nowx, yy = nowy + 1;
        if (xx < 1 || xx > n || yy < 1 || yy > m) {
          int syy = sy - 1, ll = l - 1;
          if (syy < 1 || ll < 1) {
            isOK = false;
            break;
          }
          sy = syy, l = ll;
        } else
          nowx = xx, nowy = yy, r = max(r, nowy);
      } else if (s[now] == 'U') {
        int xx = nowx - 1, yy = nowy;
        if (xx < 1 || xx > n || yy < 1 || yy > m) {
          int sxx = sx + 1, dd = d + 1;
          if (sxx > n || dd > n) {
            isOK = false;
            break;
          }
          sx = sxx, d = dd;
        } else
          nowx = xx, nowy = yy, u = min(u, nowx);
      } else {
        int xx = nowx + 1, yy = nowy;
        if (xx < 1 || xx > n || yy < 1 || yy > m) {
          int sxx = sx - 1, uu = u - 1;
          if (sxx < 1 || uu < 1) {
            isOK = false;
            break;
          }
          sx = sxx, u = uu;
        } else
          nowx = xx, nowy = yy, d = max(d, nowx);
      }
      if (!isOK) break;
      ans = max(ans, now);
    }
    printf("%d %d\n", sx, sy);
  }
  return 0;
}
