#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
    ;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, i, j, k, l, ans = 0, l1, l2, l3, g = 0;
    cin >> l1 >> l2 >> l3;
    if (l1 + l2 == l3 || l2 + l3 == l1 || l1 + l3 == l2) g = 1;
    if ((l1 == l2 && l3 % 2 == 0) || (l3 == l2 && l1 % 2 == 0) ||
        (l3 == l1 && l2 % 2 == 0))
      g = 1;
    if (g == 1)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
