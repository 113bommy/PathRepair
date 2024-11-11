#include <bits/stdc++.h>
using namespace std;
void _init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long int lcm(long long int x, long long int y) {
  long long int e = gcd(x, y);
  return (x * y) / e;
}
bool isprime(int n) {
  if (n == 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 1; i <= n / 2; i++) {
    cout << a[i] << " " << a[0] << "\n";
  }
}
int main() {
  _init();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
