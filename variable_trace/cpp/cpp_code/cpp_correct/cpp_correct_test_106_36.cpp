#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << i + 1 << ' ';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
