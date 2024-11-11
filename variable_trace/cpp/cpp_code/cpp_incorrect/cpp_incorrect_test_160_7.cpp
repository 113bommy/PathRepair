#include <bits/stdc++.h>
using namespace std;
long long inf = 1000000007;
double pi = acos(-1);
long long p(long long a, long long b) {
  long long ans = 1;
  if (a < 0) a += inf;
  while (b) {
    if (b % 2 == 1) {
      ans = ((ans % inf) * (a % inf)) % inf;
    }
    a = ((a % inf) * (a % inf)) % inf;
    if (a < 0) a += inf;
    b /= 2;
  }
  return ans;
}
long long lis(vector<long long>& arr) {
  vector<long long> temp;
  for (auto i : arr) {
    if (temp.empty() || i > temp.back())
      temp.push_back(i);
    else {
      auto it = lower_bound(temp.begin(), temp.end(), i);
      *it = i;
    }
  }
  return temp.size();
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    long long n, m, r1, c1, r2, c2;
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;
    long long ans = 1e9;
    if (r1 <= r2) {
      ans = min(ans, r2 - r1);
    } else {
      ans = min(ans, r1 - r2 + 2 * (n - r1));
    }
    if (c1 <= 2) {
      ans = min(ans, c2 - c1);
    } else {
      ans = min(ans, c1 - c2 + 2 * (m - c1));
    }
    cout << ans << '\n';
  }
  return 0;
}
