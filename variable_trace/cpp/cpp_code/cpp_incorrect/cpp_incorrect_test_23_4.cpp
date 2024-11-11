#include <bits/stdc++.h>
using namespace std;
namespace Eddd {
inline char sc() {
  return getchar();
  static const int LEN = 100000;
  static char Buf[LEN], *OP = Buf, *ED = Buf;
  if (OP == ED) ED = (OP = Buf) + fread(Buf, 1, LEN, stdin);
  return *OP++;
}
template <class T>
void rd(T &x) {
  static int c, f;
  x = f = 0;
  while (c = sc(), c < 48)
    if (c == '-') f = 1;
  do x = (x << 3) + (x << 1) + (c ^ 48);
  while (c = sc(), c > 47);
  if (f) x = -x;
}
template <class T>
void pt(T x) {
  if (x < 0)
    putchar('-'), x = -x;
  else if (!x)
    putchar('0');
  static int Stk[30], tp = 0;
  for (; x; x /= 10) Stk[tp++] = x % 10;
  while (tp) putchar(Stk[--tp] ^ 48);
}
template <class T>
void ptk(const T &x) {
  pt(x);
  putchar(' ');
}
template <class T>
void ptn(const T &x) {
  pt(x);
  putchar('\n');
}
template <class T>
bool chkmi(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
template <class T>
bool chkmx(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
}  // namespace Eddd
using namespace Eddd;
const int Mod = 998244353;
long long Fast(long long x, int b) {
  long long t = 1;
  for (; b; b >>= 1, x = x * x % Mod) {
    if (b & 1) t = t * x % Mod;
  }
  return t;
}
const int N = 4005;
int a[N], b[N], c[N], d[N];
long long f[N][N];
int n, m;
int ST[N][22];
int len[N];
int lg2[N];
int qmx(int l, int r) {
  int k = lg2[r - l + 1];
  return min(ST[l][k], ST[r - len[k] + 1][k]);
}
int solve(int L, int R) {
  if (L > R) return 0;
  int s = qmx(L, R);
  int x = d[s];
  int l = solve(L, x - 1), cl = x - L;
  int r = solve(x + 1, R), cr = R - x;
  for (int i = (1), _t = (R - L + 1); i <= _t; ++i) f[x][i] = -2e18;
  for (int i = (0), _t = (cl); i <= _t; ++i)
    for (int j = (0), _t = (cr); j <= _t; ++j) {
      f[x][i + j] =
          max(f[x][i + j], f[l][i] + f[r][j] - 1ll * a[x] * i * j * 2);
    }
  for (int i = (0), _t = (cl); i <= _t; ++i)
    for (int j = (0), _t = (cr); j <= _t; ++j) {
      f[x][i + j + 1] =
          max(f[x][i + j + 1],
              f[l][i] + f[r][j] + m * a[x] -
                  1ll * a[x] * (1ll * i * j * 2 + i * 2 + j * 2 + 1));
    }
  return x;
}
int main() {
  rd(n);
  rd(m);
  for (int i = (1), _t = (n); i <= _t; ++i) rd(a[i]), c[i] = a[i];
  sort(c + 1, c + n + 1);
  for (int i = (1), _t = (n); i <= _t; ++i)
    b[i] = lower_bound(c + 1, c + n + 1, a[i]) - c - 1;
  for (int i = (1), _t = (n); i <= _t; ++i) d[b[i]] = i;
  for (int i = (1), _t = (n); i <= _t; ++i) ST[i][0] = b[i];
  len[0] = 1;
  lg2[1] = 0;
  for (int i = (1), _t = (20); i <= _t; ++i) len[i] = len[i - 1] << 1;
  for (int i = (2), _t = (n); i <= _t; ++i) lg2[i] = lg2[i >> 1] + 1;
  for (int j = (1), _t = (20); j <= _t; ++j)
    for (int i = (1), _t = (n); i <= _t; ++i)
      if (i + len[j - 1] <= n)
        ST[i][j] = min(ST[i][j - 1], ST[i + len[j - 1]][j - 1]);
  int p = solve(1, n);
  ptn(f[p][m]);
  return 0;
}
