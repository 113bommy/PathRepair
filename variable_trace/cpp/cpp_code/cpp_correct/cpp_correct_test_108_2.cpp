#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const double eps = 1e-11;
template <class T>
using vi2 = vector<vector<T>>;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
template <class T>
T fp(T a, int b) {
  T res = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) res = res * a;
  return res;
}
struct MINT {
  int num;
  MINT(ll x = 0) {
    x %= MOD;
    if (x < 0) x += MOD;
    num = x;
  }
  inline int val() const { return num; }
  MINT inv() const { return fp(*this, MOD - 2); }
  MINT operator-() { return MINT(MOD - num); }
  MINT operator+(const MINT x) const {
    return MINT(num + x.num >= MOD ? num + x.num - MOD : num + x.num);
  }
  MINT operator-(const MINT x) const {
    return MINT(num - x.num < 0 ? num - x.num + MOD : num - x.num);
  }
  MINT operator*(const MINT x) const { return MINT(1LL * num * x.num % MOD); }
  MINT operator/(const MINT x) const { return *this * x.inv(); }
};
int main() {
  auto solve = [&]() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    vector<tuple<int, int, int>> a(n + 1);
    for (int i = 1, _i = int(n); i <= _i; i++) cin >> get<0>(a[i]);
    for (int i = 1, _i = int(n); i <= _i; i++) cin >> get<1>(a[i]);
    for (int i = 1, _i = int(n); i <= _i; i++) get<2>(a[i]) = i;
    sort(a.begin() + 1, a.end());
    vector<tuple<int, int, int>> b = a;
    auto cmp = [&](tuple<int, int, int> a, tuple<int, int, int> b) -> bool {
      return get<1>(a) < get<1>(b);
    };
    sort(b.begin() + 1, b.end(), cmp);
    vector<int> pre(n + 1), sur(n + 2);
    for (int i = 1, _i = int(n); i <= _i; i++)
      pre[i] = max(pre[i - 1], get<1>(a[i]));
    for (int i = n, _i = int(1); i >= _i; i--)
      sur[i] = max(sur[i + 1], get<1>(a[i]));
    auto chk = [&](int x) {
      int ta, tb, id;
      vector<int> vis(n + 1);
      tie(ta, tb, id) = a[x];
      int maxa = ta, maxb = pre[x];
      for (int i = 1, _i = int(x); i <= _i; i++) {
        vis[i] = 1;
      }
      int cnt1 = 1, cnt2 = 1;
      while ((cnt1 <= n && maxa >= get<0>(a[cnt1])) ||
             (cnt2 <= n && maxb >= get<1>(b[cnt2]))) {
        while (cnt1 <= n && maxa >= get<0>(a[cnt1])) {
          maxb = max(maxb, get<1>(a[cnt1]));
          cnt1++;
        }
        while (cnt2 <= n && maxb >= get<1>(b[cnt2])) {
          maxa = max(maxa, get<0>(b[cnt2]));
          cnt2++;
        }
      }
      if (cnt1 > n && cnt2 > n)
        return 1;
      else
        return 0;
    };
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = l + r >> 1;
      if (chk(mid))
        r = mid;
      else
        l = mid;
    }
    for (int i = r, _i = int(n); i <= _i; i++) ans[get<2>(a[i])] = 1;
    for (int i = 1, _i = int(n); i <= _i; i++) cout << ans[i];
    cout << endl;
  };
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
