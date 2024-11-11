#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amn(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amx(T &x, U y) {
  if (x < y) x = y;
}
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long N = 5e5 + 5;
long long top(long long x, long long y) {
  long long f = x / y;
  if (x % y) f++;
  return f;
}
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return a.first < b.first;
}
void solve() {
  long long n, m, x;
  cin >> n >> m >> x;
  vector<pair<long long, long long> > v;
  for (long long i = 1; i <= n; i++) {
    v.push_back({0, i});
  }
  long long sa = top(n, m), sb = n / m;
  long long A = (n % m) * sa;
  for (long long i = 1; i <= x; i++) {
    for (long long j = 0; j < A; j++) {
      v[j].first++;
    }
    for (long long j = 0; j < A; j += sa) {
      cout << sa;
      for (long long k = j; k < j + sa; k++) {
        cout << " " << v[k].second;
      }
      cout << endl;
    }
    for (long long j = A; j < n; j += sb) {
      cout << sb;
      for (long long k = j; k < j + sb; k++) {
        cout << " " << v[k].second;
      }
      cout << endl;
    }
    sort(v.begin(), v.end(), cmp);
  }
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
  return 0;
}
