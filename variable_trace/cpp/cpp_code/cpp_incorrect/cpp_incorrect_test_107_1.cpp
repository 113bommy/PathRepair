#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a, b;
void solve() {
  int num1 = 1, num2 = n;
  if (n == 2 && (a != 0 || b != 0)) {
    cout << -1 << '\n';
    return;
  }
  if (abs(a - b) > 1) {
    cout << -1 << '\n';
    return;
  }
  if (a == b) {
    int cnt = 2 * a + 1;
    if (n < cnt) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1)
        cout << num1++ << ' ';
      else
        cout << num2-- << ' ';
    }
    for (int i = cnt + 1; i <= n; i++) {
      cout << num1++ << ' ';
    }
    cout << '\n';
    return;
  }
  if (a > b) {
    int cnt = 2 * a;
    if (n < cnt) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1)
        cout << num1++ << ' ';
      else
        cout << num2-- << ' ';
    }
    for (int i = cnt + 1; i <= n; i++) {
      cout << num2-- << ' ';
    }
    cout << '\n';
    return;
  }
  if (a < b) {
    int cnt = b * 2;
    if (n < cnt) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (!(i & 1))
        cout << num1++ << ' ';
      else
        cout << num2-- << ' ';
    }
    for (int i = cnt + 1; i <= n; i++) {
      cout << num1++ << ' ';
    }
    cout << '\n';
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    solve();
  }
  return 0;
}
