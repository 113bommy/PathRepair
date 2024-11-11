#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  sort((a).begin(), (a).end());
  long long vic = 0;
  long long mn = a[0];
  for (long long j = 0; j < n - 1; ++j) {
    vic += (a[j] - vic);
    mn = max(mn, a[j + 1] - vic);
  }
  cout << mn << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    solve();
  }
}
