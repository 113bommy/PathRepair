#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long fast_pow(long long n, long long k) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 1) {
    long long res = fast_pow(n, k / 2) % mod;
    return (res * res * n) % mod;
  } else {
    long long res = fast_pow(n, k / 2) % mod;
    return (res * res) % mod;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    bitset<32> num(k);
    long long res = 0;
    for (long long i = 31; i >= 0; --i) {
      if (num[i] == 1) {
        res += fast_pow(n, i);
        res %= mod;
      }
    }
    cout << res % mod << endl;
  }
}
