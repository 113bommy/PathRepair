#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int mmp[1010][1010];
long long ans = 0;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  long long A = min(m, n), D = (m - n > 0) ? (m - n) : (n - m);
  ans = 2ll * (A - 1ll) * (A) * (2ll * A - 1ll) / 3ll + A * (A - 1ll) +
        D * A * (2ll * A - 1ll) + 1ll * n * m;
  int x, y;
  for (int i = 1; i <= q; i++) {
    cin >> x >> y;
    int xt = x, yt = y;
    long long up = 0, down = 0;
    for (int j = 1; j > -1; j++) {
      if (((j & 1) != 0) && mmp[xt - 1][yt] == 0 && xt - 1 >= 1)
        xt--;
      else if (((j & 1) == 0) && mmp[xt][yt - 1] == 0 && yt - 1 >= 1)
        yt--;
      else
        break;
      up++;
    }
    xt = x, yt = y;
    for (int j = 0; j >= -1; j++) {
      if (((j & 1) != 0) && mmp[xt + 1][yt] == 0 && xt + 1 <= n)
        xt++;
      else if (((j & 1) == 0) && mmp[xt][yt + 1] == 0 && yt + 1 <= n)
        yt++;
      else
        break;
      down++;
    }
    if (mmp[x][y])
      ans += (1ll * up * down + up + down + 1);
    else
      ans -= (1ll * up * down + up + down + 1);
    xt = x, yt = y;
    up = 0, down = 0;
    for (int j = 0; j > -1; j++) {
      if (((j & 1) != 0) && mmp[xt - 1][yt] == 0 && xt - 1 >= 1)
        xt--;
      else if (((j & 1) == 0) && mmp[xt][yt - 1] == 0 && yt - 1 >= 1)
        yt--;
      else
        break;
      up++;
    }
    xt = x, yt = y;
    for (int j = 1; j > -1; j++) {
      if (((j & 1) != 0) && mmp[xt + 1][yt] == 0 && xt + 1 <= n)
        xt++;
      else if (((j & 1) == 0) && mmp[xt][yt + 1] == 0 && yt + 1 <= n)
        yt++;
      else
        break;
      down++;
    }
    if (mmp[x][y])
      ans += (1ll * up * down + up + down + 1);
    else
      ans -= (1ll * up * down + up + down + 1);
    if (mmp[x][y] == 0)
      ans++;
    else
      ans--;
    mmp[x][y] ^= 1;
    cout << ans << endl;
  }
  return 0;
}
