#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main() {
  int n, i, j, l, t, z, a;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  for (z = 1; z <= t; z++) {
    cin >> n;
    int maxim = 0;
    int cnt = 0;
    for (i = 1; i <= n; i++) {
      cin >> v[i];
    }
    for (i = 2; i <= n; i++) {
      if (v[i] < v[i - 1]) {
        cnt = 1;
      }
    }
    if (n % 2 == 0) {
      cout << "Yes";
    } else {
      if (cnt == 1) {
        cout << "Yes";
      } else {
        cout << "NO";
      }
    }
    cout << '\n';
  }
  return 0;
}
