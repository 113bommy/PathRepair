#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 998244353;
void bmod(int &x) { x -= mod, x += x >> 31 & mod; }
int norm(int x) { return x < 0 ? x + mod : x; }
void Add(int &x, int y) { x += y - mod, x += x >> 31 & mod; }
void Sub(int &x, int y) { x -= y, x += x >> 31 & mod; }
int inv(int x, int k = mod - 2) {
  int r = 1;
  while (k) {
    if (k & 1) r = (long long)x * r % mod;
    x = (long long)x * x % mod;
    k >>= 1;
  }
  return r;
}
const int Flen = N;
int fact[Flen], infact[Flen];
void preF(int n = Flen - 1) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (long long)fact[i - 1] * i % mod;
  infact[n] = inv(fact[n]);
  for (int i = n; i; --i) infact[i - 1] = (long long)infact[i] * i % mod;
}
int C(int x, int y) {
  return y < 0 || x < y
             ? 0
             : (long long)fact[x] * infact[y] % mod * infact[x - y] % mod;
}
int n, m;
char str[N];
int f[N], s[N];
int main() {
  preF();
  scanf("%d%d%s", &n, &m, str + 1);
  if (!m) return puts("1"), 0;
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + (str[i] -= 48);
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    f[i] = f[i - 1];
    if (str[i]) {
      while (j < i && s[i] - s[j] > m) ++j;
      if (s[i] - s[j] != m) continue;
      if (s[j])
        Add(f[i], C(i - j - 1, m));
      else
        Add(f[i], C(i - j, m) - 1);
    } else {
      if (s[i] - s[j] != m) continue;
      Add(f[i], C(i - j - 1, m - 1));
    }
  }
  printf("%d\n", f[n]);
  return 0;
}
