#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void Print(T a[], T n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << 0 << "\n";
    return;
  }
  int same1 = 0, diff1 = 0, same = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      same++;
      if (s[i] == '1') same1++;
    } else {
      if (s[i] == '1') diff1++;
    }
  }
  int diff = n - same;
  if (same == n) {
    cout << 0 << "\n";
    return;
  }
  int ans = INT_MAX;
  if (same1 > same - same1) {
    ans = min(ans, same);
  }
  if (diff1 == diff - diff1) {
    ans = min(ans, diff);
  }
  if (ans != INT_MAX)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
