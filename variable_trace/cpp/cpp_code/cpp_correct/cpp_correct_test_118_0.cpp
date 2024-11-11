#include <bits/stdc++.h>
using namespace std;
const int M = 998244353, G = 3, N = 1 << 20;
int Pw(int x, int y = M - 2) {
  return y ? ((y & 1) ? (long long)Pw((long long)x * x % M, y / 2) * x % M
                      : Pw((long long)x * x % M, y / 2) % M)
           : 1;
}
int rt[N], mg[N], fac[N], Lm = 1;
int rev[N], a[N], iv;
void dft(int n) {
  for (int i = (0); i <= (n - 1); ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1)),
    ((i < rev[i]) && (a[i] ^= a[rev[i]] ^= a[i] ^= a[rev[i]]));
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0, l = (i >> 1); j < n; j += i)
      for (int k = 0, pa, pb, *w = rt + l; k < l; k++, w++)
        pa = a[j + k], pb = (long long)a[j + k + l] * *w % M,
        a[j + k] = (pa + pb) % M, a[j + k + l] = (pa + M - pb) % M;
  for (int i = (0); i <= (n - 1); ++i) a[i] = (long long)a[i] * iv % M;
}
int n, deg[N], cnt[N], ns, x, y, all;
int main() {
  cin >> n, fac[0] = deg[1] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = (long long)fac[i - 1] * i % M;
  for (int i = (1); i <= (n - 1); ++i) cin >> x >> y, deg[x] += 1, deg[y] += 1;
  for (int i = (1); i <= (n); ++i)
    if (deg[i] > 1) cnt[deg[i] - 1] += 1, all += 1;
  for (; Lm <= all; Lm <<= 1)
    ;
  int w = Pw(G, (M - 1) / Lm);
  mg[0] = 1, iv = Pw(Lm);
  for (int i = (1); i <= (Lm - 1); ++i) mg[i] = (long long)mg[i - 1] * w % M;
  for (int i = 1, S; i < Lm; i <<= 1) {
    S = Pw(G, M - 1 - (M - 1) / (i << 1)), rt[i] = 1;
    for (int j = (i + 1); j <= (i * 2 - 1); ++j)
      rt[j] = (long long)rt[j - 1] * S % M;
  }
  for (int i = (0); i <= (Lm - 1); ++i) a[i] = 1;
  for (int i = (1); i <= (n); ++i)
    if (cnt[i])
      for (int j = 0, *w = mg; j < Lm; j++, w++)
        a[j] = (long long)a[j] * Pw(*w + i, cnt[i]) % M;
  dft(Lm);
  for (int i = (0); i <= (all); ++i)
    (ns +=
     (long long)fac[n - i] * a[all - i] % M * ((i & 1) ? M - 1 : 1) % M) %= M;
  cout << ns << '\n';
  return 0;
}
