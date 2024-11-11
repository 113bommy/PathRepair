#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int f[5005][8205], n;
vector<int> g[5005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    g[x].push_back(i);
  }
  for (int i = 0; i <= 5000; i++)
    for (int j = 1; j <= 8200; j++) f[i][j] = inf;
  int t = 0;
  for (int i = 1; i <= 5000; i++) {
    if (!g[i].size()) continue;
    for (int j = 1; j <= 8191; j++) {
      int yu = j ^ i, kk = f[t][yu];
      if (t) f[i][j] = f[t][j];
      if ((kk != inf) && (t || !yu) && (yu <= 8191)) {
        int l = 0, r = g[i].size() - 1;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (g[i][mid] <= kk)
            l = mid + 1;
          else
            r = mid - 1;
        }
        if (l < g[i].size()) f[i][j] = min(f[i][j], g[i][l]);
      }
    }
    t = i;
  }
  int ans = 0;
  for (int i = 0; i <= 8191; i++)
    if (f[t][i] != inf) ans++;
  cout << ans << endl;
  for (int i = 0; i <= 8191; i++)
    if (f[t][i] != inf) cout << i << ' ';
  puts("");
  return 0;
}
