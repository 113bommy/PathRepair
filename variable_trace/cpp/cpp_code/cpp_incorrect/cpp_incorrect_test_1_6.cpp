#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& o, pair<T, S> p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type operator<<(
    ostream& o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
template <long long int i, class... T>
typename enable_if<i == sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {}
template <long long int i, class... T>
    typename enable_if < i<sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {
  _p<i + 1>(o << get<i>(t) << ", ", t);
}
template <class... T>
ostream& operator<<(ostream& o, tuple<T...> t) {
  _p<0>(o << '(', t);
  return o << ')';
}
long long int M = 1000000007;
long long int inv(long long int a, long long int b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
pair<long long int, long long int> neigh[4] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
long long int n, k;
vector<pair<long long int, long long int>> v;
const double ep = 1e-6;
const double PI = acos(-1);
double getNum(double a, double b, double c) {
  return (a * a + b * b - c * c) / (2 * a * b);
}
double lc(double a, double b, double c) { return acos(getNum(a, b, c)); }
bool can(double r) {
  vector<pair<double, bool>> sweep;
  for (long long int i = 0; i < (n); i++) {
    double dist = sqrtl(v[i].first * v[i].first + v[i].second * v[i].second);
    double num = getNum(r, dist, r);
    double ang = fmod(atan2(v[i].second, v[i].first) + 2 * PI, 2 * PI);
    if (abs(num) < 1.0 + ep) {
      double ang2 = fmod(acos(num) + 2 * PI, 2 * PI);
      double ent = fmod(ang - ang2 + 2 * PI, 2 * PI);
      double ex = ent + 2 * ang2;
      for (long long int j = 0; j < (3); j++) {
        sweep.push_back({ent + 2 * PI * j, true});
        sweep.push_back({ex + 2 * PI * j, false});
      }
    }
  }
  sort(sweep.begin(), sweep.end());
  long long int ma = 0;
  long long int c = 0;
  for (long long int i = 0; i < (sweep.size()); i++) {
    c += sweep[i].second ? 1 : -1;
    ma = max(c, ma);
  }
  return ma >= k;
}
double solve(double l, double r) {
  if (abs(l - r) < ep) return l;
  double mid = (l + r) / 2;
  if (can(mid)) return solve(l, mid);
  return solve(mid, r);
}
int main() {
  cin >> n >> k;
  for (long long int i = 0; i < (n); i++) {
    long long int x;
    cin >> x;
    long long int y;
    cin >> y;
    v.push_back({x, y});
    if (x == 0 && y == 0) k--;
  }
  cout << setprecision(18) << solve(0, 200000) << endl;
}
