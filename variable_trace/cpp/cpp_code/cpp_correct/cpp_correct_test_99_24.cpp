#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n == 0) {
    cout << x << '\n';
    return;
  }
  if ((x & 1)) {
    if (n % 2 != 0) {
      long long diff = 1 + n;
      if (diff % 4 == 0) {
        cout << x - diff << '\n';
      } else {
        cout << x + n << '\n';
      }
    } else {
      if (n % 4 == 0) {
        cout << x << '\n';
      } else {
        cout << x - 1 << '\n';
      }
    }
  } else {
    if (n == 1) {
      cout << x - 1 << '\n';
      return;
    }
    if (n % 2 != 0) {
      long long diff = abs(1 - n);
      if (diff % 4 == 0) {
        cout << x - n << '\n';
      } else {
        cout << x + n + 1 << '\n';
      }
    } else {
      if (n % 4 == 0) {
        cout << x << '\n';
      } else {
        cout << x + 1 << '\n';
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
