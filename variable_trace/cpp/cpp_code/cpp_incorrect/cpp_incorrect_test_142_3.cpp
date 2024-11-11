#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long my[N];
long long m, n;
vector<vector<long long>> a;
bool check(long long mid) {
  for (long long(i) = (0); (i) <= (n - 1); (i)++)
    if (my[i] < mid) return 1;
  for (long long(i) = (0); (i) <= (m - 1); (i)++) {
    long long cnt = 0;
    for (long long(j) = (0); (j) <= (n - 1); (j)++) {
      if (a[i][j] >= mid) cnt++;
    }
    if (cnt > 1) return 0;
  }
  return 1;
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> m >> n;
    a.clear();
    a.resize(m, vector<long long>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lld", &a[i][j]);
        my[j] = max(my[j], a[i][j]);
      }
    }
    long long mid, l = 0, r = 1e9;
    while (l < r - 1) {
      mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    cout << l << endl;
    for (long long(i) = (1); (i) <= (n); (i)++) my[i] = 0;
  }
  return 0;
}
