#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
char s[N];
void solve() {
  int n, m;
  cin >> n >> m;
  scanf("%s", s + 1);
  int x = 1, y = 1;
  int dx = 0, dy = 0;
  int len = strlen(s + 1);
  int maxx = n, maxny = m;
  for (register int i = 1; i <= len; ++i) {
    if (s[i] == 'L')
      dy--;
    else if (s[i] == 'R')
      dy++;
    else if (s[i] == 'D')
      dx++;
    else
      dx--;
    if (1 - dx > maxx || n - dx < x || 1 - dy > maxny || m - dy < y) break;
    x = max(1 - dx, x);
    y = max(1 - dy, y);
    maxx = min(maxx, n - dx);
    maxny = min(maxny, m - dy);
  }
  cout << x << ' ' << y << '\n';
}
signed main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
