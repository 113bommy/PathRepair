#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX = 1e6;
long long nod(long long x) {
  string s = to_string(x);
  return (long long)((s).size());
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  if (abs(log10((float)x1 / x2) + p1 - p2) <= 0.000001)
    cout << '=' << '\n';
  else if (log10((float)x1 / x2) + p1 - p2 > 0)
    cout << '>' << '\n';
  else
    cout << '<' << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
