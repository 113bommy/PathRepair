#include <bits/stdc++.h>
const int P = 998244353;
using namespace std;
template <class T>
using vector2D = vector<vector<T>>;
template <class T>
using vector3D = vector<vector2D<T>>;
template <class T>
using pque = priority_queue<T>;
template <class T>
using heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
bool umax(T &x, T y) {
  return (x < y) ? x = y, true : false;
}
template <class T>
bool umin(T &x, T y) {
  return (x > y) ? x = y, true : false;
}
void prepare() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n;
double p, i3 = 1.0 / 3;
const double eps = 1e-10;
double calc(long long m) {
  long long k = n - m;
  long long tot = n * (n - 1) * (n - 2) / 6;
  long long cas0 = k * (k - 1) * (k - 2) / 6;
  long long cas1 = k * (k - 1) / 2 * m;
  long long cas2 = m * (m - 1) / 2 * k;
  long long cas3 = m * (m - 1) * (m - 2) / 6;
  return (double)(cas3 + cas2) / tot + i3 * cas1 / tot;
}
int main() {
  prepare();
  cin >> n >> p;
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    if (calc((l + (r - l) / 2)) < p - eps)
      l = (l + (r - l) / 2) + 1;
    else
      ans = (l + (r - l) / 2), r = (l + (r - l) / 2) - 1;
  }
  cout << ans << endl;
  return 0;
}
