#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= 2 * n; i++) {
      ans = (ans * i) % mod;
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
