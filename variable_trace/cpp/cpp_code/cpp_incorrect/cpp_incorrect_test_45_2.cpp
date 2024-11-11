#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long height = 1;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0 && a[i + 1] == 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      if (a[0] == 1) {
        height += 1;
      }
      for (int i = 1; i < n; i++) {
        if (a[i - 1] == 1 && a[i] == 1) {
          height += 5;
        } else if (a[i] == 1) {
          height += 1;
        }
      }
      cout << height << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
