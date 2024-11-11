#include <bits/stdc++.h>
using namespace std;
int n, m;
int fa[((int)2e5) + 5], u[((int)2e5) + 5];
int cnt[((int)2e5) + 5][2];
int find(int x) {
  if (fa[x] == x) return x;
  int y = find(fa[x]);
  u[x] ^= u[fa[x]];
  fa[x] = y;
  return fa[x];
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(u, 0, sizeof(u));
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n), scanf("%d", &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d", &x), scanf("%d", &y);
      char s[10];
      bool cp;
      scanf("%s", s);
      if (s[0] == 'i')
        cp = 1;
      else
        cp = 0;
      int fa1 = find(x), fa2 = find(y);
      if (fa1 == fa2) {
        if (cp == 0 && u[x] == u[y]) continue;
        if (cp == 1 && u[x] != u[y]) continue;
        ans = -1;
        continue;
      }
      fa[fa1] = fa2;
      u[fa1] = cp ^ u[x] ^ u[y];
    }
    if (ans == -1) {
      printf("-1\n");
      continue;
    }
    for (int i = 1; i <= n; i++) {
      int x = find(i);
      cnt[x][u[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (fa[i] == i) {
        ans += max(cnt[i][0], cnt[i][1]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
