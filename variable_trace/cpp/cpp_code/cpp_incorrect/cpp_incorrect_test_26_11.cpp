#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  for (long x = 0; x < t; x++) {
    int n;
    cin >> n;
    int hold = 2 * n;
    long long ans = 1;
    if (hold == 2)
      cout << "2" << endl;
    else {
      for (int y = 3; y <= hold; y++) {
        ans *= y;
        ans %= 1000000007;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
