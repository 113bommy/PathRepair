#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 6;
const long long P = 1e9 + 7;
long long read() {
  long long an = 0, ff = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') ff = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    an = (an << 3) + (an << 1) + c - '0';
  return an * ff;
}
long long Add(long long a, long long b) {
  return a + b >= P ? a + b - P : a + b;
}
long long Sub(long long a, long long b) {
  return a - b < 0 ? a - b + P : a - b;
}
long long Mul(long long a, long long b) {
  long long res = 1ll * a * b;
  return res >= P ? res % P : res;
}
long long Pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = Mul(res, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return res;
}
long long Inv(long long a) { return Pow(a, P - 2); }
long long f[N];
signed main() {
  f[1] = f[0] = 1;
  for (long long i = 1; i <= 2e5; i++) f[i] = f[i - 1] * i % P;
  long long T = read();
  while (T--) {
    long long x = read();
    x *= 2;
    if (f[x - 1] * x < P)
      cout << f[x] / 2 << endl;
    else
      cout << f[x] * Inv(2) << endl;
  }
  return 0;
}
