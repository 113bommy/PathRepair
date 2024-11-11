#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353, mod2 = 1004535809, mod3 = 469762049, g1 = 3;
const long long M = 1LL * mod1 * mod2;
long long a[100010], b[100010], c[100010], d[100010];
map<int, int> p;
long long inv(long long x) {
  if (x == 1)
    return x;
  else
    return inv(1000000007 % x) * (1000000007 - 1000000007 / x) % 1000000007;
}
int rev[300005], limit = 1, l;
long long f[3][300005], g[3][300005], as[300005];
inline long long mul(long long x, int k, long long mOD) {
  long long ret = 0;
  while (k) {
    if (k & 1) (ret += x) %= mOD;
    (x += x) %= mOD;
    k >>= 1;
  }
  return ret % mOD;
}
inline long long qpow(long long x, int k, int mOD) {
  long long ret = 1;
  while (k) {
    if (k & 1) ret = ret * x % mOD;
    x = x * x % mOD;
    k >>= 1;
  }
  return ret % mOD;
}
void NTT(long long *x, int opt, int P) {
  int lim = limit;
  int i, j, k, m, gn, g, tmp;
  for (i = 0; i < lim; ++i)
    if (rev[i] < i) swap(x[i], x[rev[i]]);
  for (m = 2; m <= lim; m <<= 1) {
    k = m >> 1;
    gn = qpow(3, (P - 1) / m, P);
    for (i = 0; i < lim; i += m) {
      g = 1;
      for (j = 0; j < k; ++j, g = 1ll * g * gn % P) {
        tmp = 1ll * x[i + j + k] * g % P;
        x[i + j + k] = (x[i + j] - tmp + P) % P;
        x[i + j] = (x[i + j] + tmp) % P;
      }
    }
  }
  if (opt == -1) {
    reverse(x + 1, x + lim);
    int inv = qpow(lim, P - 2, P);
    for (i = 0; i < lim; ++i) x[i] = 1ll * x[i] * inv % P;
  }
}
inline void CRT() {
  for (int i = 0; i < limit; i++) {
    long long tmp = 0;
    (tmp += mul(f[0][i] * mod2 % M, qpow(mod2, mod1 - 2, mod1), M)) %= M;
    (tmp += mul(f[1][i] * mod1 % M, qpow(mod1, mod2 - 2, mod2), M)) %= M;
    f[1][i] = tmp;
  }
  for (int i = 0; i < limit; i++) {
    long long tmp = (f[2][i] - f[1][i] % mod3 + mod3) % mod3 *
                    qpow(M % mod3, mod3 - 2, mod3) % mod3;
    as[i] =
        (M % 1000000007 * tmp % 1000000007 + f[1][i] % 1000000007) % 1000000007;
  }
}
inline void solve(int x, int mOD) {
  NTT(f[x], 1, mOD);
  NTT(g[x], 1, mOD);
  for (int i = 0; i < limit; i++) f[x][i] = f[x][i] * g[x][i] % mOD;
  NTT(f[x], -1, mOD);
}
long long inv2[100010], jie[100010], ijie[100010];
long long C(long long n, long long m) {
  return (ijie[n - m] * ijie[m] % 1000000007) * jie[n] % 1000000007;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j, k, m, n, t, k1;
  long long x, y, z, w, ans;
  inv2[1] = 1;
  jie[0] = jie[1] = 1;
  ijie[0] = ijie[1] = 1;
  for (i = 2; i <= 100000; i++) {
    inv2[i] = inv2[1000000007 % i] * (1000000007 - 1000000007 / i) % 1000000007;
    jie[i] = jie[i - 1] * i % 1000000007;
    ijie[i] = ijie[i - 1] * inv2[i] % 1000000007;
  }
  cin >> n >> k;
  m = 1;
  for (i = 0; i < n; i++) {
    cin >> k1;
    if (k1 == -1)
      a[0]++;
    else if (!p.count(k1)) {
      p[k1] = m;
      a[m] = 1;
      m++;
    } else {
      a[p[k1]]++;
    }
  }
  for (i = 1; i < m; i++) {
    c[a[i]]++;
  }
  c[0] = k - m + 1;
  for (i = 0; i <= n; i++) {
    for (j = 0; j < 3; j++) {
      f[j][i] = c[i];
    }
  }
  for (i = 0; i <= a[0]; i++) {
    k1 = (C(a[0], i) * qpow(inv(k), i, 1000000007) % 1000000007) *
         qpow((1000000007 + 1 - inv(k)) % 1000000007, a[0] - i, 1000000007) %
         1000000007;
    for (j = 0; j < 3; j++) {
      g[j][i] = k1;
    }
  }
  l = 0;
  while (limit <= a[0] + n) limit <<= 1, ++l;
  for (int i = 0; i < limit; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
  solve(0, mod1);
  solve(1, mod2);
  solve(2, mod3);
  CRT();
  y = 1;
  w = 1;
  for (i = 1; i < n; i++) {
    y = (((y * i % 1000000007) * (k - 1) % 1000000007) * inv2[n - i] %
         1000000007) +
        n * inv2[n - i] % 1000000007;
    w = (w + y) % 1000000007;
  }
  x = (1000000007 - w) * inv(k) % 1000000007;
  b[0] = x;
  y = 1;
  for (i = 1; i < n; i++) {
    b[i] = (b[i - 1] + y) % 1000000007;
    y = (((y * i % 1000000007) * (k - 1) % 1000000007) * inv2[n - i] %
         1000000007) +
        n * inv2[n - i] % 1000000007;
  }
  b[n] = (b[n - 1] + y) % 1000000007;
  ans = 0;
  for (i = 0; i <= n; i++) {
    ans = (ans + as[i] * b[i]) % 1000000007;
  }
  cout << (1000000007 - ans) % 1000000007;
  return 0;
}
