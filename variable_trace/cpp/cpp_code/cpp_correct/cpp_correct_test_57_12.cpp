#include <bits/stdc++.h>
using namespace std;
int t;
long long s, n, k;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  for (cin >> t; t--;) {
    cin >> s >> n >> k;
    if (s == k)
      cout << "YES\n";
    else if (k > s || 2 * n - n % k <= s)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
