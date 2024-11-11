#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (k < 3)
      cout << "NO\n";
    else if (n == 1 && m == 0)
      cout << "YES\n";
    else if (m < n - 1 || m > (n * (n - 1)) / 2)
      cout << "NO\n";
    else {
      int d;
      if (m == (n * (n - 1)) / 2)
        d = 1;
      else
        d = 2;
      if (d < k - 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
