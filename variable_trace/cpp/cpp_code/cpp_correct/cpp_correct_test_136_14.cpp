#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], b[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt += a[i];
    if (cnt % ((n * n + n) / 2) != 0) {
      cout << "NO" << endl;
      continue;
    }
    cnt /= (n * n + n) / 2;
    bool flag = 1;
    for (int i = n; i <= 2 * n - 1; i++)
      if ((a[(i - 1) % n + 1] - a[i % n + 1] + cnt) % n == 0 &&
          (a[(i - 1) % n + 1] - a[i % n + 1] + cnt) > 0)
        b[i - n + 1] = (a[(i - 1) % n + 1] - a[i % n + 1] + cnt) / n;
      else
        flag = 0;
    if (flag == 1) {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) cout << b[i] << " ";
      cout << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
