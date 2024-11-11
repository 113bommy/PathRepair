#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x > y) {
      cout << x + y << "\n";
    } else {
      cout << y - (y % x) / 2 << "\n";
    }
  }
}
