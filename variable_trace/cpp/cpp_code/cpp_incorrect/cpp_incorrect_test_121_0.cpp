#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, INF = 1e9;
const long long N = 2e5 + 1;
const double ep = 1e-10;
const double pi = 3.141592653589793238;
void floyd() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long a1 = 0, a2 = 0, k = 0, ans = INF, in = -1, in2 = -1;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '1') a1++;
    if (b[i] == '1') a2++;
    if (a[i] == '1' && b[i] == '0') {
      k++;
      in2 = i;
    }
    if (a[i] == '1' && b[i] == '1') {
      in = i;
    }
  }
  if (a1 != a2 && (n - a1 + 1) != a2) {
    cout << -1 << '\n';
    return;
  }
  if (a1 == a2) {
    ans = min(k * 2, INF);
  }
  string t = a;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '1')
      a[i] = '0';
    else
      a[i] = '1';
  }
  if (in != -1) {
    a[in] = '1';
    long long k1 = 0, k2 = 0, k3 = 0, d = INF;
    for (long long i = 0; i < n; i++) {
      if (a[i] == '1') k1++;
      if (b[i] == '1') k2++;
      if (a[i] == '1' && b[i] == '0') {
        k3++;
      }
    }
    if (k1 == k2) {
      d = k3 * 2 + 1;
    }
    ans = min(ans, d);
  }
  for (long long i = 0; i < n; i++) {
    if (t[i] == '1')
      t[i] = '0';
    else
      t[i] = '1';
  }
  if (in2 != -1) {
    t[in2] = '1';
    long long k1 = 0, k2 = 0, k3 = 0, d = INF;
    for (long long i = 0; i < n; i++) {
      if (t[i] == '1') k1++;
      if (t[i] == '1') k2++;
      if (t[i] == '1' && b[i] == '0') {
        k3++;
      }
    }
    if (a1 == a2) {
      d = k3 * 2 + 1;
    }
    ans = min(ans, d);
  }
  if (ans == INF) {
    cout << -1 << '\n';
    return;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    floyd();
  }
  return 0;
}
