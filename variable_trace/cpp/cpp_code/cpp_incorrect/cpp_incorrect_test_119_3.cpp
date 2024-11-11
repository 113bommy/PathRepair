#include <bits/stdc++.h>
using lli = long long int;
using li = long int;
using namespace std;
const lli MOD{998244353};
const lli INF{(false ? (INT_MAX - 1) / 2 : (lli)1e18 + 5)};
const lli N{200005};
int main() {
  cout << setprecision(15);
  cin.tie(nullptr)->sync_with_stdio(false);
  li T{1};
  cin >> T;
  while (T--) {
    lli n{};
    cin >> n;
    vector<lli> arr(n);
    lli sum{};
    for (auto &i : arr) cin >> i, sum += i;
    if (sum & 1)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}
