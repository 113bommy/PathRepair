#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, ans = 1;
    cin >> a;
    a *= 2;
    for (long long i = 3; i <= a; i++) {
      ans = (ans * i) % mod;
    }
    cout << ans << "\n";
  }
}
