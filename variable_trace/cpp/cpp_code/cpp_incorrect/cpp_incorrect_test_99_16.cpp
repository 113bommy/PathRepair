#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n == 0) {
    cout << x << '\n';
    return;
  }
  if (x % 2 == 0) {
    if (n % 4 == 0) {
      cout << 0 << '\n';
      return;
    }
    if (n % 4 == 1) {
      cout << x - n << '\n';
      return;
    }
    if (n % 4 == 2) {
      cout << x + 1 << '\n';
      return;
    }
    if (n % 4 == 3) {
      cout << x + n + 1 << '\n';
      return;
    }
  }
  if (n % 4 == 0) {
    cout << 0 << '\n';
    return;
  }
  if (n % 4 == 1) {
    cout << x + n << '\n';
    return;
  }
  if (n % 4 == 2) {
    cout << x - 1 << '\n';
    return;
  }
  if (n % 4 == 3) {
    cout << x - n - 1 << '\n';
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
