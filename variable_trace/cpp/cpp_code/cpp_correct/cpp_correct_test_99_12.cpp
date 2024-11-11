#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const long long int INF = 1e18;
void solve() {
  long long int a, b, jump = 0;
  cin >> a >> b;
  if (b > 0) {
    jump = 1;
    long long int t = (b - 1) / 4;
    jump += t * 4;
    long long int q = (b - 1) % 4;
    if (q == 1)
      jump -= b;
    else if (q == 2)
      jump += -2 * b + 1;
    else if (q == 3)
      jump += -b + 3;
  }
  if (a % 2)
    a += jump;
  else
    a -= jump;
  cout << a << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
}
