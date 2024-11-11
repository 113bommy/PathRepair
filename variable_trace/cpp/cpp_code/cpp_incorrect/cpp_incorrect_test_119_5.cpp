#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using vi = vector<int>;
using vl = vector<ll>;
const int MOD = 1e9 + 7;
const int MX = 1e5 + 10;
const ll BIG = 1e18;
using pi = pair<int, int>;
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int main() {
  setIO();
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = (0); i < (n); ++i) cin >> a[i];
    sort(begin(a), end(a));
    ll second = 0;
    for (int i = (0); i < (n); ++i) {
      second += a[i] - a[0];
    }
    if (second % 2 == 0)
      cout << "0\n";
    else
      cout << "1\n";
  }
  return 0;
}
