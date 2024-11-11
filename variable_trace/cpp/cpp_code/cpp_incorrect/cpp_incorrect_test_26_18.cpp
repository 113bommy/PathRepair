#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[2000001];
long long a[200005];
bool is_prime[2000001];
void seive(long long N) {
  for (long long i = 0; i < N; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i * i <= N; i++) {
    if (is_prime[i] == true) {
      for (long long j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  long long x = a[2 * n] / 2;
  cout << x;
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 200005; i++) {
    a[i] = 1;
  }
  for (long long i = 2; i < 200005; i++) {
    a[i] = (a[i - 1] * i) % MOD;
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
  return 0;
}
