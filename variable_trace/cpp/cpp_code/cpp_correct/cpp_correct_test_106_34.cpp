#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  for (long long i = 2; i <= n + 1; i++) cout << i << " ";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
