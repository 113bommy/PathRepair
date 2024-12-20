#include <bits/stdc++.h>
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
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int main() {
  int n;
  db p;
  scanf("%d%lf", &n, &p);
  int P = p * 10000 + 0.5;
  auto binom = [](int n, int m) {
    if (m < 0 || n - m < 0) return 0ll;
    ll res = 1;
    for (auto i = 0; i <= m - 1; i++) res *= (n - i);
    for (auto i = 1; i <= m; i++) res /= i;
    return res;
  };
  auto check = [&](int x) {
    ll A = 0, B = binom(n, 3) * 2;
    A += binom(x, 3) * binom(n - x, 0) * 2;
    A += binom(x, 2) * binom(n - x, 1) * 2;
    A += binom(x, 1) * binom(n - x, 2);
    return A * 10000 >= B * P;
  };
  int l = 0, r = n + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
