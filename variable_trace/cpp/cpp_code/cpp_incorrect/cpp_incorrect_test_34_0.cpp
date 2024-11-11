#include <bits/stdc++.h>
using namespace std;
int n, a[5005], A = 1, m;
bool in[5005][1 << 12], s[1 << 12];
vector<int> g[5005];
int main() {
  scanf("%d", &n);
  s[0] = 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), m = max(a[i], m);
  for (int i = 0; i <= m; i++) g[i].push_back(0), in[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = (int)g[a[i]].size() - 1; ~j; j--) {
      int v = a[i] ^ g[a[i]][j];
      if (!s[v]) s[v] = 1, A++;
      for (int k = a[i] + 1; k <= m; k++) {
        if (in[k][v]) break;
        in[k][v] = 1;
        g[k].push_back(v);
      }
      g[a[i]].pop_back();
    }
  }
  printf("%d\n", A);
  for (int i = 0; i < (1 << 12); i++)
    if (s[i]) printf("%d ", i);
  puts("");
  return 0;
}
