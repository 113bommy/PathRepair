#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e5 + 5, mod = 1e9 + 7;
const int64_t N1 = 1e18;
void solve() {
  int64_t n, m;
  cin >> n >> m;
  int64_t ans = 1e15;
  vector<int64_t> z(n);
  for (int64_t &it : z) {
    cin >> it;
  }
  sort(z.begin(), z.end());
  vector<int64_t> prf(n);
  for (int64_t i = 0; i < n; i++) {
    prf[i] = z[i];
    if (i) {
      prf[i] += prf[i - 1];
    }
  }
  int64_t gh = prf.back();
  auto plz = [&](int64_t x) {
    int64_t lo = 0, hi = n - 1, mid, curans = 2e15;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (gh - (prf[n - 1] - prf[n - 1 - mid]) - z[0] + x + x * mid <= m) {
        curans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return curans;
  };
  int64_t lo = 0, hi = 1e15;
  while (hi - lo > 3) {
    int64_t mid1 = lo + (hi - lo) / 3;
    int64_t mid2 = hi - (hi - lo) / 3;
    if (plz(z[0] - mid1) >= 2e15) {
      lo = mid1;
      continue;
    }
    if (-(mid1 + plz(z[0] - mid1)) < -(mid2 + plz(z[0] - mid2))) {
      lo = mid1;
    } else {
      hi = mid2;
    }
  }
  for (int64_t cur = lo; cur <= hi + n; cur++) {
    ans = min(ans, cur + plz(z[0] - cur));
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int64_t tq = 1;
  cin >> tq;
  for (; tq; tq--) {
    solve();
  }
}
