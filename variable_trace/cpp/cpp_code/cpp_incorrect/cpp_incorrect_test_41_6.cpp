#include <bits/stdc++.h>
using namespace std;
int n, m, ans[1005][1005], cnt;
int main() {
  scanf("%d%d", &n, &m);
  int s = 1;
  while (s <= n) {
    cnt++;
    s *= m;
    int res = 0;
    while (res < n) {
      for (int i = 1; i <= s && res + i <= n; i++)
        for (int j = i + 1; j <= s && res + j <= n; j++)
          if (!ans[res + i][res + j]) ans[res + i][res + j] = cnt;
      res += s;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", ans[i][j]);
  return 0;
}
