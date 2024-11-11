#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long h[N], n;
bool check(long long k) {
  vector<long long> a(h, h + n);
  for (int i = n - 1; i > 1; i--) {
    if (a[i] < k) return false;
    int d = min(h[i], a[i] - k) / 3;
    a[i - 1] += d;
    a[i - 2] += d;
    a[i - 2] += d;
  }
  return a[0] >= k && a[1] >= k;
}
void solve() {
  cin >> n;
  long long MAX = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    MAX = max(MAX, h[i]);
  }
  long long l = 0;
  long long r = 1e9 + 1;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    check(mid) ? l = mid : r = mid;
  }
  cout << l << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
