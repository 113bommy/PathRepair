#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 1e5 + 10;
template <typename... T>
void debug(T&... args) {
  cout << "\n==================\n";
  ((cout << args << ", "), ...);
  cout << "\n==================\n";
}
template <typename T>
void debug(vector<T>& a) {
  cout << "\n==============\n";
  for (auto& e : a) cout << e << ' ';
  cout << "\n==============\n";
}
template <typename... T>
void put(T&... args) {
  ((cout << args << " "), ...);
}
void solve() {
  long long n, k, x;
  string s;
  cin >> n >> k >> x >> s;
  vector<long long> a;
  for (long long i = 0; i < n;) {
    if (s[i] == 'a') {
      a.push_back(-1);
      i++;
    } else {
      long long c = 0;
      while (i < n && s[i] == '*') i++, c += k;
      a.push_back(c);
    }
  }
  vector<long long> b(a.size() + 1);
  b[a.size()] = 1;
  x--;
  for (long long i = a.size(); i > 0; i--) {
    long long prv = b[i + 1];
    if (a[i] < 0)
      b[i] = prv;
    else {
      if (a[i] + 1 > x / prv) {
        b[i] = x + 1;
      } else
        b[i] = prv * (a[i] + 1);
    }
  }
  string ans;
  for (long long i = 0; i < a.size(); i++) {
    if (a[i] < 0)
      ans += 'a';
    else {
      long long nxt = b[i + 1];
      while (x >= nxt) x -= nxt, ans += 'b';
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
