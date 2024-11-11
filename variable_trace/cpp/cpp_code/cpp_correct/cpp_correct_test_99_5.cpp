#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long int x;
    long long int d;
    cin >> x >> d;
    if (d == 0) {
      cout << x << endl;
      continue;
    }
    if (abs(x) % 2 == 1) {
      x += 1;
      long long int circle = d - 1;
      x += circle / 4 * 4;
      switch (circle % 4) {
        case 1:
          x -= d;
          break;
        case 2:
          x -= d + d - 1;
          break;
        case 3:
          x -= d - 3;
          break;
        default:
          break;
      }
    } else {
      x -= 1;
      long long int circle = d - 1;
      x -= circle / 4 * 4;
      switch (circle % 4) {
        case 1:
          x += d;
          break;
        case 2:
          x += d + d - 1;
          break;
        case 3:
          x += d - 3;
          break;
        default:
          break;
      }
    }
    cout << x << endl;
  }
  return 0;
}
