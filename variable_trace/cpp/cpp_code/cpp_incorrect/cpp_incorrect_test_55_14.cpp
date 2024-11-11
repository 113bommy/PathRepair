#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int pwr(int a, long long b) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = 1LL * res * a % MOD;
    a = 1LL * a * a % MOD;
  }
  return res;
}
int T, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  while (T--) {
    cin >> n;
    if (n == 1) return cout << 6 << '\n', 0;
    long long x = (1 << n);
    x -= 2;
    cout << 1LL * 6 * pwr(4, x) % MOD << '\n';
  }
}
