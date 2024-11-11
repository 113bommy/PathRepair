#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int t, n;
long long a[N], b[N], m[N], lo[N], hi[N], ans[N];
long long solve(vector<tuple<long long, long long, int>> vec) {
  long long ret = 0;
  sort(vec.begin(), vec.end());
  for (int i = 0, j = 0; i < vec.size(); i = j) {
    auto [r, l, id] = vec[i];
    ++ret;
    while (j < vec.size()) {
      auto [new_r, new_l, new_id] = vec[j++];
      if (new_l > r) break;
      ans[new_id] = r;
    }
  }
  return ret;
}
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    map<long long, vector<tuple<long long, long long, int>>> f;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld %lld", a + i, b + i, m + i);
      b[i] -= m[i], lo[i] = max(0LL, -b[i]), hi[i] = min(m[i], a[i]);
      f[a[i] + b[i]].emplace_back(a[i] - lo[i], a[i] - hi[i], i);
    }
    long long tot = 0;
    for (auto [key, vec] : f) tot += solve(vec);
    for (int i = 1; i <= n; ++i) ans[i] = a[i] - ans[i];
    printf("%lld\n", tot);
    for (int i = 1; i <= n; ++i) printf("%lld %lld\n", ans[i], m[i] - ans[i]);
  }
  return 0;
}
