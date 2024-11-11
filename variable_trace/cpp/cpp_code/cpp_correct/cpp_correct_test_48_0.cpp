#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 50;
int T, n, h[maxn], f[maxn], tot, ti[maxn];
int ans, sum;
int main() {
  scanf("%d", &T);
  for (int oo = 1; oo <= T; ++oo) {
    scanf("%d", &n);
    tot = 0;
    vector<bool> used(n);
    vector<set<int>> gi(n), ed(n);
    vector<int> seet;
    ans = 0, sum = 0;
    for (int i = 0; i < n; i++) f[i] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &h[i]);
      tot = max(tot, ++f[--h[i]]);
    }
    for (int i = 0; i < n; ++i) ti[i] = h[i];
    sort(h, h + n);
    for (int i = 0; i < n; i++)
      if (h[i] != ti[i])
        gi[ti[i]].insert(i), seet.push_back(i), ed[h[i]].insert(i);
    function<void(int)> dfs = [&](int u) {
      ed[h[u]].erase(u);
      sum++;
      gi[ti[u]].erase(u);
      if (!ed[ti[u]].empty()) dfs(*ed[ti[u]].begin());
    };
    for (int i : seet)
      if (gi[ti[i]].count(i)) {
        sum = 0;
        dfs(i);
        if (sum % 2 == 0) ++ans;
      }
    bool p = 1;
    if (tot > 1 || ans % 2 == 0) p = 0;
    if (!p)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
