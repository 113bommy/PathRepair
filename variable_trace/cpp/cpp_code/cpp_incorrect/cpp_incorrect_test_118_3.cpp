#include <bits/stdc++.h>
using namespace std;
int yh() {
  int ret = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == EOF) return -1;
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return f ? -ret : ret;
}
const int maxn = 6e5 + 5, N = 6e5 + 5, mod = 998244353;
int ksm(long long a, int b, int c = 1) {
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) {
      c = c * a % mod;
    }
  return c;
}
inline void reduce(int &x) { x += x >> 31 & mod; }
int n_, lgn_, omg_[N], inv_[N];
int inv[maxn], fac[maxn], ifac[maxn];
void FFT_init(int n) {
  for (lgn_ = 0; (1 << lgn_ <= n); ++lgn_)
    ;
  n_ = 1 << lgn_;
  int w = ksm(3, (mod - 1) >> lgn_);
  omg_[0] = 1;
  inv_[0] = 0;
  for (int i = 1; i < n_; ++i) {
    omg_[i] = (long long)omg_[i - 1] * w % mod;
    inv_[i] = (inv_[i >> 1] >> 1) | ((i & 1) << (lgn_ - 1));
  }
}
long long ww[N];
void FFT(int *a, int flag = 0) {
  for (int i = 0; i < n_; i++)
    if (i < inv_[i]) swap(a[i], a[inv_[i]]);
  for (int i = 0; i < lgn_; i++) {
    int s, t = 1 << i;
    for (int j = 0; j < t; j++) ww[j] = omg_[j << (lgn_ - i - 1)];
    for (int j = 0; j < n_; j += t << 1) {
      int *f = a + j, *g = a + j + t;
      for (int k = 0; k < t; k++) {
        s = g[k] * ww[k] % mod;
        reduce(g[k] = f[k] - s);
        reduce(f[k] += s - mod);
      }
    }
  }
  if (flag) {
    reverse(a + 1, a + n_);
    int iv = (1 - mod) / n_ + mod;
    for (int i = 0; i < n_; i++) a[i] = (long long)a[i] * iv % mod;
  }
}
void mul(int *a, int n, int *b, int m, int *c) {
  FFT_init(n + m + 1);
  for (int i = n + 1; i <= n_; i++) a[i] = 0;
  for (int i = m + 1; i <= n_; i++) b[i] = 0;
  FFT(a);
  FFT(b);
  for (int i = 0; i <= n_; i++) c[i] = (long long)a[i] * b[i] % mod;
  FFT(c, 1);
}
int n, m;
int fa[maxn];
int p[maxn];
vector<int> adj[maxn];
int u[maxn];
void dfs(int x) {
  for (int y : adj[x])
    if (y != fa[x]) {
      fa[y] = x;
      dfs(y);
      u[x]++;
    }
}
int num[50000000];
int *pool = num;
int *solve(int l, int r) {
  int *rt = pool;
  pool += 4 * (r - l + 1);
  if (l == r) {
    rt[0] = 1;
    rt[1] = u[l];
    return rt;
  }
  int mid = (l + r) >> 1;
  int *lf = solve(l, mid);
  int *rf = solve(mid + 1, r);
  mul(lf, (mid - l + 1), rf, (r - mid), rt);
  return rt;
}
int main() {
  fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
  inv[1] = 1;
  for (int i = (2), iss = (maxn - 5); i <= iss; i++) {
    fac[i] = (long long)fac[i - 1] * i % mod;
    inv[i] = (mod - (mod / i) * (long long)inv[mod % i] % mod) % mod;
    ifac[i] = (long long)ifac[i - 1] * inv[i] % mod;
  }
  n = yh();
  for (int i = (2), iss = (n); i <= iss; i++) {
    int x = yh(), y = yh();
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  int *F = solve(1, n);
  long long ans = 0, sgn = 1;
  for (int i = (0), iss = (n); i <= iss; i++) {
    ans = (ans + sgn * F[i] * fac[n - i] % mod) % mod;
    sgn = -sgn;
  }
  cout << (ans % mod + mod) % mod << '\n';
  return 0;
}
