#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long ans = 1;
    long long x;
    cin >> x;
    for (long long i = 3; i <= 2 * x; i++) {
      ans *= i;
      ans %= 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
