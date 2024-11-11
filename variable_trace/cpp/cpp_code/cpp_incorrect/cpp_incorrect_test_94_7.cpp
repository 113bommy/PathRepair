#include <bits/stdc++.h>
using namespace std;
long long a[15], b[15];
long long lt(long long x, long long y) {
  if (y == 0) return 1;
  long long ans = 1;
  for (long long i = 1; i <= y; i++) {
    ans *= x;
  }
  return ans;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, max = 0, ans = 0;
    cin >> n >> k;
    b[n] = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      if (i >= 2) {
        b[i - 1] = pow(10, a[i] - a[i - 1]) - 1;
        max += b[i - 1];
      }
    }
    if (max > k) {
      for (long long i = n - 1; i >= 1; i--) {
        long long sub = min(max - k - 1, b[i]);
        max -= sub;
        b[i] -= sub;
        if (max == k + 1) {
          break;
        }
      }
    } else if (max < k) {
      b[n] = k - max + 1;
    }
    for (long long i = 1; i <= n; i++) {
      ans += lt(10, a[i]) * b[i];
    }
    cout << ans << endl;
  }
  return 0;
}
