#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll s, n, k;
    cin >> s >> n >> k;
    if (s == k) {
      cout << "YES\n";
      continue;
    }
    if (s < k) {
      cout << "NO\n";
      continue;
    }
    int u = s - n;
    int v = (n / k) * k;
    if (u < v)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
