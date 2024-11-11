#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int cnt[30];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
      cin >> x;
      for (int j = 0; j < 30; j++) {
        cnt[j] += bool(x & (1 << j));
      }
    }
    int g = 0;
    for (int i = 0; i < 30; i++) {
      if (cnt[i]) {
        g = gcd(g, cnt[i]);
      }
    }
    for (int k = 1; k <= n; k++) {
      if (g % k == 0) {
        cout << k << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
