#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  fast();
  long long t, z;
  cin >> t;
  for (long long z = 1; z < t + 1; z++) {
    long long x, n;
    long long ex;
    cin >> x >> n;
    if (abs(x) % 2)
      ex = x - 1;
    else
      ex = x;
    long long ans;
    if (abs(x) % 2) {
      if (n % 4 == 0)
        ans = 1;
      else if (n % 4 == 1)
        ans = n + 1;
      else if (n % 4 == 2)
        ans = 6;
      else
        ans = -n;
    } else {
      if (n % 4 == 0)
        ans = 0;
      else if (n % 4 == 1)
        ans = -n;
      else if (n % 4 == 2)
        ans = 1;
      else
        ans = n + 1;
    }
    ans += ex;
    cout << ans << "\n";
  }
}
