#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 109, inf = 1e9;
const long double pi = acos(-1);
int n, k;
int x[N], y[N];
bool solve(long double r) {
  vector<pair<long double, int> > ranges;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    long double theta = fmod(atan2(y[i], x[i]) + 2 * pi, 2 * pi);
    if (1ll * x[i] * x[i] + 1ll * y[i] * y[i] >
        2 * r * (x[i] * cos(theta) + y[i] * sin(theta)))
      continue;
    long double low = acos(sqrt(x[i] * x[i] + y[i] * y[i]) / (2 * r));
    long double L = theta - low, R = theta + low;
    R = fmod(R + 2 * pi, 2 * pi);
    if (L < 0) {
      L += 2 * pi;
    }
    if (L <= R) {
      ranges.push_back({L, 1});
      ranges.push_back({R, 2});
    } else {
      ranges.push_back({L, 1});
      ranges.push_back({2 * pi, 2});
      ranges.push_back({0, 1});
      ranges.push_back({R, 2});
    }
  }
  sort(ranges.begin(), ranges.end());
  cnt = 0;
  for (auto i : ranges) {
    if (i.second == 1)
      cnt++;
    else
      cnt--;
    if (cnt >= k) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  long double low = 0, high = 2e6;
  for (int i = 0; i < 50; i++) {
    long double m = (low + high) / 2;
    if (solve(m))
      high = m;
    else
      low = m;
  }
  if (low > 1.5e6) return cout << -1, 0;
  cout << fixed << low;
}
