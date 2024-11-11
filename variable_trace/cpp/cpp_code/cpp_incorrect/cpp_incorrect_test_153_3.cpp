#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0, ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return (1 - 2 * f) * x;
}
inline void writebit(int x, int len) {
  for (int i = (len - 1); i >= (0); i--) {
    printf("%d", (x >> i) & 1);
  }
}
const int N = 24, L = 2e4 + 10, M = 1 << 23, K = 26, mod = 998244353, inf = 1e9;
int n, a[N][K], f[M];
char s[L];
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) {
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int j = (1); j <= (l); j++) a[i][s[j] - 'a']++;
  }
  for (int i = (1); i <= ((1 << n) - 1); i++) {
    f[i] = -1;
    for (int j = (1); j <= (n); j++)
      if ((i >> j - 1) & 1) f[i] = f[i];
    for (int j = (0); j <= (K - 1); j++) {
      int tmp = inf;
      for (int k = (1); k <= (n); k++)
        if ((i >> k - 1) & 1) (tmp = ((tmp) < (a[k][j]) ? (tmp) : (a[k][j])));
      (f[i] = (1ll * (f[i]) * (tmp + 1) % mod));
    }
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= ((1 << n) - 1); j++) {
      if ((j >> i - 1) & 1) {
        (f[j] = (((f[j]) + (f[j - (1 << i - 1)])) % mod));
      }
    }
  }
  long long ans = 0;
  for (int i = (1); i <= ((1 << n) - 1); i++) {
    long long k = 0, sum = 0;
    for (int j = (1); j <= (n); j++)
      if ((i >> j - 1) & 1) k++, sum += j;
    ans ^= k * sum * (((f[i]) % mod + mod) % mod);
  }
  printf("%lld\n", ans);
}
