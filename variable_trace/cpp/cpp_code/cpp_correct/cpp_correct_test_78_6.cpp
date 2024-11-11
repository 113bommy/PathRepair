#include <bits/stdc++.h>
using namespace std;
int t, n, a[200005], bit[32], num;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
      cin >> num;
      int j = 1;
      while (num) {
        bit[j++] += num & 1;
        num >>= 1;
      }
    }
    int k = 0;
    for (int i = 1; i <= 31; i++) k = gcd(k, bit[i]);
    if (k == 0) {
      for (int i = 1; i <= n; i++) cout << i << " ";
    } else
      for (int i = 1; i <= k; i++) {
        if (k % i == 0) cout << i << " ";
      }
    cout << endl;
  }
  return 0;
}
