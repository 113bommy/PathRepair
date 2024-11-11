#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a[8];
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    cout << a[0] << " " << a[1] << " " << a[6] - (a[0] + a[1]) << endl;
  }
  return 0;
}
