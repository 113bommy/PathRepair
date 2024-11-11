#include <bits/stdc++.h>
using namespace std;
long long int a[500005], b[500005], c[500005], d[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j, k, n, m, w, y, z, x, l, r, k1, k2;
  cin >> t;
  while (t--) {
    cin >> n;
    x = 0;
    for (i = 1; i <= n; i++) cin >> b[i], x += b[i];
    y = (n * (n + 1)) / 2;
    if (x % y != 0) {
      cout << "NO" << endl;
      continue;
    }
    x /= y;
    z = 0;
    for (i = 1; i <= n; i++) {
      y = x + b[((i + n - 2) % n) + 1] - b[i];
      if (y <= 0 || (y % n != 0)) {
        z = 1;
        break;
      }
      a[i] = y / n;
    }
    if (z)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (i = 1; i <= n; i++) cout << a[i] << " ";
      cout << endl;
    }
  }
}
