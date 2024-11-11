#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int MOD = 998244353;
int z, n, i, x, sum, tab[N], bat[N], lj;
int main() {
  scanf("%d", &z);
  while (z--) {
    scanf("%d", &n);
    for (i = 0; i <= n + 2; i++) tab[i] = bat[i] = 0;
    lj = 1;
    for (i = 0; i < n; i++) {
      scanf("%d", &x);
      tab[x] = (tab[x] + tab[x]) % MOD;
      if (x > 0) tab[x] = (tab[x] + tab[x - 1]) % MOD;
      if (x == 0) tab[x] = (tab[x] + 1) % MOD;
      bat[x] = (bat[x] + bat[x]) % MOD;
      bat[x + 2] = (bat[x + 2] + bat[x + 2]) % MOD;
      if (x > 1) bat[x] = (bat[x] + tab[x - 2]) % MOD;
      if (x == 1) lj = (lj * 2) % MOD;
    }
    sum = 0;
    for (i = 0; i <= n; i++) {
      sum = (sum + tab[i]) % MOD;
      sum = (sum + bat[i]) % MOD;
    }
    sum = (sum + lj - 1) % MOD;
    printf("%d\n", sum);
  }
  return 0;
}
