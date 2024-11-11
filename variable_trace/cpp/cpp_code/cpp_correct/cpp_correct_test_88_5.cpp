#include <bits/stdc++.h>
using namespace std;
const int kMod = 1000000007;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    bool res = false;
    if (n % 2) {
      for (int i = 0; i < n - 1; i++) {
        if (v[i] >= v[i + 1]) {
          res = true;
          break;
        }
      }
    } else {
      res = true;
    }
    cout << ((res) ? "YES\n" : "NO\n");
  }
}
