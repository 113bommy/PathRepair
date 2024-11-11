#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  cin >> T;
  while (T--) {
    long long x, y;
    cin >> x >> y;
    long long ans = y % 4;
    long long cnt = 0;
    if (x % 2 == 0) {
      if (ans == 0) {
        cnt = x;
      }
      if (ans == 1) {
        cnt = x - y;
      }
      if (ans == 2) {
        cnt = x + 1;
      }
      if (ans == 3) {
        cnt = x + 1 + y;
      }
    } else {
      if (ans == 0) {
        cnt = x;
      }
      if (ans == 1) {
        cnt = x + y;
      }
      if (ans == 2) {
        cnt = x - 1;
      }
      if (ans == 3) {
        cnt = x - y - 1;
      }
    }
    cout << cnt << endl;
  }
}
