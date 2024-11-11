#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, unsigned long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long one(long long x, long long y) {
  long long s = (x + 1) / power(2, y);
  if (s % 2 == 0) {
    return s / 2 * power(2, y);
  } else {
    return (s / 2 * power(2, y)) + ((x + 1) % power(2, y));
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> s;
    long long x = sqrt(n);
    for (long long i = 1; i <= x; i++) {
      if (i * i <= n) {
        s.insert(i * i);
      }
      if (i * i * i <= n) {
        s.insert(i * i * i);
      }
    }
    cout << s.size() << endl;
  }
}
