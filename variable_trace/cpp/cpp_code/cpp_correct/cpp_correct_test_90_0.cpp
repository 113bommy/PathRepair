#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  ll a, b;
  cin >> a >> b;
  a /= 2, b /= 2;
  if (a > b)
    cout << 2 * (a + b) << '\n';
  else if (a == b)
    cout << 2 * a << '\n';
  else
    cout << (2 * b - b % a) << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  ll t = 1;
  cin >> t;
  while (t--) solve();
}
