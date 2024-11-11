#include <bits/stdc++.h>
using namespace std;
char d[100001][3];
inline long long qpow(long long base, long long expo) {
  long long ret = 1;
  for (; expo; (base *= base) %= 998244353, expo >>= 1)
    if (expo & 1) (ret *= base) %= 998244353;
  return ret;
}
long long fac[100001], invfac[100001];
inline long long C(int n, int m) {
  return fac[n] * invfac[m] % 998244353 * invfac[n - m] % 998244353;
}
int main() {
  int n;
  scanf("%d", &n);
  int b0 = 0, b1 = 0, w0 = 0, w1 = 0;
  fac[0] = invfac[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", d[i]);
    b0 += d[i][0] == 'B';
    b1 += d[i][1] == 'B';
    w0 += d[i][0] == 'W';
    w1 += d[i][1] == 'W';
    fac[i] = fac[i - 1] * i % 998244353;
  }
  invfac[n] = qpow(fac[n], 998244353 - 2);
  for (int i = n - 1; i; i--) invfac[i] = invfac[i + 1] * (i + 1) % 998244353;
  int f0 = n - b0 - w0, f1 = n - b1 - w1;
  long long ans = 0;
  for (int i = 0; i <= f0; i++) {
    int c1 = b0 + i - b1;
    if (c1 >= 0 && c1 <= f1) ans = (ans + C(f0, i) * C(f1, c1)) % 998244353;
  }
  bool flag = 0;
  int set = 0, bw = 0, wb = 0;
  for (int i = 1; i <= n; i++) {
    if ((d[i][0] == 'B' && d[i][1] == 'B') ||
        (d[i][0] == 'W' && d[i][1] == 'W')) {
      flag = 1;
      break;
    }
    bw += d[i][0] == 'B' || d[i][1] == 'W';
    wb += d[i][0] == 'W' || d[i][1] == 'B';
    if (d[i][0] != '?' || d[i][1] != '?') set++;
  }
  if (!flag) {
    ans = ans - qpow(2, n - set) + 998244353;
    if (!bw || !wb) ans++;
    if (!set) ans++;
    ans %= 998244353;
  }
  printf("%lld", ans);
  return 0;
}
