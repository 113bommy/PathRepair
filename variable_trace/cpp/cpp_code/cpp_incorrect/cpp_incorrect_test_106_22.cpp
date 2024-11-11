#include <bits/stdc++.h>
using namespace std;
template <typename T>
static inline void sd(vector<T> &x) {
  sort((x).begin(), (x).end(), greater<T>());
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cout << i << " ";
  cout << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
