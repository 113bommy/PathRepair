#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, sum = 0, c = 0, mn = INT_MIN, m;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if (n == 2) {
      cout << max(a[0], a[1] - a[0]) << endl;
    } else {
      for (long long i = 0; i < n - 1; i++) {
        m = a[i + 1] - a[i];
        mn = max(m, mn);
      }
      mn = max(mn, a[0]);
      cout << mn << endl;
    }
  }
}
