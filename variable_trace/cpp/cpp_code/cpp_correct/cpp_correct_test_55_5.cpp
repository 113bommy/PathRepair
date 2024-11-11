#include <bits/stdc++.h>
using namespace std;
long long bexp(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long k = bexp(2, n, 3e18);
  k -= 2;
  long long s = bexp(4, k, 1000000007);
  long long ans = (6 * s) % 1000000007;
  cout << ans;
}
