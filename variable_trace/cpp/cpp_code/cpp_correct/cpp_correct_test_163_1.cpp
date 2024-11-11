#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <int mod>
struct modint {
  int x;
  modint(int xx = 0) : x(xx) {}
  modint(ll xx) : x(int(xx % mod)) {}
  inline friend modint operator+(modint u, const modint& v) { return u += v; }
  modint& operator+=(const modint& o) {
    if ((x += o.x) >= mod) x -= mod;
    return *this;
  }
  inline friend modint operator-(modint u, const modint& v) { return u -= v; }
  modint& operator-=(const modint& o) {
    if ((x -= o.x) < 0) x += mod;
    return *this;
  }
  inline friend modint operator*(modint u, const modint& v) { return u *= v; }
  modint& operator*=(const modint& o) { return *this = modint(1ll * x * o.x); }
  modint pow(ll exp) const {
    modint ans = 1, base = *this;
    for (; exp > 0; exp >>= 1, base *= base)
      if (exp & 1) ans *= base;
    return ans;
  }
  inline friend modint operator/(modint u, const modint& v) { return u /= v; }
  modint& operator/=(const modint& o) { return *this *= o.pow(mod - 2); }
};
using mint = modint<(int)1e9 + 7>;
void solve() {
  ll n, m, ax, ay, bx, by;
  mint p;
  cin >> n >> m >> ax >> ay >> bx >> by >> p.x;
  mint u = 0, v = 1;
  p = 1 - p / 100;
  int lrflag = -1, udflag = -1;
  for (int i = 0; i < 4 * (n - 1) * (m - 1); i++) {
    if (ax + udflag < 1 || ax + udflag > n) udflag = -udflag;
    if (ay + lrflag < 1 || ay + lrflag > m) lrflag = -lrflag;
    ax += udflag;
    ay += lrflag;
    u += 1;
    if (ax == bx || ay == by) {
      u *= p;
      v *= p;
    }
  }
  mint ans = u / (1 - v);
  cout << ans.x << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ll t;
  cin >> t;
  while (t--) solve();
}
