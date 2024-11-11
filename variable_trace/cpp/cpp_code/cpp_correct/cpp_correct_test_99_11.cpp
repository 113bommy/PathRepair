#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (x % 2 == 0) {
      if (y % 4 == 0) {
        cout << x << endl;
      } else if (y % 4 == 1) {
        cout << x - y << endl;
      } else if (y % 4 == 2) {
        cout << x + 1 << endl;
      } else if (y % 4 == 3) {
        cout << (x + 1) + y << endl;
      }
    } else {
      if (y % 4 == 0) {
        cout << x << endl;
      } else if (y % 4 == 1) {
        cout << x + y << endl;
      } else if (y % 4 == 2) {
        cout << x - 1 << endl;
      } else if (y % 4 == 3) {
        cout << (x - 1) - y << endl;
      }
    }
  }
  return 0;
}
