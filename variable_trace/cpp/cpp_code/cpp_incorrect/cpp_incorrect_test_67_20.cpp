#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void ckmin(T &a, T b) {
  a = min(a, b);
}
template <class T>
inline void ckmax(T &a, T b) {
  a = max(a, b);
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using ipair = pair<int, int>;
using VI = vector<int>;
using VD = vector<double>;
using VS = vector<string>;
using VVI = vector<VI>;
double choose[1024][1024];
double calc(int n, int m) {
  double r = 0;
  for (int c1 = 0; c1 < (4); ++c1) {
    int c2 = 3 - c1;
    if (c1 <= m && c2 <= n - m) {
      double prob1 = choose[m][c1] * choose[n - m][c2];
      double prob2 = 0;
      if (c1 == 0)
        prob2 = 0;
      else if (c1 == 1)
        prob2 = 2.0 / 3.0;
      else
        prob2 = 1;
      r += prob1 * prob2;
    }
  }
  r /= choose[n][3];
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  memset(choose, 0, sizeof(choose));
  for (int i = 0; i < (1024); ++i)
    for (int j = 0; j < (i + 1); ++j)
      choose[i][j] = (j == 0 ? 1 : choose[i - 1][j - 1] + choose[i - 1][j]);
  int n;
  double p;
  cin >> n >> p;
  for (int m = 0; m <= n; m++)
    if (calc(n, m) >= p - eps) {
      printf("%d\n", m);
      return 0;
    }
  printf("%d\n", n);
  return 0;
}
