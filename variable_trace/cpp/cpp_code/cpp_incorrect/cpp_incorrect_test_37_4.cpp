#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long find[n + 1];
    memset(find, 0, sizeof(find));
    for (long long i = 1; i <= n; i++) {
      long long a, b, c;
      cin >> a >> b >> c;
      find[b]++;
    }
    long long i;
    for (i = 1; i <= n; i++) {
      if (!find[i]) {
        break;
      }
    }
    for (long long j = 1; j <= n; j++) {
      if (j != i) {
        cout << i << " " << j << endl;
      }
    }
  }
  return 0;
}
