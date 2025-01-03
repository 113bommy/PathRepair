#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 200000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
ll qp(ll a, ll k) {
  ll res = 1;
  while (k) {
    if (k & 1) res = res * a % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return res;
}
const int K = 52;
int a[maxn + 5];
int ps[maxn + 5], hx[maxn + 5], si[maxn + 5][K + 5];
int binom[K + 5][K + 5];
int inv[maxn + 5];
inline void chadd(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void chsub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
inline int Madd(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int Msub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }
int main() {
  for (auto i = 0; i <= K; i++) binom[i][0] = 1;
  for (auto i = 1; i <= K; i++)
    for (auto j = 1; j <= i; j++)
      binom[i][j] = Madd(binom[i - 1][j - 1], binom[i - 1][j]);
  inv[1] = 1;
  for (auto i = 2; i <= maxn; i++)
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
  si[0][0] = 1;
  for (auto i = 1; i <= maxn; i++) {
    int p = 1;
    for (auto k = 0; k <= K; k++)
      si[i][k] = Madd(si[i - 1][k], p), p = 1ll * p * i % mod;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (auto i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (auto i = 1; i <= n; i++) ps[i] = Madd(ps[i - 1], a[i]);
  for (auto i = 1; i <= n; i++) hx[i] = Madd(hx[i - 1], qp(a[i], K));
  for (auto i = 1; i <= m; i++) {
    int l, r, D;
    scanf("%d%d%d", &l, &r, &D);
    int sum = Msub(ps[r], ps[l - 1]);
    int N = r - l + 1;
    chsub(sum, 1ll * N * (N - 1) / 2 % mod * D % mod);
    int x0 = 1ll * sum * inv[N] % mod;
    x0 = 1ll * x0 * qp(D, mod - 2) % mod;
    int S = 0, p = 1;
    for (auto k = 0; k <= K; k++) {
      S = (S + 1ll * p * binom[K][k] % mod * si[N - 1][K - k]) % mod;
      p = 1ll * p * x0 % mod;
    }
    if (1ll * S * qp(D, K) % mod == Msub(hx[r], hx[l - 1]))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
