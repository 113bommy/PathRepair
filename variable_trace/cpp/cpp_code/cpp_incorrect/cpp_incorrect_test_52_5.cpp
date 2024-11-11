#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
bool prime[100002];
long long fr[200005];
vector<int> adj[200005];
int euler[400020];
void sieve() {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (int i = 2; i <= 100000; i++) {
    if (!prime[i]) continue;
    for (int j = 2 * i; j <= 100000; j += i) {
      prime[j] = false;
    }
  }
}
long long factorial(long long n) {
  if (n == 0) return 1;
  long long x = 1;
  for (long long i = 1; i <= n; i++) {
    x = (x * i) % mod;
  }
  return x;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y = y >> 1;
  }
  return res % mod;
}
long long modInverse(long long n) { return power(n, mod - 2); }
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return ((fr[n] % mod) *
          (modInverse(((fr[r] % mod) * (fr[n - r] % mod)) % mod) % mod) % mod);
}
void f() {
  fr[0] = 1;
  fr[1] = 1;
  for (long long i = 2; i <= 200001; i++) {
    fr[i] = (fr[i - 1] * i) % mod;
  }
}
void EULER(int k, int &ind, int par) {
  euler[ind++] = k;
  for (auto &x : adj[k]) {
    if (x != par) {
      EULER(x, ind, k);
      euler[ind++] = k;
    }
  }
}
long long power1(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    x = (x * x);
    y = y >> 1;
  }
  return res;
}
void test_case() {
  long long n, k;
  cin >> n >> k;
  if (k > 2) {
    long long ans = 0;
    for (int i = 0; i <= 30; i++) {
      if ((1 << i) & k) ans = (ans + power(n, (long long)i)) % mod;
    }
    cout << ans % mod << "\n";
  } else {
    cout << k << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases = 1, tt = 1;
  cin >> test_cases;
  while (test_cases--) {
    test_case();
  }
  return 0;
}
