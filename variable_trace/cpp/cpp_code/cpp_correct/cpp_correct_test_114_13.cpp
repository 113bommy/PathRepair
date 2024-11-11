#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 1;
ll t, n, m, k, a, b, c, f, ans;
ll d[N], fa[N], x[N];
vector<ll> g[N];
string S;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + n + 1);
    for (ll i = 2; i <= n + 2 >> 1; i++) cout << x[i] << ' ' << x[1] << '\n';
  }
}
