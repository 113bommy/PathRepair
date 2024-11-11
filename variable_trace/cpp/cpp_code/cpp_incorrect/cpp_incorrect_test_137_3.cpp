#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pll = pair<ll, ll>;
using str = string;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
const ld PI = acos(-1);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
str Y = "YES";
str N = "NO";
map<str, bool> used;
void solve() {
  ll x, y;
  cin >> x >> y;
  str sx = "", sy = "";
  while (x) {
    ll ot = x % 2;
    sx += char('0' + ot);
    x /= 2;
  }
  reverse(((sx).begin()), ((sx).end()));
  while (y) {
    ll ot = y % 2;
    sy += char('0' + ot);
    y /= 2;
  }
  reverse(((sy).begin()), ((sy).end()));
  used[sx] = true;
  queue<str> q;
  q.push(sx);
  while (!q.empty()) {
    str nit = q.front();
    q.pop();
    str pl = nit + '1';
    reverse(((pl).begin()), ((pl).end()));
    while (pl.front() == '0') {
      pl.erase(pl.begin());
    }
    if ((ll)pl.size() <= (ll)sy.size() && !used[pl]) {
      used[pl] = true;
      q.push(pl);
    }
    str mn = nit;
    reverse(((nit).begin()), ((nit).end()));
    while (mn.front() == '0') {
      mn.erase(mn.begin());
    }
    if ((ll)mn.size() <= (ll)sy.size() && !used[mn]) {
      used[mn] = true;
      q.push(mn);
    }
  }
  if (used[sy]) {
    cout << Y;
    return;
  }
  cout << N;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  t = 1;
  for (ll i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
