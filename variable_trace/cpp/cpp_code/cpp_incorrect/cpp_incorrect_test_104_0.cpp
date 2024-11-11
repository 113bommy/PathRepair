#include <bits/stdc++.h>
using namespace std;
const int maxdouble = 0x7f;
const int mindouble = 0xfe;
const long long mod = 998244353;
double jz(int n) {
  double ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int prime(long long n) {
  if (n == 0 || n == 1) return 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int ksm(long long int a, long long int b) {
  long long int ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
inline long long mul(long long a, long long b, long long mod) {
  return (a * b - (long long)((long double)a / mod * b) * mod + mod) % mod;
}
int main(void) {
  int T, n;
  long long m;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%lld", &n, &m);
    vector<long long> a(n), b(n), A(n), B(n);
    long long l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld", &a[i], &b[i]);
      A[i] = min(a[i], m);
      B[i] = m - A[i];
      l += (a[i] - A[i]);
      r += (b[i] - B[i]);
    }
    long long minn = r - l;
    if (minn % 2 == 1) minn--;
    for (int i = 0; i < n; i++) {
      if (minn) {
        long long tmp = min(minn, min(A[i], b[i] - B[i]) * 2);
        minn -= tmp;
        A[i] -= tmp / 2;
        B[i] += tmp / 2;
      } else
        break;
    }
    l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      l += (a[i] - A[i]);
      r += (b[i] - B[i]);
    }
    cout << r - l << endl;
    for (int i = 0; i < n; i++) {
      cout << A[i] << " " << B[i] << endl;
    }
  }
  return 0;
}
