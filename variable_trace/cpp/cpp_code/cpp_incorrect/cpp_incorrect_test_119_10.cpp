#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k, s = 0;
    for (int i = 0; i < n; i++) {
      cin >> k;
      s += k;
    }
    if (s % k == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
