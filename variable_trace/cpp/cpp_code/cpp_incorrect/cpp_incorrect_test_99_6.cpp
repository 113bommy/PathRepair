#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, x0, n;
  cin >> t;
  while (t--) {
    cin >> x0 >> n;
    if (x0 % 2 == 0) {
      if (n % 4 == 0)
        x0 = x0;
      else if (n % 4 == 1)
        x0 = x0 - n;
      else if (n % 4 == 2)
        x0 = x0 + 1;
      else if (n % 3 == 0)
        x0 = x0 + 3 + n;
    } else {
      if (n % 4 == 0)
        x0 = x0;
      else if (n % 4 == 1)
        x0 = x0 + n;
      else if (n % 4 == 2)
        x0 = x0 - 1;
      else if (n % 4 == 3)
        x0 = x0 - 1 - n;
    }
    cout << x0 << "\n";
  }
  return 0;
}
