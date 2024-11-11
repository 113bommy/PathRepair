#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int mp[1010][1010];
long long dpR[1010][1010], dpD[1010][1010];
long long Ans = 0;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dpR[i][j] = 1 + dpD[i][j + 1];
      dpD[i][j] = 1 + dpR[i + 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Ans += dpR[i][j] + dpD[i][j] - 1;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) mp[i][j] = 1;
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (mp[x][y]) {
      Ans -= dpR[x][y] + dpD[x][y] - 1;
      int xx = x, yy = y;
      int step = 0;
      while (xx > 0 && yy > 0) {
        if (step & 1)
          xx--;
        else
          yy--;
        if (!mp[xx][yy]) break;
        if (xx <= 0 || yy <= 0) break;
        if (step & 1) {
          dpD[xx][yy] -= dpR[x][y];
          Ans -= dpR[x][y];
        } else {
          dpR[xx][yy] -= dpD[x][y];
          Ans -= dpD[x][y];
        }
        step++;
      }
      xx = x, yy = y;
      step = 0;
      while (xx > 0 && yy > 0) {
        if (step & 1)
          yy--;
        else
          xx--;
        if (!mp[xx][yy]) break;
        if (xx <= 0 || yy <= 0) break;
        if (step & 1) {
          dpR[xx][yy] -= dpD[x][y];
          Ans -= dpD[x][y];
        } else {
          dpD[xx][yy] -= dpR[x][y];
          Ans -= dpR[x][y];
        }
        step++;
      }
      dpR[x][y] = dpD[x][y] = 0;
      mp[x][y] = 0;
    } else {
      dpR[x][y] = dpD[x][y + 1] + 1;
      dpD[x][y] = dpR[x + 1][y] + 1;
      Ans += dpR[x][y] + dpD[x][y] - 1;
      int xx = x, yy = y;
      int step = 0;
      while (xx > 0 && yy > 0) {
        if (step & 1)
          xx--;
        else
          yy--;
        if (!mp[xx][yy]) break;
        if (xx <= 0 || yy <= 0) break;
        if (step & 1) {
          dpD[xx][yy] += dpR[x][y];
          Ans += dpR[x][y];
        } else {
          dpR[xx][yy] += dpD[x][y];
          Ans += dpD[x][y];
        }
        step++;
      }
      xx = x, yy = y;
      step = 0;
      while (xx > 0 && yy > 0) {
        if (step & 1)
          yy--;
        else
          xx--;
        if (!mp[xx][yy]) break;
        if (xx <= 0 || yy <= 0) break;
        if (step & 1) {
          dpR[xx][yy] += dpD[x][y];
          Ans += dpD[x][y];
        } else {
          dpD[xx][yy] += dpR[x][y];
          Ans += dpR[x][y];
        }
        step++;
      }
      mp[x][y] = 1;
    }
    printf("%lld\n", Ans);
  }
  return 0;
}
