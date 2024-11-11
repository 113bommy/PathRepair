#include <bits/stdc++.h>
using namespace std;
int a[32], bt[32];
int gcd(int x, int y) { return (!y) ? x : gcd(y, x % y); }
int main() {
  bt[0] = 1;
  for (int i = 1; i < 30; i++) bt[i] = bt[i - 1] << 1;
  int T;
  cin >> T;
  while (T--) {
    int n;
    memset(a, 0, sizeof a);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      for (int j = 0; j < 30; j++)
        if (bt[j] & x) a[j]++;
    }
    int ans = a[0];
    for (int i = 0; i < 30; i++)
      if (a[i]) ans = a[i];
    for (int i = 0; i < 30; i++) ans = gcd(ans, a[i]);
    for (int i = 1; i <= ans; i++)
      if (ans % i == 0) printf("%d ", i);
    if (ans == 0)
      for (int i = 1; i <= n; i++) printf("%d ", i);
    puts("");
  }
  return 0;
}
