#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ul = unsigned long long;
using db = double;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pd = pair<ld, ld>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long long>;
using vd = vector<ld>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <typename T, size_t size>
using va = vector<array<T, size>>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace input {
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
void re(ld& x) {
  string t;
  re(t);
  x = stold(t);
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T>
void re(complex<T>& x) {
  T a, b;
  re(a, b);
  x = cd(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < int(((int)(a).size())); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < int(SZ); i++) re(a[i]);
}
}  // namespace input
using namespace input;
namespace output {
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T, size_t SZ>
void pr(const array<T, SZ>& x);
template <class T>
void pr(const vector<T>& x);
template <class T>
void pr(const set<T>& x);
template <class T1, class T2>
void pr(const map<T1, T2>& x);
template <class T>
void pr(const T& x) {
  cout << x;
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  pr(first);
  pr(rest...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr(x.first, " ", x.second);
}
template <class T>
void prContain(const T& x) {
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? " " : "", a), fst = 0;
}
template <class T, size_t SZ>
void pr(const array<T, SZ>& x) {
  prContain(x);
}
template <class T>
void pr(const vector<T>& x) {
  prContain(x);
}
template <class T>
void pr(const set<T>& x) {
  prContain(x);
}
template <class T1, class T2>
void pr(const map<T1, T2>& x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg& first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace output
using namespace output;
namespace error {
template <class T1, class T2>
void dg(const pair<T1, T2>& x);
template <class T, size_t SZ>
void dg(const array<T, SZ>& x);
template <class T>
void dg(const vector<T>& x);
template <class T>
void dg(const set<T>& x);
template <class T1, class T2>
void dg(const map<T1, T2>& x);
template <class T>
void dg(const T& x) {
  cerr << x;
}
template <class Arg, class... Args>
void dg(const Arg& first, const Args&... rest) {
  dg(first);
  dg(rest...);
}
template <class T1, class T2>
void dg(const pair<T1, T2>& x) {
  dg(x.first, " ", x.second);
}
template <class T>
void dgContain(const T& x) {
  bool fst = 1;
  for (const auto& a : x) dg(!fst ? " " : "", a), fst = 0;
}
template <class T, size_t SZ>
void dg(const array<T, SZ>& x) {
  dgContain(x);
}
template <class T>
void dg(const vector<T>& x) {
  dgContain(x);
}
template <class T>
void dg(const set<T>& x) {
  dgContain(x);
}
template <class T1, class T2>
void dg(const map<T1, T2>& x) {
  dgContain(x);
}
void ds() { dg("\n"); }
template <class Arg>
void ds(const Arg& first) {
  dg(first);
  ds();
}
template <class Arg, class... Args>
void ds(const Arg& first, const Args&... rest) {
  dg(first, " ");
  ds(rest...);
}
}  // namespace error
using namespace error;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  dg(H);
  debug(T...);
}
inline long long modPow(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  ;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % mod;
    }
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
char dirs[4] = {'L', 'D', 'R', 'U'};
unordered_map<char, int> rdirs = {{'R', 2}, {'D', 1}, {'L', 0}, {'U', 3}};
const long long mod = 1e9 + 7;
const long long INF = 2e18 + 6;
const int MXN = 1e6 + 5;
void solve() {
  int n;
  re(n);
  vs second(n);
  re(second);
  vi delta(n), min_delta(n);
  vector<unordered_map<int, int>> mp(n);
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(((int)(second[i]).size())); j++) {
      delta[i] += (second[i][j] == '(' ? 1 : -1);
      min_delta[i] = min(min_delta[i], delta[i]);
      if (min_delta[i] == delta[i]) {
        mp[i][delta[i]]++;
      }
    }
  }
  vi dp(1 << n, -1e6);
  int ans = 0;
  dp[0] = 0;
  for (int msk = 0; msk < int(1 << n); msk++) {
    int cur = 0;
    for (int i = 0; i < int(n); i++) {
      if (msk >> i & 1) {
        cur += delta[i];
      }
    }
    if (cur >= 0)
      for (int i = 0; i < int(n); i++) {
        if ((msk >> i & 1) == 0) {
          if (cur > -min_delta[i]) {
            ckmax(dp[msk | 1 << i], dp[msk]);
          } else if (cur == -min_delta[i]) {
            ckmax(dp[msk | 1 << i], dp[msk] + mp[i][-cur]);
            ans = max(ans, dp[msk | 1 << i]);
          } else {
            ans = max(ans, dp[msk] + mp[i][-cur]);
          }
        }
      }
  }
  ps(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(6);
  int t = 1, tc = 1;
  while (t--) {
    solve();
    tc++;
  }
  return 0;
}
