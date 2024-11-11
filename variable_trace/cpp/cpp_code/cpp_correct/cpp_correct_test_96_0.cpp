#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long A[510][510], nck[510][510];
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return a * b % mod; }
long long po(long long a, long long b) {
  long long re = 1;
  while (b) {
    if (b & 1) {
      re = mul(re, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return re;
}
long long solve(long long n, long long x) {
  if (A[n][x]) return A[n][x];
  long long re = po(min(n - 1, x), n);
  if (x - n + 1 >= 1) {
    for (long long k = 2; k <= n; k++) {
      re = add(mul(mul(nck[n][k], po(n - 1, n - k)), solve(k, x - n + 1)), re);
    }
  }
  A[n][x] = re;
  return A[n][x];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x;
  cin >> n >> x;
  for (long long i = 0; i <= n; i++) {
    for (long long k = 0; k <= i; k++) {
      if (k == 0) {
        nck[i][k] = 1;
      } else {
        nck[i][k] = add(nck[i - 1][k], nck[i - 1][k - 1]);
      }
    }
  }
  cout << solve(n, x) << "\n";
}
