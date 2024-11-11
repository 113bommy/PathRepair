#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> ls(n);
  for (int i = 0; i < n; i++) cin >> ls[i];
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += ls[i];
  if (sum % (n * (n + 1) / 2) != 0) {
    cout << "NO" << '\n';
    return;
  }
  int s = sum / (n * (n + 1) / 2);
  vector<long long> ans(n);
  for (int i = 0; i < n; i++) {
    long long k = ls[i] - s;
    long long j = ((i - 1 + n) % n);
    long long y = ls[j] - k;
    if (y == 0 or y % n) {
      cout << "NO" << '\n';
      return;
    }
    ans[i] = y / n;
  }
  cout << "YES" << '\n';
  for (auto i : ans) cout << i << " ";
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
