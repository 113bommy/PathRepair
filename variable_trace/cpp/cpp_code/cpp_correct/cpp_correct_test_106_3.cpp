#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long qs(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 2; i <= n + 1; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
