#include <bits/stdc++.h>
using namespace std;
long long T, n, ans[1000005], a[1000005];
long long sum;
signed main() {
  cin >> T;
  while (T--) {
    cin >> n;
    sum = 0;
    for (long long i = 0; i < n; i++) cin >> a[i], sum += a[i];
    if (sum % ((n + 1) * n / 2) != 0) {
      puts("NO");
      continue;
    }
    bool flag = 1;
    sum /= (n + 1) * n / 2;
    for (long long i = 0; i < n; i++) {
      if ((a[i] - a[(i + 1) % n] + sum) % n ||
          a[i] - a[(i + 1) % n] + sum <= 0) {
        puts("NO");
        flag = 0;
        break;
      } else
        ans[i] = (a[i] - a[(i + 1) % n] + sum) / n;
    }
    if (!flag) continue;
    puts("YES");
    for (long long i = 0; i < n; i++) cout << ans[(i - 1 + n) % n] << ' ';
    cout << endl;
    sum = 0;
  }
}
