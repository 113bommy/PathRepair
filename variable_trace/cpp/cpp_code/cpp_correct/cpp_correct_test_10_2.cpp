#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ksm(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
signed main() {
  long long n, m, all, a, b, q, w, e, r;
  scanf("%lld%lld%lld%lld%lld", &n, &m, &all, &a, &b);
  scanf("%lld%lld%lld%lld", &q, &w, &e, &r);
  long long sg = n * m - a * b;
  sg = sg % (mod - 1);
  if (q == e && w == r) {
    sg += a * b;
  } else {
  }
  printf("%lld\n", ksm(all, sg, mod));
  return 0;
}
