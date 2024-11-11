#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (s == k) {
    cout << "YES\n";
    return;
  }
  long long num = s / (k * 2) * k, ost = s % (k * 2);
  long long mn = min(ost + 1, k);
  if (n + 1 > mn + num)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
