#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int rb, cb, rd, cd;
    cin >> rb >> cb >> rd >> cd;
    int x1, x2;
    if (rb <= rd) {
      x1 = rd - rb;
    } else if (rb > rd) {
      x1 = 2 * (n)-rb - rd;
    }
    if (cb <= cd) {
      x2 = cd - cb;
    } else if (cb > cd) {
      x2 = 2 * (m)-cb - cd;
    }
    if (x1 < x2) {
      cout << x1 << endl;
    } else
      cout << x2 << endl;
  }
  return 0;
}
