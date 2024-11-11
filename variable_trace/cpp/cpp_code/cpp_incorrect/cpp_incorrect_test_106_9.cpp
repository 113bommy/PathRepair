#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool isPowerOfTwo(long long n) {
  if ((n & (n - 1)) == 0) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}
