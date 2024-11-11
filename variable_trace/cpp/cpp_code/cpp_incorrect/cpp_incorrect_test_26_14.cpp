#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t) {
    const long long m = 1e9 + 7;
    long long n;
    cin >> n;
    long long no = 2 * n;
    long long ans = 1;
    for (long long i = 1; i <= no; i++) {
      ans = ((ans % m) * (i % m)) % m;
    }
    cout << (ans / 2) << "\n";
    t--;
  }
  return 0;
}
