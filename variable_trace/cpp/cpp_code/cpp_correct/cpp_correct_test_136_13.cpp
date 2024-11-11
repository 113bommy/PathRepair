#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cout << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cout << ' ' << H;
  dbg_out(T...);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long sum = accumulate((a).begin(), (a).end(), 0ll);
    long long tot = (n * (n + 1)) / 2;
    if (sum % tot || sum / tot < n) {
      cout << "NO\n";
      continue;
    }
    sum /= tot;
    vector<long long> ans(n);
    long long bad = 0;
    for (long long i = 0; i < n; i++) {
      long long diff = a[(i + 1) % n] - a[i];
      if ((sum - diff) % n) bad = 1;
      ans[(i + 1) % n] = (sum - diff) / n;
    };
    long long s = 0;
    for (auto x : ans) bad |= (x <= 0), s += x;
    if (bad || sum != s)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto x : ans) cout << x << " ";
      cout << "\n";
    }
  }
}
