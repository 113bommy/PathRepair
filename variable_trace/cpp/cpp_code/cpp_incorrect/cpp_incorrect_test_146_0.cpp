#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
const ll inf = (1e18);
const ll mod = 1000000007;
const vector<int> dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll c, ll d) { return c / GCD(c, d) * d; }
struct __INIT {
  __INIT() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} __init;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
void debag(const vector<T> &a) {
  cerr << "debag :";
  for (auto v : a) cerr << v << " ";
  cerr << "\n";
}
template <class T>
void print(const vector<T> &a) {
  for (auto v : a) cout << v << " ";
  cout << "\n";
}
void solve() {
  int n, q;
  cin >> n >> q;
  int B = ll(sqrt(double(n))) + 10;
  V<int> f(n), fb(n), inv(n);
  iota((fb).begin(), (fb).end(), 0);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
  }
  for (int i = 0; i < n; i++) {
    inv[f[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < B; j++) {
      fb[f[i]] = f[fb[i]];
    }
  }
  V<bool> used(n, true);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    --x;
    --y;
    if (t == 1) {
      V<int> tmp;
      int cp = x;
      for (int j = 0; j <= B; j++) {
        tmp.emplace_back(cp);
        used[cp] = false;
        cp = inv[cp];
        if (cp == x) break;
      }
      cp = y;
      for (int j = 0; j <= B; j++) {
        tmp.emplace_back(cp);
        used[cp] = false;
        cp = inv[cp];
        if (cp == y) break;
      }
      swap(f[x], f[y]);
      swap(inv[f[x]], inv[f[y]]);
      for (int v : tmp) {
        if (!used[v]) {
          if (used[f[v]]) {
            fb[v] = inv[fb[f[v]]];
          } else {
            fb[v] = v;
            for (int j = 0; j < B; j++) {
              fb[v] = f[fb[v]];
            }
          }
          used[v] = true;
        }
      }
    } else {
      y++;
      int cur = x;
      while (B <= y) {
        cur = fb[cur];
        y -= B;
      }
      while (y > 0) {
        cur = f[cur];
        y--;
      }
      cout << cur + 1 << "\n";
    }
  }
}
int main() {
  int t = 1;
  while (t--) solve();
}
