#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 60;
const int mod = 1e9 + 7;
int n, q, hf, k1, k2, cur1, cur2, tar1, tar2, a1[N], c1[M][M], s1[M][N], sum[N],
    mul[2][N], b1[2][N][M];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
inline int qpow(int x, int y) {
  long long s = 1, t = 1ll * x;
  while (y) {
    if (y & 1) s = s * t % mod;
    t = t * t % mod;
    y >>= 1;
  }
  return s;
}
int main() {
  n = read(), q = read();
  k1 = 13, k2 = 18;
  hf = qpow(2, mod - 2);
  mul[0][0] = mul[1][0] = sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    a1[i] = read();
    sum[i] = (sum[i - 1] + a1[i]) % mod;
    mul[0][i] = (mul[0][i - 1] + qpow(a1[i], k1)) % mod;
    mul[1][i] = (mul[1][i - 1] + qpow(a1[i], k2)) % mod;
  }
  c1[0][0] = 1, s1[0][1] = 1;
  for (int i = 2; i <= n; ++i) s1[0][i] = s1[0][i - 1] + 1;
  for (int i = 1; i <= k2; ++i) {
    c1[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      c1[i][j] = (c1[i - 1][j - 1] + c1[i - 1][j]) % mod;
    s1[i][1] = 0;
    for (int j = 2; j <= n; ++j)
      s1[i][j] = (s1[i][j - 1] + qpow(j - 1, i)) % mod;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k1; ++j)
      b1[0][i][j] = 1ll * s1[j][i] * c1[k1][j] % mod;
    for (int j = 0; j <= k2; ++j)
      b1[1][i][j] = 1ll * s1[j][i] * c1[k2][j] % mod;
  }
  for (int i = 1, l, r, d, len, a0, x; i <= q; ++i) {
    l = read(), r = read(), d = read();
    if (l == r) {
      printf("Yes\n");
      continue;
    }
    if (l > r) {
      printf("No\n");
      continue;
    }
    cur1 = (mul[0][r] - mul[0][l - 1] + mod) % mod;
    cur2 = (mul[1][r] - mul[1][l - 1] + mod) % mod;
    len = r - l + 1;
    a0 = (1ll * sum[r] - 1ll * sum[l - 1] -
          1ll * len * (len - 1) % mod * hf % mod * d % mod + 2ll * mod) %
         mod * qpow(len, mod - 2) % mod;
    if (a0) {
      x = 1ll * d * qpow(a0, mod - 2) % mod;
      tar1 = tar2 = 0;
      for (int j = 0; j <= k1; ++j)
        tar1 = (tar1 + 1ll * qpow(x, j) * b1[0][len][j] % mod) % mod;
      for (int j = 0; j <= k2; ++j)
        tar2 = (tar2 + 1ll * qpow(x, j) * b1[1][len][j] % mod) % mod;
      tar1 = 1ll * tar1 * qpow(a0, k1) % mod;
      tar2 = 1ll * tar2 * qpow(a0, k2) % mod;
    } else {
      tar1 = 1ll * qpow(d, k1) * s1[k1][len] % mod;
      tar2 = 1ll * qpow(d, k2) * s1[k2][len] % mod;
    }
    if (cur1 == tar1 && cur2 == tar2)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
