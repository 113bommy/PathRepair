#include <bits/stdc++.h>
using namespace std;
int a[7];
int main() {
  int n;
  cin >> n;
  while (n--) {
    for (int i = 0; i <= 7; i++) {
      cin >> a[i];
    }
    if ((a[6] - a[0]) - a[1] == a[2]) {
      cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
      continue;
    }
    if ((a[6] - a[0]) - a[1] == a[3]) {
      cout << a[0] << ' ' << a[1] << ' ' << a[3] << '\n';
      continue;
    }
  }
}
